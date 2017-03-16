#include <stdio.h> 
#include <stdlib.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>


using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
LL gcd(LL a,LL b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
	ifstream ifs( "A-small-attempt2.in" );
	ofstream ofs( "test.txt" );
	int T;
	ifs>>T;
	vector<string>answer;
	REP(i,T){
		LL p,q;
		char b;
		bool c=true;
		ifs>>p>>b>>q;
		LL g=gcd(p,q);
		p/=g;q/=g;
		LL t=q;
		int count=0;
		while(t%2==0){
			t/=2;
			count++;
		}//2‚Ìcountæ
		if(p>q||t!=1){
			answer.PB("impossible");
			continue;
		}
		LL comp=1;
		int minus=0;
		while(p>=comp){
			comp*=2;
			minus++;
		}
		answer.PB(toString(count-minus+1));
	}
	REP(i,T){
		ofs<<"Case #"<<i+1<<": "<<answer[i]<<endl;
		cout<<"Case #"<<i+1<<": "<<answer[i]<<endl;
	}
	return 0;
}