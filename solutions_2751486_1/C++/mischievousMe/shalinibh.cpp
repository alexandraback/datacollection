
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
    //freopen("A0000.in","r",stdin);
    //freopen("A0000.out","w",stdout);
    int t,n,l;
    long long cnt;
    int tt=0;
    string s;
    cin>>t;
    while(t--)
    {
        tt++;
        cin>>s>>n;
        l=s.size();
        cnt=0;
        int last=0,lastf=0;
        for(int i=0;i<l;i++)
        {
            if(!vowel(s[i])) last++;
            else last=0;
            if(last<n) continue;
            else if(last==n)
            {
                //
                cnt=cnt+l-i;
                cnt=cnt+i-lastf-(n-1);
                cnt=cnt+(long long)(i-lastf-(n-1LL))*(long long)(l-i-1LL);
                lastf=i-(n-2);
            }
            else
            {
                cnt=cnt+l-i;
                lastf=i-(n-2);
            }
        }
        cout<<"Case #"<<tt<<": "<<cnt<<"\n";
    }
    return 0;
}
