//{ ---------- C headers
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <cctype>
//}

//{ ---------- C++ headers
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <queue>
# include <stack>
# include <map>
# include <sstream>
# include <set>
//}
using namespace std;

//{ ---------- Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement
//}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int CASE = 1;
    int t; cin >> t;
    while( t-- )
    {
        vector <string> str;
        int COUNT = 0;
        int n; cin >> n;

        for(int i=0; i<n; i++)
        {
            string line; cin >> line;
            str.push_back( line );
        }

        int ind = 0;
        while( true )
        {
            int i;
            for(i=0; i<n; i++)
            {
                if( ind < str[i].size() && str[i][ind]==str[0][ind] );
                else break;
            }
            if( i!=n ) break;

            int mid;
            vector <int> cnt(n,0);
            for( i = 0; i < n; i++ )
            {
                for( int j=ind+1; j<str[i].size(); j++ )
                {
                    if( str[i][j] != str[0][ind] ) break;
                    else cnt[i]++;
                }
            }
            vector <int> temp=cnt;
            sort( temp.begin(), temp.end() );
            mid = temp[ n / 2 ];

            for( i = 0; i < n; i++ )
            {
                if( cnt[i] < mid )
                {
                    while( cnt[i]++ != mid ) { str[i].insert( str[i].begin() + ind + 1, str[0][ind] ); COUNT++; }
                }
                else if( cnt[i] > mid )
                {
                    while( cnt[i]-- != mid ) { str[i].erase( str[i].begin() + ind +1 ); COUNT++; }
                }
            }

            ind++;
        }

        cout << "Case #" << CASE++ << ": ";
        int i;
        for(i=0; i<n-1; i++) if( str[i] != str[i+1] ) break;
        if(i!=n-1) cout << "Fegla Won" << endl;
        else cout << COUNT << endl;
    }

    return 0;
}
