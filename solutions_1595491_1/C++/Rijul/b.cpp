#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 300
int a[maxm],n,s,p;

int main(){

	int i,j,k,l,test,t=1;

	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d %d",&n,&s,&p);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		reverse(a,a+n);
		int ans=0;
		k=p+p+p-2;
		if(k<0) k=0;
		l=p+p+p-4;
		if(l<0) l=0;
		for(i=0;i<n;i++){
			if(!a[i]){
			    if(p==0) ans++;
			    continue;
			}
			if(a[i]>=k) ans++;
			else{
				if(a[i]>=l&&s){
					ans++;
					s--;
				}
			}
		}

		printf("Case #%d: %d\n",t++,ans);

	}

	return 0;
}
