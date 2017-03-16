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
		string s,s1;
		cin >> s >> s1;
		int n = s.size();
		int id = n;
		for (int i = 0; i<n; i++)
			if (s[i]!='?' && s1[i]!='?' && s[i]!=s1[i])
			{
				id = i;
				break;
			}
			else
			{
				if (s[i]=='?' && s1[i]=='?')
					s[i] = s1[i] = '0';
				else if (s[i]=='?')
					s[i] = s1[i];
				else if (s1[i]=='?')
					s1[i] = s[i];
			}
		int f = 0;
		if (id<n && s[id]>s1[id]) 
		{
			swap(s,s1);
			f = 1;
		}
		for (int i = id+1; i<n; i++)
		{
			if (s[i]=='?')
				s[i] = '9';
			if (s1[i]=='?')
				s1[i] = '0';
		}
		if (f) swap(s,s1);
		cout << s << ' ' << s1 << '\n';
	}
	return 0;
}