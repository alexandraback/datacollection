#include <cstdio>
#include <iostream>
using namespace std;
int mown[101][101];
int shap[101][101];
bool hor(int n,int m){
     for (int i=0;i<n;++i) for (int j=0;j<m;++j) shap[i][j]=100;
     int ctr;
     for (int i=0;i<n;++i){
         ctr=-1;
         for (int j=0;j<m;++j) if (ctr<mown[i][j]) ctr=mown[i][j];
         for (int j=0;j<m;++j) if (shap[i][j]>ctr) shap[i][j]=ctr;
     }
     for (int j=0;j<m;++j){
         ctr=-1;
         for (int i=0;i<n;++i) if (ctr<mown[i][j]) ctr=mown[i][j];
         for (int i=0;i<n;++i) if (shap[i][j]>ctr) shap[i][j]=ctr;
     }
     for (int i=0;i<n;++i){
         for (int j=0;j<m;++j){
             if (shap[i][j]!=mown[i][j]) return 0;
         }
     }
     return 1;
}
bool ver(int n,int m){
     for (int i=0;i<n;++i) for (int j=0;j<m;++j) shap[i][j]=100;
     int ctr;
     for (int j=0;j<m;++j){
         ctr=-1;
         for (int i=0;i<n;++i) if (ctr<mown[i][j]) ctr=mown[i][j];
         for (int i=0;i<n;++i) if (shap[i][j]>ctr) shap[i][j]=ctr;
     }
     for (int i=0;i<n;++i){
         ctr=-1;
         for (int j=0;j<m;++j) if (ctr<mown[i][j]) ctr=mown[i][j];
         for (int j=0;j<m;++j) if (shap[i][j]>ctr) shap[i][j]=ctr;
     }
     for (int i=0;i<n;++i){
         for (int j=0;j<m;++j){
             if (shap[i][j]!=mown[i][j]) return 0;
         }
     }
     return 1;
}
void solve(){
     int n,m;
     scanf("%d %d",&n,&m);
     for (int i=0;i<n;++i){
         for (int j=0;j<m;++j){
             scanf("%d",&mown[i][j]);
         }
     }
     if (hor(n,m) || ver(n,m)){
        printf("YES\n");
     }
     else printf("NO\n");
}
int main(){
    int ntest;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        printf("Case #%d: ",test);
        solve();
    }
    return 0;
}
