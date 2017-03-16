#include<bits/stdc++.h>


using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("A-small-attempt1.in","r",stdin);
    freopen("Asmall1.out","w",stdout);

    int t,i,j;
    char p[1010];
    string a,s,x;
    scanf("%d",&t);
    for(i=1;i<=t;++i)
    {
        scanf("%1000s",p);
        s=p;
        a=s[0];
        for(j=1;j<s.length();++j)
        {
            x=s[j];
            if((int)s[j]>=(int)a[0])
                a=x+a;
            else
                a=a+x;
        }
        printf("Case #%d: %s\n",i,a.c_str());
    }
    return 0;
}
