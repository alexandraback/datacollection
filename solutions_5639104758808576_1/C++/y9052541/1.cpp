#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 100005
#define For(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
char s[N];
int n,Case,num[N],sum[N];
int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	
	int Q_Q; scanf("%d",&Q_Q);
	while(Q_Q--){
		scanf("%d",&n);
		scanf("%s",s);
		For(i,0,n) sum[i]=num[i]=(s[i]-'0');
		For(i,1,n) sum[i]+=sum[i-1];
		int Ans=0;
		For(i,1,n) Ans=max(Ans,i-sum[i-1]);
		printf("Case #%d: %d\n",++Case,Ans);
	}
}
