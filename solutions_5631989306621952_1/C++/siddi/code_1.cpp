#include<bits/stdc++.h>

using namespace std;

int main()
{

	freopen("input1.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int county = 0;
	int t;

	cin >> t;

	while(t--)
	{
		county ++;
		char a[1000];
		int n;
		string s = "";
		cin >> a;

		n = strlen(a);

		for(int i = 0;i < n;i++)
		{
			if(i == 0)
			{
				s = s+a[i];
			}
			else if(i == 1)
			{
				if(a[i] >= s[0])
				{
					s = a[i] + s;
				}
				else
				{
					s = s + a[i];
				}
			}
			else
			{
				int x = s.size();	

				if((a[i] > s[x-1]) && (a[i] < s[0]))
				{
					s = s+a[i];
				}
				else if(a[i] >= s[0])
				{
					s = a[i] + s;
				}
				else if(a[i] <= s[x-1])
				{
					s = s+a[i];
				}
			}
		}
		cout <<"Case #" << county << ": "<< s << endl;
	}
	return 0;
}
