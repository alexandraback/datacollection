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

int num_dig(int n){
	int s=0;
	while(n)s++,n/=10;
	return s;
}

void main2(){
	int A,B;
	cin>>A>>B;
	int d=num_dig(A);
	int p=1;
	REP(i,d)p*=10;
	p/=10;
	int ans=0;
	for(int n=A;n<=B;n++){
		int m=n;
		set<int> ms;
		REP(i,d){
			int r=m%10;
			m=m/10+r*p;
//			cout<<n<<" "<<m<<endl;
			if(A<=m and m<=B and n<m){
				ms.insert(m);
			}
		}
		ans+=ms.size();
	}
	cout<<ans<<endl;
}

//{{{ main function
int main() {
	int T;scanf("%d", &T);
	REP(ct, T){ printf("Case #%d: ",ct+1);main2();}
	return 0;
}
//}}}
