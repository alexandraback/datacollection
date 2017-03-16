#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    int t=0,T;
    scanf("%d",&T);
    while(t++<T)
    {
        int n;
        string s;
        cin>>s;
        scanf("%d",&n);
        long long i,j,sz=s.size(),ans=0,x=0;
        for(i=0;i<sz;i++)
        {
            int br=0;
            while(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&i<sz)
            {
                br++;
                if(br>=n){ans+=((sz-i)*(i-n+2-x));x+=(i-n+2-x);}
             //   else
             //   if(br>n)
             //   ans+=(sz-(i-n+1)-1);
                i++;
            }
        }
        printf("Case #%d: %lld\n",t,ans);
    }
    return 0;
}

