
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define REP(a,b) for(int a=0;a<(b);a++)
#define PER(a,b) for(int a=(b)-1;a>=0;a--)

int T;
char str[110];

int main(){
    scanf("%d",&T);
    REP(i,T){
        scanf("%s",&str);
        char c='+';
        int count=0;
        PER(j,strlen(str))
            if(str[j]!=c){
                c=str[j];
                count++;
            }
        printf("Case #%d: %d\n",i+1,count);
    }
    return 0;
}

