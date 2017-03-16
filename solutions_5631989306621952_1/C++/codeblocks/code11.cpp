#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int k=0;
    while(t--)
    {
        string s;
        cin>>s;
        string news="";
        news=news+s[0];
k++;
        for(int i=1;i<s.length();i++)
        {

            int c=(int)(s[i]);
            int d=(int)(news[0]);
            if(c>=d)
                news=s[i]+news;
            else
                news=news+s[i];

                    }
                    cout<<"Case #"<<k<<": "<<news<<"\n";
    }
}
