// Rohit Bhardwaj

#include<bits/stdc++.h>
#define md 1000000007
#define gc getchar//_unlocked
#define ll unsigned long long
using namespace std;

int main()
{
	
    	#ifndef ONLINE_JUDGE
			freopen("input.txt","r",stdin);
			freopen("out.txt","w",stdout);				
		#endif
		int test;
		scanf("%d",&test);
		for(int tt=1;tt<=test;tt++){
			printf("Case #%d: ",tt);
			int r,c,w;
			scanf("%d%d%d",&r,&c,&w);
			int ans;
			if(c%w==0)
			ans=c/w+w-1;
			else
			ans=c/w+w;
		ans+=(r-1)*(c/w);
		printf("%d\n",ans);
		}
    return 0;
}

