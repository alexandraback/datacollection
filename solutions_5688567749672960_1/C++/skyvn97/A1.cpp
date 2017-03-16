#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
using namespace std;
int d[MAX];
long long pw[100];
vector<int> digit(int x) {
    vector<int> res;
    while (x>0) {
        res.push_back(x%10);
        x/=10;
    }
    return (res);
}
void dfs(void) {
    memset(d,-1,sizeof d);
    queue<int> q;
    d[1]=1;
    q.push(1);
    while (!q.empty()) {
        int u=q.front();q.pop();
        if (u+1<MAX && d[u+1]<0) {
            d[u+1]=d[u]+1;
            q.push(u+1);
        }
        vector<int> dig=digit(u);
        int x=0;
        REP(i,dig.size()) x=x*10+dig[i];
        if (x<MAX && d[x]<0) {
            d[x]=d[u]+1;
            q.push(x);
        }
    }
}
void print(void) {
    //FOR(i,10,19) if (d[i]!=d[i-1]+1) printf("Diff: d(%d)=%d but d(%d)=%d\n",i-1,d[i-1],i,d[i]);
    //FOR(i,100,199) if (d[i]!=d[i-1]+1) printf("Diff: d(%d)=%d but d(%d)=%d\n",i-1,d[i-1],i,d[i]);
    //FOR(i,1000,1999) if (d[i]!=d[i-1]+1) printf("Diff: d(%d)=%d but d(%d)=%d\n",i-1,d[i-1],i,d[i]);
    //FOR(i,100000,120000) if (d[i]!=d[i-1]+1) printf("Diff: d(%d)=%d but d(%d)=%d\n",i-1,d[i-1],i,d[i]);
}
vector<long long> revPoint;
void getRevPoint(void) {
    pw[0]=1;
    FOR(i,1,17) pw[i]=10*pw[i-1];
    FOR(nDig,4,14) {
        long long mod=pw[nDig-nDig/2];
        long long x=pw[nDig-1]+1+mod;
        while (x<pw[nDig]) {
            revPoint.push_back(x);
            x+=mod;
        }
    }
    sort(ALL(revPoint));
}
long long revNumber(long long x) {
    vector<int> dig;
    while (x>0) {
        dig.push_back(x%10);
        x/=10;
    }
    long long res=0;
    REP(i,dig.size()) res=res*10+dig[i];
    return (res);
}
long long guess(long long x) {
    if (x<=2015) return (d[x]);
    int id=upper_bound(ALL(revPoint),x)-revPoint.begin()-1;
    assert(id>=0);
    long long t=revPoint[id];
    return (guess(revNumber(t))+1+x-t);
}
void check(void) {
    FOR(i,2,MAX-1) assert(guess(i)==d[i]);
}
int main(void) {
    dfs();
    getRevPoint();
    int t;
    scanf("%d",&t);
    FOR(i,1,t) {
        long long x;
        cin>>x;
        cout<<"Case #"<<i<<": "<<guess(x)<<endl;
    }
    return 0;
}
