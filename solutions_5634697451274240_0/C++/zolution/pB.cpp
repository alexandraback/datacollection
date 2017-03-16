#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int co1=1;co1<=t;co1++){
        char s[105];
        scanf("%s",s);
        int len = strlen(s);
        int co=0;
        char prev=s[len-1];
        for(int t=len-2;t>=0;t--){
            if(s[t]!=prev) co++;
            prev=s[t];
        }
        co+=((s[len-1]=='-')?1:0);
        printf("Case #%d: %d\n",co1,co);

    }

}
