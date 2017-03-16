#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int maxn=105;
char s[maxn];
int n,L;

bool volw(char c)
{
    return c=='a' || c=='o' || c=='e'
      || c=='u' || c=='i';
}

bool fit(int x,int y)
{
    int ck=0;
    for(int i=x;i<=y;i++)
    {
        if(!volw(s[i]))
        {
            ck++;
            if(ck==n)return true;
        }
        else ck=0;
    }
    return false;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A.out.txt","w",stdout);
    int T,cnt;
    cin>>T;
    for(int ii=1;ii<=T;ii++)
    {
        cin>>s>>n;
        L=strlen(s);
        cnt=0;
        for(int i=0;i<L;i++)
          for(int j=i;j<L;j++)
          {
              if(fit(i,j))cnt++;
          }
        cout<<"Case #"<<ii<<": ";
        cout<<cnt<<endl;
    }
    return 0;
}
