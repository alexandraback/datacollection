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

int p[40],sp[40];

int point(int s){
	return p[s];
	if(s%3==0)return s/3;
	else s/3+1;
}

int surprise_point(int s){
	return sp[s];
	if(s<=2)return s;
	if(s%3==0){
		return s/3+1;
	}else if(s%3==1){
		return s/3+1;
	}else{
		return s/3+2;
	}
}

void main2(){
	deque<int> s;
	int N,S,p;
	cin>>N>>S>>p;
	REP(i,N){
		int t;
		cin>>t;
		s.push_back(t);
	}
	sort(ALL(s),greater<int>());
	int ans=0;
	while(!s.empty()){
		int k=s.front();
		int sc;
		sc=point(k);
		if(sc>=p)ans++;
		else{
			sc=surprise_point(k);
			if(sc>=p and S>0)ans++,S--;
		}
		s.pop_front();
	}
	cout<<ans<<endl;
}

void init(){
	REP(i,40)p[i]=-1,sp[i]=-1;
	REP(i,11)REP(j,11)REP(k,11){
		int m=11,M=-1;
		int s=i+j+k;
		m=min(m,i);m=min(m,j);m=min(m,k);
		M=max(M,i);M=max(M,j);M=max(M,k);
		if(M-m>2)continue;
		if(M-m<=1){
			p[s]=max(p[s],M);
		}
		if(M-m<=2){
			sp[s]=max(sp[s],M);
		}
	}
}

//{{{ main function
int main() {
	init();
	int T;scanf("%d", &T);
	REP(ct, T){ printf("Case #%d: ",ct+1);main2();}
	return 0;
}
//}}}
