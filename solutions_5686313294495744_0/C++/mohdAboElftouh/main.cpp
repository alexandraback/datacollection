#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mp make_pair
using namespace std;


int n;
string one[20] , two[20];
int ans;
int a[20];

void solve(int j){
    if(j == n){
        map<string , bool> x , y;
        for(int i = 0; i < n; ++i){
            if(!a[i]){
                x[one[i]] = 1;
                y[two[i]] = 1;
            }
        }

        int b = 0;

        for(int i = 0; i < n; ++i){
            if(a[i]){
                ++b;
                if(x[one[i]] && y[two[i]])continue;
                return;
            }
        }

        if(b > ans){
            ans = b;
        }

        return;

    }

    a[j] = 1;
    solve(j+1);
    a[j] = 0;
    solve(j+1);

}


int main(){

    freopen("C-small-attempt0.in" , "r" , stdin);
    freopen("dream.out" , "w" , stdout);
    int t , z = 1;
    cin >> t;
    while(t--){
        memset(a , 0 , sizeof a);
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> one[i] >> two[i];
        }
        ans = 0;
        solve(0);
        printf("Case #%d: %d\n" , z++ , ans);
    }
    return 0;
}
