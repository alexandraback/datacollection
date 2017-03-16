#include<iostream>
#include<cmath>
using namespace std;
int f[10];
int flag[10];
bool check(int y,int w)
{
    for(int i=0;i<w;i++)
    if(flag[i]==y) return true;
    return false;
}
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C.out","w",stdout);
    int ca,a,b,y,i;
    cin>>ca;
    f[0]=1;
    for(i=1;i<9;i++)
    f[i]=f[i-1]*10;
    for(int k=1;k<=ca;k++)
    {
        printf("Case #%d: ",k);
        cin>>a>>b;
        int ans=0;
        for(int x=a;x<b;x++)
        {
           //  int h=int(log10(x)+1);
             int h=0,tmp=x;
             while(tmp!=0)
             {
                 tmp/=10;h++;
             }
           //  cout<<"h="<<h<<"f[h]="<<f[h]<<endl;
             int z=x;
             memset(flag,0,sizeof(flag));
             for(int w=0;w<h-1;w++)
             {
                 y=(z%10)*f[h-1]+z/10;
                 z=y;
                 flag[w]=y;
                //  cout<<y<<endl;
                // system("pause");
                 if(y>x&&y<=b && check(y,w)==false)
                 {
                     ans++;
                 }

             }
        }
        cout<<ans<<endl;
    }
    return 0;
}

