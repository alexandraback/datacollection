#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("A-small-attempt0 (1).in","r",stdin);
    freopen("CJ1A.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int j=1;j<=t;j++)
    {   string s;
        cin>>s;
        int l=s.length();
        string ans="";
        char p;
        ans=s[0];
        for(int i=1;i<l;i++)
        {
            if(s[i]<ans[0])
                ans=ans+s[i];
            else
            {
                ans=s[i]+ans;
            }
        }
        printf("Case #%d: ",j);
		cout<<ans<<endl;
    }

    return 0;
}
