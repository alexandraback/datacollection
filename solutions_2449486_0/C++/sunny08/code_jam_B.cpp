#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
int main()
{
  fstream myf,f2;
  myf.open("input.txt",ios::in|ios::app);
  f2.open("output.txt",ios::out);
    string s[4];
    int t;
    if(myf.is_open())
    {
        myf>>t;
        //cin>>t;
        //getline(cin,line);
        int test=0;
        while(t--)
        {
            test++;
            int m,n;
            myf>>n>>m;
            int ar[n][m],sr[n][m];
            for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            myf>>ar[i][j],sr[i][j]=2;
            //check rows first

            for(int i=0;i<(n+m);i++)
            {
                if(i<n)
                {
                    int mx=0;
                    for(int j=0;j<m;j++)
                    {
                        mx=max(mx,ar[i][j]);
                    }
                    for(int j=0;j<m;j++)
                    {
                        sr[i][j]=min(mx,sr[i][j]);
                    }
                }
                else
                {
                    int mx=0;
                    for(int j=0;j<n;j++)
                    {
                        mx=max(mx,ar[j][i-n]);
                    }
                    for(int j=0;j<n;j++)
                    {
                        sr[j][i-n]=min(mx,sr[j][i-n]);
                    }
                }
            }
            int flg=0;
            for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(ar[i][j]!=sr[i][j])
                flg=1;
            }
            f2<<"Case #"<<test<<": ";
            if(flg==0)
            f2<<"YES\n";
            else
            f2<<"NO\n";
        }
    }
    myf.close();
    f2.close();
    return 0;
}

