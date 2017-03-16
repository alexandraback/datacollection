#include<iostream>
#include<cstring>
using namespace std;
int m[1010][1010];
int n;
int main()
{
int t;
cin>>t;
for(int i=1;i<=t;i++)
{
cin>>n;
int g;
memset(m,0,sizeof(m));
for(int i=1;i<=n;i++)
{
    cin>>g;
    for(int j=1;j<=g;j++)
    {
        int h;
        cin>>h;
        m[i][h]=1;
    }
}
bool f=0;
for(int k=1;k<=n;k++)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(m[i][j]>1){f=1;break;}
            m[i][j]=m[i][j]+m[i][k]*m[k][j];
        }
        if(f)break;
    }
    if(f)break;
}
if(!f){
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(m[i][j]>1){f=1;break;}
    }
    if(f)break;
    }
}
if(f)cout<<"Case #"<<i<<": Yes"<<endl;
else cout<<"Case #"<<i<<": No"<<endl;
}
return 0;
}
