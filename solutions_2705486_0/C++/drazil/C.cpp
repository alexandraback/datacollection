#include <cstdio>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std ;

set<string> dic ;

int max(int a, int b)
{
    return a>b ? a : b ;
}

char str[4100] ;
int dpt[4100][5] ;

int calc(char *str, int len, int a, int b)
{
    char cpy[20] ;
    int i, j ;
    
    for(i=0;i<len;i++) cpy[i] = str[i] ;
    cpy[i] = '\0' ;
    
    //try origin, i.e. modify 0
    if(dic.find(cpy)!=dic.end()) return 0 ;
    
    //try modify 1
    for(i=a;i<len-b;i++)
    {
        char ori = cpy[i] ;
        char ch ;
        for(ch='a';ch<='z';ch++)
        {
            if(ch==ori) continue ;
            cpy[i] = ch ;
            if(dic.find(cpy)!=dic.end()) return 1 ;
        }
        cpy[i] = ori ;
    }
    
    //try modify 2
    for(i=a;i+5<len-b;i++)
    {
        char ori = cpy[i] ;
        char ch ;
        for(ch='a';ch<='z';ch++)
        {
            if(ch==ori) continue ;
            cpy[i] = ch ;
            for(j=i+5;j<len-b;j++)
            {
                char ori2 = cpy[i] ;
                char ch2 ;
                for(ch2='a';ch2<='z';ch2++)
                {
                    if(ch2==ori2) continue ;
                    cpy[j] = ch2 ;
                    if(dic.find(cpy)!=dic.end()) return 2 ;
                }
                cpy[j] = ori2 ;
            }
        }
        cpy[i] = ori ;
    }
    
    //try modify 3, pos= 0,5,10
    if(len==11&&a==0&&b==0)
    {
        char ori[3] ;
        ori[0] = cpy[0] ;
        ori[1] = cpy[5] ;
        ori[2] = cpy[10] ;
        char ch[3] ;
        for(ch[0]='a';ch[0]<='z';ch[0]++)
        {
            if(ch[0]==ori[0]) continue ;
            cpy[0] = ch[0] ;
            for(ch[1]='a';ch[1]<='z';ch[1]++)
            {
                if(ch[1]==ori[1]) continue ;
                cpy[5] = ch[1] ;
                for(ch[2]='a';ch[2]<='z';ch[2]++)
                {
                    if(ch[2]==ori[2]) continue ;
                    cpy[10] = ch[2] ;
                    if(dic.find(cpy)!=dic.end()) return 3 ;
                }
            }
        }
    }
    
    return -1 ;
}

int main(void)
{
    char tstr[30] ;
    int len = 0 ;
    int i, d ;
    FILE *fp = fopen("dic.txt","r") ;
    while(fgets(tstr,210,fp)!=NULL)
    {
        for(i=0;tstr[i]!='\n';i++) ;
        tstr[i] = '\0' ;
        dic.insert(tstr) ;
    }
    
    fclose(fp) ;
    
    int tc, cas, a, b ;
    
    scanf("%d",&tc) ;
    for(cas=1;cas<=tc;cas++)
    {
        scanf("%s",str) ;
        len = strlen(str) ;
        memset(dpt,0xff,sizeof(dpt)) ;
        dpt[len][0] = dpt[len][1] = dpt[len][2] = dpt[len][3] = dpt[len][4] = 0 ;
        
        for(i=len-1;i>=0;i--)
        {
            for(d=1;d<=11&&i+d<=len;d++)
            {
                for(b=0;b<=4;b++)
                if(dpt[i+d][b]!=-1)
                {
                    for(a=0;a<=4;a++)
                    {
                        int pp = calc(str+i,d,a,b) ;
                        if(pp>=0)
                        {
                            int tans = dpt[i+d][b]+pp ;
                            if(dpt[i][4-a]==-1||tans<dpt[i][4-a])
                            {
                                dpt[i][4-a] = tans ;
                            }
                        }
                    }
                }
            }
        }
        
        int ans = dpt[0][0] ;
        for(a=1;a<5;a++) if(ans>dpt[0][a]||ans==-1) ans = dpt[0][a] ;
        
        printf("Case #%d: %d\n",cas,ans) ;
        fprintf(stderr,"Case #%d: %d\n",cas,ans) ;
    }

    return 0 ;
}
