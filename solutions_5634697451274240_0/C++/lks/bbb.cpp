#include <stdio.h>
#include <string.h>
#define S_SIZE 107
char state[S_SIZE];
int flip_count;

void flip(int top, int bottom)
{
    int i;
    char temp[S_SIZE];
    for(i=top;i<=bottom;i++) temp[bottom-(i-top)] = state[i]=='+'?'-':'+';
    for(i=top;i<=bottom;i++) state[i] = temp[i];
}

void greedy(int top, int bottom)
{
    for(;;)
    {
        int nt = top;
        int nb = bottom;
        while(nb>=top && state[nb] == '+') nb--;
        if(nb<top) break;
        
        // flip start
        // top flip
        while(nt<=bottom && state[nt] == '+') nt++;
        if(nt>top) 
        {
            flip_count++;
            flip(top,nt-1);
        }
        
        // bottom flip... top - nb
        flip_count++;
        flip(top,nb);
        // flip end
    }
    
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
    int T,t;
    scanf("%d", &T);
    for(t=1;t<=T;t++)
    {
        flip_count = 0;
        scanf("%s",state+1);
        int len = strlen(state+1);
        greedy(1,len);
        printf("Case #%d: %d\n",t, flip_count);
    }
    return 0;
}