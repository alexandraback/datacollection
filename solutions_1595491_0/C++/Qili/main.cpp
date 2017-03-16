#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int score[110];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T, N, S, p, ans;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d %d %d", &N, &S, &p);
        for(int j = 0; j < N; j++)
            scanf("%d", &score[j]);
        sort(score, score + N, greater<int>());
        ans = 0;
        for(int j = 0; j < N; j++){
            int x = score[j] / 3, y = score[j] % 3;
            if(y == 0){
                if(x >= p){
                    ans++;
                }else if(x > 0 && S > 0 && x + 1 >= p){
                    S--;
                    ans++;
                }
            }else if(y == 2){
                if(x + 1 >= p){
                    ans++;
                }else if(S > 0 && x + 2 >= p){
                    ans++;
                    S--;
                }
            }else {
                if(x + 1 >= p){
                    ans++;
                }
            }
        }
        printf("Case #%d: %d\n", i + 1, ans);
    }
    return 0;
}
