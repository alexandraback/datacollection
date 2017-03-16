#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
bool ok(char c)
{
    if(c!='a'&&c!='e'&&c!='o'&&c!='u'&&c!='i')return true;
    else return false;
}
int main()
{
   // freopen("A-small-attempt2.in", "r", stdin);
   // freopen("a.out", "w", stdout);
    int t,n,l,_=0;
    int le,ri,temp;
    long long ans;
    char s[1000];
    scanf("%d",&t);
    while(t--)
    {   getchar();
        scanf("%s %d",s,&n);
        l=strlen(s);
        ans=0ll;
        temp=0;
        le=0;
        ri=0;
        for(int i=0; i<l; ++i)
        {
            if(ok(s[i]))
            {
                temp++;
                if(temp>n)
                {
                    temp--;
                }
              //  cout<<i<<"~~\n";
              //  cout<<temp<<endl;
            }
            else
            {
                temp=0;
            }
           // cout<<"lalal";
           // cout<<temp<<endl;
            if(temp==n)
            {
                //cout<<i<<"~~~\n";
                ans+=(long long)((i-n-le+2)*(l-i));
                le=i-n+2;
            }
        }
        printf("Case #%d: ",++_);
        printf("%lld\n",ans);
    }
    return 0;
}
