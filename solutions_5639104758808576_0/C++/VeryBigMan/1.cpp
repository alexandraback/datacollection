#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    for(int tt=1;tt<=T;tt++)
    {
        int n;
        cin>>n;
        string str;
        cin>>str;
        int cnt=str[0]-'0';
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int temp=0;
            if(cnt<i)
            {
                temp=i-cnt;
            }
            cnt+=str[i]-'0'+temp;
            ans+=temp;
        }
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}
