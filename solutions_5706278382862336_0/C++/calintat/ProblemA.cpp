#include <cstdio>
#include <cstring>
using namespace std;
int t,a,b,g,T,k,j,M,c;
double x,y;
char word[100];
int isPowerOfTwo(unsigned int);
int main()
{
    freopen("ProblemA.in","r",stdin);
    freopen("ProblemA.out","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        k=0;a=0;b=0;
        scanf("%s",&word);
        M=strlen(word);
        while(word[k]!='/')
        {
            a=a*10+int(word[k])-48;
            k++;
        }
        for(j=k+1;j<=M-1;j++)
        b=b*10+int(word[j])-48;
        c=b;
        if(isPowerOfTwo(c))
        {
            x=double(a)/double(b);
            g=0;
            while(x<double(1) && g<=39)
            {
                x*=2;
                g++;
            }
            if(g>40)
            printf("Case #%d: impossible\n",t);
            else
            printf("Case #%d: %d\n",t,g);
        }
        else
        printf("Case #%d: impossible\n",t);

    }
}
int isPowerOfTwo (unsigned int x)
{
 while (((x % 2) == 0) && x > 1) /* While x is even and > 1 */
   x /= 2;
 return (x == 1);
}
