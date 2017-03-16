#include<iostream>
#include<vector>
#include<fstream>
#include<set>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

#define forn(i, n) for(int i=0; i < n; i++)

const int mm = 1000000000;

int A[4][4] = 
{{1, 2, 3, 4},
{2, -1, 4, -3},
{3, -4, -1, 2},
{4, 3, -2, -1}
};

int m(int a, int b)
{
	int sn = 1;
	if (a <0)
		sn = -sn;
	if (b < 0)
		sn = -sn;
	return sn * A[abs(a) - 1][abs(b) - 1];
}
int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int t;
	cin>>t;
	int uuu = 1;
	while(t--)
	{
		int ans, l, x, g[10101];
		string s;
		cin>>l>>x;
		cin>>s;
		forn(i, l)
			g[i] = s[i] - 'i' + 2;
		int tt = 1;
		forn(i, l)
			tt = m(tt, g[i]);
		int res = -1;
		int u = 1;
		forn(i, x % 4)
			u = m(u, tt);
		if (u != res)
			ans = 0;
		else
		{
			int ml = mm, mr = mm;
			vector <int > val;
			u = 1;
			forn(i, min(4, x))
			{
				val.push_back(u);
				u = m(u, tt);
			}
			int vl = 1, vr = 1;
			forn(i, l)
			{
				vl = m(vl, g[i]);
				vr = m(vr, g[l - i - 1]);
				forn(j, val.size())
				{
					if (m(val[j], vl) == 2)
						ml = min(ml, j * l + i + 1);
					if (m(vr, val[j]) == 4)
						mr = min(mr, j *l + i + 1);
				}
			}
			if ((ml == mm) || (mr == mm))
				ans = 0;
			else
			{
				long long ar = l;
				long long al = x;
				ar = l * x;
				long long dr = ml + mr;
				if (ar < dr)
					ans = 0;
				else
					ans = 1;
			}
		}
		cout<<"Case #"<<uuu<<": ";
		uuu++;
		if (ans)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}
	return 0;
}