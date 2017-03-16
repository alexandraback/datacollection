#include <bits/stdc++.h>
using namespace std;
#define llong long long
#define long llong

int m, n, p, n_test;

int main ()
{
    cin.rdbuf((new ifstream("A.inp"))->rdbuf());
    cout.rdbuf((new ofstream("A.out"))->rdbuf());

    cin >> n_test;
    for (int i = 1; i <= n_test; ++i)
    {
    	cout << "Case #" << i << ": ";
    	cin >> m >> n >> p;
    	cout << n / p + (n % p != 0) + p - 1 << "\n";
    }
}