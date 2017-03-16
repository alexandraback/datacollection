#include<cmath>
#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<fstream>
#include<set>
#include<map>
using namespace std;

int main()
{
	ifstream in ("A-small-attempt0.in");
	bool arr[26];
	memset(arr, false, sizeof(arr));
	arr['a'- 'a'] = true;
	arr['e'- 'a'] = true;
	arr['i'- 'a'] = true;
	arr['o'- 'a'] = true;
	arr['u'- 'a'] = true;
	int t, n;
	long long ret;
	in >> t;
	for (int z = 1; z <= t; ++ z)
	{
		int lastEnd = 0;
		ret = 0;
		string s;
		in >> s >> n;
		for (int i = 0; i <= s.size() - n; ++ i)
		{
			bool hard = true;
			for (int j = 0; j < n; ++ j)
			{
				if(!arr[s[i + j] - 'a'])
					continue;
				hard = false;
				break;
			}
			if (hard){
				ret += (i - lastEnd + 1) * (s.size() - (i + n) + 1);
				lastEnd = i + 1;
			}
		}
		cout << "Case #" << z << ": " << ret << endl;
	}
	return 0;
}
