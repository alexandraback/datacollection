#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;


int a[110];
int n, N, num, p, ans;




int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out", "w", stdout);
    scanf("%d", &N);
    getchar();
    for(int T = 1;T <= N;T++){
        scanf("%d %d %d", &n, &num, &p);
        ans = 0;
        for(int i = 0;i < n;i++){
            scanf("%d", &a[i]);
            if(a[i]%3 == 0){
                if(a[i]/3 >= p){
                    ans++;
                }
                else if(num > 0 && a[i] != 0){
                    if(a[i]/3+1 >= p){
                        ans++;
                        num--;
                    }
                }
            }else{
                if(a[i]/3 + 1 >= p){
                    ans++;
                }
                else if(num > 0&&a[i]%3 == 2){
                    if(a[i]/3 + 2 >= p){
                        ans++;
                        num--;
                    }
                }
            }
        }
        printf("Case #%d: %d\n", T, ans);
    }
    return 0;
}
