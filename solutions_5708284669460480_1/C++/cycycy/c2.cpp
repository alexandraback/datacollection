#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

int key[26];


int main()
{
    int T;
    cin>>T;
    for (int t=0;t<T;t++)
    {
        cout<<"Case #"<<t+1<<": ";
        int n,m,c;
        cin>>n>>m>>c;
        string s;
        cin>>s;
        for (int i=0;i<26;i++)
            key[i]=0;
        for (int i=0;i<n;i++)
            key[s[i]-'A']++;
        cin>>s;
        int k=m;
        for (int i=1;i<m;i++)
        {
            bool tf=true;
            for (int j=i;j<m;j++)
                if (s[j]!=s[j-i])
                {
                    tf=false;
                    break;
                }
            if (tf)
            {
                k=i;
                break;
            }
        }
        int ans1=(c-m)/k+1;
        for (int i=0;i<m;i++)
            if (key[s[i]-'A']==0)
                ans1=0;
        double ans2=1;
        for (int i=0;i<m;i++)
            ans2=ans2*(1.0*key[s[i]-'A']/1.0/n);
        ans2*=c-m+1;
        printf("%.6f\n",ans1-ans2);
    }

}
