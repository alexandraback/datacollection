#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

int tick[1002] ; 

int main()
{
	int t ;
	int n , num , no ; 
	int i , j ;
	int val ;
	int flag ; 
	int l ;
	int total = 1 ; 
	scanf("%d",&t);

	while(t--)
	{
		vector<int> v[1002] ; 
		scanf("%d",&n);

		for(i = 0 ; i < n ; i++)
		{
			scanf("%d",&num);
			for(j = 0 ; j < num ; j++)
			{
				scanf("%d",&no);
				v[i+1].push_back(no);
			}
		}


		for(i = 1 ; i <= n ; i++)
		{
			queue<int> q ; 
			flag = 0 ; 
			memset(tick , 0, sizeof(tick));
			tick[i] = 1 ; 

			q.push(i);

			while( !q.empty())
			{
				val = q.front() ; 
				q.pop() ;
				l = v[val].size() ; 

				for(j = 0 ; j < l ; j++)
				{
					if(tick[v[val][j]] == 0)
					{
						tick[v[val][j]] = 1; 
						q.push(v[val][j]);
					}
					else
					{
						flag = 1; 
						break ; 
					}
				}
			}
			if(flag == 1)
				break ; 
		}
		if(flag == 0)
			printf("Case #%d: No\n",total++);
		else
			printf("Case #%d: Yes\n",total++);
	}
	return 0;
}
