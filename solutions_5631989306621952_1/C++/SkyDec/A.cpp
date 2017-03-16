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
const int N=1100;
int n;char a[N];
char b[N];
char c[N];
char d[N];
void Main(int Cas){
	scanf("%s",a+1);
	printf("Case #%d: ",Cas);
	n=strlen(a+1);
	rep(i,1,n){
		rep(j,1,i-1)c[j]=b[j];
		c[i]=a[i];
		d[1]=a[i];
		rep(j,1,i-1)d[j+1]=b[j];
		int bg=0;
		rep(j,1,i)if(c[j]>d[j]){bg=-1;break;}
		else if(c[j]<d[j]){bg=1;break;}
		if(bg<=0){
			rep(j,1,i)b[j]=c[j];
		}
		else rep(j,1,i)b[j]=d[j];
	}
	rep(i,1,n)printf("%c",b[i]);
	printf("\n");
}
int main(){
	int T;scanf("%d",&T);int CC=0;
	while(T--)Main(++CC);
	return 0;
}


