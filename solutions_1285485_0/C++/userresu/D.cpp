#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int H,W,D,sx,sy;
char in[30][30];
pair<int,int> where[4000][4000];

int dist (int x,int y,int z,int w) {
       return (x-z)*(x-z)+(y-w)*(y-w);
}

int gcd (int a,int b) {
    if (a<b) return gcd(b,a);
    if (!b) return a;
    return gcd(b,a%b);
}
set<pair<int,int> > S;
int main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int z=1;z<=T;++z) {
    S.clear();
    scanf("%d %d %d",&H,&W,&D);
    for (int i=0;i<H;++i) {
        scanf("%s",in[i]);
        for (int j=0;j<W;++j) if (in[i][j]=='X') sx=i,sy=j;
    }
    W-=2;
    H-=2;
    int w=50*D/W+2,h=50*D/H+2;
    where[0][0]=make_pair(sx-1,sy-1);
    for (int i=0;i<h;++i) for (int j=0;j<w;++j) if (i || j) {
        if (!j) where[i][j]=make_pair(2*H*i-1-where[i-1][j].first,where[i-1][j].second);
        else where[i][j]=make_pair(where[i][j-1].first,2*W*j-1-where[i][j-1].second);
    }
    int a=h/2,b=w/2;
    int cnt=0;
    for (int i=0;i<h;++i) for (int j=0;j<w;++j) if ((i!=a || j!=b) && dist(where[i][j].first,where[i][j].second,where[a][b].first,where[a][b].second)<=D*D) {
        pair<int,int> t=make_pair(where[i][j].first-where[a][b].first,where[i][j].second-where[a][b].second);
        int g=gcd(abs(t.first),abs(t.second));
        t.first/=g;
        t.second/=g;
        set<pair<int,int> >::iterator I = S.find(t);
        if (I==S.end()) ++cnt,S.insert(t);
    }
    printf("Case #%d: %d\n",z,cnt);
    }
    return 0;
}
