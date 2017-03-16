#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include<string>
#include<algorithm>

using namespace std;

#define mp make_pair
#define pb push_back 
#define fi(n) for(int i = 0; i < n; i++)
#define fj(n) for(int j = 0; j < n; j++)
#define f first
#define s second
#define ll long long
#define itt ::iterator it = 

ifstream in;
ofstream out;

int main()
{
	string str[] = { "ZERO", "EIGHT", "SIX", "SEVEN", "TWO", "FOUR", "FIVE", "NINE", "THREE", "ONE" };
	char sym[] = { 'Z', 'G', 'X', 'S', 'W', 'U', 'F', 'I', 'T', 'O' };
	int n[] = { 0, 8, 6, 7,2,4,5,9,3,1};

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		string s;
		cin >> s;
		map<char, int> count;
		fi(s.size())
			count[s[i]]++;
		vector<int> res;
		fi(10)
		{
			int k = count[sym[i]];
			fj(k)
				res.push_back(n[i]);

			fj(str[i].size())
				count[str[i][j]] -= k;
		}
		sort(res.begin(), res.end());

		cout << "Case #" << tc << ": ";
		fi(res.size()) cout << res[i];
		cout << endl;
	}




	return 0;
}

