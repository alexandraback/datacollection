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
int a[2000 * 1000 + 20];
bool processed = false;
void process(){
    processed = true;
    a[1] = 1;
    REP(i, 2000010){
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
int digCo(int n){
    int res = 0;
    while(n != 0){
        n /= 10;
        res++;
    }
    return res;
}

int solve3(int n){
    //cout<<n<<endl;
    if(n == 1){
        return 1;
    }
    if(n % 10 == 0){
        return 1 + solve3(n - 1);
    }
    int half = ceill((long double)digCo(n) / (long double)2);
    int newn = n / powl(10, half);
    newn *= powl(10,half);
    newn++;
    int add = n - newn;
    if(add == 0){
        if(getRev(n) < n){
        return add + 1 + solve3(getRev(newn));
        }
        return add + 1 + solve3(newn - 1);
    }
    return add + solve3(newn);
}

#undef int
int main()
{
#define int long long
    #define name "A-large"
    freopen(name ".in","r",stdin);
    freopen(name ".out","w",stdout);
    int t;
    cin>>t;
    REP(q,t){
        int tmp;
        cin>>tmp;
        cout<<"Case #"<<q + 1<<": "<<solve3(tmp)<<'\n';
    }

    return 0;
}

