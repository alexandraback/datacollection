#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=10;

int n,m;
bool a[maxn];

void add(int pos) {
    if(!a[pos])m++;
    a[pos]=1;
}

void f(int x) {
    if(x==0) {
        add(0);
        return;
    }
    while(x) {
        add(x%10);
        x/=10;
    }
}

int main() {
    //freopen("in.cpp","r",stdin);
    freopen("A-small-attempt0 .in","r",stdin);
    freopen("out","w",stdout);
    int ncase=0;
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        m=0;
        memset(a,0,sizeof(a));
        bool sign=0;
        f(n);
        for(int i=2; i<=100; i++) {
            f(i*n);
            if(m==10) {
                sign=1;
                printf("Case #%d: %d\n",++ncase,n*i);
                break;
            }
        }
        if(!sign)printf("Case #%d: INSOMNIA\n",++ncase);
    }
    return 0;
}
