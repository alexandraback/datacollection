
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t,cs=0;
    scanf("%d",&t);
    while(cs++<t){
    
        int x,y;
        scanf("%d%d",&x,&y);

        printf("Case #%d: ",cs);

        if(x>0){
            while(x--) {putchar('W');putchar('E');}
        }
        else{
            x=-x;
            while(x--) {putchar('E');putchar('W');}
        }
    
        if(y>0){
            while(y--) {putchar('S');putchar('N');}
        }
        else{
            y=-y;
            while(y--) {putchar('N');putchar('S');}
        }

        puts("");
    }



    return 0;
}
