#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
#include <utility>
#include <iterator>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <iomanip>

using namespace std;

template<class T>
string tostring(T a){stringstream ss; ss<<a; return ss.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;
#define SZ(a) int((a).size()) 
#define PB push_back 
#define ALL(c) (c).begin(),(c).end() 
#define FOR(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define LOOP(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define MP(a,b) make_pair((a),(b))
#define LAST(t) (t[SZ(t)-1])

int n;

int main(){

	//ifstream be("A-large.in");
	ifstream be("C-small-attempt0.in");
	ofstream ki("ki.txt");

	int tt; be>>tt;
	for(int ttt=0; ttt<tt; ttt++){
		be>>n;
		VI xs;
		FOR(i,n){
			int x; be>>x;
			xs.PB(x);
		}
		VI volt(10000000);
		int solse1, solse2;
		//FOR(se,1<<n){
		for(int se=1; se<1<<n; se++){
			int he=1, sum=0;
			FOR(i,n){
				if(se & he)
					sum+=xs[i];

				he<<=1;
			}
			if(!volt[sum])
				volt[sum]=se;
			else{
				solse1=se;
				solse2=volt[sum];
				break;
			}
		}
		VI sol1, sol2;
		{
			int he=1;
			FOR(i,n){
				if(solse1 & he)
					sol1.PB(xs[i]);
				if(solse2 & he)
					sol2.PB(xs[i]);

				he<<=1;
			}
		}
		
		ki<<"Case #"<<ttt+1<<": "<<endl;

		FOR(i,SZ(sol1)){
			ki<<sol1[i];
			if(i<SZ(sol1)-1)
				ki<<" ";
		}
		ki<<endl;
		FOR(i,SZ(sol2)){
			ki<<sol2[i];
			if(i<SZ(sol2)-1)
				ki<<" ";
		}
		ki<<endl;
		//ki<<"Case #"<<ttt+1<<": "<<  <<endl;
	}

	return 0;
}