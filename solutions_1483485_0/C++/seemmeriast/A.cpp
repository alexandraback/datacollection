#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
     freopen("A-small-attempt0.in","r",stdin);
     freopen("A-small-attempt0.out","w",stdout);

     int m[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
     int T;

     cin>>T;
     char ss[110];
     gets(ss);
     for(int t=1;t<=T;t++)
     {
          char s[110];
          gets(s);
          int n=strlen(s);
          for(int i=0;i<n;i++)
          {
               if('a'<=s[i]&&s[i]<='z')
               s[i]=m[s[i]-'a'];
               }

          cout<<"Case #"<<t<<": "<<s<<endl;
          }

     return 0;
     }
