#include <cstdio>
#include <iostream>
using namespace std;

typedef long double LD;

const LD COOKIES_PER_SECOND0 = 2.0;

int main(){

    freopen ( "B-large.in", "r", stdin );
    freopen ( "B-large.out", "w", stdout );

    int t;
    cin >> t;

    cout.precision ( 7 );
    cout.setf ( ios::fixed );
    for ( int testcase = 1; testcase <= t; ++testcase ){
        LD c, f, x;
        cin >> c >> f >> x;
        LD cookies_per_second = COOKIES_PER_SECOND0;
        LD min_time = x / cookies_per_second;
        for ( LD time = c / cookies_per_second; time < min_time; time += c / cookies_per_second ){
            cookies_per_second += f;
            LD time_after_farm = x / cookies_per_second;
            min_time = min ( min_time, time + time_after_farm );
        }

        cout << "Case #" << testcase << ": " << min_time << endl;
    }

    return 0;
}
