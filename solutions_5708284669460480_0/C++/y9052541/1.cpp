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
char s[10005];
int Case,num[1005],fail[100005];
int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int Q_Q; scanf("%d",&Q_Q);
	while(Q_Q--){
		int n,m,T; scanf("%d%d%d",&n,&m,&T);
		
		scanf("%s",s+1);
		For(i,'A','Z') num[i]=0;
		For(i,1,n) num[s[i]]++;
		
		scanf("%s",s+1); double Cnt=1;
		For(i,1,m) Cnt=Cnt*(1.*num[s[i]]/n); Cnt*=T-m+1;
		
		for(int i=1,j=0;i<=m;i++){
			for(;j && s[j+1]!=s[i];j=fail[j]);
			if(s[j+1]==s[i]) j++; if(i==1) j=0;
			fail[i]=j;
		}
		
//		For(i,1,m) printf("%d ",fail[i]); printf("fail\n");
		
		double Ans=(T-m)/(m-fail[m])+1; Ans-=Cnt;
		For(i,1,m) if(!num[s[i]]) Ans=0;
		
		printf("Case #%d: %.12lf\n",++Case,Ans);
	}
}
