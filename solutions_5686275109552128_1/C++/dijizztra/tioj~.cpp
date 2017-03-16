#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef short int si;
int t,d,p[1005],cas=0,ans=-1;


int main(){
	freopen("ans.txt","w",stdout);
	freopen("B-large.in","r",stdin);
	
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&d);
		
		ans=-1;
		for(int i=0;i<d;++i){
			scanf("%d",&p[i]);
			if(p[i]>ans){
				ans=p[i];
			}
		}
		int tmp=2;
		
		while(tmp<ans){
			int sum=0;
			for(int i=0;i<d;++i){
				sum+=(p[i]-1)/tmp;
			}
			ans=min(ans,sum+tmp);
			++tmp;
		}
		
		printf("Case #%d: %d\n",++cas,ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
