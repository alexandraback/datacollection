#include <iostream>

#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;

	cin >> T;

	for(int tc = 1; tc <= T; ++tc)
	{
		int k, l, s;

		double ans = 0;

		cin >> k >> l >> s;

		string key, target;

		cin >> key >> target;

		set<char> mask;
		
		map<char, int> count;

		for(int i = 0; i < k; ++i)
		{
			mask.insert(key[i]);
			count[key[i]]++;
		}

		bool is_null = false;

		for(int i = 0; i < l; ++i)
		{
			if(mask.find(target[i]) == mask.end())
			{
				is_null = true;
				cout << "Case #" << tc << ": " << ans << endl;
				break;
			}
		}

		if(is_null)
			continue;

		double mx = 1;

		string ololo;

		ololo = target;

		while(ololo.size() < s)
		{
			bool flag = false;
			for(int i = 1; i < l; ++i)
			{
				string str2(target.begin(), target.end() - i);
				string str3(target.end() - i, target.end());
				string str1(ololo.begin() + ololo.size() - l + i, ololo.end());

				if(str1 == str2)
				{
					flag = true;
					for(int i = 0; i < str3.size(); ++i)
					{
						ololo += str3[i];
					}

					if(ololo.size() <= s)
						++mx;

					break;
				}
			}

			if(!flag)
			{
				if(s - ololo.size() >=l)
				{
					ololo += target;
					++mx;
				}
				else
				{
					string str(target.begin(), target.begin() + (s - ololo.size()));
					ololo += str;
				}
			}
		}

		double mo = 1;

		for(int i = 0; i < l; ++i)
		{
			mo *= (double)count[target[i]];
		}

		for(int i = 0; i < l; ++i)
		{
			mo /= (double)k;
		}

		mo *= s - l + 1;

		ans = mx - mo;

		cout << "Case #" << tc << ": " << ans << endl;
	}

	return 0;
}