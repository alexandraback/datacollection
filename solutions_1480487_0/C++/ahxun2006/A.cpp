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

int S[205];
double prob[205];
int main() {
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small-attempt1.out", "w", stdout);
    int T, N;
    scanf("%d", &T);
    for (int caseId = 1; caseId <= T; ++caseId) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) scanf("%d", &S[i]);
        int sum = accumulate(S, S + N, 0), cnt = 0;
        double total = 0.0;
        double avg = 2.0 * sum / N;
        for (int k = 0; k < N; ++k) 
            if ((double)S[k] < avg) {
                total += (double)S[k];
                ++cnt;
            }    
        total = (total + sum) / cnt;
       // cout << avg << " " << total << endl;
        for (int k = 0; k < N; ++k) {
            if (avg <= (double)S[k]) {
                prob[k] = 0.0;
            } else {
                prob[k] = (total - S[k]) / sum;
            }    
        }    
        printf("Case #%d:", caseId);
        for (int k = 0; k < N; ++k) printf(" %.10lf", prob[k] * 100.0);
        printf("\n");
    }    
  //  system("pause");
    return 0;
}    
