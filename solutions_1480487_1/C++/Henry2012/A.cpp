#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned char uchar;

#define sz(x) ((int)x.size())
#define mp(x,y) make_pair(x, y)
#define pb(x) push_back(x)

template<class T> inline T gcd(T a,T b)
{
    if(a<0) return gcd(-a, b);
    if(b<0) return gcd(a, -b);

    return (b==0) ? a : gcd(b, a % b);
}

template<class T> inline T lcm(T a,T b)
{
    if(a<0) return lcm(-a,b); 
    if(b<0)return lcm(a,-b);

    return a*(b/gcd(a,b));
}

inline bool isPrime(ll n)
{
    if(n<=1)  return false;

    for (ll i=2;i*i<=n; i++) 
        if (n%i==0) return false;

    return true;
}

using namespace std;

// const bool FILE_WRITE = false;
const bool SHOW_TIME = 
true;

//#define MYDEBUG

#define START_CLOCK  clock_t start_clock = clock();
#define PRINT_TIME   if(SHOW_TIME) cout << (clock() - start_clock) / double(CLOCKS_PER_SEC) << endl;

// ---  Solution begins. ---------------------- 


int p[204];
const double eps = 1e-7;

vector<double>  Solve(int n)
{
    int total =0; 
    for (int i=0; i<n; i++)
        total += p[i];

    double avg= total*2/(double)(n);
    vector<double> ans(n, 100);
    vector<bool> visited(n, false);

    int unvisitedcount=n;
    int fullcount =0;
    do {
        fullcount =0;
        int inner_total = 0;
        for (int j=0;j<n; j++) {
            if (visited[j])
                continue;

            if (p[j]>avg) {
                unvisitedcount--;
                fullcount++;
                visited[j] = true;
                ans[j] = 0;
            } else
                inner_total+=p[j];
        }

        avg= (inner_total+total)/(double)(unvisitedcount);

    } while (fullcount);

        for (int i=0; i<n; i++) {
            if (visited[i])
                continue;
            ans[i] = 100.0* (avg-p[i])/(double)(total );
        }

        return ans;
}

int main(int argc, char * argv[])
{
    ifstream fin; 
    FILE * fout;
    int run_mode(10);
    switch (run_mode)
    {
    case -1:
        fin.open("A.in");
        fout = stdout;
        break;
    case 0: 
        fin.open("A-small-attempt0.in");
        fout = fopen("A-small-attempt0.out", "w");
        break;
    case 1: 
        fin.open("A-small-attempt1.in");
        fout = fopen("A-small-attempt1.out", "w");
        break;
    case 10:
        fin.open("A-large.in");
        fout = fopen("A-large.out", "w");
        break;
    }
    assert(fin && fout);

    START_CLOCK;

    int T;  fin >> T;
    for (int t=0; t<T; t++) {
        int N;   fin >>N; 
        for (int j=0; j<N; j++) {
            fin >> p[j];
        }

        vector<double> ans = Solve(N);
        fprintf(fout, "Case #%d:", t+1);
        for (int j =0; j<ans.size(); j++ )
            fprintf(fout, " %.6Lf ", ans[j]);
        fprintf(fout, "\n");
    }

    PRINT_TIME

        return 0;
}

