#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int hash[1010][3];
/*int val[1010][3];*/
int n;
struct PP
{
	int x;
	int y;
}val[1010];
int work()
{
	memset(hash,0,sizeof(hash));
	int sum = 0;
	int ans = 0;
	while(true)
	{
		int flag = 0;
		for(int i = 1; i <= n ; i ++)
		{
			if(hash[i][2] == 0 && sum >= val[i].y)
			{
				hash[i][2] = 1;
				if(hash[i][1] == 1)
					sum += 1;
				else
					sum+=2;
				flag = 1;
				hash[i][1] = 1;
				ans ++;
				break;
				// 能够搞定2
			}
		}

		if(flag == 0)
		{
			for(int i = 1; i <= n; i ++)
			{
				if(hash[i][1] == 0 && sum >= val[i].x)
				{
					hash[i][1] = 1;
					sum ++;
					flag = 1;
					ans ++;
					break;
				}
			}
			if(flag == 0)
			{
				if(sum == n+n)
					return ans;
				return -1;
			}
		}
	}
}
int ans;


// void dfs(int sum,int cnt)
// {
// 	if(sum == n+n)
// 	{
// 		//搜到答案了 
// 		if(ans == -1 || ans > cnt)
// 			ans = cnt;
// 		return ;
// 	}
// 	if(ans != -1 && ans <= cnt) return ;
// 	for(int i = 1; i <= n ; i ++)
// 	{
// 		if(ok[i][2] == 0 && val[i][2] <= sum)
// 		{
// 			if(ok[i][1] == 1)
// 			{
// 				ok[i][2] =1;
// 				dfs(sum+1,cnt+1);
// 				ok[i][2] = 0;
// 			}
// 			else
// 			{
// 				ok[i][2] = 1;
// 				dfs(sum+2,cnt+1);
// 				ok[i][2] = 0;
// 			}
// 		}
// 		else if(ok[i][1] ==0 && ok[i][2] == 0 && val[i][1] <= sum)
// 		{
// 			//1 keyi na
// 			ok[i][1] = 1;
// 			dfs(sum+1,cnt+1);
// 			ok[i][1] = 0;
// 		}
// 	}
// }
int cmp(PP a,PP b)
{
	if(a.y == b.y)
		return a.x < b.x;
	return a.y > b.y;
}
int main()
{

	freopen("B-large.in","r",stdin);
	freopen("b.out","w",stdout);
	int T;
	int cas = 1;
	
	
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i = 1; i <= n ; i ++)
			//cin>>val[i][1]>>val[i][2];
			cin>>val[i].x>>val[i].y;
		
		sort(val+1,val+n+1,cmp);
	//	for(int i = 1; i <= n ; i ++)
	//		cout<<"     "<<val[i].x<<"  "<<val[i].y<<endl;
		ans = -1;
		

		//memset(ok,0,sizeof(ok));
		//dfs(0,0);
		ans = work();
		cout<<"Case #"<<cas++<<": ";
		if(ans == -1)
			cout<<"Too Bad"<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}