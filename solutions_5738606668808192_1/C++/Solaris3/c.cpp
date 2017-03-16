#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 1
	#define DEB printf
#else
	#define DEB(...)
#endif

typedef long long ll;
typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int mod = 1000000007;
const int MAXN = 106;

vi P;
void solve() {
	int N=32,J=500;
	int ile=0;
	vi D;
	fru(m,1<<(N-2)){
		unsigned int mask=1+2*m+(1<<(N-1));
		bool ok=1;
		D.clear();
		fru(h,11)if(h>1){
			bool ok2=0;
			tr(it,P){
				//podstawa h, szukam swiadka p
				int ret=0;
				fru(w,N){
					ret*=h;
					if(mask &(1<<(w)))ret++;
					ret%=*it;
				}
				if(ret==0){
					ok2=1;D.pb(*it);break;
				}
			}
			if(!ok2){ok=0;break;}
		}
		if(ok){
			vi M;
			while(mask){
				M.pb(mask%2);mask/=2;
			}
			//reverse(ALL(M));
			tr(it,M)printf("%d",*it);printf(" ");
			tr(it,D)printf("%d ",*it);puts("");
			ile++;
			if(ile==J)return;
		}
	}
}
bool cmpl[MAXN];
int main() {
	fru(i,MAXN)if(i>1 && !cmpl[i]){
		P.pb(i);
		for(int j=2*i;j<MAXN;j+=i)cmpl[j]=1;
	}
	int _;
//	scanf("%d%d%d",&_,&_,&_);
	printf("Case #1:\n");
	solve();
	return 0;
}
