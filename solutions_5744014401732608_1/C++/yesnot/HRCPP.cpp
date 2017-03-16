#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <limits>

using namespace std;

typedef unsigned long ul;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vecs;
typedef vector<int> veci;
typedef vector<long long> vecll;

template <typename T>
string tostring ( T value )
{
    ostringstream ss;
    ss << value;
    return ss.str();
}

template <typename T>
T strtonum ( const string &Text )
{
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
#define MOD 1000000007

//----------------------------------
void solve()
{
    int numCases = 1;
    cin >> numCases;

    for ( int ncase=1; ncase <= numCases; ncase++ )
    {
        //===== start case
        ull B, M;
        cin >> B >> M;
        ull maxM=1;
        for (ull i=0; i<B-2; i++)
        {
            maxM*=2;
        }

        cout << "Case #" << ncase <<": ";
        //cout << maxM << endl;

        if (M>maxM)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
        {
            cout << "POSSIBLE" << endl;
            //cout << maxM << endl;
            int b[50][50];
            for (int i=0; i<50; i++)
                for (int j=0; j<50; j++)
                    b[i][j]=0;

            ull mm=maxM/2;
            ull curm=M;
            for (int i=1; i<=B-1; i++)
            {
                if (mm<=curm)
                {
                    b[0][i]=1;
                    for (int a=i;a<B;a++) {
                        for (int j=a+1;j<B;j++) {
                            b[a][j]=1;
                        }
                    }
                    curm-=mm;
                }
                if (curm==0)
                    break;
                mm /= 2;
            }

            if (curm==1) {
                b[0][B-1]=1;
            }
            for (int i=0; i<B; i++)
            {
                for (int j=0; j<B; j++)
                {
                    cout << b[i][j];
                }
                cout << endl;
            }
        }

        //===== end case
    }
}

int main()
{
#ifdef CCQTEST
#include "HRCPP1.h"
#endif
    solve();
#ifdef CCQTEST
#include "HRCPP2.h"
#endif
    return 0;
}
