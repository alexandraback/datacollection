#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,i,k;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%lld",&t);
    for(k=1;k<=t;k++)
    {
         char s[1005];
         scanf("%s",s);
         n=strlen(s);
         list<char>q;
         list<char>::iterator it;
         q.push_back(s[0]);
         for(i=1;i<n;i++)
         {
             if(q.front()<=s[i])
             {
                 q.push_front(s[i]);
             }
             else
                q.push_back(s[i]);
         }
         printf("Case #%lld: ",k);
         for(it=q.begin();it!=q.end();it++)
         {
             cout<<*it;
         }
         printf("\n");




    }

    return 0;
}
