#include <iostream>
#include<cstring>
#include<stdio.h>
#define lgmax 25
using namespace std;
int card, crez, n, nr1, nr2, v[50][5], ls, ex1[50], ex2[50], sol[50], t, ii;
bool ok;
char c1[lgmax], c2[lgmax], dict1[100][50][lgmax], dict2[100][50][lgmax];

bool egal(char s1[lgmax], char s2[lgmax]){
    if (strlen(s1)!=strlen(s2))
        return 0;
    ls=strlen(s1);
    for (int i=0;i<ls;i++)
        if (s1[i]!=s2[i])
            return 0;
    return 1;
}

void verificare(){
    for (int i=1;i<=nr1;i++)
        ex1[i]=0;
    for (int i=1;i<=nr2;i++)
        ex2[i]=0;
    for (int i=1;i<=n;i++)
        if (sol[i]==1){
            ex1[v[i][1]]=1;
            ex2[v[i][2]]=1;
        }
    ok=1;
    for (int i=1;((i<=nr1)&&(ok));i++)
        ok&=(ex1[i]==1);
    for (int i=1;((i<=nr2)&&(ok));i++)
        ok&=(ex2[i]==1);
    if ((ok) && ((card<crez)||(crez==-1)))
        crez=card;
}

bool gen(int poz){
    if (poz==n+1)
        verificare();
    else
        if ((card<crez) || (crez==-1))
        {
            sol[poz]=0;
            gen(poz+1);
            sol[poz]=1;
            card++;
            gen(poz+1);
            card--;
        }
}

int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    scanf("%d",&t);
    for (ii=1;ii<=t;ii++){
        scanf("%d",&n);
        nr1=nr2=0;
        for (int i=1;i<=n;i++){
            v[i][1]=v[i][2]=0;
            scanf("%s %s\n",&c1,&c2);
            for (int j=1;j<=nr1;j++)
                if (egal(dict1[ii][j],c1)){
                    v[i][1]=j;
                    break;
                }
            if (v[i][1]==0){
                nr1++;
                ls=strlen(c1);
                for (int j=0;j<ls;j++)
                    dict1[ii][nr1][j]=c1[j];
                //dict1[nr1][ls]='\n';
                v[i][1]=nr1;
            }
            for (int j=1;j<=nr2;j++)
                if (egal(dict2[ii][j],c2)){
                    v[i][2]=j;
                    break;
                }
            if (v[i][2]==0){
                nr2++;
                ls=strlen(c2);
                for (int j=0;j<ls;j++)
                    dict2[ii][nr2][j]=c2[j];
                //dict2[nr2][ls]='\n';
                v[i][2]=nr2;
            }
        }
        card=0; crez=-1;
        gen(1);
        printf("Case #%d: %d\n",ii,n-crez);
    }
    return 0;
}
