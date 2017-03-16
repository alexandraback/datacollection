#include<cstdio>

int Max(int a, int b){return a<b ?b:a;}

int main(){
    int t, n, m, con[100][100], row[100], col[100];

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);


    scanf("%d", &t);
    for (int k=0; k<t; k++){
        bool suc = true;
        scanf("%d%d", &n, &m);

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                scanf("%d", &con[i][j]);
            }
        }

        for (int i=0; i<n; i++) row[i] = 0;
        for (int j=0; j<m; j++) col[j] = 0;

        for (int i=0; i<n; i++) for (int j=0; j<m; j++) row[i] = Max(row[i], con[i][j]);
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) col[j] = Max(col[j], con[i][j]);

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (con[i][j] < row[i] && con[i][j] < col[j])   suc = false;
            }
        }

        printf("Case #%d: ", k + 1);
        if (suc)    puts("YES");
        else    puts("NO");
    }
}
