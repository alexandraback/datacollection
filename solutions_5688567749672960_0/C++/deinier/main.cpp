#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> par;
#define mp make_pair

#define MAXN 1000005
#define MOD 1000000007

// Define Variables/
ll c, k, n, res, rev;
// Define Variables

queue<par> Q;
par Qfront;

bool checked[MAXN];
bool findV;

ll reverse(ll numb)
{
	ll sol = 0;

	while (numb > 9)
	{
		sol *= 10;
		
		sol += numb % 10;

		numb /= 10;
	}

	sol *= 10;

	sol += numb % 10;

	return sol;
}

int main()
{
	ios::sync_with_stdio(false);

	ifstream in("A-small.in");
	ofstream out("A-small.out");

	in >> c;

	for (k = 1; k <= c; k++)
	{
		in >> n;

		if (n == 1)
		{
			res = 1;
		}
		else
		{
			Q.push(mp(1, 1));

			memset(checked, 0, sizeof(checked));

			checked[1] = 0;

			while (!Q.empty())
			{
				Qfront = Q.front();
				Q.pop();

				rev = reverse(Qfront.first);

				if (Qfront.first + 1 == n || rev == n)
				{
					res = Qfront.second + 1;

					break;
				}

				if (!checked[Qfront.first + 1])
				{
					checked[Qfront.first + 1] = 1;

					Q.push(mp(Qfront.first + 1, Qfront.second + 1));
				}

				if (!checked[rev])
				{
					checked[rev] = 1;

					Q.push(mp(rev, Qfront.second + 1));
				}
			}
		}		

		//cout << reverse(n) << endl;
		
		out << "Case #" << k << ": " << res << endl;

		while (!Q.empty())
			Q.pop();
	}	

	//input.close();
	//output.close();

	return 0;
}