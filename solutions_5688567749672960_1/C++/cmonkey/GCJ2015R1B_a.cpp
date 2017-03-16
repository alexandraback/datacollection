#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

long long INF;
long long base[20], ten[20];
char num[20];

long long revert(long long a){
    long long ans, k;
    ans = 0;
    while(a){
        ans = ans * 10 + (a % 10);
        a /= 10;
    }
    return ans;
}

int lens(long long a){
    int k = 0;
    while(a){
        k++;
        a /= 10;
    }
    return k;
}

long long calc(char *tar){
    int len = strlen(tar);
    long long ans = 0;
    ans += base[len];
    if (len == 1) ans += tar[0] - '0';
//    else if (tar[len - 1] == '0' && len == 2){
//        if (tar[0] > '1'){
//            ans += tar[0] - '0' + 9;
//        }
//    }
    else{
        int best;
        long long bestnum = INF;
        for (int i = 0; i <= len; i++){
            long long left = 0;
            for (int j = i - 1; j >= 0; j--)
                left = left * 10 + tar[j] - '0';
            long long right = 0;
            for (int j = i; j < len; j++)
                right = right * 10 + tar[j] - '0';

            if (right == 0 && left > 1){
                long long tmp = 0;
                for (int j = 0; j < i; j++)
                    tmp = tmp * 10 + tar[j] - '0';
                tmp--;
                if (lens(tmp) != i) continue;
                left = revert(tmp);
                right = ten[len - i + 1];
//                cout << "i = " << i << " left "
//                << left << " right " << right << endl;
//                if (left > 0) left += 1;
            }else if (left == 0 || left == 1) left--;
            if (left + right < bestnum){
                bestnum = left + right;
                best = i;
            }
        }
        ans += bestnum;
    }
    return ans;
}

int main(){
    int t, T;
    long long i, j, k, n;

    freopen("A-large.in", "r", stdin);
    freopen("a.out", "w", stdout);

    INF = 1;
    INF <<= 60;

    base[1] = 0;
    base[2] = 10;
    memset(num, 0, sizeof(num));
    num[0] = '9';
    for (i = 3; i <= 15; i++){
        num[i - 2] = '9';
        base[i] = calc(num) + 1;
//        cout << "base " << base[i] << endl;
    }
    ten[0] = ten[1] = 1;
    for (i = 2; i <= 15; i++){
        ten[i] = ten[i - 1] * 10;
    }

    cin >> T;
    for (t = 1; t <= T; t++){
        cin >> n;
        for (j = k = 1; k <= n; k *= 10, j++);
        memset(num, 0, sizeof(num));
        j -= 2;
        while(n){
            num[j] = (n % 10) + '0';
            n /= 10;
            j--;
        }
        k = calc(num);
        cout << "Case #" << t << ": " << k << endl;
    }
    return 0;
}
