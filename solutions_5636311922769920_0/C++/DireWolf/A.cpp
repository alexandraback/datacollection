#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

FILE *fin = freopen("D-small-attempt2.in", "r", stdin);
FILE *fout = freopen("A-small.out", "w", stdout);

using namespace std;

void solve()
{
	int k, c, s;
	cin >> k >> c >> s;
	long long int counter = pow(k, c-1);
	for (long long int i = 0; i < s; i++)
	{
		if(i+1 >= s)
		{
			cout << i*counter + 1;
		}
		else
		{
			cout << i*counter + 1 << " ";
		}
	}
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