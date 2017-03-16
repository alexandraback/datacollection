#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;

vector<string> vs;
vector<int> ndx;

// #def ArtonTest
//

int calc()
{
    for ( char c = 'a'; c <= 'z'; ++c )
    {
        bool first_appear = false;
        bool cut = false;
        for ( int i = 0; i < ndx.size(); ++i )
        {
            for ( int j = 0; j < vs[ndx[i]].size(); j++ )
            {
                if ( c == vs[ndx[i]][j] )
                {
                    if ( first_appear == false )
                    {
                        first_appear = true;
                    }
                    else if ( cut == false )
                    {
                        ;
                    }
                    else
                    {
                        // cout << "x";
                        return 0;
                    }
                }
                else if ( first_appear == true )
                {
                    cut = true;
                }
            }
        }
    }

    /*
    for ( int i = 0; i < ndx.size(); ++i )
    {
        cout << vs[ndx[i]];
    }
    cout << endl;
    */
    return 1;
}

long long solve() {
    ndx.clear();
    for ( int i = 0; i < vs.size(); ++i )
        ndx.push_back( i );

    std::sort (ndx.begin(),ndx.end());
    int result = 0;
    // cout << vs.size();
    do {
        //cout << "^^" << ndx[0] << " "; 
        result += calc();
    } while ( std::next_permutation(ndx.begin(),ndx.end()) );

    return  result;
}

string shorten( string str)
{
    string ret = "";
    ret = ret + str[0];
    // cout << "!!" << ret << endl;
    for ( int i = 1; i < str.size(); ++i )
    {
        if ( str[i] != ret[ret.size() -1 ] )
            ret = ret + str[i];
    }
    // cout << ret << endl;
    return ret;
}

void solveTest(int CS) {
    vs.clear();
    int car_count;
    scanf( "%d", &car_count );
    for ( int i = 0; i < car_count ; ++ i )
    {
        string t;
        cin >> t;
        vs.push_back( shorten(t) );
    }
    printf("Case #%d: ", CS);
    long long ans = solve();
    printf("%lld\n", ans);
}

int main() {
#ifdef ArtonTest
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  scanf("%d\n", &T);
  for (int test = 1; test <= T; ++test) {
    solveTest(test);
  }
  return 0;
}
