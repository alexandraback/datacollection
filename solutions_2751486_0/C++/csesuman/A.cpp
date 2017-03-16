#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<conio.h>

using namespace std;

#define MX  100020
#define inf 2000000000
#define pi acos(-1.0)

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);

    long long int t,len,n,nw,fst,last,tot,st,cnt,cc=1;
    string str;

    cin>>t;

    while(t--)
    {
        cin>>str>>n;

        len = str.size();
        st = 0;
        cnt = 0;
        tot = 0;

        for(int i=0;i<len;i++)
        {
            if(!(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'))
            {
                if(cnt<n) cnt++;
            }
            else cnt = 0;

            if(cnt==n)
            {
                nw = i - n + 1;

                fst  = nw - st + 1;
                last = len - i;

                tot += fst*last;

                st = nw + 1;
            }
        }

        cout<<"Case #"<<cc++<<": "<<tot<<endl;
    }

    return 0;
}
