#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>


using namespace std;


int main()
{

	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int t;
	cin >> t;
	for(int tt = 0; tt < t; tt++)
	{
		int n;
		string s;
		cin >> n >> s;

		int res = 0, tot = 0;
		
		for(int i = 0; i < n + 1; i++)
		{
			int num = s[i]-'0';
			if(num > 0)
			{
				if(tot < i)
				{
					res += i - tot;
					tot = i;
				}
				tot += num;
			}
		}

		printf("Case #%d: %d\n", tt+1, res);
	}


	return 0;
}