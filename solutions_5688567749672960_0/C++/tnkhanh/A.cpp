#pragma comment(linker, "/STACK: 200000000")

#include <bits/stdc++.h>
#define __ ios_base::sync_with_stdio(0);cin.tie(0);

#define FI first
#define SE second
#define MP make_pair
#define PB push_back

using namespace std;

const int MAXN = 1000005, INF = 2*(int)1e9;

typedef pair<int,int> pii;

int tnum, n, f[MAXN];

int reverse(int x){
    int res = 0;
    while (x){
        res = res * 10 + x%10;
        x/=10;
    }
    
    return res;
}

int memo(int x){
    if (f[x]>0) return f[x];
    if (x==1) return f[x] = 1;
    
    int res = memo(x-1) + 1, rev = reverse(x);
    if (rev<x && reverse(rev)==x) res = min(res, memo(rev) + 1);
    
    return f[x] = res;
}

int main(){
    cin>>tnum;
    for (int t=1; t<=tnum; t++){
        cin>>n;
        cout<<"Case #"<<t<<": "<<memo(n)<<"\n";
    }
    return 0;
}