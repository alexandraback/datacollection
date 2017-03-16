#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define N 103456


string s;

int b[1236];
int n;

int main()
{
    int T;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>T;

    for (int _=1;_<=T;_++)
    {
        cin>>s;
        printf("Case #%d: ",_);
        int x=0;
        memset(b,0,sizeof(b));
        int n=s.size();
        string ans;
        int pos=n;
        for (int i=0;i<s.size();i++)
        {
            char tmp=0;
            for (int j=pos-1;j>=0;j--)
            if (b[j]==0)
            {
                tmp=max(tmp,s[j]);
            }
            if (tmp==0) break;
            for (int j=pos-1;j>=0;j--)
            if (s[j]==tmp)
            {
                ans+=s[j];
                b[j]=1;
                pos=j;
            }
        }
        for (int i=0;i<n;i++)
        if (b[i]==0) ans+=s[i];
        cout<<ans<<endl;
    }
    return 0;
}
