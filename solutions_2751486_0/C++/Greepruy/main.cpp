#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;
const long double epx=0.000001;

int main()
{
    //freopen("A-large.in","r",stdin);freopen("A-large.in","r",stdin);
    freopen("A-small-attempt0.in","r",stdin);

    freopen("out.txt","w",stdout);

    int cas;
    scanf("%d",&cas);
    for(int ci=1;ci<=cas;ci++)
    {
        char s[1001000];
        int l;
        scanf("%s%d",s,&l);
        int ans=0;
        int n=strlen(s);
        for(int i=0;i<n;i++)
        {
            for(int j=i+l;j<=n;j++)
            {
                int c=0;
                for(int k=i;k<j;k++)
                {
                    if(s[k]=='a' || s[k]=='e' || s[k]=='i' || s[k]=='o' || s[k]=='u')
                    {
                        c=0;
                        continue;
                    }
                    c++;
                    if(c>=l)
                    {
//                        cout << i << ' ' << j << endl;
                        ans++;
                        break;
                    }
                }
            }
        }
        cout << "Case #" << ci << ": " << ans << endl;
    }
}
