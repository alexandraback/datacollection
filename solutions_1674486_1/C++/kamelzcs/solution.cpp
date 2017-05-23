#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<LL> VLL;
VI adj[1010];
int N;
bool visited[1010];

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T;
	cin>>T;
	for(int tt=1;tt<=T;++tt)
	{
		for(int j=0;j<1010;++j) adj[j].clear();
		memset(visited,0,sizeof(visited));
		printf("Case #%d: ",tt);
		cin>>N;
		for(int j=1;j<=N;++j)
		{
			int num;
			cin>>num;	
			for(int k=0;k<num;++k)
			{
				int temp;
				cin>>temp;
				adj[j].push_back(temp);
			}
		}
		for(int j=1;j<=N;++j)
		{
			memset(visited,0,sizeof(visited));
			queue<int> Q;
			Q.push(j);
			visited[j]=true;
			while (!Q.empty())
			{
				int top=Q.front();
				Q.pop();
				for(int k=0;k<adj[top].size();++k)
				{
					int next=adj[top][k];
					if(visited[next])
					{
						puts("Yes");
						goto loop;
					}
					Q.push(next);
					visited[next]=true;
				}
			}
		}
		puts("No");
loop:
		{

		}
	}

	//system("pause");
	return 0;
}