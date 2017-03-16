#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 105;

char A[N];

int main(){
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("lol.out", "w", stdout);
    int t;
    cin>>t;
    for(int big = 1; big <= t; big++){
        cout<<"Case #"<<big<<": ";
        cin>>A;
        int len = strlen(A), ans = 0;
        for(int i = 1; i < len; i++){
            if(A[i] != A[i - 1])    ans++;
        }
        if(A[len - 1] == '-')   ans++;
        cout<<ans<<endl;
    }
}
