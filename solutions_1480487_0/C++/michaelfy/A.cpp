#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
using namespace std;

double total_score = 0;
int score[300];
double ans[300];
int main()
{
    freopen("A.in", "r", stdin);
    freopen("aout.txt", "w", stdout);
    int tc;
    scanf("%d", &tc);
    for (int testcase=1; testcase<=tc; ++testcase) {
        int N;
        scanf("%d", &N);
        for (int i=0; i<N; ++i) {
            scanf("%d", &score[i]);
        }
        total_score = 0;
        for (int i=0; i<N; ++i) {
            total_score += score[i];
        }
        double sum_score = total_score * 2.0;
        double share = sum_score / N;
        int cntN = N;
        for (int i=0; i<N; ++i) {
            if (share < score[i]) {
                sum_score -= score[i];
                ans[i] = 0.0;
                cntN--;
            }
        }
        double share1 = sum_score / cntN;
        //cout << "share1 " << share1 << " cntN " << cntN << " tos " << total_score << endl;
        for (int i=0; i<N; ++i) {
            if (share >= score[i]) {
                ans[i] = 100.0 * (share1 - score[i]) / total_score;
            }
        }
        printf("Case #%d: %0.5lf", testcase, ans[0]);
        for (int i=1; i<N; ++i) {
            printf(" %0.5lf", ans[i]);
        }
        printf("\n");
    }
    
    return 0;
}
