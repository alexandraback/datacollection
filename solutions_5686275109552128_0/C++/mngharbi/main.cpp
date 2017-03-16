#include <bits/stdc++.h>

#define all(c) c.begin(),c.end()
#define ll long long
#define ii pair <ll ,ll>
#define iii pair <int, ii >
#define vi vector <int>
#define vii vector < ii >
#define viii vector < iii >
#define oo numeric_limits<int>::max()
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
    int T,D,Max,E,best,K;
    int P[1000];
    cin >> T;
    for(int t=1;t<=T;t++) {
        Max = 0;
        best = oo;
        cin >> D;
        for(int i=0;i<D;i++) {
            cin >> P[i];
            Max = max(Max,P[i]);
        }
        for(E=1;E<=Max;E++) {
            K = E;
            for(int i=0;i<D;i++)
                K += (int)ceil((double)(P[i]-E)/(double)E);
            best = min(best,K);
        }
        cout << "Case #" << t << ": " << best << endl;
    }
    return 0;
}
