#include <bits/stdc++.h>

typedef long long ll;
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*freopen("/Users/Ayur/Downloads/A-large.in","r",stdin);
    freopen("/Users/Ayur/Downloads/A-large-output.txt","w",stdout);*/
    int t,tt,i,n,cnt,sum;
    string s;
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        cout<<"Case #"<<tt<<": ";
        cin>>n; ++n;
        cin>>s;
        cnt=0; sum=(int)(s[0]-'0');
        for(i=1;i<n;i++)
        {
            if((int)(s[i]-'0')>0 && sum<i)
            {
                cnt += (i-sum);
                sum += (i-sum);
            }
            sum += (int)(s[i]-'0');
        }
        cout<<cnt<<"\n";
    }
    return 0;
}