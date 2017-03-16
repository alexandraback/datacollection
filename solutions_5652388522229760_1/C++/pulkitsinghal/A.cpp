#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, n;
	cin >> t;
	for(int test=1;test<=t;++test)
	{
		cin >> n;
		cout << "Case #" << test << ": ";
		if(n==0)
			cout << "INSOMNIA" << endl;
		else
		{
			set<int> st;
			for(int i=1;i<=500;++i)
			{
				int j = i*n;
				while(j)
				{
					st.insert(j%10);
					j /= 10;
				}
				if(st.size()==10)
				{
					cout << i*n << endl;
					break;
				}
			}
		}
	}
	return 0;
}
