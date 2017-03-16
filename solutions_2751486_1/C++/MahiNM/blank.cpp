#include <iostream>
#include <cmath>
#include <deque>
#include <algorithm>
#include <map>
#include <cstdio>
#include <sstream>
#include <deque>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

#define MAXN 12000
#define pi pair <int, int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a.size())

vector < int > v;
int T, L, N;
string S;

int test (int I, int J)
{
    //cout << "test (" << I << J << ")\n";
	int ret = 0, mr = -1;
	for (int i = I; i <= J; i += 1)
	{
		if(v[i] == 0)
		{
			mr = max (mr, ret);
			ret = 0 ;
		}
		else {ret += 1; }//cout << i <<'\n';}
	}

    mr = max (mr, ret);
    ret = 0 ;
    //cout << mr <<"\n";
	if (mr >= N) return 1;
	else return 0;
}

int main (int argc, char const* argv[])
{
    ifstream cin ("A-large.in");
    ofstream cout ("A-large.out");
	cin >> T;
	for (int t = 0; t < T; t += 1)
	{
		int ans = 0;
		cin >> S >> N;
		v.clear();
		for (int i = 0; i < S.size(); i += 1)
		{
			char ch;
			ch = S[i];
			if ( ch == 'a' || ch == 'e'  || ch == 'i' || ch == 'o' ||ch == 'u')
			{
				v.pb(0);
			}
			else v.pb(1);
		}
		L = S.size();
		for (int i = 0; i < L; i += 1)
		{
			for (int j = i + N-1; j < L; j += 1)
			{
				ans += test (i,j);

			}
		}
		cout << "Case #" << t+1 << ": " << ans <<'\n';
	}
	return 0;
}

