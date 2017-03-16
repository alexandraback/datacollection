#include <iostream>
#include <cstdio>
#define MAXN 111

using namespace std;

int n, s, p, a[MAXN], t, test, res;

void sort(){
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[i] < a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

int main(){
//    freopen("B-large.in", "rt", stdin);
//    freopen("B-large.out", "wt", stdout);
    cin >> t;
    for (int test = 1; test <= t; test++){
        cin >> n >> s >> p;
        res = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort();
        int k1 = p + p - 1 + p - 1;
        int k2 = p + p - 2 + p - 2;
        for (int i = 1; i <= n; i++)
            if (a[i] >= k1) res++;
            else if (a[i] >= max(2, k2) && s > 0){
                res ++;
                s--;
            }
        cout << "Case #" << test << ": " << res << endl;
    }
    return 0;
}
