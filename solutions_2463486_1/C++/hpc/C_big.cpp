#include <iostream>
#include <cstdio>
using namespace std;
char a[15][10]={"1","2","3","11","22","111","121","212","1111","11111","11211","111111","1111111","11111111","111111111"};
long long int A,B;
int cnt;
bool check(long long int x)
{
    if(x>=A&&x<=B) return true;
    else return false;
}
long long int CTI(char c[])
{
    int len=strlen(c);
    long long int s=0;
    for(int i=0;i<len;++i)
    {
        s*=10;
        s+=int(c[i]-'0');
    }
    s*=s;
    return s;
}
bool cmd(char c[],int len,int b[])
{
    long long int s=0;
    for(int i=0;i<len;++i)
    {
        s*=10;
        s+=int(c[i]-'0');
        if(b[i])
        {
            int y=b[i];
            while(y--)
                s*=10;
        }
        else if(b[len-2-i])
        {
            int y=b[len-2-i];
            while(y--)
                s*=10;
        }
    }
    //cout<<s<<" ";
    s*=s;
    //cout<<s<<"\n";
    if(check(s))
        cnt++;
    if(s>B||s<0) return false;
    else return true;
}
void add0(char c[],int len,int b[],int x)
{
    if(cmd(c,len,b));
    else return;
    for(int i=x;i<len/2;++i)
    {
        b[i]++;
        add0(c,len,b,i);
        b[i]--;
    }
}
int process()
{
    cnt=0;
    for(int i=0;i<3;++i)
    {
        if(check(CTI(a[i]))) cnt++;
    }
    for(int i=3;i<15;++i)
    {
        int len=strlen(a[i]);
        int b[15];
        memset(b,0,sizeof(b));
        add0(a[i],len,b,0);
    }
    return cnt;
}
int main()
{
    freopen("C-large-1.in","r",stdin);
    freopen("C-large-1.out","w",stdout);
    int t,T;
    scanf("%d",&t);
    T=t;
    while(t--)
    {
        scanf("%lld%lld",&A,&B);
        printf("Case #%d: %d\n",T-t,process());
    }
    return 0;
}
