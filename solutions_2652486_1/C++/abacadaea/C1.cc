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
const int MAXT = 20000, MAX = 6000;
const int mx [] = {1, 0, -1, 0}, my[] = {0, 1, 0, -1};

FILE * fout = fopen ("C1.out", "w");

int R, N, M, K, A[MAX];
int ssize = 0, prsize = 0;
vector<ll> prod_dumb, prod;
map <ll, int> mp;
int num [MAXT][MAX];
int sets[MAXT][20];
ll cou[MAXT];
ll fact [] = {1,1,2,6,24,120,720,5040,40320, 362880, 3628800, 39916800, 479001600};

int count ()
{
    ll a = fact[12], n;
    for (int i=2; i<=M; i++)
    {
	n =0;
	for (int j=0; j<N; j++)
	    n += (A[j] == i);
	//cout << n << " "<< fact[n] << "\n";
	a /= fact[n];
    }
    return a;
}

void getprod (int a, int k)
{
    if (k == N)
    {
	ll p = 1;
	for (int i=0; i<N; i++)
	    p *= A[i];
	prod_dumb.push_back (p);
	return;
    }
    for (int i=a; i<=M; i++)
    {
	A[k] = i;
	getprod (i, k + 1);
    }
}

void find (int a, int k)
{
    if (k == N)
    {
	printf ("%d\n", ssize);
	ll p = 1;
	for (int i=0; i<N; i++)
	{
	    sets[ssize][i] = A[i];
	}
	for (int i=0; i<(1 << N); i++)
	{
	    p = 1;
	    for (int j=0; j<N; j++)
	    {
		if (i & (1 << j))
		    p *= A[j];
	    }
	    num [ssize][mp[p]] ++;
	}
	cou[ssize] = count ();
	/*for (int i=0; i<nprod; i++)
	{
	    if (num[nprod][i] > 0)
		cout << prod[i] << " " << num[nprod][i] << "\n";
	}*/
	ssize ++;
	return;
    }
    for (int i=a; i<=M; i++)
    {
	A[k] = i;
	find (i, k + 1);
    }
}

ll B[20];

void go (int T)
{
    
    fprintf (fout, "Case #%d:\n", T); 
    scanf ("%d%d%d%d", &R, &N, &M, &K);
    //cout << R << " " << N << " " << M << " " << K << "\n";
    prod.clear ();
    prod_dumb.clear ();
    
    getprod (1, 0);
    sort (prod_dumb.begin(), prod_dumb.end ());
    for (int i=0; i<prod_dumb.size (); i++)
    {
	if (i == 0 or prod_dumb[i] != prod_dumb[i - 1])
	{
	    mp [prod_dumb[i]] = prod.size();
	    prod.push_back (prod_dumb[i]);
	}
    }
    
    prsize = prod.size();
    memset (num, 0, sizeof (num));
    ssize = 0;
    find (2, 0);

    
    for (int i=0; i<R; i++)
    {
	printf ("%d\n", i);
	for (int j=0; j<K; j++)
	{
	    scanf ("%llu", &B[j]);
	    B[j] = mp[B[j]];
	}
	double best = -1; int id = -1;
	for (int j=0; j<ssize; j++)
	{
	    double score = log (cou [j]);
	    for (int k=0; k<K; k++)
	    {
		if (num[j][B[k]] == 0)
		{
		    score = -INF;
		    break;
		}
		score += log (num[j][B[k]]);
	    }
	    if (score > best)
	    {
		best = score;
		id = j;
	    }
	}
	for (int j=0; j<N; j++)
	{
	    fprintf (fout, "%d", sets[id][j]);
	    //printf ("%d", sets[id][j]);
	}
	fprintf (fout, "\n");
	//printf ("\n");
    }
}

int main()
{
    int T;
    scanf ("%d", &T);
    for (int i=0; i<T; i++)
    {
	go (i + 1);
    }
}
