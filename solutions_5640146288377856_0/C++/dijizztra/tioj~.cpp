#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef short int si;

int t,r,c,w,now=0;

int main(){
	freopen("ans.txt","w",stdout);
	freopen("A-small-attempt5.in","r",stdin);
	
	scanf("%d",&t);
	
	while(t--){
		scanf("%d%d%d",&r,&c,&w);
		int ans=0;
		/*if(c==w)ans=c;
		else if(w==1)ans=r*c;
		else ans=w+1;*/
		
		if(c%w>0){
			ans=(c/w)*r-1+w+1;
		}
		else {
			ans=(c/w)*r-1+w;
		}
		
		printf("Case #%d: %d\n",++now,ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
