#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
int TC;
char str[1000];
int n;
int main(){
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; ++tc){
        scanf("%s", str);
        n = strlen(str);
        int ans = 0;
        for(int i = 1; i < n; ++i) ans += (str[i] != str[i-1]);
        ans += (str[n-1] != '+');
        printf("Case #%d: %d\n", tc, ans);
    }
}
