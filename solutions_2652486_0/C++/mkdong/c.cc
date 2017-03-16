#include <iostream>
#include <cstdio>

using namespace std;

int R, N, M, K;
int arr[10];

int max(int a, int b) {return a > b ? a : b;}

void resolve(int tmp)
{
    int a[10];
    for (int i=2; i<10; ++i) a[i] = 0;
    for (int i=2; i<6; ++i) {
        while (tmp % i == 0) {
            tmp /= i;
            a[i]++;
        }
    }
    for (int i=2; i<10; ++i) arr[i] = max(arr[i], a[i]);
}

void solve()
{
    int n = N;
    int tot = 0;
    for (int i=2; i<10; ++i) tot += arr[i];
    int move = tot - N;
    arr[2] -= 2*move;
    arr[4] += move;
    for (int i=2; i<6; ++i) {
        for (int j=0; n>0&&j<arr[i]; ++j) {
            cout << i;
            --n;
        }
    }
    while (n>0) {
        cout << 2;
        n--;
    }

    cout << endl;
}

int main()
{
    int tc;
    cin >> tc;
    cout << "Case #1:" << endl;
    cin >> R >> N >> M >> K;
    for (int r=1; r<=R; ++r) {
        for (int i=2; i<10; ++i) arr[i] = 0;
        for (int i=0; i<K; ++i) {
            int tmp;
            cin >> tmp;
            resolve(tmp);
        }
        solve();
    }
    return 0;
}

