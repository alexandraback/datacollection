#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;

#define For(i,n) for(int i = 0;i < n;i++)

long long count(string *s,int n)
{
	int num[30];
	bool flag[30];
	int head[30],tail[30];
	memset(head,0,sizeof(head));
	memset(tail,0,sizeof(tail));
	memset(num,0,sizeof(num));
	memset(flag,0,sizeof(flag));
	For(i,n)
	{
		bool f = true;
		For(j,s[i].size())
		{
			if(s[i][j] != s[i][0])
			{
				f = false;
				break;
			}
		}
		if(f)
		{
			flag[i] = 1;
			int t = s[i][0] - 'a';
			num[t]++;
		}
		else
		{
			int t1 = s[i][0] - 'a';
			head[t1]++;
			int n1 = s[i].size();
			int t2 = s[i][n1-1] - 'a';
			tail[t2]++;
		}
	}
	for(int i = 0;i < 30;i++)
	{
		if(head[i] > 1 || tail[i] > 1)
			return 0;
	}
	int isolated[30];
	memset(isolated,0,sizeof(isolated));
	For(i,n)
	{
		int n1 = s[i].size();
		int t1 = s[i][0] - 'a';
		if(isolated[t1]) 
			return 0;
		int t2 = s[i][n1 - 1] -'a';
		if(isolated[t2]) 
			return 0;
		if(n1 < 3)
		{
			continue;
		}
		for(int j = 1;j < n1 -1;j++)
		{
			int t3 = s[i][j] -'a';
			if(isolated[t3]) 
				return 0;
			if(s[i][j] != s[i][j - 1] && s[i][j] != s[i][j+1])
			{
				isolated[t3] = 1;
				if(head[t3] > 0 || tail[t3] > 0)
					return 0;
			}
		}
	}


	long long sum = 0;
	for(int i = 0;i < 30;i++)
	{
		if(head[i] == 1 && tail[i] == 0)
			sum++;
		if(num[i] > 0 && head[i] == 0 && tail[i] == 0)
			sum++;
	}
	if(sum == 0)
		return 0;
	long long result = 1;
	for(long long i = 1;i <= sum;i++)
	{
		result *= i;
	}
	for(int i = 0;i < 30;i++)
	{
		if(num[i] != 0)
		{
			for(long long j = 1;j <= (long long)num[i];j++)
				result *= j;
		}
	}
	return result;
}




int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int t;
	cin>>t;
	int id = 0;
	while(t--)
	{
		int n;
		cin>>n;
		string s[105];
		For(i,n)
		{
			cin>>s[i];
		}
		cout<<"Case #"<<++id<<": "<<count(s,n)<<endl;
	}
	return 0;
}
