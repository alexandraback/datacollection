#include <iostream>
#include <stdio.h>

using namespace std;

char a[10][10];

int main()
{
    int cases;

    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    scanf("%d", &cases);

    for(int h=0; h<cases; ++h){
        printf("Case #%d: ", h+1);

        int n, m;
        scanf("%d %d", &n, &m);

        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                scanf("%d", &a[i][j]);
            }
        }

        if(n < 2 || m < 2){
            printf("YES\n");
            continue;
        }

        bool done = false;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                char val = a[i][j];
                bool top = false, left = false, right = false, bottom = false;
                for(int k=0;;++k){
                    if(!top    && k<=i  && a[i-k][j] > val) top = true;
                    if(!left   && k<=j  && a[i][j-k] > val) left = true;
                    if(!right  && k+j<m && a[i][j+k] > val) right = true;
                    if(!bottom && k+i<n && a[i+k][j] > val) bottom = true;
                    if((top || bottom) && (left || right) ||
                       k > i && k > j && k+j >=m && k+i >= n)
                        break;
                }
                if((top || bottom) && (left || right)){
                    printf("NO\n");
                    done = true;
                    break;
                }
            }
            if(done) break;
        }
        if(!done)
            printf("YES\n");
    }
    return 0;
}

