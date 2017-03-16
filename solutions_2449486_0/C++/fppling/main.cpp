#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int n,m;
int a[200][200];
int c[200][200];

/*bool pattern(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            c[i][j] = maxh;

    memset(row, 0, sizeof(int)*200);
    memset(col, 0, sizeof(int)*200);

    bool flag =true;
    while(flag){
       for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == c[i][j]){
                row[i] = 1;
                col[j] = 1;
            }
       for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] < c[i][j]){
                if (row[i] == 1 && col[j] ==1)return false;
                    else if(row[i] == 1){
                        for (int k = 0; k < n; k++)
                            if (a[k][j] > a[i][j]) return false; else
                                c[k][j] = min(c[k][j],a[i][j]);
                            }else if(col[j] == 1){
                                for(int k = 0; k < m; k++)
                                    if(a[i][k] > a[i][j]) return false; else
                                        c[i][k] = min(c[i][k],a[i][j]);
                            }

            }

    }



}*/

bool pattern(){
    for (int i = 0; i < n; i++){
        int maxr = 0;
        for (int j = 0; j < m; j++)
            maxr = max(maxr, a[i][j]);
        for (int j = 0; j < m; j++)
            c[i][j] = maxr;
    }
    for (int j = 0; j < m; j++){
        for (int i = 0; i < n; i++)
        if(c[i][j] > a[i][j]){
            for(int k = 0; k < n; k++){
                if(a[k][j] > a[i][j]) return false;
                c[k][j] = min(c[k][j],a[i][j]);
            }
        }
    }
    return true;
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    //cout << "Hello world!" << endl;
    int t;
    scanf("%d\n",&t);
    for (int k = 0; k < t; k++){
        scanf("%d %d\n",&n, &m);
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            scanf("%d",&a[i][j]);
            c[i][j] = 100;
        }
        if(pattern())
            printf("Case #%d: YES\n",k+1);
        else
            printf("Case #%d: NO\n",k+1);
    }
    return 0;
}
