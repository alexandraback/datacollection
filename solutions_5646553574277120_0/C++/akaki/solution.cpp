#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

long long i,j,k,l,m,n, v, cur , r,c,w,test,t, mx, a[20],d,dd ,ii,x;
string alphabet, s;
int used[31];

void solve(){
    int which[31];
    memset(which, 0, sizeof(which));
    int mask,j;
    for (mask = 1;mask<(1<<(d+n));mask++){
        //cout<<mask<<"  "<<dd<<" aaa\n";
        int cur = 0;
        for (j=0;j<(d+n);j++){
            if (mask&(1<<j)){
                cur+=a[j];
            }
        }
        if (cur<=v)
        which[cur] = 1;
    }
    int ddd = 1;
    for (j=1;j<=v;j++){
        if (which[j]==0){
            ddd = 0;
            break;
        }
    }
    if (ddd) dd = 1;
}

void rec(int from, int k){
    if (dd) return;
    //cout<<from<<"  "<<k<<"\n";
    //cout.flush();
    if (k==n){solve();return;}
    int i;
    for (i=from;i<=v;i++){
        if (dd) return;
        if (used[i]==0){
            a[d+k] = i;
            if (d+k>=20) {cout<<"wwwwwwwwwwww\n";cout.flush();}
            
            rec(i+1,k+1);
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w", stdout);
    cin>>t;

    while(t--){
        cin>>c>>d>>v;
        test++;
        memset(used, 0, sizeof(used));
        dd = 0;
        for (i=0;i<d;i++){
            cin>>a[i];
            if (a[i]<=v)
                used[a[i]] = 1;
        }
        for (n=0;n<5;n++){
            rec(1,0);
            if (dd) break;
        }
        cout<<"Case #"<<test<<": "<<n<<"\n";
    } 
    return 0;
}
