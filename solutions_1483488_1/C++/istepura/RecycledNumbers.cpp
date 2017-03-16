#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
#define FORN(i_, n_) for(int i_ = 0; i_ < (n_); ++i_)
inline int countdigits(int n){
    int res = 0;
    while (n > 0){
        n/=10;
        res++;
    }
    return res;
}
inline int pow(int n, int p){
    int res = 1;
    while (p > 0){
        if (p & 1){
            res *= n;
            p--;
        }
        n *= n;
        p /= 2;
    }
    return res;
}
int main (int argc, char** argv)
{
    istream* is = &cin;
    ostream* os = &cout;

    if (argc >= 2) is = new ifstream(argv[1]);
    if (argc == 3) os = new ofstream(argv[2]);
    
    int T;
    *is >> T;
    FORN(i,T){
        int A, B, count = 0;
        *is >> A >> B;
        int d = countdigits(A);
        set<pair<int,int> > S;
        for(int n = A; n <= B; n++){
            for (int k = 1; k < d; k++){
                int dec = pow(10,k);
                int m = n/dec + ((n % dec) * pow(10,d-k));
                if ((n < m) && (m <= B)){
                    S.insert(make_pair(n,m));
                }
            }

        }
        *os << "Case #" << i+1 <<": " << S.size() << endl;
    }
    if (is != &cin) delete is;
    os->flush();
    if (os != &cout) delete os;
    return 0;
}

