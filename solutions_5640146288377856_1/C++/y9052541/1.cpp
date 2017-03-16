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
int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int Q_Q; scanf("%d",&Q_Q);
	while(Q_Q--){
		int Ans=0,n,m,w;
		scanf("%d%d%d",&n,&m,&w);
		if(m%w!=0) Ans=n*(m/w+1)+w-1;
		else Ans=n*(m/w)+w-1;
		printf("Case #%d: %d\n",++Case,Ans);
	}
}
