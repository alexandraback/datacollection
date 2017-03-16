#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char s[11111],c1[3],c2[3],g[11111];
int n,cg[33],xx=0;
int main(){
    int i,j,k,l;
    scanf("%d",&n);
    for (i=0;i<26;i++)
        cg[i]=i;
    while (n--){
          scanf("%s %s",c1,c2);
          cg[c1[0]-97]=c2[0]-97;
          //cg[c2[0]-97]=c1[0]-97;
    }
    freopen("a.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d",&n);
    fgets(s,1111,stdin);
    while (n--){
          fgets(s,1111,stdin);
          for (i=0;i<strlen(s)-1;i++)
              if (s[i]==' ') g[i]=' ';
              else g[i]=cg[s[i]-97]+97;
          g[i]=0;
          printf("Case #%d: ",++xx);
          puts(g);
          
    }
    return 0;   
}
