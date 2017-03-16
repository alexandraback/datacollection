#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define int long long


int getRev(int a){
    int result = 0;
    while(a != 0){
        result *= 10;
        result += a % 10;
        a /= 10;
    }
    return result;
}

int solve(int n){
    int result = 1;
    while(n != 1){
        if(getRev(n) < n && n % 10 != 0){
            //cout<<n<<'\n';
            n = getRev(n);
        } else{
            n--;
        }
        //cout<<n<<" ";
        result++;
    }
    return result;
}
int a[1000 * 1000 + 5];
bool processed = false;
void process(){
    processed = true;
    a[1] = 1;
    REP(i, 1000000){
        int idx = i + 2;
        a[idx] = a[idx - 1] + 1;
        if(getRev(idx) < idx && idx % 10 != 0){
            a[idx] = min(a[idx], a[getRev(idx)] + 1);
        }
    }
}

int solve2(int n){
    if(!processed){
        process();
    }
    return a[n];
}

#undef int
int main()
{
#define int long long
#define name "A-small-attempt0"
    freopen(name ".in","r",stdin);
    freopen(name ".out","w",stdout);
    int t;
    cin>>t;
    REP(q,t){
        int n;
        cin>>n;
        cout<<"Case #"<<q + 1<<": "<<solve2(n)<<'\n';
    }

    return 0;
}

