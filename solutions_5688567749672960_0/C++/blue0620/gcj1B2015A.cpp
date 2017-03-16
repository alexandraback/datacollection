#include <stdio.h> 
#include <stdlib.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//conversion
//------------------------------------------
inline int toLL(string s) {long long v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;


int main(){
	ifstream ifs("A-small-attempt5.in");
	ofstream ofs("test.txt");
	LL T,B;
	LL N;
	ifs>>T;
	vector<LL>answer;
	REP(tt,T){
		ifs>>N;
		LL buf=0;
		if(N<=10){
			answer.PB(N);
			continue;
		}
		if(N%10==0){
			N--;buf=1;
		}
		int digit=SZ(toString(N));
		int nd=1;
		LL nw=1;LL cnt=0;
		while(nd<digit){
			LL pw=pow(10,nd-1);//nd==2‚È‚ç10-1
			nw+=pw-1;
			string str=toString(nw);
			reverse(ALL(str));
			nw=toLL(str);
			nw+=9;
			cnt+=(pw+9);
			nd++;
		}//Œ…”‚ª‘µ‚¤‚Ü‚Å100,1000
		//cout<<tt+1<<" "<<cnt<<" "<<nw<<endl;
		LL cnt2=cnt+(N-nw);//‹ð’¼‰ð
		if(N-nw<0)cout<<"!"<<endl;
		string sN=toString(N);
		string st="";
		REP(i,digit/2)st+=sN[i];
		reverse(ALL(st));
		LL nn=toLL(st);
		cnt+=nn+1;//ÅŠñ‚è‚Ü‚Å
		nw+=nn;
		string snw=toString(nw);
		reverse(ALL(snw));
		nw=toLL(snw);
		cnt+=(N-nw);
		//cout<<"!"<<cnt<<" "<<cnt2<<endl;
		answer.PB(cnt2+buf);
	}
	REP(tt,T){
		cout<<answer[tt]<<endl;
		ofs<<"Case #"<<tt+1<<": "<<answer[tt]<<endl;
	}
	return 0;
}