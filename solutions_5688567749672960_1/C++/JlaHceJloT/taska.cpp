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
	
	freopen("A-large (3).in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	ll test;
	cin >> test;
	for (ll t = 1; t <= test; ++t)
	{
		string str;
		cin >> str;

		string cur = "1";
		ll ans = 1;
		bool fl = false;
		while (1)
		{
			if (cur.size() < str.size())
			{
				ll tmp = 0;
				ll st = 1;
				for (ll i = (ll)cur.size() - 1; i >= ((ll)cur.size()) / 2 ; --i)
				{
					ll q = '9' - cur[i];
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
				for (ll i = (ll)cur.size() - 1; i >= ((ll)cur.size() ) / 2 ; --i)
				{
					ll q = '9' - cur[i];
					tmp += q * st;
					cur[i] = '9';
					st *= 10;
				}
				tmp++;
				ans += tmp;
				string next = "1";
				for (ll i = 0; i <(ll)cur.size(); ++i)
				{
					next += '0';
				}
				cur = next;
			}
			else
			{
				ll tmp = 0;
				ll st = 1;
				
				for (ll i = (ll) cur.size() - 1, j = 0; i >= 0; --i, ++j)
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
					ll tmp = 0;
					ll st = 1;
					ll ind = 0;
					for (ll i = 0; i < (ll)str.size(); ++i)
					{
						if (str[i] != '0')
							ind = i;
					}

					ll j= cur.size() -1;
					for (ll i = 0; i <= ((ll)cur.size()+1)/2 -1 ; ++i, --j)
					{
						if (i < ind)
						{
							ll q = str[i] - cur[j];
							tmp += q*st;
							cur[j] = str[i];
						}
						if (i == ind)
						{
							ll q = str[ind] - cur[j];
							tmp += (q - 1)*st;
							cur[j] = str[ind] - 1;
						}
						if (i > ind)
						{
							ll  q = '9' - cur[j];
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
					for (ll i = (ll)cur.size() - 1; i!=ind; --i)
					{
						ll q = '9' - cur[i];
						tmp += q * st;
						cur[i] = '9';
						st *= 10;
					}
					tmp++;
					ans += tmp;
					for (ll i = cur.size() -1 ; ; --i)
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
					
					for (ll i = str.size() - 1; i >= 0; --i)
					{
						ll q = str[i] - cur[i];
						tmp += q*st;
						st *= 10;
					}
					ans += tmp;
					


					break;
				}

				tmp = 0;
				st = 1;
				ll qwee = ((ll)cur.size() + 1) / 2 - 1;

				for (ll i = (ll)cur.size() - 1, j = 0; i >= ((ll)cur.size()) / 2 ; --i, ++j)
				{
					ll q = str[j] - cur[i];
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
				for (ll i = (ll)cur.size() - 1, j = (ll)str.size() - 1; i >= ((ll)cur.size()) / 2 ; --i, --j)
				{
					ll q = str[j] - cur[i];
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

