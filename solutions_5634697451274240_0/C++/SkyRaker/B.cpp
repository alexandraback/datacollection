#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    cin>>T;
    for(int cas=1;cas<=T;++cas)
    {
        string str;
        cin>>str;
        int len=str.length();
        int pos=len-1;
        long long cnt=0;
        while(pos>=0)
        {
            if(str[pos]=='-')
            {
                ++cnt;
                for(int i=0;i<=pos;++i)
                {
                    if(str[i]=='+') str[i]='-';
                    else str[i]='+';
                }
            }
            --pos;
        }
        cout<<"Case #"<<cas<<": "<<cnt<<endl;
    }
    return 0;
}
