#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define N 100000

double a[N], b[N];

int f(double a[], double b[], int n){
    int l1, l2, j;
    l1 = 0;
    l2 = 0;
    while(l1 < n && l2 < n){
        j = l2;
        while(j < n){
            if(a[l1] < b[j]){
                break;
            }
            j++;
        }
        if(j == n){
            break;
        }
        l2 = j + 1;
        l1++;
    }
    return n - l1;
}

inline void solve(){
    int i, n;
    cin>>n;
    for(i = 0; i < n; i++){
        cin>>a[i];
    }
    for(i = 0; i < n; i++){
        cin>>b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    printf(" %d %d\n", n-f(b,a,n), f(a,b,n));
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
        cin>>t;
    for(int i = 0; i < t; i++){
        printf("Case #%d:", i + 1);
        solve();
    }
    return 0;
}
