#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct X {
    static const int f1[4][4],f2[4][4];
    int v,sign;
    X(int v=0,int sign=1):v(v),sign(sign) {};
    X operator * (const X &o) const {
        return X(f1[v][o.v],sign*o.sign*f2[v][o.v]);
    }
    operator int () {
        return v+(sign==-1)*4;
    }
};
const int X::f1[4][4]={{0,1,2,3},
                       {1,0,3,2},
                       {2,3,0,1},
                       {3,2,1,0}};
const int X::f2[4][4]={{1,1,1,1},
                       {1,-1,1,-1},
                       {1,-1,-1,1},
                       {1,1,-1,-1}};
const int N = 10007;
char str[N];
X ans[N];

int fir[10],last[10];
X lst[10];
bool test(int n,long long x) {
    for (int i=1;i<=3;++i)
        lst[i]=lst[i-1]*ans[n];
    if (lst[x%4]!=X(0,-1)) return false;
    long long posi=n*x,posj=-1,tmp=x/4*4;
    for (long long i=0;i<4&&i<x;++i) {
        if (tmp==x) tmp-=4;
        for (int v=0;v<4;++v) {
            //cout << lst[i] << ' ' << (lst[i]*X(v)==X(3)) << ' ' << (lst[i]*X(v,-1)==X(3)) << endl;
            //cout << last[X(v)] << ' ' << last[X(v,-1)] << endl;

            if (lst[i]*X(v)==X(1)&&fir[X(v)]!=-1)
                posi=min(posi,i*n+fir[X(v)]);
            if (lst[i]*X(v,-1)==X(1)&&fir[X(v,-1)]!=-1)
                posi=min(posi,i*n+fir[X(v,-1)]);
            if (lst[i]*X(v)==X(3)&&last[X(v)]!=-1)
                posj=max(posj,tmp*n+last[X(v)]);
            if (lst[i]*X(v,-1)==X(3)&&last[X(v,-1)]!=-1)
                posj=max(posj,tmp*n+last[X(v,-1)]);

        }
        ++tmp;
    }
    //cout << posi << ' ' << posj << endl;
    return posi<posj;

}
int main() {
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int T,cas,n;
    long long x;
    cin >> T;
    while (T--) {
        memset(fir,-1,sizeof fir);
        memset(last,-1,sizeof last);
        cin >> n >> x;
        cin >> str;
        for (int i=0;i<n;++i) {
            ans[i+1]=ans[i]*X(str[i]-'i'+1);
            if (fir[ans[i+1]]==-1) fir[ans[i+1]]=i;
            last[ans[i+1]]=i;
        }
        printf("Case #%d: %s\n",++cas,test(n,x)?"YES":"NO");
    }
    return 0;
}
