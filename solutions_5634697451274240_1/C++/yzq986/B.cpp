#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=110;

int f[maxn][2];
char s[maxn];

void solve(){
	scanf("%s",s+1);int n=strlen(s+1);
	
	f[0][0]=f[0][1]=0;
	for(int i=1;i<=n;++i)
		if(s[i]=='+'){
			f[i][1]=min(f[i-1][0]+1,f[i-1][1]);
			f[i][0]=f[i][1]+1;
		}else{
			f[i][0]=min(f[i-1][0],f[i-1][1]+1);
			f[i][1]=f[i][0]+1;
		}
	printf("%d\n",f[n][1]);
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int kase,i=0;scanf("%d",&kase);
	for(int i=1;i<=kase;++i){
		printf("Case #%d: ",i);
		solve();
	}
//	for(;;);
	return 0;
}
