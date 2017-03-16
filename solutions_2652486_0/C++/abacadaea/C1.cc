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

int R, N, M, K, A[MAX];
int ssize = 0, prsize = 0;
vector<ll> prod_dumb, prod;
map <ll, int> mp;
int num [MAXT][MAX];
int sets[MAXT][20];

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
	ll p = 1;
	for (int i=0; i<N; i++)
	{
	    sets[ssize][i] = A[i];
	    //cout << A[i] << " ";
	}
	//cout << "\n";
	for (int i=0; i<(1 << N); i++)
	{
	    p = 1;
	    for (int j=0; j<N; j++)
	    {
		if (i & (1 << j))
		    p *= A[j];
	    }
	    //cout << p << " ";
	    num [ssize][mp[p]] ++;
	}
	//cout << "\n";
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

int B[20];

void go (int T)
{
    printf ("Case #%d:\n", T); 
    cin >> R >> N >> M >> K;
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
    /*
    for (int i=0; i<prod.size(); i++)
	cout << prod[i] << " ";
    cout << "\n";
    */
    prsize = prod.size();
    memset (num, 0, sizeof (num));
    ssize = 0;
    find (2, 0);

    
    for (int i=0; i<R; i++)
    {
	for (int j=0; j<K; j++)
	{
	    cin >> B[j];
	    B[j] = mp[B[j]];
	}
	double best = -1; int id = -1;
	for (int j=0; j<ssize; j++)
	{
	    double score = 0;
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
	    printf ("%d", sets[id][j]);
	}
	printf ("\n");
    }
}

int main()
{
    int T; cin >> T;
    for (int i=0; i<T; i++)
    {
	go (i + 1);
    }
}
