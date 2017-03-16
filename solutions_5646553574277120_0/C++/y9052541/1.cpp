#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define N
#define mo 1000000007
#define inf 100000000
#define eps 0.00000001
#define Long long long
#define uint unsigned int
#define lowbit(x) (x&(-x))
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Dor(i,r,l) for(int i=r;i>=l;i--)
#define Rep(i,t) for(int i=son[t];i;i=Next[i]) if(ed[i]!=f)
#define next Next
#define link Link
using namespace std;
int Case;
int Val[100005];
int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int Q_Q; scanf("%d",&Q_Q);
	while(Q_Q--){
		int Ans=0;
		int C,D,V; scanf("%d%d%d",&C,&D,&V);
		For(i,1,D) scanf("%d",&Val[i]);
		sort(Val+1,Val+1+D); Long Sum=0;
		for(int i=1;Sum<V;){
			for(;i<=D && Val[i]<=Sum+1;i++) Sum+=1LL*C*Val[i];
			if(Sum>=V) break;
			Ans++; Sum+=1LL*C*(Sum+1);
		}
		printf("Case #%d: %d\n",++Case,Ans);
	}
}
