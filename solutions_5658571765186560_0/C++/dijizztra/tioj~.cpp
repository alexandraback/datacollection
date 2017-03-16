#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef short int si;

int main(){
	freopen("ans.txt","w",stdout);
	freopen("D-small-attempt0.in","r",stdin);
	
	int t,cas=0,x,r,c;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d %d %d",&x,&r,&c);
		
		bool ans=true;
		
		if(x>=7)ans=false;
		else if(x>r && x>c)ans=false;
		else if(r*c%x)ans=false;
		else if((x+1)/2>min(r,c))ans=false;
		else if(x==1 || x==2 || x==3)ans=true;
		else if(x==4)ans=min(r,c)>2;
		else if(x==5)ans=!(min(r,c)==3 && max(r,c)==5);
		else if(x==6)ans=min(r,c)>3;
		
		printf("Case #%d: %s\n",++cas,ans?"GABRIEL":"RICHARD");
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
