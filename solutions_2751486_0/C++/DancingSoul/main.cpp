#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int cas, CAS, n, l, i, j, ans;

char s[1000];
int find(int l, int r){
    int now = 0, mx = 0;
    for (int i = l; i <= r; i++)
    if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u'){
        now++;
        mx = max(now, mx);
    }else now = 0;
    return mx >= n;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &CAS);
    for (cas = 1; cas <= CAS; cas++){
        scanf("%s %d", s, &n);
        l = strlen(s);
        ans = 0;
        for (i = 0; i < l; i++)
        for (j = i + n - 1; j < l; j++)
        if (find(i, j)) ans++;
        printf("Case #%d: %d\n", cas, ans);
    }

}
