#include <cstdio>
#include <iostream>
#include <string>

FILE *fin = freopen("B-large.in", "r", stdin);
FILE *fout = freopen("A-small.out", "w", stdout);

using namespace std;

void solve()
{
	string s;
	cin >> s;
	char lastChr = '-1';
	int res = 0;
	for (unsigned int i = 0; i < s.length(); i++)
	{
		if(i==0)
		{
			lastChr = s[i];
		}
		else
		{
			if(s[i] != lastChr)
			{
				lastChr = s[i];
				res++;
			}
		}
	}
	if(lastChr == '-')
	{
		res++;
	}
	cout << res;
}

// Multiple text cases
void main(){
	int t;
	cin >> t;
	for(int i=1 ; i<=t ; i++){
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
}