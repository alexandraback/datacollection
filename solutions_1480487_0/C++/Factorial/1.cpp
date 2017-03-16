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

VI s;
int n, sum;

bool ok(double x, int c){
	double khrl=0;
	double van=s[c]+sum*x;
	FOR(i,n){
		khrl+=max((double)0, (van-s[i])/((double)sum));
		//khrl+=max((double)0, sum*(s[i]-van));
	}
	return khrl>1;
}

int main(){

	ifstream be("A-small-attempt0.in");
	//ifstream be("be1.txt");
	ofstream ki("ki.txt");

	int tt; be>>tt;
	for(int ttt=0; ttt<tt; ttt++){
		be>>n;
		sum=0;
		s=VI();
		FOR(i,n){
			int x; be>>x;
			s.PB(x);
			sum+=x;
		}
		ki<<"Case #"<<ttt+1<<": ";
		FOR(i,n){
			double a=0, b=1;
			while(b-a>0.00000001){
				double c=(a+b)/2;
				if(ok(c,i))
					b=c;
				else
					a=c;
			}
			ki<<setprecision(9)<<a*100<<" ";
		}
		ki<<endl;
		
		//ki<<"Case #"<<ttt+1<<": "<<  <<endl;
	}

	return 0;
}