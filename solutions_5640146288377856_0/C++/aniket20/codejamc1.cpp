#include<bits/stdc++.h>
#define N 1000000007
#define maxs 100005
#define mins 1005
#define ll long long
#define pb push_back
using namespace std;

int main()
{
	int t,r,c,w,ans,cnt=1;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&r,&c,&w);
		ans=(c/w);
		ans=ans*r;
		ans=ans+w-1;
		if(c%w!=0){
            ans++;
		}
		printf("Case #%d: %d\n",cnt,ans);
		cnt++;
	}
	return 0;
}
