#include <bits/stdc++.h>

using namespace std;

#define mem0(arr) memset(arr , 0 , sizeof arr)
#define memf(arr) memset(arr , false , sizeof arr)
#define memdp(arr) memset(arr , -1 , sizeof arr)
#define rep(i , n) for(int i = 1; i <= n; i++)
#define loop(i , n) for(int i = 0; i < n; i++)
#define pb push_back
#define fi first
#define se second
#define cs(y) cout << "Case #" << y << ": "
#define cs2(y) cout << "Case " << y << ":" << "\n"

typedef long long ll;

string arr1 [1000 + 1];
string arr2 [1000 + 1];

int n , m  , k , d , t , tem1 , tem2 , tem3 , tem4 , y = 1, sum = 0 , ans = 0;
string s , c;

int dp [131072 + 10];


int rec (int msk){

    if( (1 << n) == (msk + 1) ) return 0;


    int res = -1e18;

    int &st = dp[msk];
    if(st != -1) return st;

    map < string , bool > p1;
    map <string , bool> p2;

    for(int i = 0; i < n; i++){

        if( (msk & (1 << i)) == 0 ) continue;

        p1[arr1[i]] = true;
        p2[ arr2[i] ] = true;
    }

    for(int i = 0; i < n; i++){

        if( (msk & (1 << i)) != 0) continue;

        if( p1[ arr1[i] ] &&  p2[ arr2[i] ] ) res = max(1 + rec(msk | (1 << i) ) , res);
        else res = max( rec(msk  | (1 << i) ) , res );
    }

    return st = res;
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);
    freopen ("C-small-attempt1.in", "r", stdin);
    freopen ("ans.txt","w",stdout);


    cin >>        t        ;

    while(t--){

        memset(dp , -1, sizeof dp);
        cin >> n;

        for(int i = 0; i < n; i++){

            cin >> arr1[i] >> arr2[i];
        }

         cs(y++);

        cout << rec(0) << "\n";
    }

    return 0;
}
