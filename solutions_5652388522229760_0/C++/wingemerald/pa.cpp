#include <bits/stdc++.h>
using namespace std;

void Solve(int t){
    int x;
    scanf("%d", &x);
    if(x == 0){
        printf("Case #%d: INSOMNIA\n", t);
        return;
    }
    set<char> s;
    for(int i = 1 ; ; i++){
        for( auto j : to_string(i*x))
            s.insert(j);
        if(s.size() == 10){
            printf("Case #%d: %d\n", t, i * x);
            return;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++)
        Solve(i);
    return 0;
}
