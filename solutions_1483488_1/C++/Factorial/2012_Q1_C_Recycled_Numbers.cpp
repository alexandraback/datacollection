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

int main(){
	ifstream be("C-large.in");
	ofstream ki("ki.txt");

	LL T; be>>T;
	FOR(tt,T){
		
		LL a,b; be>>a>>b;
		LL nd=1, bp10=10;
		int c=0;
		set<II> s;
		for(LL x=1; x<=b; x++){
			if(x==bp10){
				nd++;
				bp10*=10;
			}

			if(x>a){
				LL pow10=1;
				for(LL k=1; k<nd; k++){
					pow10*=10;
					LL y= x/pow10 + (x%pow10)* bp10/pow10;
					II par=MP(min(x,y),max(x,y));
					//II par=MP(x,y);
					//if((x%pow10)/(pow10/10) && y>=a && y<=b && !s.count(par)){
					if(x!=y && y>=a && y<=b && !s.count(par)){
						c++;
						s.insert(par);
					}
				}
			}
		}
		cout<<tt<<endl;
		ki<<"Case #"<<tt+1<<": "<<c<<endl;
	}

	return 0;
}