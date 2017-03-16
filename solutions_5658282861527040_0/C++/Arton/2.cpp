#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long int64;

int64 A,B,K;
void print_ans()
{
    int64 ans = 0;
    for ( int64 a = 0; a < A; ++a )
    {
        for ( int64 b = 0; b < B; ++b )
        {
            // cout << "@ " << a << " " << b << " " << (a&b) << " " << K << endl;
            if ( ( a & b ) < K )
            {
                ans++;
            }
        }
    }
    cout << ans;
}
int main()
{
    int case_num;
    cin >> case_num;
    for ( int i = 0; i < case_num; ++i )
    {
        cin>>A>>B>>K;
        printf( "Case #%d: ", i + 1 );
        print_ans();
        printf( "\n" );
    }
    return 0;
}

