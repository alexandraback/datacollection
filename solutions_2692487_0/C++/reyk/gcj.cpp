#include<stdio.h>
#include<algorithm>
using namespace std;
int ar[100];
int min(int a,int b){return a<b?a:b;}
int main(){
	int dn;
	scanf("%d",&dn);
	for(int di=0;di<dn;di++){
		int st,n;
		int i,j;
		scanf("%d %d",&st,&n);
		for(i=0;i<n;i++)scanf("%d",&ar[i]);
		sort(ar,ar+n);
		int ans=n;
		for(i=0;i<n;i++){
			int res=0;
			int s=st;
			for(j=0;j<n-i;j++){
				while(ar[j]>=s){
					s=s*2-1;
					res++;
					if(res>=n)break;
				}
				s+=ar[j];
			}
			ans=min(ans,res+i);
		}
		printf("Case #%d: %d\n",di+1,ans);
	}
	return 0;
}