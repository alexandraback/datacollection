#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int cas, tcases;
	cin >> tcases;
	for( cas = 1; cas <= tcases; cas++)
	{
		string s;
		int n;
		cin >> s >> n;
		int l = s.length();
		vector <int> v(l, 0), e(l,0);
		for( int i = 0; i < l; i++)
			if( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
				v[i] = 1;
		for( int i = 0; i < n; i++)
			e[n-1] += v[i];
		for( int i = n; i < l; i++)
		{
			e[i] = e[i-1];
			e[i] -= v[i-n];
			e[i] += v[i];
		}
		int j = n-1;
		long long result = 0;
		for( int i = 0; i < l-n+1; i++)
		{
			for( ;j < l ; j++)
			{
				if( e[j] == 0)
				{
					result += l-j;
					if( j == i+n-1)
						j++;
					break;
				}
			}
		}
		cout << "Case #" << cas <<": " << result << endl;
	}
}