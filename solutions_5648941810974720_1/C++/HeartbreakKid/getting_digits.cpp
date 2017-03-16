//Created By Mayur Agarwal :)

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <map>
#include <iterator>
#include <functional>
#include <stack>
#include <queue>

#define ll long long
#define in(a) scanf("%lld",&a)
#define inc(a) scanf("%c",&a)
#define ins(a) scanf("%s", &a)
#define pr(a) printf("%lld\n",a)
#define prc(a) printf("%c",a)
#define prs(a) printf("%s\n",a)
#define fori(I,N) for(ll I=0;I<N;I++)
#define forin(i,n) for(ll I=1;I<=N;I++)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define ALL(X) (X).begin(), (X).end()
#define pi   acos(-1.0)
#define mod 1000000007
#define SIZE 200010

using namespace std;
typedef pair<ll, ll>pll;
string s;
int cnt[32], temp[32];
std::vector<ll> vec;
string s1[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int main()
{
	//freopen ("input.txt", "r", stdin);
	//freopen ("output1.txt", "w", stdout);
	int t;
	cin >> t;
	// w = 2;
	// z = 0;
	// x = 6;
	// g = 8;
	// f = 4, 5;
	// s = 6, 7;

	for (int xx = 1; xx <= t; xx++)
	{
		cin >> s;
		MS0(cnt);
		MS0(temp);
		vec.clear();
		int n = s.size();
		for (int i = 0; i < n; i++)
		{
			cnt[s[i] - 'A']++;
			temp[s[i] - 'A']++;
		}
		cout << "Case #" << xx << ": ";
		while (cnt['F' - 'A'] && cnt['O' - 'A'])
		{
			int i = 4;
			bool flag = 0;
			for (int j = 0; j < s1[i].size(); j++)
			{
				if (!temp[s1[i][j] - 'A'])
				{
					flag = 1;
					break;
				}
				else
				{
					temp[s1[i][j] - 'A']--;
				}
			}
			if (!flag)
			{
				for (int j = 0; j < 30; j++)
				{
					cnt[j] = temp[j];
				}
				vec.push_back(4);
			}
			else
			{
				for (int j = 0; j < 30; j++)
				{
					temp[j] = cnt[j];
				}
				break;
			}
		}
		while (cnt['F' - 'A'] && cnt['I' - 'A'])
		{

			bool flag = 0;
			int i = 5;
			for (int j = 0; j < s1[i].size(); j++)
			{
				if (!temp[s1[i][j] - 'A'])
				{
					flag = 1;
					break;
				}
				else
				{
					temp[s1[i][j] - 'A']--;
				}
			}
			if (!flag)
			{
				for (int j = 0; j < 30; j++)
				{
					cnt[j] = temp[j];
				}
				vec.push_back(i);
			}
			else
			{
				for (int j = 0; j < 30; j++)
				{
					temp[j] = cnt[j];
				}
				break;
			}
		}
		while (cnt['X' - 'A'])
		{
			int i = 6;

			bool flag = 0;
			for (int j = 0; j < s1[i].size(); j++)
			{
				if (!temp[s1[i][j] - 'A'])
				{
					flag = 1;
					break;
				}
				else
				{
					temp[s1[i][j] - 'A']--;
				}
			}
			if (!flag)
			{
				for (int j = 0; j < 30; j++)
				{
					cnt[j] = temp[j];
				}
				vec.push_back(i);
			}
			else
			{
				for (int j = 0; j < 30; j++)
				{
					temp[j] = cnt[j];
				}
				break;
			}
		}
		while (cnt['S' - 'A'] && cnt['V' - 'A'])
		{
			int i = 7;

			bool flag = 0;
			for (int j = 0; j < s1[i].size(); j++)
			{
				if (!temp[s1[i][j] - 'A'])
				{
					flag = 1;
					break;
				}
				else
				{
					temp[s1[i][j] - 'A']--;
				}
			}
			if (!flag)
			{
				for (int j = 0; j < 30; j++)
				{
					cnt[j] = temp[j];
				}
				vec.push_back(i);
			}
			else
			{
				for (int j = 0; j < 30; j++)
				{
					temp[j] = cnt[j];
				}
				break;
			}
		}
		while (cnt['W' - 'A'])
		{
			int i = 2;

			bool flag = 0;
			for (int j = 0; j < s1[i].size(); j++)
			{
				if (!temp[s1[i][j] - 'A'])
				{
					flag = 1;
					break;
				}
				else
				{
					temp[s1[i][j] - 'A']--;
				}
			}
			if (!flag)
			{
				for (int j = 0; j < 30; j++)
				{
					cnt[j] = temp[j];
				}
				vec.push_back(i);
			}
			else
			{
				for (int j = 0; j < 30; j++)
				{
					temp[j] = cnt[j];
				}
				break;
			}
		}
		int i = 0;
		while (i < 10)
		{
			bool flag = 0;
			for (int j = 0; j < s1[i].size(); j++)
			{
				if (!temp[s1[i][j] - 'A'])
				{
					flag = 1;
					break;
				}
				else
				{
					temp[s1[i][j] - 'A']--;
				}
			}
			if (!flag)
			{
				for (int j = 0; j < 30; j++)
				{
					cnt[j] = temp[j];
				}
				vec.push_back(i);
			}
			else
			{
				for (int j = 0; j < 30; j++)
				{
					temp[j] = cnt[j];
				}
				i++;
			}
		}
		sort(vec.begin(), vec.end());
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i];
		}
		cout << endl;
	}

	return 0;

}