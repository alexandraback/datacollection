#include "stdio.h"
#include "vector"
#include "map"
#include "set"
#include "iostream"

using namespace std;

int num[50001];

int run()
{
    int res = 0;
    int n;
    scanf("%d", &n);
    char input[10000];
    scanf("%s", input);
    for(; n > 0 && input[n] == '0'; --n) {
        continue;
    }
    int pre = input[0] - '0';
    for(int i = 1; i <= n; ++i) {
        if(pre < i) {
            ++pre;
            ++res;
        }
        pre += input[i] - '0';
    }
    printf("%d\n", res);
    return 0;
}


int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        run();
    }

    return 0;
}











/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */

