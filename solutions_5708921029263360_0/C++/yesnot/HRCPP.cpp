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
        int J,P,S,K;
        cin >> J >> P >> S >> K;
        //cout << "JPSK:" << J << "," <<P << "," <<S << "," <<K << endl;
        cout << "Case #" << ncase <<": ";

        vector<vector<int>> vans;
        map<vector<int>,int> jp;
        map<vector<int>,int> js;
        map<vector<int>,int> ps;
        for (int is=1; is<=S; is++)
        {
            for (int ip=1; ip<=P; ip++)
            {
                for (int ij=1; ij<=J; ij++)
                {
                    vector<int> pjp(2);
                    pjp[0]=ij;
                    pjp[1]=ip;
                    vector<int> pjs(2);
                    pjs[0]=ij;
                    pjs[1]=is;
                    vector<int> pps(2);
                    pps[0]=ip;
                    pps[1]=is;
                    //cout << jp.size() << "," << js.size() << "," << ps.size() << endl;
                    int jpsize = jp.find(pjp)==jp.end()?0:jp[pjp];
                    int jssize = js.find(pjs)==js.end()?0:js[pjs];
                    int pssize = ps.find(pps)==ps.end()?0:ps[pps];
                    if (jpsize<K && jssize<K && pssize<K)
                    {
                        vector<int> v(3);
                        v[0]=ij;
                        v[1]=ip;
                        v[2]=is;
                        vans.push_back(v);
                        jp[pjp]=jpsize+1;
                        js[pjs]=jssize+1;
                        ps[pps]=pssize+1;
                    }
                }
            }
        }
        cout << vans.size() << endl;
        for (int i=0; i<vans.size(); i++)
        {
            cout << vans[i][0] << " ";
            cout << vans[i][1] << " ";
            cout << vans[i][2] << endl;
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
