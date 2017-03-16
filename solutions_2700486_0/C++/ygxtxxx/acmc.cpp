#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int pre[1001];
double C[1001][1001];
int main(){
	freopen("b.in","r",stdin);
	freopen("b.txt","w",stdout);
	pre[1]=1;
	for(int i=2; i<=1000; ++i){
		pre[i]=pre[i-1]+(i*2-1)*2-1;
	}
	//printf("%d",pre[1000]);
	C[0][0]=1;
	for(int i=1; i<=1000; ++i){
		C[i][0]=C[i-1][0]/2;
		for(int j=1; j<=i; ++j){
			C[i][j]=C[i-1][j-1]/2+C[i-1][j]/2;
		}
	}
	int T,n,x,y;
	scanf("%d",&T);
	for(int cas=1; cas<=T; ++cas){
		scanf("%d%d%d",&n,&x,&y);
		int tmp=abs(x)+abs(y);
		tmp/=2;
		double ans;
		if(tmp>1000||n<=pre[tmp]){
			ans=0;
		}
		else if(n>=pre[tmp+1]){
			ans=1;
		}
		else{
			int rem=n-pre[tmp];
			int cc=tmp*2;
			if(x==0){
				ans=0;
			}
			else if(rem<abs(y)+1){
				ans=0;
			}
			else if(rem>=abs(y)+1+cc){
				ans=1;
			}
			else{
				double sum=0;
				for(int i=abs(y)+1; i<=rem; ++i) sum+=C[rem][i];
				ans=sum;
			}
		}
		printf("Case #%d: %f\n",cas,ans);
	}
	//system("pause");
}