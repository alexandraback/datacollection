#include <iostream>
#include <cstdio>

using namespace std;

int R, N, M, K;
int arr[10];

int max(int a, int b) {return a > b ? a : b;}
int min(int a, int b) {return a < b ? a : b;}

void resolve(int tmp)
{
    int a[10];
    for (int i=2; i<10; ++i) a[i] = 0;
    for (int i=2; i<10; ++i) {
        while (tmp % i == 0) {
            tmp /= i;
            a[i]++;
        }
    }
    for (int i=2; i<10; ++i) arr[i] = max(arr[i], a[i]);
}


bool rec(int no)
{
    if (no == 2) {
        int tot = 0;
        for (int i=0; i<10; ++i) {
            tot += arr[i];
        }
        if (tot == N) return true;
        return false;
    }
    if (no == 5 || no == 7 || no == 3) return rec(no-1);
    int tarr[10];
    for (int i=0; i<10; ++i) tarr[i] = arr[i];
    if (no==8) {
        int maxx = arr[2] / 3;
        for (int i=0; i<=maxx; ++i) {
            arr[8] = i;
            arr[2] -= i*3;
            if (rec(no-1)) return true;
            for (int i=0; i<10; ++i) arr[i] = tarr[i];
        }
    } else if (no==6) {
        int maxx = min(arr[2], arr[3]);
        for (int i=0; i<=maxx; ++i) {

            arr[6] = i;
            arr[2] -= i;
            arr[3] -= i;
            if (rec(no-1)) return true;
            for (int i=0; i<10; ++i) arr[i] = tarr[i];
        }

    } else if (no==4) {
        int maxx = arr[2] / 2;
        for (int i=0; i<=maxx; ++i) {
            arr[4] = i;
            arr[2] -= i;
            arr[2] -= i;
            if (rec(no-1)) return true;
            for (int i=0; i<10; ++i) arr[i] = tarr[i];
        }
    }
    return false;

}

void solve()
{
    int n = N;
    rec(8);
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

