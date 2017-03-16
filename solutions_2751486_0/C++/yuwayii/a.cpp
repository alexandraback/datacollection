#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for( int tcase = 1; tcase <= t; ++tcase )
    {
        cout << "Case #" << tcase << ": ";

        int res = 0, n;
        string str;
        cin >> str >> n;
        for( int l = str.size(); l >= n; --l )
            for( int i = 0; i + l <= str.size(); ++i )
            {
                bool flag = false;
                int cnt = 0;
                for( int j = i; j < i + l && !flag; ++j )
                    if( str[ j ] == 'a' || str[ j ] == 'e' ||
                        str[ j ] == 'i' || str[ j ] == 'o' ||
                        str[ j ] == 'u' )
                        cnt = 0;
                    else
                    {
                        ++cnt;
                        if( cnt == n ) flag = true;
                    }
                if( flag ) ++res;
            }       
        cout << res << endl;
    }
}
