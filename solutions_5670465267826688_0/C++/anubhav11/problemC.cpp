#include<bits/stdc++.h>
#define cin file
#define cout file2
#define N 10010
using namespace std;

int x[5][5] = { {0, 0, 0, 0, 0}, {0, 1, 2, 3, 4}, {0, 2, 1, 4, 3}, {0, 3, 4, 1, 2}, {0, 4, 3, 2, 1} };
bool y[5][5] = { {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 1}, {0, 0, 1, 1, 0}, {0, 0, 0, 1, 1} };
int n, times, arr[15*N], dp2[15*N], dp[15*N];

main() {

    ifstream file("C-small-attempt0.in");
    ofstream file2("C-small-attempt0.out");

    int test;
    cin>>test;
    for (int t=1; t<=test; t++) {

        for (int i=0; i<15*N; i++) {
            arr[i] = 0;
            dp[i] = 0;
            dp2[i] = 0;
        }

        int len1=100000000, len2=100000000, block;

        char a[N];
        cin>>n>>times>>a;

        for (int i=0; i<13*n; i++) {
            if (a[i%n] == 'i') arr[i] = 2;
            if (a[i%n] == 'j') arr[i] = 3;
            if (a[i%n] == 'k') arr[i] = 4;
        }

        dp[0] = arr[0];

        for (int i=1; i<=4*n; i++) {
            //cout<<dp[i-1]<<" "<<dp2[i-1]<<endl;
            dp[i] = x[dp[i-1]][arr[i]];
            dp2[i] += dp2[i-1] + y[dp[i-1]][arr[i]];
            dp2[i] %= 2;
            if (dp[i-1] == 2 && dp2[i-1] == 0) {
                len1 = i;
                break;
            }
        }

        if (len1>=times*n) goto last;

        dp[len1] = arr[len1];
        dp2[len1] = 0;

        for (int i=len1+1; i<=len1+1+4*n; i++) {
            dp[i] = x[dp[i-1]][arr[i]];
            dp2[i] += dp2[i-1] + y[dp[i-1]][arr[i]];
            dp2[i] %= 2;
            if (dp[i-1] == 3 && dp2[i-1] == 0) {
                len2 = i;
                break;
            }
        }

        if (len2>=times*n) goto last;

        block = len2/n +1;
        if (len2%n==0) block--;
        times = (times - block) % 4;

        dp[len2] = arr[len2];
        dp2[len2] = 0;

        for (int i=len2+1; i<(times*n) + (block*n); i++) {
            dp[i] = x[dp[i-1]][arr[i]];
            dp2[i] += dp2[i-1] + y[dp[i-1]][arr[i]];
            dp2[i] %= 2;
        }

        if (dp[(times*n) + (block*n) - 1] == 4 && dp2[(times*n) + (block*n) - 1] == 0) {
            cout<<"Case #"<<t<<": YES"<<endl;
            goto last2;
        }

        last:;
        cout<<"Case #"<<t<<": NO"<<endl;
        last2:;
    }
}
