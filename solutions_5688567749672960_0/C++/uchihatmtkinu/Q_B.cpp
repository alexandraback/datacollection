#include<iostream>
#include <cstring>
#include <stdio.h>
#include <cmath>
#include <iomanip>
using namespace std;

int T;
int a[1000001];
int N;
int ans;


int trans(int h)
{
    int k = 0;
    while (h>0)
    {
        k = k*10+h%10;
        h = h/10;
    }
   //cout << k;
    return k;
}

void solve()
{

    int x;
    for (int i = 0; i <= 1000000; i++) a[i] = 0;
    a[1] = 1;
    cin >> x;
    int l = 0;
    while (l<x)
    {
        l++;
        if (a[l+1] == 0 || (a[l]+1 < a[l+1])) a[l+1] = a[l]+1;
        int y = trans(l);
        if (a[y] == 0) a[y] = a[l]+1;
    }
    cout << a[x];
}

int main() {

    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small-attempt1.out", "w", stdout);

    cin >> T;
    for (int test = 1; test <= T; test++) {
        cout << "Case #" << test << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
