#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); (i) <= (b); ++(i))
#define mp make_pair
#define inf 2000000000
#define pb push_back
#define X first
#define Y second
#define LL long long
const double eps = 0.0000000001;
const int maxCount = 100000*20+2;

int  a[2002];
int b[maxCount], c[maxCount];
int n,sum;

void go(int ind, int mask)
{
	if (b[ind] == mask || c[ind] == mask) return;
	if (b[ind] == -1)
	{
		b[ind] = mask;
		return;
	}
	if (c[ind] == -1)
	{
		c[ind] = mask;
		return;
	}
	
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin >> T;
	FOR(test,1,T)
	{
		cin >> n;
		sum = 0;
		FOR(i,1,n)
		{
			cin >> a[i];
			sum += a[i];
		}
		b[0] = c[0] = 0;
		FOR(i,1,sum) b[i] = c[i] = -1;
		FOR(i,1,n)		
		for (int j = sum; j >=0; --j)
		{
			if (c[j] != -1)
			{
				go(j+a[i], c[j] | (1<<(i-1)));
			}

			if (b[j] != -1)
			{
				go(j+a[i], b[j] | (1<<(i-1)));
			}
		}
		cout << "Case #"<<test<<":\n";
		bool ok = false;
		for (int j = 1; j < (1<<n); ++j)
		{
			int tsum = 0;
			FOR(i,1,n)
				if (j & (1<<(i-1))) tsum += a[i];

			if (b[tsum] != -1 && b[tsum] != j)
			{
				ok = true;
				vector<int> tmp1, tmp2;
				FOR(i,1,n)
				{
					if (j & (1<<(i-1))) tmp1.pb(a[i]);
					if (b[tsum] & (1<<(i-1))) tmp2.pb(a[i]);
				}
				for(size_t i = 0; i < tmp1.size()-1; ++i)
					cout << tmp1[i]<< " ";
				cout << tmp1[tmp1.size()-1]<<endl;

				for(size_t i = 0; i < tmp2.size()-1; ++i)
					cout << tmp2[i]<< " ";
				cout << tmp2[tmp2.size()-1]<<endl;
				break;
			}
			if (ok) break;

			if (c[tsum] != -1 && c[tsum] != j)
			{
				ok = true;
				vector<int> tmp1, tmp2;
				FOR(i,1,n)
				{
					if (j & (1<<(i-1))) tmp1.pb(a[i]);
					if (c[tsum] & (1<<(i-1))) tmp2.pb(a[i]);
				}
				for(size_t i = 0; i < tmp1.size()-1; ++i)
					cout << tmp1[i]<< " ";
				cout << tmp1[tmp1.size()-1]<<endl;

				for(size_t i = 0; i < tmp2.size()-1; ++i)
					cout << tmp2[i]<< " ";
				cout << tmp2[tmp2.size()-1]<<endl;
				break;
			}
		}
		if (!ok)
			cout << "Impossible\n";
	}	
    return 0;
}