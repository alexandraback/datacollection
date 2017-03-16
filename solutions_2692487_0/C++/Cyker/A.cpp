#include <algorithm>
#include <cassert>
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
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define PI 3.1415926535897932384626433832795
#define INF 0x7FFFFFFF

int T;
int s[100 + 2];
int crem[100 + 2];
int cins[100 + 2];

int main(int argc, char **argv)
{
    scanf("%d\n", &T);
    REP(t, T) {
        memset(s, 0, sizeof(s));
        memset(crem, 0, sizeof(crem));
        memset(cins, 0, sizeof(cins));

        int A, N;
        scanf("%d %d\n", &A, &N);
        REP(i, N) {
            scanf("%d ", &s[i]);
        }
        sort(s, s + N);


        bool stop = false;
        int Nstop = 0;
        REP(i, N) {
            //  Set crem.
            crem[i] = N - i;

            //  Set cins.
            if (A <= 1) {
                stop = true;
                Nstop = i + 1;
                break;
            } else {
                int n = 0;
                while (A <= s[i]) {
                    A = A + A - 1;
                    n++;
                }
                cins[i] = n;
            }
            A += s[i];
            Nstop++;
        }

        int res = INF;
        int accum = 0;
        for (int i = 0;i < Nstop;i++) {
            if (accum + crem[i] < res) {
                res = accum + crem[i];
            }
            accum += cins[i];
        }
        if (!stop && accum < res) {
            res = accum;
        }

        printf("Case #%d: %d\n", t + 1, res);
    }

    return 0;
}

