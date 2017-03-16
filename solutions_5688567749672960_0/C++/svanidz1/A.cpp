#include <bits/stdc++.h>
#define MA(a,b) ((a)>(b)?(a):(b))
#define MI(a,b) ((a)<(b)?(a):(b))
#define AB(a) (-(a)<(a)?(a):-(a))
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define ep 0.00000001
#define pi 3.1415926535897932384626433832795
#define na(x) ((x)<P?(x):(x)-P)
using namespace std;
int a[1000222];
inline int g(int x){
    int y=0;
    while (x){
        y=y*10+x%10;
        x/=10;
    }
    return y;
}
int main() {
    freopen("A1.in","r",stdin);
    freopen("text.txt","w",stdout);

    queue<int> Q;
    Q.push(1);
    a[1]=1;
    int x,y;
    while (Q.size()){
        x=Q.front();
        Q.pop();
        y=x+1;
        if (y<=1000000 && a[y]==0) a[y]=a[x]+1,Q.push(y);
        y=g(x);
        if (y<=1000000 && a[y]==0) a[y]=a[x]+1,Q.push(y);
    }
    int t;
    cin>>t;
    for (int tt=1;tt<=t;tt++){
        scanf("%d",&x);
        printf("Case #%d: %d\n",tt,a[x]);
    }
    return 0;
}
