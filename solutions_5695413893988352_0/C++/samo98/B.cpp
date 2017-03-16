#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,n;
string s,str;
int main()
{
    cin>>t;
    for(int ij=1;ij<=t;ij++)
    {
        cin>>s>>str;
        int odpoved1=-1,odpoved2=10000000;
        for(int i=0;i<1000;i++)
        {
            if(s.size()==1 && i==10)break;
            if(s.size()==2 && i==100)break;
            int ii=i;
            bool zle=false;
            for(int j=s.size()-1;j>=0;j--)
            {
                if(s[j]=='?'){ii/=10;continue;}
                int cislica=s[j]-'0';
                if(cislica!=ii%10)zle=true;
                ii/=10;
            }
            if(zle)continue;
            for(int j=0;j<1000;j++)
            {
                if(str.size()==1 && j==10)break;
                if(str.size()==2 && j==100)break;
                if(abs(i-j)>=abs(odpoved1-odpoved2))continue;
                bool von=false;
                int jj=j;
                for(int k=str.size()-1;k>=0;k--)
                {
                    if(str[k]=='?'){jj/=10;continue;}
                    if((str[k]-'0')!=jj%10)von=true;
                    jj/=10;
                }
                if(von)continue;
                odpoved1=i;odpoved2=j;
            }
        }
        cout <<"Case #"<<ij<<": ";
        if(odpoved1<10 && s.size()==2)cout <<"0";
        if(odpoved1<10 && s.size()==3)cout <<"0";
        if(odpoved1<100 && s.size()==3)cout <<"0";
        cout <<odpoved1<<" ";
        if(odpoved2<10 && str.size()==2)cout <<"0";
        if(odpoved2<10 && str.size()==3)cout <<"0";
        if(odpoved2<100 && str.size()==3)cout <<"0";
        cout <<odpoved2<<endl;
    }
    return 0;
}
