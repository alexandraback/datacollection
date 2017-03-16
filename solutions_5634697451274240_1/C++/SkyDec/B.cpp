#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=105;
int f[N][2];
int n;
char str[N];
void Main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	rep(i,1,n){
		if(str[i]=='+'){
			f[i][1]=min(f[i-1][1],f[i-1][0]+1);
			f[i][0]=f[i-1][1]+1;
		}
		else{
			f[i][0]=min(f[i-1][0],f[i-1][1]+1);
			f[i][1]=f[i-1][0]+1;
		}
		f[i][0]=min(f[i][0],f[i][1]+1);
		f[i][1]=min(f[i][1],f[i][0]+1);
	}
	printf("%d\n",f[n][1]);
}
int main(){
	int T;scanf("%d",&T);
	rep(Cas,1,T){
		printf("Case #%d: ",Cas);
		Main();
	}
	return 0;
}


