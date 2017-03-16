#include <bits/stdc++.h>

#define all(c) c.begin(),c.end()
#define ll long long
#define ii pair <ll ,ll>
#define iii pair <int, ii >
#define vi vector <int>
#define vii vector < ii >
#define viii vector < iii >
#define oo numeric_limits<ll>::max()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define MAXN 100000

using namespace std;

int main()
{
    freopen("input.in","r+",stdin);
    freopen("output.txt","w+",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T,X,R,C;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> X >> R >> C;
        int trick;
        if(!(X%2))
            trick = ((X-1)/2 + 1)*((X-1)/2 + 2);
        else
            trick = ((X-1)/2 + 1)*((X-1)/2 + 1);
        cout << "Case #" << t << ": ";
        if(X>=7 || trick>R*C || ((R*C)%X))
            cout << "RICHARD";
        else
            cout << "GABRIEL";
        cout << endl;
    }
    return 0;
}
