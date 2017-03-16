#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

using namespace std;

#define pb push_back
#define sz(x) ((int) (x).size())
#define fo(i, n) for (int i = 0; i < (n); i++)
#define fo2(i, j, n) for (int i = j; i < (n); i++)
#define rfo(i, n) for (int i = (n) - 1; i >= 0; i--)
#define clr(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef long long ll;
typedef pair<ll,ll> pll;

using namespace std;

int mset[1000];

bool recurs(int i, vvi* v)
{
	int s = (*v)[i].size();
	fo(j, s)
	{
		if (mset[(*v)[i][j]] == 1)
			return true;
		else
		{
			mset[(*v)[i][j]] = 1;
			if (recurs((*v)[i][j], v))
				return true;
		}
	}
	return false;
}

int main()
{

	int T;

	cin >> T;

	fo(t, T)
	{

		vvi v;
		int N;
		cin >> N;
		fo(i, N)
		{
			int M;
			cin >> M;
			vi inh;
			fo(j, M)
			{
				
				int temp;
				cin >> temp;
				inh.pb(temp - 1);
			}
			v.pb(inh);
		}

		cout << "Case #" << t+1 << ": ";
		bool flag = false;
		fo(i, N)
		{
			if (v[i].size() >= 2)
			{
				memset(mset, 0, 1000*sizeof(int));
				if (recurs(i, &v))
				{
					flag = true;
					break;
				}
			}
		}
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}