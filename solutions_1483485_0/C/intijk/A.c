#include <stdio.h>
#include <string.h>
 
int main()
{
        char a[128];
        char s[105];
        int n,i,j;
        scanf("%d",&n);
        getchar();
        a['a']='y';
        a['b']='h';
        a['c']='e';
        a['d']='s';
        a['e']='o';
        a['f']='c';
        a['g']='v';
        a['h']='x';
        a['i']='d';
        a['j']='u';
        a['k']='i';
        a['l']='g';
        a['m']='l';
        a['n']='b';
        a['o']='k';
        a['p']='r';
        a['q']='z';
        a['r']='t';
        a['s']='n';
        a['t']='w';
        a['u']='j';
        a['v']='p';
        a['w']='f';
        a['x']='m';
        a['y']='a';
        a['z']='q';
        
        for(i=0;i<n;i++){
                memset(s,0,105);
                scanf("%[^\n]",s);
                getchar();
                for(j=0;j<strlen(s);j++){
                        if(s[j]>='a' && s[j]<='z'){
                                s[j]=a[s[j]];
                        }
                }
                printf("Case #%d: %s\n",i+1,s);
                
        }
        return 0;
}