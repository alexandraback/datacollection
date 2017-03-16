#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stack>
#include <string.h>
#include <climits>
#include <limits>
using namespace std;

#define FOR(i, a, b) for(int i=a; i<b; i++)
#define FORE(i, a, b) for(int i=a; i<=b; i++)
#define ll long long
#define mp make_pair
#define mtriple(a, b, c) make_pair(a, make_pair(b, c))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define tripleii pair<int, pair<int ,int> >
#define triplell pair<long long, pair<long long ,long long> >
#define PI 3.14159265359
#define MOD 1000000007
#define ceil(a, b) ((a)/(b) + ((a)%(b)!=0))
#define square(a) ((a)*(a))
#define debug3(names, a, b, c) cout << names << a << ", " << b << ", " << c << endl;
#define debug2(names, a, b) cout << names << a << ", " << b << endl;
#define debug1(names, a) cout << names << a << endl;

#define maxN 100000+6


string A[120];
bool c[120];
bool used_chars[300];
int n;


ll datvale(int a, int q, char used_last)
{
	char plast_used = used_last;
	//debug3("----", q, a, used_last)
    ll r = 0;
    FOR(i, 0, A[a].size())
    {
        if (used_chars[A[a][i]] && used_last != A[a][i]) {
        	FOR(j, 0, i) used_chars[A[a][j]] = false;
        	return 0;
        }
        used_chars[A[a][i]] = true;
        used_last = A[a][i];
    }
    //cout << "Movida!" << endl;
    //cout << "Used A:" << used_chars['a'] << endl;
    if (q == n) r++; 
    c[a] = true;

    FOR(i, 0, n)
    if (!c[i])
        r = (r + datvale(i, q + 1, used_last)) % MOD;


    FOR(i, 0, A[a].size())
    {
        if(A[a][i] != plast_used) used_chars[A[a][i]] = false;
    }
    c[a] = false;
    return r;
}

int main()
{

    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int T;
    cin >> T;
    FOR(awt, 0, T)
    {
    	memset(used_chars, false, sizeof(bool)*300);
        cin >> n;
        FOR(i, 0, n) cin >> A[i];

        ll variantebi = 0;
        FOR(i, 0, n) {
        	variantebi = (variantebi + datvale(i, 1, '-')) % MOD;
        }
        printf("Case #%d: %d\n", awt + 1, variantebi);


    }

    return 0;
}