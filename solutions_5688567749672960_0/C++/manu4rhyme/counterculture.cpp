#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#define ABS(x) ((x) < 0 ? -1*(x) : (x))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define mp make_pair
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;

queue< pair<int, int> > q;
int rev[1000010];
long long int ans;

inline int reve(int n)
{
	int ans = 0;
	while(n)
	{
		ans = (10*ans) + n % 10;
		n /= 10;
	}

	return ans;
}

void BFS(int N)
{
	pair<int, int> t;
	int top,tmp;
	unordered_map<long long int, int> visited;
	q.push(mp(1,1));
	ans = 0;
	visited[1] = 1;
	while(q.size())
	{
		t = q.front();
		q.pop();
		++ans;
		top = t.first;
		if(top == N)
		{
			ans = t.second;
			break;
		}
		tmp = top+1;
		if(!visited[tmp])
		{
			q.push(mp(tmp,t.second+1));
			visited[tmp] = 1;
		}

		tmp = reve(top);
		if(!visited[tmp])
		{
			q.push(mp(tmp,t.second+1));
			visited[tmp] = 1;
		}
	}
}


int main()
{
	int T,N,i;

	/*for(i = 0; i < 1000010; ++i)
		rev[i] = reve(i);*/

	/*for(i = 0; i < 20; ++i)
		printf("%d\n", rev[i]);*/

	scanf("%d",&T);

	for(i = 1; i <= T; ++i)
	{
		scanf("%d", &N);

		while(q.size())
			q.pop();

		BFS(N);

		printf("Case #%d: %lld\n",i, ans);
	}

	return 0;
}