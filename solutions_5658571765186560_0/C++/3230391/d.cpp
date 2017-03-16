#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void){
    int t, x, r, c, ys = 0;
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    scanf("%d", &t);
    while (t--){
        cin>>x>>r>>c;
        int ans = 0;
        if (x==1) ans = 1;
        else if (x==2){
            if (r%2==0 || c%2==0) ans = 1;
        }else  if (x==3){
            if (r%3==0 && c>1) ans = 1;
            if (c%3==0 && r>1) ans = 1;
        }else if (x==4){
            if (r%4==0 && c>2) ans = 1;
            if (r>2 && c%4==0) ans = 1;  
        }
        if (ans==1)
            printf("Case #%d: GABRIEL\n", ++ys);
        else printf("Case #%d: RICHARD\n", ++ys);
    }
    return 0;
}
