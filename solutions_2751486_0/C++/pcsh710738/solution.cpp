#include <iostream>
#include <string>
using namespace std;

string s;

bool checkANS(int st, int ed, int n)
{
	int num = 0;
	bool ck = false;

	for(int i = st ; i <= ed ; i++)
	{
		if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
		{
			num++;

			if(num == n) 
			{
				ck = true;
				break;
			}
		}
		else
		{
			num = 0;
			ck = false;
		}
	}

	return ck;
}

int main()
{
	int T, count;
	int n, ans;

	cin >> T;
	count = T;

	while(T--)
	{
		cin >> s >> n;

		ans = 0;
		for(int i = 0 ; i < s.size() ; i++)
		{
			for(int j = i+n-1 ; j < s.size() ; j++)
			{
				if(checkANS(i, j, n))
					ans++;
			}
		}

		cout << "Case #" << count-T << ": " << ans << endl;
	}
}