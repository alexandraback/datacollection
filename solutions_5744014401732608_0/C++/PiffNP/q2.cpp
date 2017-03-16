#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define LEN 3000
#define FOR(a, b, c) for(int a = (b); a < (c); a++)
int F[100][100];
int ans = 0;
int dfs(int x, int n, int dst){
    if(x == dst){
        ans++;
        return 1;
    } else {
        for(int i = 0; i < n; i++)
            if(F[x][i] != 0)
                dfs(i, n, dst);
        return 1;
    }
    return 0;
}

int main(){
    int t;
    FILE *fp1, *fp2;
    if((fp1 = fopen("a.in", "r")) == NULL)
        return 1;
    fp2 = fopen("a.out", "w");
    fscanf(fp1, "%d", &t);
    for(int tt = 0; tt < t; tt++){
        int B;
        long long M;
        fscanf(fp1, "%d%lld", &B, &M);
        long long MM = M;
        int count = 0;
        long long num = 0;
        long long p = 1;
        for(count = 0; count < B - 2; count++){
            if(M <= p)
                break;
            p = p * 2;
        }
        if(M <= p){
            fprintf(fp2, "Case #%d: POSSIBLE\n", tt + 1);
            long r = p / 2;
            fprintf(fp2, "0");
            //printf("%d\n", count);
            for(int i = count; i > 0; i--){
                fprintf(fp2, "%d", (M >= r? 1: 0));
                if(M >= r)
                    M -= r;
                r = r / 2;
            }
            for(int i = B - count - 2; i > 0; i--)
                fprintf(fp2, "0");
            if(M == 1)
                fprintf(fp2, "1\n");
            else
                fprintf(fp2, "0\n");
            for(int i = count; i > 0; i--){
                fprintf(fp2, "00");
                for(int j = 1; j < count; j++)
                    fprintf(fp2, "%d", (j <= count - i? 0: 1));
                for(int j = B - count - 2; j > 0; j--)
                    fprintf(fp2, "0");                    
                fprintf(fp2, "1\n");
            }
            for(int i = B - count - 1; i > 0; i--){
                for(int i = 0; i < B; i++){
                    fprintf(fp2, "0");
                }
                fprintf(fp2, "\n");
            }
            /*
            ans = 0;

            M = MM;
            r = p / 2;
            FILE *fp3 = fopen("test.txt", "w");
            //printf("%d\n", count);
            fprintf(fp3, "0");
            for(int i = count; i > 0; i--){
                fprintf(fp3, " %d", (M >= r? 1: 0));
                if(M >= r)
                    M -= r;
                r = r / 2;
            }
            for(int i = B - count - 2; i > 0; i--)
                fprintf(fp3, " 0");
            if(M == 1)
                fprintf(fp3, " 1\n");
            else
                fprintf(fp3, " 0\n");
            for(int i = count; i > 0; i--){
                fprintf(fp3, "0 0");
                for(int j = 1; j < count; j++)
                    fprintf(fp3, " %d", (j <= count - i? 0: 1));
                for(int j = B - count - 2; j > 0; j--)
                    fprintf(fp3, " 0");                    
                fprintf(fp3, " 1\n");
            }
            for(int i = B - count - 1; i > 0; i--)
                for(int i = 0; i < B; i++)
                    fprintf(fp3, "0%c", (i == B - 1? '\n': ' '));
            fclose(fp3);
            fp3 = fopen("test.txt", "r");
            for(int i = 0; i < B; i++)
                for(int j = 0; j < B; j++){
                    fscanf(fp3, "%d", &F[i][j]);
                }
            fclose(fp3);
            ans = 0;
            dfs(0, B, B - 1);

            //if(ans != MM){
                printf("Case %d: %d %lld\n", tt + 1, ans, MM);
            //}
            */
        }
        else{
            fprintf(fp2, "Case #%d: IMPOSSIBLE\n", tt + 1);

        }
    }
    return 0;
}
