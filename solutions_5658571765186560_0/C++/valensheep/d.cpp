#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

char s[2000];

bool check(int x,int r,int c){
        if (x == 1) return true;
        else if (x == 2) return (r * c % 2 == 0);
        else if (x == 3) return
                ((r == 2 && c == 3) || (r == 3 && c == 3) || (r == 3 && c == 4));
        else if (x == 4)
                return ((r == 3 && c == 4) || (r == 4 && c == 4));
        else return false;
}

int main(){
        int tt, ca = 0;
        scanf("%d",&tt);
        while (tt--){
                int x,r,c;
                scanf("%d%d%d",&x,&r,&c);
                if (r > c) swap(r,c);
                bool flag = check(x,r,c);
                printf("Case #%d: ", ++ca);
                if (!flag) printf("RICHARD\n");
                else printf("GABRIEL\n");
        }
}
