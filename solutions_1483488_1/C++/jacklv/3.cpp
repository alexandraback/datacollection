#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
int a[30],ans,bb[30],len,sx,sy,ss;
map<int , bool> h;
void get(int n,int a[30])
{
    int i=1;
    memset(a,0,sizeof(a));
    while (n>0)
    {
        a[i]=n%10; n=n/10; i++;
    }
}
int get2(int s)
{
    int t=0,j=1;
    for (int i=s; i<=s+len-1; i++)
    {
        t+=j*a[i]; j=j*10;
    }
    return t;
}
int getl(int n)
{
    int l=0;
    while (n>0){n=n/10; l++;}
    return l;
}
int cmp(int s,int aa[30])
{
    for (int i=s+len-1; i>=s; i--)
    {
        if (a[i]<aa[i-s+1]) return 1;
        if (a[i]>aa[i-s+1]) return -1;
    }
    return 0;
}
void cal()
{
    h.clear();
    for (int i=2; i<=len; i++)
    {
        int t=get2(i);
        if (ss<t&&t<=sy&&h.find(t)==h.end())
        {
            h[t]=true;
            ans++;
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int T; cin>>T;
    for (int tt=1; tt<=T; tt++)
    {
        cin>>sx>>sy;
        ans=0; //get(sx,aa); get(sy,bb);
        for (ss=sx; ss<=sy-1; ss++)
        {
            len=getl(ss);
            //get(i,cc);
            get(ss,a);
            for (int j=1; j<=len; j++)
            a[j+len]=a[j];
            cal();
        }
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
}
