#include <bits/stdc++.h>

#define TASK ""
#define sqr(x) ((x)*(x))
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
const ll INFLL = numeric_limits<long long>::max();
const ll INFINT = numeric_limits<int>::max();
const ld EPS = 1e-7;
const ll MOD = 1e9 + 7LL;
const ll MAXN = 250000;

int run()
{
	ll t;
	cin >> t;
	for (int q = 0; q < t; q++)
	{
		ll n;
		cin >> n;
		vector<ll> pred;
		vector<bool> used;
		vector<bool> isgood;
		vector<vector<ll> > potom;
		vector<ll> tm;
		pred.resize(n);
		potom.resize(n, vector<ll>());
		used.resize(n, false);
		tm.resize(n, -1);
		ll nowtime = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> pred[i];
			pred[i]--;
			potom[pred[i]].push_back(i);
		}
		ll ans = -1;
		for (int i = 0; i < n; i++)
		{
			ll cur = i;
			ll starttime = nowtime;
			while (!used[cur])
			{
				tm[cur] = nowtime;
				used[cur] = true;
				nowtime++;
				cur = pred[cur];
			}
			if (tm[cur] >= starttime)
			{
				ans = max(ans, nowtime - tm[cur]);
			}
		}
		ll ans3 = 0;
		for (int i = 0; i < n; i++)
		{
			if (pred[pred[i]] == i && pred[i]>i)
			{
				//cout << "good\n";
				ll tans1 = 0;
				ll tans2 = 0;
				queue<pair<ll, ll> > q;
				q.push(make_pair(1, i));
				while (!q.empty())
				{
					tans2 = max(tans2, q.front().first);
					for (auto j : potom[q.front().second])
					{
						if (j != i && j != pred[i])
							q.push(make_pair(q.front().first + 1, j));
					}
					q.pop();
				}
				q.push(make_pair(1, pred[i]));
				while (!q.empty())
				{
					tans1 = max(tans1, q.front().first);
					for (auto j : potom[q.front().second])
					{
						if (j != i && j != pred[i])
							q.push(make_pair(q.front().first + 1, j));
					}
					q.pop();
				}
				ans3 += tans1 + tans2;
			}
		}
		cout << "Case #" << q + 1 << ": " << max(ans, ans3) << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef LOCAL
#ifdef STRESS
	freopen("input.txt","w",stdout);



#endif
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	if(strcmp(TASK,"")!=0)
	{
		freopen(TASK".in", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}
#endif

	run();

	return 0;
}