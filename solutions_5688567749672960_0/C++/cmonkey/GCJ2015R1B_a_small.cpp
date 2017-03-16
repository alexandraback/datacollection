#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

long long f[1000001];

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

int main(){
    int t, T;
    long long i, j, k, n;

    freopen("A-small-attempt1.in", "r", stdin);
    freopen("a.out", "w", stdout);

    f[0] = 0;
    for (i = 1; i <= 1000000; i++){
        f[i] = f[i - 1] + 1;
        k = revert(i);
        if (k < i && lens(k) == lens(i))
            f[i] = min(f[i], f[k] + 1);
    }
    cin >> T;
    for (t = 1; t <= T; t++){
        cin >> n;
        cout << "Case #" << t << ": " << f[n] << endl;
    }
    return 0;
}
