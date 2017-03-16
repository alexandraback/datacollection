#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

int t, n, a, w, cykl, sum, tab[1005], longto[1005];
vector<int> par[1005], v;
bool b[1005], o[1005];

void GS(int l, int deep, int init) {
    o[l]=1;
    if (b[tab[l]]==1) {
        if (deep+1> longto[tab[l]]) {
            longto[tab[l]]=deep+1;
                        //cout<<"longto from  |"<<init<<"|  to  |"<<tab[l]<<"|  changed to: "<<deep+1<<endl;
        }
    } else {
        if (tab[l]==init && cykl < deep) {
            cykl=deep;
                        //cout<<"new longest cycle from  |"<<init<<"|  : "<<deep<<endl;
        } else {
            if (o[tab[l]]==0) {
                GS(tab[l], deep+1, init);
            }
        }
    }
}

int main() {
    int i, j;
    scanf("%d", &t);
    for (j=0; j<t; ++j) {
        scanf("%d", &n);
        fill(tab, tab+1003, 0);
        fill(b, b+1003, 0);
        fill(longto, longto+1003, 0);
        v.clear();
        cykl=0;
        sum=0;
        w=0;
        for (i=0; i<n+2; ++i) {
            par[i].clear();
        }
        for (i=1; i<=n; ++i) {
            scanf("%d", &a);
            tab[i]=a;
            par[a].push_back(i);
            if (a<i && tab[a]==i) {
                //v.push_back(i);
                b[i]=1; longto[i]=1;
                b[a]=1; longto[a]=1;
            }
        }
        for (i=1; i<=n; ++i) {
            if (b[i]==0) {
                GS(i, 1, i);
                fill(o, o+1003, 0);
            }
        }
        for (i=1; i<=n; ++i) {
            if (b[i]==1) {
                sum+=longto[i];
            }
        }
        if (sum>cykl) {
            w=sum;
        } else {
            w=cykl;
        }
        printf("Case #%d: %d\n", j+1, w);
    }
    return 0;
}
