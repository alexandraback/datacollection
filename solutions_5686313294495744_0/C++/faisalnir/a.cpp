#include<bits/stdc++.h>
#define pb push_back
using namespace std;


int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for(int c=1;c<=t;c++)
    {
       int n;
       scanf("%d",&n);
       multiset<string>f,s;
       vector<string>A,B;
       for(int i=1;i<=n;i++)
       {
           string x,y;
           cin>>x>>y;
           A.pb(x);
           B.pb(y);
           f.insert(x);
           s.insert(y);
       }
       int ans=0;
       bool ok[100];
       memset(ok,1,sizeof ok);
       int p=100;
        while(p--)
        {

            for(int i=0;i<B.size();i++)
            {

                if(ok[i]==1 && s.count(B[i])>1 && f.count(A[i])>1)
                {
                    ok[i]=0;
                    ans++;
                     if(f.find(A[i])!=f.end())
                    f.erase(f.find(A[i]));
                    if(s.find(B[i])!=s.end())
                    s.erase(s.find(B[i]));
                }
            }
            //printf("%d\n",ans);
        }
        printf("Case #%d: %d\n",c,ans);



    }

}
