#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree_set;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

#define I 2
#define J 3
#define K 4

struct Q{
	int x;
	Q(){};
	Q(char c) {
		if(c==1) x=1;
		if(c=='i') x=I;
		if(c=='j') x=J;
		if(c=='k') x=K;
	}
	Q(int _x):x(_x){}
	Q operator*(Q q) {
		int tx=abs(x);
		int ty=abs(q.x);
		int r;
		if(tx==1) {
			if(ty==1) r=1;
			if(ty==2) r=I;
			if(ty==3) r=J;
			if(ty==4) r=K;
		}else if(tx==2) {
			if(ty==1) r=I;
			if(ty==2) r=-1;
			if(ty==3) r=K;
			if(ty==4) r=-J;
		}else if(tx==3) {
			if(ty==1) r=J;
			if(ty==2) r=-K;
			if(ty==3) r=-1;
			if(ty==4) r=I;
		}else if(tx==4) {
			if(ty==1) r=K;
			if(ty==2) r=J;
			if(ty==3) r=-I;
			if(ty==4) r=-1;
		}
		
		if(x<0^q.x<0) r=-r;
		return Q(r);
	}
	
	bool operator==(Q b){
		return x==b.x;
	}
};

char s[90010];
int main()
{
	#ifdef LOCAL
		freopen("C-large.in","r",stdin);
		freopen("C-large.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	int t,l,cs=1;
	ll x;
	cin>>t;
	while(t--) {
		cin>>l>>x;
		cin>>s;
		REP(i,9)
		REP(j,l)
			s[i*l+j]=s[j];
		ll n=x*l;
		
		int L=-1, R=-1;
		Q q1(1), q2(1);
		REP(i,9*l) {
			q1=q1*Q(s[i]);
			q2=Q(s[9*l-i-1])*q2;
			if(q1==Q(I) && ~L) L=i+1;
			if(q2==Q(K) && ~R) R=i+1;
		}
		Q r(1), t(1);
		REP(i,l) t=t*Q(s[i]);
		while(x) {
			if(x&1) r=r*t;
			x>>=1;
			t=t*t;
		}
		
		int ok = L+R<n && r==Q(I)*Q(J)*Q(K);
		/*int c=0;
		REP(i,n) {
			q[i+1]=q[i]*Q(s[i]);
			if(c==0 && q[i+1]==Q(I)) c++;
			else if(c==1 && q[i+1]==Q(I)*Q(J)) c++;
			else if(i==n-1 && c==2 && q[i+1]==Q(I)*Q(J)*Q(K)) c++;
		}
		int ok=c==3;
		*/
		cout<<"Case #"<<cs++<<": "<<(ok?"YES":"NO")<<endl;
	}
	
	return 0;
}


