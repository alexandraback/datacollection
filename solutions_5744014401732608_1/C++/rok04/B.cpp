#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<math.h>
#include<fstream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           make_pair(a,b)
#define      pb(a)             push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      fill(a)           memset(a, 0, sizeof (a))
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      X                 first
#define      Y                 second
ll MOD = 1000000007;

int main() {
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
    ll T;
    cin>>T;
    for(int t=1; t<=T; t++) {
        ll  b,m,tt;
        cin>>b>>m;
        tt=1;
        for(int i=1; i<=b-2; i++)
            tt*=2;
        if(m>tt) {
            cout<<"Case #"<<t<<": IMPOSSIBLE\n";
            continue;
        }
        cout<<"Case #"<<t<<": POSSIBLE\n";
        ll arr[100][100];
        for(int i=1;i<=b; ++i) {
            for(int j=1;j<=i; ++j)
                arr[i][j]=0;
            for(int j=i+1;j<b; ++j)
                arr[i][j]=1;
        }
        if(m==tt) {
            for(int i=1; i<b; ++i)
                arr[i][b]=1;
        } else {
            arr[1][b]=0;
            for(int i=2; i<b; ++i) {
                arr[i][b]=(m%2);
                m/=2;
            }
        }
        for(int i=1; i<=b; ++i) {
            for(int j=1; j<=b; ++j) {
                cout<<arr[i][j];
            }
            cout<<endl;
        }
    }
}
