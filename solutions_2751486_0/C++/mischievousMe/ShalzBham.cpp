
//header files
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<map>
#include<vector>

using namespace std;

bool vowel(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return 1;
    return 0;
}

int main()
{
    //freopen("A00.in","r",stdin);
    //freopen("A00.out","w",stdout);
    int t,n,l,cnt,tt=0;
    string s;
    cin>>t;
    while(t--)
    {
        tt++;
        cin>>s>>n;
        l=s.size();
        cnt=0;
        for(int i=0;i<l;i++)
        {
            for(int j=i;j<l;j++)
            {
                int last=0,fl=0;
                for(int k=i;k<=j;k++)
                {
                    if(!vowel(s[k])) last++;
                    else last=0;
                    if(last>=n)
                    {
                        fl=1;
                        break;
                    }
                }
                if(fl) cnt++;
            }
        }
        cout<<"Case #"<<tt<<": "<<cnt<<"\n";
    }
    return 0;
}
