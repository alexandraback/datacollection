#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,j;
		cin >> n >> j;
		cout << "Case #1:" << endl;
		int k = 0;
		while(j)
		{
			string tc;
			int x = k;
			while(x)
			{
				tc += char((x%2)+'0');
				x /= 2;
			}
			while(tc.size()<n-2)
				tc += "0";
			tc += "1";
			reverse(tc.begin(), tc.end());
			tc += "1";
			int res[11];
			memset(res, -1, sizeof res);
			for(int base=2;base<=10;++base)
				for(int divi=2;divi<=100;++divi)
				{
					int cur = 0;
					for(int i=0;i<tc.size();++i)
					{
						cur *= base;
						if(tc[i]=='1')
							++cur;
						cur %= divi;
					}
					if(cur==0)
					{
						res[base] = divi;
						break;
					}
				}
			int chk = 0;
			for(int i=2;i<=10;++i)
				if(res[i]!=-1)
					++chk;
			if(chk==9)
			{
				cout << tc << " ";
				for(int i=2;i<=10;++i)
					cout << res[i] << " ";
				cout << endl;
				--j;
			}
			++k;
		}
	}
	return 0;
}
