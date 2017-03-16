#include "iostream"
#include "cstring"
#include "cstdio"
#include "vector"
#include "string"
#include "algorithm"
#define PB push_back
#define MP make_pair
using namespace std;
const int N = 1000010;
int a[N];
int main(void)
{
	freopen("A-small-attempt0.in","r",stdin);
	int T,n,val;
	scanf("%d",&T);
	int g=0;
	while(T--){
		scanf("%d%d",&val,&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		int ans=10000000;
		int flag=0;
		int tmp;
		for(int i=1;i<=n;i++){
			if(a[i]<val){
				val+=a[i];
			}else{
				flag=1;
				tmp=n-i+1;
				ans=tmp;
				int sum=0;
				int j=i;
				while(1){
					if(j>n){
						ans=min(ans,sum);
						break;
					}
					if(val==1){
						break;
					}
					if(val>a[j]){
						val+=a[j];
						j++;
					}else{
						ans=min(ans,sum+n-j+1);
						sum++;
						val+=val-1;
					}
				}
				break;
			}
		}
		if(!flag){
			ans=0;
		}
		printf("Case #%d: %d\n",++g,ans);
	}

	return 0;
}