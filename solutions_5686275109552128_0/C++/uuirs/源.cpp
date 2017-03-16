#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;
int p[1010];
LL f[1010],fe[1010];
int main()
{
	int T,Cas = 1,D;
	int i, j, t, pmax;
	LL opt,ans;
	ifstream cin("B-small-attempt4.in");
	ofstream cout("out.txt");
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	cin >> T;
	while (T--)
	{
		cin >> D;
		for (i = 0; i < 1010; i++)
		{
			f[i] = 0;
		}
		pmax = 0;
		for (i = 0; i < D; i++)
		{
			cin >> p[i];
			pmax = max(pmax, p[i]);
			f[p[i]]++;
		}

		ans = pmax;
		for (i = pmax; i > 0; i--)
		{
			opt = 0;
			for (j = i + 1; j <= pmax; j++)
			{
				opt += f[j] *( (j + i-1) / i - 1);
			}
			ans = min(ans, i + opt);
		}
		cout << "Case #" << Cas++ << ": " << ans << endl;
	}

}