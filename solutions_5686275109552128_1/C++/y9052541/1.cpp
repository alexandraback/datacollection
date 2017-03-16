#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#define N 10005
#define For(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
multiset <int> S;
int w[N],Case;
int main(){
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	
	int Q_Q; scanf("%d",&Q_Q);
	while(Q_Q--){
		int n,Ans=1000; scanf("%d",&n);
		For(i,1,n) scanf("%d",&w[i]);
		
		For(t,1,1000){
			int Cnt=0;
			For(i,1,n) if(w[i]>t){
				int Tmp=w[i]/t;
				if(Tmp*t<w[i]) Tmp++;
				Tmp--; Cnt+=Tmp;
			}
			Ans=min(Ans,t+Cnt);
		}
		printf("Case #%d: %d\n",++Case,Ans);
	}
}
