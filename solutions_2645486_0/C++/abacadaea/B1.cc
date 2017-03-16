#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cassert>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <iomanip>
#include <utility>
#include <ctime>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const double PI = acos (-1.0), EPS = 1e-9;
const int INF = 1e9, MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const int mx [] = {1, 0, -1, 0}, my[] = {0, 1, 0, -1};

int E, N, R, A[MAX];

void go (int T)
{
    scanf ("%d%d%d", &E, &R, &N);
    R = min (R, E);
    for (int i=0; i<N; i++)
	scanf ("%d", &A[i]);
    ll res = 0, ctank = E;
    int id = 0;
    for (int i=0; i<N; i ++)
    {
	id = -1;
	for (int j=i + 1; j<N; j++)
	{
	    if (A[j] > A[i])
	    {
		id = j;
		break;
	    }
	}
	if (id == -1)
	{
	    res += (ll)A[i] * ctank;
	    ctank = 0;
	}else
	{
	    int targ = E - R * (id - i);
	    targ = max (targ, 0);
	    if (ctank <= targ)
	    {
	    }else
	    {
		res += A[i] * (ctank - targ);
		ctank = targ;
	    }
	}
	ctank += R;
    }
    printf ("Case #%d: ", T); 
    printf ("%llu\n", res);
}

int main()
{
    int T; cin >> T;
    for (int i=0; i<T; i++)
    {
	go (i + 1);
    }
}
