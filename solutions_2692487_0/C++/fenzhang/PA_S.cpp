#include<stdio.h>
#include<algorithm>
using namespace std;
int a;
int n;
int b[514];
void sol(int uuu){
	scanf("%d",&a);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",b+i);
	if(a==1){
		printf("Case #%d: %d\n",uuu,n);
		return;
		}
	sort(b,b+n);
	int ans=n,tmp=0;
	for(int i=0;i<n;i++){
		for(;a<=b[i];){
			tmp++;
			a=a*2-1;
			}
		a+=b[i];
		ans=min(ans,tmp+n-i-1);
		}
	printf("Case #%d: %d\n",uuu,ans);
	}
int main(){
	freopen("A-small-attempt1.in","r",stdin);
	freopen("PAout.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int ti=1;ti<=t;ti++)
		sol(ti);
	return 0;
	}
