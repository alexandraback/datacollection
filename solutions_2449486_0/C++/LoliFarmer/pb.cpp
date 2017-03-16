#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int mat[110][110];
int m,n;
struct S{
    int x,y;
    int val;
}s[100100];
bool cmp(S a,S b){
    return a.val < b.val;
}
int chk(){
    int cc = 0 ;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            s[cc++] = (S){i,j,mat[i][j]};
        }
    }
    sort(s,s+cc,cmp);
    int flagx, flagy;
    for(int k=0;k<cc;k++){
        if(mat[ s[k].x ][ s[k].y ] < 0){
            continue;
        }
        flagx = flagy = 1;
        for(int i=0;i<m && flagx;i++){
            if(mat[ i ][ s[k].y ] > mat[ s[k].x ][ s[k].y ]){
                flagx = 0;
            }
        }
        for(int i=0;i<n && flagy;i++){
            if(mat[ s[k].x ][ i ] > mat[ s[k].x ][ s[k].y ]){
                flagy = 0;
            }
        }
        for(int i=0;i<m && flagx;i++){
            mat[i][s[k].y] = -1;
        }
        for(int i=0;i<n && flagy;i++){
           mat[ s[k].x ][ i ] = -1;
        }
        if(flagx == 0 && flagy == 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int f = 1; f<=T ; f++){
        scanf("%d%d",&m,&n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&mat[i][j]);
            }
        }
        printf("Case #%d: ",f);
        if(chk()==1){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
