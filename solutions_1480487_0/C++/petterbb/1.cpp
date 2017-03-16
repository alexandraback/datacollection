#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int s[210];
double ans[210];
bool fail[210];

int main(){
    freopen("a.out", "w", stdout);
    int t;
    cin >> t;
    for(int testCases = 1; testCases <= t; testCases++){
        double sum = 0;
        int n;
        cin >> n;
        memset(fail, false, sizeof(fail));
        for(int i = 0; i < n; i++){
            cin >> s[i];
            sum += s[i];
        }
        double sum2 = sum;
        printf("Case #%d: ", testCases);
        int size = n; 
        while(true){
            double target = (sum + sum2) / (double)size;
            int i;
            for(i = 0; i < n; i++){
                if(fail[i])
                    continue;
                ans[i] = 100 * (target - s[i]) / sum;
                if(ans[i] < 0){
                    fail[i] = true;
                    sum2 -= s[i];
                    ans[i] = 0;
                    size--;
                    break;
                }
            }
            if(i == n)
                break;
        }
        for(int i = 0; i < n; i++)
            printf("%.6lf ", ans[i]);

        cout << endl;
    }

    return 0;
}
