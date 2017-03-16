// #includes {{{
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cmath>
using namespace std;
// }}}
// pre-written code {{{
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define RREP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
//#define IFOR(i,it,c) for(__typeof((c).begin())it=(c).begin();it!=(c).end();++it,++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair
//#define PB push_back
#define TO_STRING(VariableName) # VariableName
//#define DB(c) cout<<TO_STRING(c)<<"="<<(c)<<endl

#define EXIST(e,s) ((s).find(e)!=(s).end())
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define debug2(x) cerr << #x << " = [";REP(__ind,(x).size()){cerr << (x)[__ind] << ", ";}cerr << "] (L" << __LINE__ << ")" << endl;

#define reset(a) memset((a),0,sizeof(a))
#define set(a) memset((a),-1,sizeof(a))
#define pb push_back

typedef long long Int;
typedef unsigned long long uInt;
typedef long double rn;

typedef pair<int,int> pii;

struct IO{ }io;//dummy
#define endl "\n"
IO& operator>>(IO &io,int &n){scanf("%d",&n);return io;}
IO& operator>>(IO &io,unsigned int &n){scanf("%u",&n);return io;}
IO& operator>>(IO &io,long long &n){scanf("%lld",&n);return io;}
IO& operator>>(IO &io,unsigned long long &n){scanf("%llu",&n);return io;}
IO& operator>>(IO &io,double &n){scanf("%lf",&n);return io;}
IO& operator>>(IO &io,long double &n){scanf("%Lf",&n);return io;}
IO& operator>>(IO &io,char *c){scanf("%s",c);return io;}

IO& operator<<(IO &io,const int &n){printf("%d",n);return io;}
IO& operator<<(IO &io,const unsigned int &n){printf("%u",n);return io;}
IO& operator<<(IO &io,const long long &n){printf("%lld",n);return io;}
IO& operator<<(IO &io,const unsigned long long &n){printf("%llu",n);return io;}
IO& operator<<(IO &io,const double &n){printf("%lf",n);return io;}
IO& operator<<(IO &io,const long double &n){printf("%Lf",n);return io;}
IO& operator<<(IO &io,const char c[]){printf("%s",c);return io;}
// }}}

map<char,char> m;

void main2(){
	string s;
	getline(cin,s);
	REP(i,s.size()){
		if(s[i]==' ')cout<<s[i];
		else cout<<m[s[i]];
	}
	cout<<endl;
}

void init(){
	string s[]={
		"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	string t[]={
		"our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up"
	};
	REP(i,3){
		REP(j,s[i].size()){
			assert(s[i].size()==t[i].size());
			if(s[i][j]==' ')continue;
			m[s[i][j]]=t[i][j];
		}
	}
	m['z']='q';
	set<char> sc;
	FOR(it,m)sc.insert(it->second);
	REP(i,26){
		char c='a'+i;
		if(!EXIST(c,sc)){
			m['q']=c;
		}
	}
//	cout<<m.size()<<endl;
}

//{{{ main function
int main() {
	init();
	int T;scanf("%d", &T);
	string dum;
	getline(cin,dum);
	REP(ct, T){ printf("Case #%d: ",ct+1);main2();}
	return 0;
}
//}}}
