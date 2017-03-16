#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 105;

char A[N];

int main(){
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("lol.out", "w", stdout);
    int t, n, k;
    cin>>t;
    for(int big = 1; big <= t; big++){
        cin>>n>>k;
        cout<<"Case #"<<big<<": "<<endl;
        for(int i = 0; i < k; i++){
            cout<<"11";
            for(int j = 0; j < (n - 4)/2; j++){
                if(i & (1 << j))    cout<<"11";
                else cout<<"00";
            }
            cout<<"11 ";
            for(int j = 2; j <= 10; j++)    cout<<j + 1<<" ";
            cout<<endl;
        }
    }
}
