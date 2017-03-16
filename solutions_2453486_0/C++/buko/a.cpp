#include<cstdio>
#include<iostream>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<iomanip>
#include<fstream>
#include<ctime>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair <int,int> ii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;

int z,q,sk,i,j,tab[4][4],wyg;
char t[10];

void sprawdz (int a, int b, int c, int d, int &e) {
     if (e!=0) return;
     int tab[4];
     tab[0]=a; tab[1]=b; tab[2]=c; tab[3]=d;
     sort(tab,tab+4);
     if (tab[0]==tab[3] && tab[0]>=1 && tab[0]<=2) e = tab[0];
     else if (tab[0]==tab[2] && tab[0]>=1 && tab[0]<=2 && tab[3]==3) e = tab[0];
}

int main() {
scanf("%d",&z);
for (q=1;q<=z;q++) {
    sk = 1;
    for (i=0;i<4;i++) {
        scanf ("%s",t);
        for (j=0;j<4;j++) if (t[j]=='X') tab[i][j]=1; else if (t[j]=='O') tab[i][j]=2; else if (t[j]=='T') tab[i][j]=3;
        else {
             tab[i][j]=0;
             sk = 0;
        }
    }
    wyg = 0;
    for (i=0;i<4;i++) {
        sprawdz(tab[i][0],tab[i][1],tab[i][2],tab[i][3],wyg);
        sprawdz(tab[0][i],tab[1][i],tab[2][i],tab[3][i],wyg);
    }
    sprawdz(tab[0][0],tab[1][1],tab[2][2],tab[3][3],wyg);
    sprawdz(tab[0][3],tab[1][2],tab[2][1],tab[3][0],wyg);
    printf("Case #%d: ",q);
    if (wyg == 1) printf("X won\n");
    else if (wyg == 2) printf("O won\n");
    else if (wyg == 0 && sk == 1) printf("Draw\n");
    else printf("Game has not completed\n");
}      
return 0;
}
