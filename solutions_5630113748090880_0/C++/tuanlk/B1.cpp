#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define DFOR(i,a,b) for(int i=a;i>=b;i--)
#define mp(x,y) make_pair((int)x,(int)y)
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(x,a,b) {cout << #x << " = "; FOR(i,a,b) cout << x[i] << ' '; cout << endl;}
#define ll long long
#define DEBUG 1

int main(){
    if (DEBUG==1){
        freopen("B-small.in","r",stdin);
        freopen("output.txt","w",stdout);
    }
    int test;
    int n;
    int a[60][60];
    int h;
    int hi[2600];
    cin>>test;
    FOR(t,1,test){
        cin>>n;
        FOR(i,1,2500) hi[i]=0;
        FOR(i,1,2*n-1){
            FOR(j,1,n){
                cin>>h;
                 hi[h]=1-hi[h];
            }
        }
        cout<<"Case #"<<t<<":";
        FOR(i,1,2500) if (hi[i]==1) cout<<" "<<i;
        if (t<test) cout<<endl;
    }
    return 0;
}
/*
1
3
1 2 3
2 3 5
3 5 6
2 3 4
1 2 3
*/
