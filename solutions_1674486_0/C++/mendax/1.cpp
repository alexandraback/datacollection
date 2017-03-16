/* Author :  Jay Pandya */

// Standard includes
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<string.h>

//Data Structures
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>

//Macros
#define all(c) c.begin(),c.end() //all element in container c

#define tr(container, it) \
        for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) //to iterate in container

#define stringswap(swstingA, swstringB) \
        swstringA.swap(swstringB) //to swap string

#define present(container, element) (container.find(element) != container.end()) //to check whether a element is in a set or a map
#define cpresent(container, element) (find(all(container),element) != container.end()) //to check whether  a element is in container like vector

#define print(x) cout<<#x<<" is "<<x<<endl;//for printing
#define sz(a) int((a).size()) 
#define pb push_back 
#define vi vector<int>; 
#define vvi  vector<vi>; //2D string 
#define ii pair<int,int>; 
#define mp(typeA,typeB)  make_pair<typeA,typeB> //maing pair

//macros for limits

#define MAX 1123456
#define LLI long long int
#define ULLI unsigned long long int

using namespace std;
int a[MAX];
vector <int> graph[1024];
void dfs(int source,int dest)
{
	if(source==dest)
	{
		a[dest]++;
		return;
	}
	for(int i=0;i<graph[source].size();i++)
	{
		dfs(graph[source][i],dest);
	}
	return;
}
int main()
{
	int test;
	scanf("%d",&test);
	for(int cas=1;cas<=test;cas++)
	{
		printf("Case #%d: ",cas);
		for(int i=0;i<1024;i++)
			graph[i].resize(0);

		int n,x,y;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&y);
			for(int j=0;j<y;j++)
			{
				scanf("%d",&x);
				graph[i+1].pb(x);
			}
		}
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					memset(a,0,sizeof a);
					dfs(i,j);
					if(a[j]>=2)
					{
						printf("Yes\n");
						flag=1;
						break;
					}
				}
			}
			if(flag==1)
				break;
		}
		if(flag==0)
			printf("No\n");
	}
	return 0;
}

