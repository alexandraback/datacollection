
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#define REP(a,b) for(int a=0;a<(b);a++)
#define PER(a,b) for(int a=(b)-1;a>=0;a--)

int N,J,T;

int main(){
    scanf("%d",&T);
    (T==1);
    scanf("%d %d",&N,&J);
    char str[40];
    printf("Case #1:\n");
    int j=0;
    for(int a=1;a<N-1;a+=2)
      for(int b=a+1;b<N-1;b+=2)
        for(int c=b+1;c<N-1;c+=2)
          for(int d=c+1;d<N-1;d+=2){
            REP(i,N) str[i]='0';
            str[N]=0;
            str[0]='1';
            str[a]='1';
            str[b]='1';
            str[c]='1';
            str[d]='1';
            str[N-1]='1';
            printf("%s 3 2 3 2 7 2 3 2 3\n",str);
            j++;
            if(j==J) return 0;
          }
    return 0;
}

