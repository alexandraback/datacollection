#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <hash_map>
#include <unordered_set>
#include <fstream>

using namespace std;
typedef long long ll;



int main(){
	
	freopen("A-small-attempt3.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int test;
	cin >> test;
	for (int t = 1; t <= test; ++t)
	{
		string str;
		cin >> str;

		string cur = "1";
		int ans = 1;
		bool fl = false;
		while (1)
		{
			if (cur.size() < str.size())
			{
				int tmp = 0;
				int st = 1;
				for (int i = (int)cur.size() - 1; i >= ((int)cur.size()) / 2 ; --i)
				{
					int q = '9' - cur[i];
					tmp += q * st;
					cur[i] = '9';
					st*=10;
				}
				ans += tmp;
				string qwe = cur;
				reverse(cur.begin(), cur.end());
				if (cur != qwe)
					ans++;

				tmp = 0;
				st = 1;
				for (int i = (int)cur.size() - 1; i >= ((int)cur.size() ) / 2 ; --i)
				{
					int q = '9' - cur[i];
					tmp += q * st;
					cur[i] = '9';
					st *= 10;
				}
				tmp++;
				ans += tmp;
				string next = "1";
				for (int i = 0; i <(int)cur.size(); ++i)
				{
					next += '0';
				}
				cur = next;
			}
			else
			{
				int tmp = 0;
				int st = 1;
				
				for (int i = (int) cur.size() - 1, j = 0; i >= 0; --i, ++j)
				{
					if (cur[i] > str[j])
					{
						fl = true;
						break;
					}
				}
				if (fl)
				{
					if (cur == str)
						break;
					int tmp = 0;
					int st = 1;
					int ind = 0;
					for (int i = 0; i < (int)str.size(); ++i)
					{
						if (str[i] != '0')
							ind = i;
					}

					int j= cur.size() -1;
					for (int i = 0; i <= ((int)cur.size()+1)/2 -1 ; ++i, --j)
					{
						if (i < ind)
						{
							int q = str[i] - cur[j];
							tmp += q*st;
							cur[j] = str[i];
						}
						if (i == ind)
						{
							int q = str[ind] - cur[j];
							tmp += (q - 1)*st;
							cur[j] = str[ind] - 1;
						}
						if (i > ind)
						{
							int  q = '9' - cur[j];
							tmp += q*st;
							cur[j] = '9';
						}
						st *= 10;
					}

					ans += tmp;
					string qwe = cur;
					reverse(cur.begin(), cur.end());
					if (cur != qwe)
						ans++;

					tmp = 0;
					st = 1;
					for (int i = (int)cur.size() - 1; i!=ind; --i)
					{
						int q = '9' - cur[i];
						tmp += q * st;
						cur[i] = '9';
						st *= 10;
					}
					tmp++;
					ans += tmp;
					for (int i = cur.size() -1 ; ; --i)
					{
						if (cur[i] == '9')
							cur[i] = '0';
						else
						{
							cur[i]++;
							break;
						}
					}

					tmp = 0;
					st = 1;
					
					for (int i = str.size() - 1; i >= 0; --i)
					{
						int q = str[i] - cur[i];
						tmp += q*st;
						st *= 10;
					}
					ans += tmp;
					


					break;
				}

				tmp = 0;
				st = 1;
				int qwee = ((int)cur.size() + 1) / 2 - 1;

				for (int i = (int)cur.size() - 1, j = 0; i >= ((int)cur.size()) / 2 ; --i, ++j)
				{
					int q = str[j] - cur[i];
					tmp += q * st;
					cur[i] = str[j];
					st *= 10;
				}
				ans += tmp;
				string qwe = cur;
				reverse(cur.begin(), cur.end());
				if (cur!=qwe)
					ans++;

				tmp = 0;
				st = 1;
				for (int i = (int)cur.size() - 1, j = (int)str.size() - 1; i >= ((int)cur.size()) / 2 ; --i, --j)
				{
					int q = str[j] - cur[i];
					tmp += q * st;
					cur[i] = str[j];
					st *= 10;
				}
				ans += tmp;
				break;
			}
		}
		

		cout << "Case #"<<t<<": "<< ans<<"\n";


	}


	return 0;
}

