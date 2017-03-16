#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define uint unsigned int

int a[30][30];

void fill_a()
{
    for(int i=0;i<=25;i++)
        for(int j=0;j<=25;j++)
        {
            if(i>j)
                a[i][j]=0;
            else if(i==j || i==j-1)
                a[i][j]=j;
        }
    for(int i=0;i<=25;i++)
        a[1][i]=i;
        for(int i=2;i<=25;i++)
        {       int x=1;
                int val=i+1;
            for(int j=i+2;j<=25;j++)
            {        a[i][j]=val;
                x++;
                if(x==i){val++;x=0;}
            }
        }
}

void printa()
{
    for(int i=1;i<=10;i++)
    {
        cout<<endl;
        for(int j=1;j<=10;j++)
            cout<<a[j][i]<<"   ";
    }
}
inline void func()
{
    int r,c,w;
    cin>>r>>c>>w;
    int ans=0;
    ans +=(r-1)*(c/w);
    ans+=a[w][c];
    cout<<ans<<endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
        fill_a();
        //printa();
   
        for(int tc=0;tc<T;tc++)
    {
        cout<<"Case #"<<tc+1<<": ";
                func();
    }
  // */
}
