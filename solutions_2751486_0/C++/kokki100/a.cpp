#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
long long a,b,c,d,e,f,g,h;
string s;
long long zz[1000006],zz2[1000006];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);

    scanf("%I64d",&a);
    for (b=1;b<=a;b++)
    {
        cin >> s;
        scanf("%I64d",&c);
        e=0;
        f=0;
        memset(zz,-1,sizeof(zz));
        memset(zz2,0,sizeof(zz2));
        for (d=s.length()-1;d>=0;d--)
        {
            if (s[d]!='a' && s[d]!='i' && s[d]!='u' && s[d]!='e' && s[d]!='o')
            {
                e++;
                if (e>=c) {zz[d]=d; zz2[d]=e;}
            }
            else e=0;
        }
        h=s.length();
        for (d=s.length()-1;d>=0;d--)
            if (zz[d]==-1)
                zz[d]=h;
            else
            {
                h=zz[d];
            }
        g=0;
        for (d=0;d<s.length();d++)
        {
            if (zz[d]!=s.length())
            g+=s.length()-zz[d]-c+1; //printf("%I64d %I64d %I64d %I64d\n",d,zz[d],zz2[d],g);
        }
        printf("Case #%I64d: %I64d\n",b,g);
    }

    return 0;
}
