#include<stdio.h>
#include <algorithm>
#include <string.h>

int lawn[100][100], maxrow[100], maxcol[100], T, n, m;

bool calculate(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if( (lawn[i][j]<maxrow[i]) && (lawn[i][j]<maxcol[j]) ) return false;
        }
    }
    return true;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&T);

    for(int t=0; t<T; t++){
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                scanf("%d",&lawn[i][j]);
            }
        }
        for(int i=0; i<n; i++){
            maxrow[i] = 0;
            for(int j=0; j<m; j++){
                if(lawn[i][j] > maxrow[i]) maxrow[i] = lawn[i][j];
            }
        }
        for(int j=0; j<m; j++){
            maxcol[j] = 0;
            for(int i=0; i<n; i++){
                if(lawn[i][j] > maxcol[j]) maxcol[j] = lawn[i][j];
            }
        }
        if(calculate()) printf("Case #%d: YES\n",t+1);
        else printf("Case #%d: NO\n",t+1);

    }
return 0;
}
