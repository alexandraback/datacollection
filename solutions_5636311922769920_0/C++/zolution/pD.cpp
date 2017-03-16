#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D-output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int co=1;co<=t;co++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        printf("Case #%d: ",co);
        for(int f=1;f<=a;f++) printf("%d%c",f,(f==a)?'\n':' ');
    }

}
