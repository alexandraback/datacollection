#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	int cas=0;
	while(t--){
		int ans=0;
		int c,d,v;
		scanf("%d%d%d",&c,&d,&v);
		int a[d];
		int i;
		for(i=0;i<d;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+d);
		int place=0;
		int tot=0;
		while(tot<v){
			if(place==d){
				ans++;
				tot=tot+(tot+1)*c;
				continue;
			}
			if(tot>=a[place]-1){
				tot+=a[place]*c;
				place++;
			}
			else{
				ans++;
				tot=tot+(tot+1)*c;
			}
		}
		printf("Case #%d: %d\n",++cas,ans);
	}
}