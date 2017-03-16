#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#define INF 99999999
#define MAX 100010
#define MOD 1000000007
#define mem(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
using namespace std;

int n ,l;
string str[160] ,str1[160] ,str2[160];
int num[50] ,no[50];
vector<int> v;

int main()
{
	/*freopen("A-small-attempt3.in","r",stdin);
    freopen("A-small-attempt3.out","w",stdout);*/
	int t;
	scanf("%d",&t);
	for(int r = 1;r <= t;r++)
	{
		mem(num);
		mem(no);
		v.clear();
		scanf("%d%d",&n,&l);
		for(int i = 0;i < n;i++)
		{
			cin>>str[i];
		}
		for(int i = 0;i < n;i++)
		{
			cin>>str1[i];
		}
		int flag = 0 ,ans = 0;
		for(int i = 0;i < l;i++)
		{
			for(int j = 0;j < n;j++)
			{
				if(str[j][i]=='1')
				{
					num[i]++;
				}
				if(str1[j][i]=='1')
				{
					no[i]++;
				}
			}
			if(num[i]==no[i])
			{
				if(num[i]==n/2)
				{
					v.push_back(i);
				}
				continue;
			}
			else if(num[i]==n - no[i])
			{
				ans++;
				for(int j = 0;j < n;j++)
				{
					if(str[j][i]=='1')
					{
						str[j][i] = '0';
					}
					else
					{
						str[j][i] = '1';
					}
				}
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if(flag)
		{
			printf("Case #%d: NOT POSSIBLE\n",r);
			continue;
		}
		sort(str1,str1+n);
		int size = v.size() ,sta = 1<<size ,min = 100;
		for(int i = 0;i < sta;i++)
		{
			for(int j = 0;j < n;j++)
			{
				str2[j] = str[j];
			}
			int cnt = 0 ,re = i ,cou = 0;
			while(re)
			{
				if(re&1)
				{
					for(int j = 0;j < n;j++)
					{
						if(str2[j][v[cnt]]=='1')
						{
							str2[j][v[cnt]] = '0';
						}
						else
						{
							str2[j][v[cnt]] = '1';
						}
					}
					cou++;
				}
				re >>= 1;
				cnt++;
			}
			sort(str2,str2+n);
			flag = 0;
			for(int j = 0;j < n;j++)
			{
				if(str1[j].compare(str2[j]))
				{
					flag = 1;
					break;
				}
			}
			if(!flag)
			{
				if(min > cou)
				{
					min = cou;
				}
			}
		}
		if(min==100)
		{
			printf("Case #%d: NOT POSSIBLE\n",r);
		}
		else
		{
			printf("Case #%d: %d\n",r,ans + min);
		}
	}
	return 0;
}