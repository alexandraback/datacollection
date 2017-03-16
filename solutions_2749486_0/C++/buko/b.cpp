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
const int K = 200;

int xx[4] = {0,0,1,-1};
int yy[4] = {1,-1,0,0};
char kie[4] = {'N', 'S', 'E', 'W'};

int tab[2*K+5][2*K+5],tab1[2*K+5][2*K+5],tab2[2*K+5][2*K+5],a,b,c,i,j,kier[2*K+5][2*K+5],
kier1[2*K+5][2*K+5],kier2[2*K+5][2*K+5],z,q,x,y,xq;
ii w;
queue<ii> kol;
string s;

bool good (int a, int b, int tab[][2*K+5]) {
     if (a<0 || a>2*K || b<0 || b>2*K || tab[a][b] != -1) return false;
     return true;
}

void jedz (int a, int b, int c, int tab[][2*K+5], int kier[][2*K+5]) {
     kol.push(ii(a,b));
     for (i=0;i<=2*K;i++) for (j=0;j<=2*K;j++) tab[i][j]=-1;
     tab[a][b]=c;
     while (kol.size() > 0) {
           w = kol.front();
           kol.pop();
           a = w.first;
           b = w.second;
           c = tab[a][b];
           for (i=0;i<4;i++) if (good(a+xx[i]*(c+1),b+yy[i]*(c+1),tab)) {
               kol.push(ii(a+xx[i]*(c+1),b+yy[i]*(c+1)));
               tab[a+xx[i]*(c+1)][b+yy[i]*(c+1)] = c+1;
               kier[a+xx[i]*(c+1)][b+yy[i]*(c+1)] = i;
           }
     }
}

void szukaj (int tab[][2*K+5], int kier[][2*K+5], int a, int b) {
     while (x!=a || y!=b) {
          s+=kie[kier[x][y]];
          //printf("%d\n",kier[x][y]);
          xq = x-xx[kier[x][y]]*tab[x][y];
          //printf("%d %d %d %d\n",xq,xx[2],xx[kier[x][y]],x);
          y = y-yy[kier[x][y]]*tab[x][y];
          x = xq;
          //printf("%d %d\n",x,y);
    }
}

void sprawdz(string s) {
     int x=0;
     int y=0;
     for (i=0;i<s.size();i++) for (j=0;j<4;j++) if (s[i]==kie[j]) {
         x+=xx[j]*(i+1);
         y+=yy[j]*(i+1);
     }
     printf("%d %d\n",x,y);
}

int main() {
jedz(K,K,0,tab,kier);
jedz(K+1,K,1,tab1,kier1);
jedz(K-1,K,1,tab2,kier2);

/*for (i=K-100;i<=K+100;i++) for (j=K-100;j<=K+100;j++) 
if (tab[i][j]==-1 && tab1[i][j]==-1 && tab2[i][j]==-1) printf("%d %d\n",i,j);
printf("tu\n");*/
scanf("%d",&z);
for (q=1;q<=z;q++) {
    scanf("%d %d",&x,&y);
    x+=K; y+=K;
    s = "";
    if (tab[x][y]!=-1) szukaj(tab,kier,K,K);
    else if (tab1[x][y]!=-1) {
         szukaj(tab1,kier1,K+1,K);
         s+='E';
    }
    else if (tab2[x][y]!=-1) {
         szukaj(tab2,kier2,K-1,K);
         s+='W';
    }
    for (i=0;i<s.size()/2;i++) swap(s[i],s[s.size()-1-i]);
    printf("Case #%d: %s\n",q,s.c_str());
    //sprawdz(s);
}
return 0;
}
