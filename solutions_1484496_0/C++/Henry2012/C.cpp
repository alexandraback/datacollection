#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
// #include <unordered_map>
// #include <unordered_set>

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

typedef std::map<int, int> intmap;
// typedef std::unordered_map<int, int> intmap;
// typedef std::unordered_set<int> intset;

long num[501];

void Solve(int n, vector<int> &a, vector<int> &b)
{
    sort(num, num+n);
     intmap mymap; 

    //for (int i=0; i<n; i++)
    //    myset.inser(num[i]);

    int maxperm = 2 << n;
    for (int perm=1; perm<=maxperm; perm++) {
        int s=0;
        int test =1;
        for (int j=0; j<n && test<= perm; j++) {
            if (perm & test) {
                s += num[j];
            }
            test <<= 1;
        }

        if (mymap.count(s) == 0) {
            mymap[s] = perm;
        } else {
            for (int pe=mymap[s], k=0; pe; pe>>=1, k++) {
                if (pe&1)
                    a.push_back(num[k]);
            }

            for (int pe=perm, k=0; pe; pe>>=1, k++) {
                if (pe&1)
                    b.push_back(num[k]);
            }

            return;
        }
    }
    
}


int main(int argc, char * argv[])
{
    ifstream fin; 
    FILE * fout;
    int run_mode(0);
    switch (run_mode)
    {
    case -1:
        fin.open("C.in");
        fout = stdout;
        break;
    case 0: 
        fin.open("C-small-attempt0.in");
        fout = fopen("C-small-attempt0.out", "w");
        break;
    case 1: 
        fin.open("C-small-attempt1.in");
        fout = fopen("C-small-attempt1.out", "w");
        break;
    case 10:
        fin.open("C-large.in");
        fout = fopen("C-large.out", "w");
        break;
    default:
        cerr << "Incorrect run mode" << endl;
        assert(0);
    }
    assert(fin && fout);

    START_CLOCK;

    int T;     fin >> T;
    for (int t=0; t<T; t++) {
        int N;
        fin >> N  ;
        for (int j=0; j<N; j++) {
             fin >> num[j];   
        }

        vector <int> a;
        vector <int> b;
        Solve(N, a, b);
        if (a.size() == 0) 
            fprintf(fout, "Case #%d:\nImpossible\n", t+1);
        else {
            if (a[0] <= b[0]) {
                fprintf(fout, "Case #%d:\n", t+1);
                for (int j =0; j<a.size(); j++ )
                    fprintf(fout, "%ld ", a[j]);
                fprintf(fout, "\n");
                for (int j =0; j<b.size(); j++ )
                    fprintf(fout, "%ld ", b[j]);
                fprintf(fout, "\n");
            } else {
                fprintf(fout, "Case #%d:\n", t+1);
                for (int j =0; j<b.size(); j++ )
                    fprintf(fout, "%ld ", b[j]);
                fprintf(fout, "\n");
                for (int j =0; j<a.size(); j++ )
                    fprintf(fout, "%ld ", a[j]);
                fprintf(fout, "\n");
            }
        }

    }

    PRINT_TIME

        return 0;
}
