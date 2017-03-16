#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <stack>
#include <string.h>

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define PI 3.14159265358979
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define L(s) (int)((s).size())
#define ms(x) memset(x,0,sizeof(x))
#define del(y,x) erase(y.begin()+x)

typedef long long ll;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;
const int ST = 100010;
const int ST1 = 1000010;
const ll MOD = 1000000007;

ll ABS(ll a)
{
	if(a<0)
		return a*(-1);
	else
		return a;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	int ANS = 1;
	while(T)
	{
		int n;
		cin >> n;
		double mas[210],ans[210],sum = 0;
		bool used[210] = {};
		for(int i = 0;i < n;i++)
		{
			cin >> mas[i];
			sum+=mas[i];
		}
		double minn = 100;
		int nk = n;
		bool otr = true;
		double summ = sum;

		do
		{
			otr = true;
			for(int i = 0;i < n;i++)
			{
				if(!used[i])
				{
					minn = 1;
					double r = (sum + summ) / nk;
					r = r - mas[i];
					minn = r / (summ);
					ans[i] = minn * 100;
					if(minn < 0)
					{
						used[i] = true;
						nk--;
						sum-=mas[i];
						otr= false;
						ans[i] = 0;
					}
				}
			}
		}
		while(!otr);
		printf("Case #%d: ",ANS);
		for(int i = 0;i < n;i++)
		{
			printf("%0.5f ",ans[i]);
		}
		printf("\n");
		T--;
		ANS++;
	}
}