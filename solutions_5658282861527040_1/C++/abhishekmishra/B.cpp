#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<string> v;
vector<int> nchar;
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    long long t,i,n,cnt,ans,l,j,f,cse=1,tmp,sum,avg,a,b,k;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>a>>b>>k;
        if(a<=k || b<=k)
        {
            ans = a*b;
        }
        else
        {
            ans = (k)*(k);
            ans += k*(b-k);
            ans += k*(a-k);
//            for(i=0;i<k;i++)
//            {
//                for(j=k;j<b;j++)
//                {
//                    if((i&j)<k)
//                    {
//                        ans++;
//                    }
//                }
//            }
//            for(i=k;i<a;i++)
//            {
//                for(j=0;j<k;j++)
//                {
//                    if((i&j)<k)
//                    {
//                        ans++;
//                    }
//                }
//            }
            for(i=k;i<a;i++)
            {
                for(j=k;j<b;j++)
                {
                    if((i&j)<k)
                    {
                        ans++;
                    }
                }
            }
        }

        cout<<"Case #"<<cse++<<": "<<ans<<endl;
    }
    return 0;
}
