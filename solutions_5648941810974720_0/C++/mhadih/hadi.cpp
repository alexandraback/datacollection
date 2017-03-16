#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> pii;

const ll N = 1000;
const ll M = 11;
const ll INF = 1e7;
const ll SQ = 320;
const ll MOD = 1e9+7;

#define inf cin
#define of cout
#define mp make_pair
#define F first
#define S second

string s1[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
int a[10];
int c[N];
int d[10];
int tmp[N];

int main()
{
	ios_base::sync_with_stdio(false);
	ifstream inf("input.txt");
	ofstream of("output.txt");
	cin.tie();

	int t;
	cin >> t;
	for (int k = 1; k<=t; k++)
	{
		cout << "Case #" << k << ": "; 
		for (int i = 0; i<10; i++)
			a[i] = i;
		for (int i = 0; i<N; i++)
			c[i] = 0;
		string s;
		cin >> s;
		int n = s.size();
		for (int i = 0; i<n; i++)
			c[s[i]]++;
		do
		{
			for (int i = 0; i<N; i++)
				tmp[i] = c[i];
			for (int i = 0; i<10; i++)
				d[i] = 0;
			for (int i = 0; i<10; i++)
			{
				int mn = INF;
				for (int j = 0; j<s1[a[i]].size(); j++)
					mn = min(mn,tmp[s1[a[i]][j]]);
				d[a[i]] += mn;
				for (int j = 0; j<s1[a[i]].size(); j++)
					tmp[s1[a[i]][j]] -= mn;
			}
			int f = 0;
			for (int i = 0; i<N; i++)
				if (tmp[i]!=0)
					f = 1;
			if (!f)
			{
				for (int i = 0; i<10; i++)
					for (int j = 0; j<d[i]; j++)
						cout << i;
				break;
			}
		} while (next_permutation(a,a+10));
		cout << '\n';
	}
	return 0;
}