/*
  ID: nigo1
  LANG: C++
  TASK: C
*/
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <stack>

#define TIME printf("%f", (double)clock()/CLOCKS_PER_SEC);

using namespace std;

int T;

int N;
int a[32];

int used[100010*20];

int main()
{
	freopen ("C.in", "r", stdin);
	freopen ("C.out", "w", stdout);

	scanf ("%d", &T);

	N = 20;

	for (int test = 1; test <= T; test++) {
        printf ("Case #%d:\n", test);

        scanf ("%d", &N);

        for (int i = 0; i < N; i++)
            scanf ("%d", a + i);

        memset (used, 0, sizeof used);


        for (int mask = 1; mask < (1 << N); mask++) {
            int sum = 0;
            for (int i = 0; i < N; i++)
                if (mask & (1 << i))
                    sum += a[i];

            if (used[sum]) {
                bool b = 0;
                for (int i = 0; i < N; i++)
                    if (used[sum] & (1 << i)) {
                        if (b) printf (" ");
                        printf ("%d", a[i]);
                        b = 1;
                    }

                printf ("\n");
                b = 0;
                for (int i = 0; i < N; i++)
                    if (mask & (1 << i)) {
                        if (b) printf (" ");
                        printf ("%d", a[i]);
                        b = 1;
                    }

                printf ("\n");
                break;
            }
            used[sum] = mask;
        }

	}


    return 0;
}
