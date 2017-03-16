#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

char o[1000]="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jvqz";
char t[1000]="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give upzq";
char to[1000];
char in[10000];
int main(){
    int tt,cas=1,i;
    for(i=0;o[i];i++)to[o[i]]=t[i];
    scanf("%d",&tt);
    gets(in);
    while(tt--){
        gets(in);
        printf("Case #%d: ",cas++);
        for(i=0;in[i];i++)putchar(to[in[i]]);
        puts("");
    }
}

