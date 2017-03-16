#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
string s[2];
string tmp[2];
char getc(int i)
{
    char a=s[0][i];
    char b=s[1][i];
    if(a!='?')
    {
        if(b!='?') return '#';
        return a;
    }
    return b;
}
int cmp(char a,char b)
{
    if(a==b) return -1;
    else if(a>b) return 0;
    return 1;
}
int len;
int cur;
string c,j;
void dfs(int deep)
{
    if(deep==len)
    {
        //cout<<s[0]<<s[1]<<endl;
        int num1=0;
        int num2=0;
        for(int i=0;i<len;i++)
        {
            num1=num1*10+(s[0][i]-'0');
            num2=num2*10+(s[1][i]-'0');
        }
        int ab=abs(num1-num2);
        if(ab<cur)
        {
            c=s[0];
            j=s[1];
            cur=ab;
        }
        else if(ab==cur)
        {
            if(s[0]<c)
            {
                c=s[0];
                j=s[1];
            }
            else if(s[0]==c)
            {
                if(s[1]<j)
                {
                    c=s[0];
                    j=s[1];
                }
            }
        }
        return ;
    }
        for(int j=0;j<10;j++)
        {
            if(tmp[0][deep]=='?')
                s[0][deep]=j+'0';
            for(int i=0;i<10;i++)
            {
                if(tmp[1][deep]=='?')
                s[1][deep]=i+'0';
                dfs(deep+1);
            }
        }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    for(int ca=1;ca<=T;ca++)
    {
        cin>>s[0]>>s[1];
        tmp[0]=s[0];
        tmp[1]=s[1];
        len=s[0].length();
        cur=1e9;
        dfs(0);
        printf("Case #%d: ",ca);
        cout<<c<<" "<<j<<endl;
    }
    return 0;
}
