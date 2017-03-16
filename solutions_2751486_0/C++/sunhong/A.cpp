#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A_output_small.txt","w",stdout);
    int T,N;
    int c[101];
    char s[110];
    scanf("%d",&T);
    for (int cases=1;cases<=T;cases++)
    {
        scanf("%s",s);
        scanf("%d",&N);
        int L=strlen(s);
        int maxc=0;
        int counter=0;
        int result=0;
        for (int i=0;i<L;i++)
        {
            maxc=counter=0;
            for (int j=i;j<L;j++)
            {
                if (s[j]=='a' || s[j]=='e' 
                   || s[j]=='i' || s[j]=='o' || s[j]=='u')
                {
                    counter=0;
                }else{
                    counter++;
                    maxc=max(maxc,counter);
                }
                if (maxc>=N) result++;
                //printf("i=%d j=%d result=%d\n",i,j,maxc);
            }
        }
        printf("Case #%d: %d\n",cases,result);
    }
    return 0;
}
