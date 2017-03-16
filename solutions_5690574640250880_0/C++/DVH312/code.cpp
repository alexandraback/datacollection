#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <ctime>

using namespace std;

#define F1 "code.inp"
#define F2 "code.out"

const int inf=1000000000;
const int md=1000000007;
const double esp=0.000000000001;
typedef pair<int,int>ii;

char a[55][55];
int r,c,m;
int init(){
    for (int i=1;i<=50;i++){
        for (int j=1;j<=50;j++){
            a[i][j]='.';
        }
    }
    return 0;
}

int read(){
    scanf("%d %d %d",&r,&c,&m);
    return 0;
}
int xuat(){
//    printf("%d\n",m);
    a[r][c]='c';
    for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++) printf("%c",a[i][j]);
        printf("\n");
    }
}
int process(){
    if (m==0){
        xuat();
        return 0;
    }
    if (r*c-m==1){
        for (int i=1;i<=r;i++){
            for (int j=1;j<=c;j++) a[i][j]='*';
        }
        xuat();
        return 0;
    }
    // r||c ==1
    if (r==1){
        for (int i=1;i<=m;i++) a[1][i]='*';
        xuat();
        return 0;
    }
    if (c==1){
        for (int i=1;i<=m;i++) a[i][1]='*';
        xuat();
        return 0;
    }
    // r||c ==2
    if (r==2){
        for (int j=1;j<=c-2;j++){
            if (m>1){
                m-=2;
                a[1][j]='*';
                a[2][j]='*';
            }
        }
        if (m>0) printf("Impossible\n");
        else xuat();
        return 0;
    }
    if (c==2){
        for (int i=1;i<=r-2;i++){
            if (m>1){
                m-=2;
                a[i][1]='*';
                a[i][2]='*';
            }
        }
        if (m>0) printf("Impossible\n");
        else xuat();
        return 0;
    }
    // r && c >=3
    for (int i=1;i<=r-2;i++){
        for (int j=1;j<=c-2;j++){
            if (m==0)break;
            a[i][j]='*';
            m--;
        }
    }
    if (m==0){
        xuat();
        return 0;
    }
    for (int i=1;i<=r-3;i++){
        if (m>1){
            m-=2;
            a[i][c-1]='*';
            a[i][c]='*';
        } else if (m==1){
            a[i][c-1]='*';
            a[i][c]='*';
            a[r-2][c-2]='.';
            m=0;
        } else break;
    }
    for (int j=1;j<=c-3;j++){
        if (m>1){
            m-=2;
            a[r-1][j]='*';
            a[r][j]='*';
        } else if (m==1){
            a[r-1][j]='*';
            a[r][j]='*';
            a[r-2][c-2]='.';
            m=0;
        } else break;
    }
    if (m==0){
        xuat();
        return 0;
    }
    if (m>4 || m%2==1){
        printf("Impossible\n");
        return 0;
    }
    if (m>=2){
        a[r-2][c-1]='*';
        a[r-2][c]='*';
    }
    if (m==4){
        a[r-1][c-2]='*';
        a[r][c-2]='*';
    }
    xuat();
    return 0;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen(F1,"r",stdin);
    freopen(F2,"w",stdout);
    #endif // ONLINE_JUDGE
    int sotest;
    scanf("%d",&sotest);
//    sotest=1;
    for (int test=1;test<=sotest;test++){
        init();
        printf("Case #%d:\n",test);
        read();
        process();
    }

    return 0;
}
