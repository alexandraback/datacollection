#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int x[1000];
int main(){
	int ca;
	int n;
	scanf("%d",&ca);
	for(int cas=1;cas<=ca;cas++){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",x+i);
		}
		sort(x,x+n);
		int low=0,high=x[n-1];
		while(high-low>1){
			int mid=(high+low)/2;
			bool f=false;
			for(int r=1;!f&&r<=mid;r++){
				int ct=0;
				for(int i=0;i<n;i++){
					ct+=(x[i]-1)/r;
				}
				if(ct+r<=mid)f=true;
			}
			if(!f)low=mid;
			else high=mid;
		}
		printf("Case #%d: %d\n",cas,high);
	}
}
