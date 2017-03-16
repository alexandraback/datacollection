#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

double tans = 0;

double calc(int x, int maxL){
    if(x >= maxL) return 1.0;
    return 0.5;
}

void dfs(int les, int x, int L, int R, int maxL, int Y, double pi){
    if(x == les){
        if(R >= Y){
            tans += pi;
            //cout << R << " " << Y << " " << pi << endl;
        }
        return ;
    }
    if(R + 1 <= maxL) dfs(les, x + 1, L, R + 1, maxL, Y, pi * calc(L, maxL));
    if(L + 1 <= maxL) dfs(les, x + 1, L + 1, R, maxL, Y, pi * calc(R, maxL));
}

int main(){
    freopen("B-small-attempt0.in" , "r", stdin);
    freopen("B.out", "w", stdout);
    int T;scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas){
        int N, X, Y;scanf("%d%d%d", &N, &X, &Y);
        X = abs(X);
        int sum = 0, ceng = 0;
        int add = 1;
        for(int i = 1; ; ++i){
            if(sum + add > N) break;
            sum += add;
            add += 4;
            ceng = i;
        }
        int maxC = (X + Y) / 2 + 1;
        //printf("%d %d %d\n", maxC, ceng, sum);
        printf("Case #%d: ", cas);
        if(maxC <= ceng){
            puts("1.0");
        }
        else {
            double ans = 0;
            int les = N - sum;
            if(maxC > ceng + 1 || Y > les){
                ans = 0;
            }
            else {
                double temp = 1;
                if(X == 0){
                    ans = 0.0;
                }
                else {
                    int maxL = ceng * 2;
                    if(les - maxL >= Y + 1){
                        ans = 1;
                    }
                    else {
                        tans = 0;
                        dfs(les, 0, 0, 0, maxL, Y + 1, 1.0);
                        ans += tans;
                    }
                }
            }
            printf("%.7f\n", ans);
        }
    }
}
