#include<iostream>
#include<vector>
#include<fstream>
#include<set>
#include<algorithm>
using namespace std;

#define forn(i, n) for(int i=0; i < n; i++)

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int t;
	cin>>t;
	int u = 1;
	while(t--)
	{
		int ans, d, mx = 0;
		vector<int> p;
		cin>>d;
		forn(i, d)
			{
				int p2;
				cin>>p2;
				p.push_back(p2);
				mx = max(mx, p2);
			}
		ans = mx;
		for (int i = 1; i <= mx; i++)
		{
			int res = i;
			forn(j, d)
			{
				if (p[j] > i)
				{
					int h = p[j] / i;
					if (p[j] % i)
						h++;
					int s = 0, pw = 1, tt = 0;
					while (pw < h)
					{
						s++;
						tt += s;
						pw *= 2;
					}
					res += (h - 1);
				}
			}
			ans = min(ans, res);
		}
		cout<<"Case #"<<u<<": "<<ans<<endl;
		u++;
	}
	return 0;
}