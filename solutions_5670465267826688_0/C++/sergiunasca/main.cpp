#include <stdio.h>
#include <string.h>
using namespace std;
int t,l,kl,sign;
char a[10008];
char b[10008],el;
bool x,y,z;
void inmultire(char &A,char B)
{
    if(A=='i'&&B=='j')A = 'k';
    else if(A=='i'&&B=='k')A = 'j',sign = sign*(-1);
    else if(A=='j'&&B=='i')A = 'k',sign = sign*(-1);
    else if(A=='j'&&B=='k')A = 'i';
    else if(A=='k'&&B=='i')A = 'j';
    else if(A=='k'&&B=='j')A = 'i',sign = sign*(-1);
}
int main()
{
    freopen("text.in","r",stdin);
    freopen("text.out","w",stdout);
    scanf("%d",&t);
    for(int k=1;k<=t;++k)
    {
        printf("Case #%d: ",k);
        scanf("%d %d ",&l,&kl);
        scanf("%s",&a);
        strcpy(b,a);
        x = false;y = false;z = false;
        for(int i=2;i<=kl;++i)strcat(a,b);
        sign = 1;el = a[0];
        if(el=='i')x = true;
        for(int i=1;i<strlen(a);++i)
        {
            if(el==a[i])
            {
                el = 0;
                sign = sign*(-1);
            }
            else if(el==0)el = a[i];
            else inmultire(el,a[i]);
            if(el=='i'&&sign==1)x = true;
            else if(el=='k'&&sign==1)y = true;
        }
        if(el==0&&sign==-1)z = true;
        if(x&&y&&z)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
