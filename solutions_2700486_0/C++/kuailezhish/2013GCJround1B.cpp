//made by kuailezhish
//gl && hf
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <cstdlib>
#include <string>
#include <stack>
#include <sstream>
#include <cstring>
#include <ctime>
#define mem(a,b) memset(a,b,sizeof(a));
#define INF 0x3f3f3f3f
#define lldINF 0x3f3f3f3f3f3f3f3fll
#define eps 1e-8
#define lld long long
#define sqr(x) ((x)*(x))
#define ab(x) (((x)>0) ? (x) : -(x))
#define PI 3.14159265358979323846
#define psl pair<sting,lld>
#define pll pair<lld,lld>
#define pii pair<int,int>
#define MP make_pair
#define er(i) (1ll<<(i))
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define rin freopen("in.txt","r",stdin)
#define pout freopen("out.txt","w",stdout)
#pragma comment(linker, "/STACK:102400000,102400000")
using std::bitset;
using namespace std;

int a[200][200];
#define f(i,j) a[(i)+100][(j)+100]
int x,y,n;

double cau(){
    int i,j,tem;
    double ans=0;
    if (n==1){
        if (x==0 && y==0) return 1;
        return 0;
    }
    if (n==2){
        if (x==0 && y==0) return 1;
        if (x==-2 && y==0) return 0.5;
        if (x==2 && y==0) return 0.5;
        return 0;
    }
    if (n==3){
        if (x==0 && y==0) return 1;
        if (x==-2 && y==0) return 0.75;
        if (x==2 && y==0) return 0.75;
        if (x==-1 && y==1) return 0.25;
        if (x==1 && y==1) return 0.25;
        return 0;
    }
    if (n==4){
        if (x==0 && y==0) return 1;
        if (x==-2 && y==0) return 1;
        if (x==2 && y==0) return 1;
        if (x==-1 && y==1) return 0.5;
        if (x==1 && y==1) return 0.5;
        return 0;
    }
    if (n==5){
        if (x==0 && y==0) return 1;
        if (x==-2 && y==0) return 1;
        if (x==2 && y==0) return 1;
        if (x==-1 && y==1) return 1;
        if (x==1 && y==1) return 1;
        return 0;
    }
    if (n==6){
        if (x==0 && y==0) return 1;
        if (x==-2 && y==0) return 1;
        if (x==2 && y==0) return 1;
        if (x==-1 && y==1) return 1;
        if (x==1 && y==1) return 1;
        if (x==0 && y==2) return 1;
        return 0;
    }
    if (n==7){
        if (x==0 && y==0) return 1;
        if (x==-2 && y==0) return 1;
        if (x==2 && y==0) return 1;
        if (x==-1 && y==1) return 1;
        if (x==1 && y==1) return 1;
        if (x==0 && y==2) return 1;
        if (x==-4 && y==0) return 0.5;
        if (x==4 && y==0) return 0.5;
        return 0;
    }
    if (n==8){
        if (x==0 && y==0) return 1;
        if (x==-2 && y==0) return 1;
        if (x==2 && y==0) return 1;
        if (x==-1 && y==1) return 1;
        if (x==1 && y==1) return 1;
        if (x==0 && y==2) return 1;
        if (x==-4 && y==0) return 0.75;
        if (x==4 && y==0) return 0.75;
        if (x==-3 && y==1) return 0.25;
        if (x==3 && y==1) return 0.25;
        return 0;
    }
    if (n==9){
        if (x==0 && y==0) return 1;
        if (x==-2 && y==0) return 1;
        if (x==2 && y==0) return 1;
        if (x==-1 && y==1) return 1;
        if (x==1 && y==1) return 1;
        if (x==0 && y==2) return 1;
        if (x==-4 && y==0) return 7.0/8;
        if (x==4 && y==0) return 7.0/8;
        if (x==-3 && y==1) return 0.5;
        if (x==3 && y==1) return 0.5;
        if (x==-2 && y==2) return 0.125;
        if (x==2 && y==2) return 0.125;
        return 0;
    }
    if (n==10){
        if (x==0 && y==0) return 1;
        if (x==-2 && y==0) return 1;
        if (x==2 && y==0) return 1;
        if (x==-1 && y==1) return 1;
        if (x==1 && y==1) return 1;
        if (x==0 && y==2) return 1;
        if (x==-4 && y==0) return 15.0/16;
        if (x==4 && y==0) return 15.0/16;
        if (x==-3 && y==1) return 11.0/16;
        if (x==3 && y==1) return 11.0/16;
        if (x==-2 && y==2) return 5.0/16;
        if (x==2 && y==2) return 5.0/16;
        if (x==-1 && y==3) return 1.0/16;
        if (x==1 && y==3) return 1.0/16;
        return 0;
    }
    if (n==11){
        if (x==0 && y==0) return 1;
        if (x==-2 && y==0) return 1;
        if (x==2 && y==0) return 1;
        if (x==-1 && y==1) return 1;
        if (x==1 && y==1) return 1;
        if (x==0 && y==2) return 1;
        if (x==-4 && y==0) return 1;
        if (x==4 && y==0) return 1;
        if (x==-3 && y==1) return 13.0/16;
        if (x==3 && y==1) return 13.0/16;
        if (x==-2 && y==2) return 8.0/16;
        if (x==2 && y==2) return 8.0/16;
        if (x==-1 && y==3) return 3.0/16;
        if (x==1 && y==3) return 3.0/16;
        return 0;
    }
    if (n==12){
        if (x==0 && y==0) return 1;
        if (x==-2 && y==0) return 1;
        if (x==2 && y==0) return 1;
        if (x==-1 && y==1) return 1;
        if (x==1 && y==1) return 1;
        if (x==0 && y==2) return 1;
        if (x==-4 && y==0) return 1;
        if (x==4 && y==0) return 1;
        if (x==-3 && y==1) return 1;
        if (x==3 && y==1) return 1;
        if (x==-2 && y==2) return 21.0/32;
        if (x==2 && y==2) return 21.0/32;
        if (x==-1 && y==3) return 11.0/32;
        if (x==1 && y==3) return 11.0/32;
        return 0;
    }
    if (n==13){
        if (x==0 && y==0) return 1;
        if (x==-2 && y==0) return 1;
        if (x==2 && y==0) return 1;
        if (x==-1 && y==1) return 1;
        if (x==1 && y==1) return 1;
        if (x==0 && y==2) return 1;
        if (x==-4 && y==0) return 1;
        if (x==4 && y==0) return 1;
        if (x==-3 && y==1) return 1;
        if (x==3 && y==1) return 1;
        if (x==-2 && y==2) return 1;
        if (x==2 && y==2) return 1;
        if (x==-1 && y==3) return 16.0/32;
        if (x==1 && y==3) return 16.0/32;
        return 0;
    }
    if (n==14){
        if (x==0 && y==0) return 1;
        if (x==-2 && y==0) return 1;
        if (x==2 && y==0) return 1;
        if (x==-1 && y==1) return 1;
        if (x==1 && y==1) return 1;
        if (x==0 && y==2) return 1;
        if (x==-4 && y==0) return 1;
        if (x==4 && y==0) return 1;
        if (x==-3 && y==1) return 1;
        if (x==3 && y==1) return 1;
        if (x==-2 && y==2) return 1;
        if (x==2 && y==2) return 1;
        if (x==-1 && y==3) return 1;
        if (x==1 && y==3) return 1;
        return 0;
    }
    if (n==15){
        if (x==0 && y==0) return 1;
        if (x==-2 && y==0) return 1;
        if (x==2 && y==0) return 1;
        if (x==-1 && y==1) return 1;
        if (x==1 && y==1) return 1;
        if (x==0 && y==2) return 1;
        if (x==-4 && y==0) return 1;
        if (x==4 && y==0) return 1;
        if (x==-3 && y==1) return 1;
        if (x==3 && y==1) return 1;
        if (x==-2 && y==2) return 1;
        if (x==2 && y==2) return 1;
        if (x==-1 && y==3) return 1;
        if (x==1 && y==3) return 1;
        if (x==0 && y==4) return 1;
        return 0;
    }
    if (n==16){
        if (x==0 && y==0) return 1;
        if (x==-2 && y==0) return 1;
        if (x==2 && y==0) return 1;
        if (x==-1 && y==1) return 1;
        if (x==1 && y==1) return 1;
        if (x==0 && y==2) return 1;
        if (x==-4 && y==0) return 1;
        if (x==4 && y==0) return 1;
        if (x==-3 && y==1) return 1;
        if (x==3 && y==1) return 1;
        if (x==-2 && y==2) return 1;
        if (x==2 && y==2) return 1;
        if (x==-1 && y==3) return 1;
        if (x==1 && y==3) return 1;
        if (x==0 && y==4) return 1;
        if (x==-6 && y==0) return 0.5;
        if (x==6 && y==0) return 0.5;
        return 0;
    }
    if (n==17){
        if (x==0 && y==0) return 1;
        if (x==-2 && y==0) return 1;
        if (x==2 && y==0) return 1;
        if (x==-1 && y==1) return 1;
        if (x==1 && y==1) return 1;
        if (x==0 && y==2) return 1;
        if (x==-4 && y==0) return 1;
        if (x==4 && y==0) return 1;
        if (x==-3 && y==1) return 1;
        if (x==3 && y==1) return 1;
        if (x==-2 && y==2) return 1;
        if (x==2 && y==2) return 1;
        if (x==-1 && y==3) return 1;
        if (x==1 && y==3) return 1;
        if (x==0 && y==4) return 1;
        if (x==-6 && y==0) return 0.75;
        if (x==6 && y==0) return 0.75;
        if (x==-5 && y==1) return 0.25;
        if (x==5 && y==1) return 0.25;
        return 0;
    }
    if (n==18){
        if (x==0 && y==0) return 1;
        if (x==-2 && y==0) return 1;
        if (x==2 && y==0) return 1;
        if (x==-1 && y==1) return 1;
        if (x==1 && y==1) return 1;
        if (x==0 && y==2) return 1;
        if (x==-4 && y==0) return 1;
        if (x==4 && y==0) return 1;
        if (x==-3 && y==1) return 1;
        if (x==3 && y==1) return 1;
        if (x==-2 && y==2) return 1;
        if (x==2 && y==2) return 1;
        if (x==-1 && y==3) return 1;
        if (x==1 && y==3) return 1;
        if (x==0 && y==4) return 1;
        if (x==-6 && y==0) return 7.0/8;
        if (x==6 && y==0) return 7.0/8;
        if (x==-5 && y==1) return 0.5;
        if (x==5 && y==1) return 0.5;
        if (x==-4 && y==2) return 0.125;
        if (x==4 && y==2) return 0.125;
        return 0;
    }
    if (n==19){
        if (x==0 && y==0) return 1;
        if (x==-2 && y==0) return 1;
        if (x==2 && y==0) return 1;
        if (x==-1 && y==1) return 1;
        if (x==1 && y==1) return 1;
        if (x==0 && y==2) return 1;
        if (x==-4 && y==0) return 1;
        if (x==4 && y==0) return 1;
        if (x==-3 && y==1) return 1;
        if (x==3 && y==1) return 1;
        if (x==-2 && y==2) return 1;
        if (x==2 && y==2) return 1;
        if (x==-1 && y==3) return 1;
        if (x==1 && y==3) return 1;
        if (x==0 && y==4) return 1;
        if (x==-6 && y==0) return 15.0/16;
        if (x==6 && y==0) return 15.0/16;
        if (x==-5 && y==1) return 11.0/16;
        if (x==5 && y==1) return 11.0/16;
        if (x==-4 && y==2) return 5.0/16;
        if (x==4 && y==2) return 5.0/16;
        if (x==-3 && y==3) return 1.0/16;
        if (x==3 && y==3) return 1.0/16;
        return 0;
    }
    if (n==20){
        if (x==0 && y==0) return 1;
        if (x==-2 && y==0) return 1;
        if (x==2 && y==0) return 1;
        if (x==-1 && y==1) return 1;
        if (x==1 && y==1) return 1;
        if (x==0 && y==2) return 1;
        if (x==-4 && y==0) return 1;
        if (x==4 && y==0) return 1;
        if (x==-3 && y==1) return 1;
        if (x==3 && y==1) return 1;
        if (x==-2 && y==2) return 1;
        if (x==2 && y==2) return 1;
        if (x==-1 && y==3) return 1;
        if (x==1 && y==3) return 1;
        if (x==0 && y==4) return 1;
        if (x==-6 && y==0) return 31.0/32;
        if (x==6 && y==0) return 31.0/32;
        if (x==-5 && y==1) return 26.0/32;
        if (x==5 && y==1) return 26.0/32;
        if (x==-4 && y==2) return 16.0/32;
        if (x==4 && y==2) return 16.0/32;
        if (x==-3 && y==3) return 6.0/32;
        if (x==3 && y==3) return 6.0/32;
        if (x==-2 && y==4) return 1.0/32;
        if (x==2 && y==4) return 1.0/32;
        return 0;
    }
}

int main(){
    int i,j,tem,T,cas=0;
freopen("B-small-attempt0.in","r",stdin);
pout;
    scanf("%d",&T);
    while (T--){
        scanf("%d%d%d",&n,&x,&y);
        double ans=cau();
        printf("Case #%d: %.8lf\n",++cas,ans);
    }
    return 0;
}






















