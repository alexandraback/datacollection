#include <iostream>
#include <fstream>
#include <windows.h>
#include <math.h>
#include <cmath>

#define SUBMIT 0
#ifdef SUBMIT
    #define cin fin
    #define cout fout
#endif // SUBMIT

#define MAXN 1010
#define MAXB 1010

using namespace std;

ifstream fin("B-large.in");
ofstream fout("B-large.out");

int T, N;
int best_ans;
int pancakes[MAXN];

int main()
{
    cin >> T;

    for (int test=1; test<=T; test++) {
        cin >> N;
        best_ans = 0;
        for (int i=0; i<N; i++) {
            cin >> pancakes[i];
            best_ans = max(best_ans, pancakes[i]);
        }

        for (int max_size=1; max_size<=MAXB; max_size++) {
            int temp_ans=max_size;
            for (int i=0; i<N; i++) {
                int cuts=ceil(((double)pancakes[i]/(double)max_size));
                temp_ans += (cuts-1);
            }
            best_ans = min(best_ans, temp_ans);
        }
        cout << "Case #" << test << ": " << best_ans << endl;
    }

    return 0;
}
