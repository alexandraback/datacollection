#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RANGE(i,b,e) for(int (i)=(b);(i)<(int)(e);(i)++)
#define CRANGE(i,b,e) for(int (i)=(b);(i)<=(int)(e);(i)++)
#define RRANGE(i,b,e) for(int (i)=(b);(i)>=(int)(e);(i)--)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define PI 3.1415926535897932384626433832795
#define INF 0x7FFFFFFF

int T;
double C, F, X;
double curr_time, total_time, speed, cookie;

int main(int argc, char **argv)
{
    cin >> T;
    for (int t = 0;t < T;t++) {
        cin >> C >> F >> X;
        curr_time = total_time = cookie = 0.0;
        speed = 2.0;
        double balance_time = C / F;

        if (X <= C) {
            total_time = X / speed;
        } else {
            while (true) {
                if (cookie >= C) {
                    // can buy a farm
                    double win_time = (X - cookie) / speed;
                    if (win_time <= balance_time) {
                        // don't buy
                        total_time += win_time;
                        break;
                    } else {
                        // do buy
                        cookie -= C;
                        speed += F;
                    }
                } else {
                    // cannot buy a farm
                    double buy_time = (C - cookie) / speed;
                    cookie = C;
                    total_time += buy_time;
                }
            }
        }

        cout << "Case #" << t + 1 << ": ";
        cout << fixed << setprecision(7) << total_time;
        cout << endl;
    }

    return 0;
}
