#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int a[1009], b[1009], flag[1009];
int n;
int solve(int done, int stars)
{
	int ff=1, i;
	for(i=0; i<n&&flag[i]==2; i++);
	if(i==n)	return done;

	ff=1;
	for(i=0; i<n; i++)
	if(flag[i]<2 && b[i]<=stars)
	{	
		stars = stars + 2 - flag[i];
		done++;
		flag[i]=2;
		ff=0;
	}
	if(ff==0)	return solve(done, stars);

	for(i=0; i<n; i++)
	if(flag[i]==0 && a[i]<=stars)
	{
		flag[i]=1;
		stars++;
		done++;
		ff=0;
		break;
	}
	if(ff==0)	return solve(done, stars);
	return -1;
}	
int main()
{
	double prob;
	int t, i, j, ans;
	scanf("%d",&t);
	for(int tc=1; tc<=t; tc++)
	{
		scanf("%d",&n);
		memset(flag, 0, sizeof(flag));
		for(int i=0; i<n; i++)
		{
			scanf("%d%d",&a[i], &b[i]);
		}
		ans = solve(0,0);
		if(ans==-1)
		printf("Case #%d: Too Bad\n",tc);
		else
		printf("Case #%d: %d\n",tc, ans);
	}
	return 0;
}
			
