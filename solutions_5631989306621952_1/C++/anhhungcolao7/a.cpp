
#include <bits/stdc++.h>
#define fi "a.inp"
#define fo "a.out"
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define All(x) x.begin(),x.end()
#define st first
#define nd second
#define It interator
#define sl_int(x) __builtin_popcount(x)

using namespace std;

typedef pair<int,int> II;
typedef pair<int,II> III;
typedef long long ll;
typedef pair<ll,ll> LL;
set <II> th;
struct Point 
{
	int x,y;
	bool operator <(const Point &T)
	{
			if (x==T.x) return (y<T.y);
			return (x<T.x);
	}
};

int test,n;
char u,s[1001];
deque <char> q;

int main()
{
	freopen (fi, "r", stdin);
	freopen (fo, "w", stdout);
	scanf("%d", &test);
	For(Test,1,test)
	{
		scanf("%s",s+1);
		n = strlen(s+1);
		For(i,1,n)
		{
			u = q.front();
			if (s[i]>=u) 
			{
				q.push_front(s[i]);
			}
			else q.push_back(s[i]);
		}
		printf("Case #%d: ", Test);
		while (!q.empty())
		{
			printf("%c",q.front());
			q.pop_front();
		}
		cout<<endl;
	}
	return 0;
}
