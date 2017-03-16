	#include <bits/stdc++.h>
	#include <string.h>
	#define mp make_pair
	#define pb push_back
	#define lldd long long int
	#define mod 1000000007
	using namespace std;
int main()
{
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	int tt =t;
	while(t--)
	{
		int r,c,w;
		scanf("%d %d %d",&r,&c,&w);
		int cnt =0;
		int start =w;
		int ans =0;
		int flag=0;
		if(start==c)
				flag=1;
		while(start<=c)
		{
			cnt++;
			start+=w;
			if(start==c)
				flag=1;
		};
		ans += r*cnt;
		if(flag==1)
			ans+= (w-1);
		else
			ans+=w;
		printf("Case #%d: %d\n",(tt-t),ans);
    }
}