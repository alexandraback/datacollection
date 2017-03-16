#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <map>
#include <functional>
#include <cassert>
#include <ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;

int main()
{
#ifdef MICRO_LOCAL
	clock_t timer_start = clock();
#endif
/*------------------------------------------------------------------------------------*/
    /*
ZERO - z
ONE - o (zero two four)
TWO - w
THREE - h (eight)
FOUR - r (zero three)
FIVE - f (four)
SIX - x
SEVEN - s (six)
EIGHT - g
NINE - i (five six eight)

0!
1
2!
3 <- 8
4 <- 0, 3
5 <- 4
6!
7 <- 6
8!
9 <- 
*/
/*------------------------------------------------------------------------------------*/
    int T;
    char s[2002];
    scanf("%d",&T);
    for (int tc=1; tc<=T; tc++) {
        scanf("%s",s);
        int len = strlen(s);
        int cnt[10] = {0,};
        for (int i=0; i<len; i++) {
            if (s[i] == 'Z') {
                cnt[0]++;
            }
            else if (s[i] == 'O') {
                cnt[1]++;
            }
            else if (s[i] == 'W') {
                cnt[2]++;
            }
            else if (s[i] == 'H') {
                cnt[3]++;
            }
            else if (s[i] == 'R') {
                cnt[4]++;
            }
            else if (s[i] == 'F') {
                cnt[5]++;
            }
            else if (s[i] == 'X') {
                cnt[6]++;
            }
            else if (s[i] == 'S') {
                cnt[7]++;
            }
            else if (s[i] == 'G') {
                cnt[8]++;
            }
            else if (s[i] == 'I') {
                cnt[9]++;
            }
        }
        cnt[3] -= cnt[8];
        cnt[4] -= cnt[0] + cnt[3];
        cnt[1] -= cnt[0] + cnt[2] + cnt[4];
        cnt[5] -= cnt[4];
        cnt[7] -= cnt[6];
        cnt[9] -= cnt[5] + cnt[6] + cnt[8];
        printf("Case #%d: ", tc);
        for (int i=0; i<10; i++) {
            for (int j=0; j<cnt[i]; j++) {
                printf("%d", i);
            }
        }
        puts("");
    }
#ifdef MICRO_LOCAL
	printf("\nElapsed time : %.2lfms\n", ((double)clock() - (double)timer_start)/1000.0);
#endif
	return 0;
}
