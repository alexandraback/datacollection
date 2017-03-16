#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int n;
char s[1024];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tc;
    scanf("%d", &tc);
    for(int c = 1; c <= tc; c ++){
        scanf("%d %s", &n, s);
        int sum = 0, b = 0;
        for(int i = 1; i <= n; i ++){
            sum += s[i-1] - '0';
            if(s[i] != '0') b = max(b, i - sum);
        }
        printf("Case #%d: %d\n", c, b);
    }
}
