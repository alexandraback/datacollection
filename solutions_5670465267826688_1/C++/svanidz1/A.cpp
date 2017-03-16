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
char c[1000000];
int a[8][8];
int fx[100],ft;
bool sol1(int n,long long m){
        //jami -1
    int x=0;
    for (int i=0;i<n;i++)
    x=a[x][c[i]];
    int y=0;
    m%=4;
    for (int i=0;i<m;i++) y=a[y][x];
    return (y==4);
}
long long pr(int n,long long m){
    ft++;
    int y=0;
    int mm=0;
    while (fx[y]!=ft && 1ll+mm<=m){
        fx[y]=ft;for (int i=0;i<n;i++){
            y=a[y][c[i]];
            if (y==1) return 1ll*mm*n+i+1;
            }
        mm++;

    }
    return m*n+1;
}
long long su(int n,long long m){
    ft++;
    int y=0;
    int mm=0;
    while (fx[y]!=ft && 1ll+mm<=m){

        fx[y]=ft;for (int i=n-1;i>=0;i--){
            y=a[c[i]][y];
            if (y==3) return 1ll*mm*n+n-i;
            }
        mm++;
    }
    return m*n+1;
}
bool sol2(int n,long long m){
    return (pr(n,m)+su(n,m)<m*n);
}
void pre(){
    for (int i=0;i<8;i++)
    for (int j=0;j<8;j++)
    if (i==0 || j==0) a[i][j]=i+j;
    else
    if (i==4 || j==4) a[i][j]=(i+j)%8;
    else
    if (i==j) a[i][j]=4;
    else
    if (AB(i-j)==4) a[i][j]=0;
    else
    if (i==1){
        if (j==2) a[i][j]=3;
        if (j==3) a[i][j]=6;
        if (j==6) a[i][j]=7;
        if (j==7) a[i][j]=2;
    } else
    if (i==2){
        if (j==1) a[i][j]=7;
        if (j==3) a[i][j]=1;
        if (j==5) a[i][j]=3;
        if (j==7) a[i][j]=5;
    } else
    if (i==3){
        if (j==1) a[i][j]=2;
        if (j==2) a[i][j]=5;
        if (j==5) a[i][j]=6;
        if (j==6) a[i][j]=1;
    } else
    if (i==5){
        if (j==2) a[i][j]=7;
        if (j==3) a[i][j]=2;
        if (j==6) a[i][j]=3;
        if (j==7) a[i][j]=6;
    } else
    if (i==6){
        if (j==1) a[i][j]=3;
        if (j==3) a[i][j]=5;
        if (j==5) a[i][j]=7;
        if (j==7) a[i][j]=1;
    } else
    if (i==7){
        if (j==1) a[i][j]=6;
        if (j==2) a[i][j]=1;
        if (j==5) a[i][j]=2;
        if (j==6) a[i][j]=5;
    }
}

int main() {
	pre();
    freopen("C2.in","r",stdin);
	freopen("ans.txt","w",stdout);
	int T;
	cin>>T;
	int n;
	long long m;
	int test=0;
	while (T--){
        scanf("%d%lld",&n,&m);
        scanf("%s",&c);
        for (int i=0;i<n;i++) c[i]=(c[i]=='i'?1:c[i]=='j'?2:3);
        if (sol1(n,m) && sol2(n,m))
        printf("Case #%d: YES\n",++test); else
        printf("Case #%d: NO\n",++test);
	}
	return 0;
}
