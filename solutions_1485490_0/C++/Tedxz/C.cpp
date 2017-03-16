#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
#define For(i,l,r) for(int i=l;i<=r;++i)
#define Cor(i,l,r) for(int i=l;i>=r;--i)
#define MaxN 132
#define Fill(a,b) memset(a,b,sizeof(a))
#define PII pair<lint,lint>
#define FI first
#define SE second
#define MP make_pair

typedef long long lint;

int n,m;
PII a[MaxN],b[MaxN];

void init(){
     scanf("%d%d",&n,&m);
     //scanf("%d%d",&m,&n);
     For(i,1,n) {
         cin >> a[i].SE >>a[i].FI;
     }
     For(i,1,m) cin >>b[i].SE >> b[i].FI;
     int j = 0; 
     while (j < n) {
         ++j;
         while (a[j].FI == a[j + 1].FI && j < n) {
             a[j].SE += a[j + 1].SE; For(i,j + 1,n - 1) a[i] = a[i + 1]; --n;
         }
     }
}

lint gain[MaxN][MaxN][MaxN],Rem[MaxN][MaxN][MaxN];
void pred(){
     Fill(gain,0);
     For(i,1,n) {
                              if(i==2){
                                       int z=i;
                                       }
         For(j,1,m) {
             lint now = 0, rem = a[i].SE;
             For(k,j,m) {
                 if (b[k].FI == a[i].FI) {
                     lint tak = min(rem,b[k].SE);
                     rem -= tak; now += tak;
                 }
                 gain[i][j][k] = now; Rem[i][j][k] = rem;
             }
         }
     }
}

lint f[MaxN][MaxN];
void dp(){
     Fill(f,0);
     For(i,1,n)For(j,1,m) {
                          if(i==2&&j==1){
                                         int z=i;
                                         }
         For(k,0,j) 
             f[i][j] = max(f[i][j],f[i - 1][k] + gain[i][k + 1][j]);
     }
}

int cas;
int main(){ freopen("temp.in","r",stdin); freopen("temp.out","w",stdout);
    cin >> cas;
    For(i,1,cas) {
        printf("Case #%d: ",i); //cout << n << m << endl;
                               if(i == 2){
                                    int z=i;
                                    }
        init();
        pred();
        if (n == 1) cout << gain[1][1][m] << endl;
        if (n == 2) {
            lint ans = 0;
            For(i,1,m) ans = max(ans,gain[1][1][i] + gain[2][i+1][m]);
            cout << ans << endl;
        }
        if(n == 3) {
            dp();
            lint ans = f[n][m];
            if (a[1].FI == a[3].FI) {
                a[1].SE += a[3].SE;
                pred();
                ans = max(ans,gain[1][1][m]);
            }
            cout << ans << endl;
        }
    }
}
