#include <bits/stdc++.h>
using namespace std;

void Solve(int t){
    char s[128];
    scanf("%s", s);
    int len = strlen(s);
    int ans = s[0] == '-'; 
    for(int i = 0 ; i + 1 < len ; i++){
        if(s[i] == '+' && s[i+1] == '-')
            ans += 2;
    }
    printf("Case #%d: %d\n", t, ans);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++)
        Solve(i);
    return 0;
}
