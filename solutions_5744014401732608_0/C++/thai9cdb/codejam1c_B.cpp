#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,ntest,m;

main(){
    freopen("test.txt","w",stdout);
    cin>>ntest;
    for (int test=1;test<=ntest;test++){
        cout<<"Case #"<<test<<": ";
        cin>>n>>m;
        if ((1LL<<(n-2)<m)){
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        cout<<"POSSIBLE\n0";
        m--;
        for (int i=2;i<n;i++) cout<<((m>>(n-i-1))&1);
        cout<<"1\n";
        for (int i=2;i<=n;i++){
            for (int j=1;j<=n;j++) cout<<(i>=j?'0':'1');cout<<endl;}
    }
}
/*
100
5 4
2 1
4 20
3 16
6 3
2 9
5 5
6 16
6 15
5 17
5 11
4 17
4 13
5 2
4 4
3 9
3 13
6 1
6 14
3 4
3 17
5 7
4 8
3 1
6 8
5 19
3 10
2 2
3 19
3 2
6 12
2 10
2 19
2 17
6 9
2 11
6 2
4 14
4 10
6 4
3 12
2 3
3 11
5 3
2 5
4 2
6 11
3 6
4 7
6 5
5 10
4 18
5 6
5 14
2 20
5 8
6 18
3 14
2 13
3 20
4 6
2 15
4 12
4 19
2 6
6 19
6 6
5 20
6 13
2 4
2 14
4 3
4 9
6 7
2 7
5 15
6 10
3 3
4 1
2 18
4 11
4 15
5 12
5 9
3 5
6 17
6 20
4 5
2 12
3 8
2 8
5 16
5 13
5 18
3 15
2 16
4 16
5 1
3 18
3 7
*/
