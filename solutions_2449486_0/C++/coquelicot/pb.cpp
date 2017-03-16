#include <cstdio>
#include <algorithm>

int main(){

    int t;
    scanf("%d" ,&t);

    for(int T = 1; T <= t; T++){

        int n, m;
        scanf("%d %d" ,&n ,&m);

        int ary[110][110];
        bool win[110][110];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                win[i][j] = false;
                scanf("%d" ,&ary[i][j]);
            }
        }

        for(int i = 1; i <= n; i++){

            int max = -1;
            for(int j = 1; j <= m; j++) max = std::max(max, ary[i][j]);
            for(int j = 1; j <= m; j++){
                if(ary[i][j] == max) win[i][j] = true;
            }

        }
        for(int i = 1; i <= m; i++){

            int max = -1;
            for(int j = 1; j <= n; j++) max = std::max(max, ary[j][i]);
            for(int j = 1; j <= n; j++){
                if(ary[j][i] == max) win[j][i] = true;
            }

        }

        bool yes = true;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(!win[i][j]) yes = false;
            }
        }

        printf("Case #%d: %s\n" ,T ,yes? "YES": "NO");

    }

}
