#include <iostream>

using namespace std;

long long int dp[32][2][2][2];
int ad[32], bd[32], kd[32];
int al, bl, kl;

void convertbits(int num, int arr[], int& len) {
    for (int i = 0; i < 32; i++) {
        arr[i] = 0;
    }
    int p = 0;
    while(num) {
        arr[p] = num % 2;
        num /= 2;
        p++;
    }
    len = p;
}

long long int nums(int pos, int o1, int o2, int o3) {
    if (dp[pos][o1][o2][o3] != -1) return dp[pos][o1][o2][o3];
    if (pos == 0) {
        return !o3 && !o1 && !o2;
    }
    long long int r = 0;
    if (!o3 || kd[pos - 1]) {
        if ((o1 && !ad[pos - 1]) ||
            (o2 && !bd[pos - 1])) {

        } else {
            r += nums(pos - 1, o1, o2, o3);
        }
    }
    if (!o1 || ad[pos - 1]) {
        r += nums(pos - 1, o1, o2 && !bd[pos - 1], o3 && !kd[pos - 1]);
    }
    if (!o2 || bd[pos - 1]) {
        r += nums(pos - 1, o1 && !ad[pos - 1], o2, o3 && !kd[pos - 1]);
    }
    r += nums(pos - 1, o1 && !ad[pos - 1], o2 && !bd[pos - 1], o3 && !kd[pos - 1]);
    return dp[pos][o1][o2][o3] = r;
}

int main() {
    int t;
    cin>>t;
    for (int ca = 0; ca < t; ca++) {
        int a, b, k;
        cin>>a>>b>>k;
        convertbits(a, ad, al);
        convertbits(b, bd, bl);
        convertbits(k, kd, kl);
        for(int i = 0; i < 32; i++)for(int j = 0; j < 2; j++)for(int kk = 0; kk < 2; kk++)for(int l = 0; l < 2; l++) {
            dp[i][j][kk][l] = -1;
        }
        cout<<"Case #"<<(ca + 1)<<": "<<nums(max(kl, max(al, bl)), 1, 1, 1)<<endl;
    }
    return 0;
}