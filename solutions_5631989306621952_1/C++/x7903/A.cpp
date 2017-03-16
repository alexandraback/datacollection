#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>'
#include <fstream>
using namespace std;

string s,ans;
int t;

int main()
{
    ofstream fp("A.out");
    scanf("%d",&t);
    for (int cas=1;cas<=t;++cas)
    {
        cin>>s;
        ans=s[0];
        for (int i=1;i<s.size();++i)
        {
            if (ans[0]<=s[i]) ans=s[i]+ans;
            else ans=ans+s[i];
        }
        fp<<"Case #"<<cas<<": "<<ans<<endl;
    }
    return 0;
}
