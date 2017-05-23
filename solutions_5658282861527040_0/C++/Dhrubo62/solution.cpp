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
        int cnt = 0;
        int a, b, k;
        cin >> a >> b >> k;

        for( int i=0; i<a; i++ )
        {
            for( int j=0; j<b; j++ )
            {
                if( (i&j) < k ) cnt++;
            }
        }

        cout << "Case #" << CASE++ << ": " << cnt << endl;
    }

    return 0;
}
