#include <iostream> 
#include <vector> 
#include <string> 
#include <algorithm> 
#include <sstream> 
#include <set> 
#include <map> 
#include <queue> 
#include <cmath> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <bitset> 
#include <unordered_map> 
#include <unordered_set> 

using namespace std;
typedef long long ll;


string solve(string str)
{
	string ans;
	ans.push_back(str[0]);
	for (int i = 1; i < str.size(); ++i)
	{
		bool fl = false;
		for (int j = 0; j < ans.size(); ++j)
		{
			if (ans[j] < str[i])
			{
				fl = 1;
				break;
			}
			if (ans[j] > str[i])
			{
				fl = 0;
				break;
			}
		}
		if (fl == 0)
		{
			ans.push_back(str[i]);
		}
		else
		{
			ans = str[i] + ans;
		}
	}

	return ans;
}


int main(){
#ifdef _CONSOLE 
	freopen("A-large (1).in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	
	int test;
	cin >> test;
	
	for (int t = 1; t <= test; ++t)
	{
		string str;
		cin >> str;
		str = solve(str);
		cout << "Case #" << t << ": " << str << "\n";
	}




	return 0;
}

