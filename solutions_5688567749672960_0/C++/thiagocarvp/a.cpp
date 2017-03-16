#include <bits/stdc++.h>

#define maxn 1010000
#define inf 0x3F3F3F3F
#define linf 0x3F3F3F3F3F3F3F3FLL
#define eps 1e-9
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef priority_queue<pii, vii, greater<pii> > pq;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

int n, t;
int vis[maxn];
char s[100];

int main()
{
	int x, last, teste = 1;
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) vis[i] = -1;
		queue<int> q;
		q.push(1);
		vis[1] = 1;
		while(!q.empty() && vis[n] == -1)
		{
			x = q.front(); q.pop();
			last = vis[x];
			if(vis[x+1] == -1)
			{
				vis[x+1] = last+1;
				q.push(x+1);
			}
			sprintf(s, "%d", x);
			reverse(s, s+strlen(s));
			x = atoi(s);
			if(vis[x] == -1)
			{
				vis[x] = last+1;
				q.push(x);
			}
		}
		printf("Case #%d: %d\n", teste++, vis[n]);
	}

	return 0;
}