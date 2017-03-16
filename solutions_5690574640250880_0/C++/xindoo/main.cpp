#include<iostream>
#include<algorithm>
#include <stdio.h>
using namespace std;

int main()
{
    int t,m,n,r,c,tmp;
  //  freopen("out", "w", stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>r>>c>>m;
        n=r*c-m;
        tmp=min(r,c);
        cout<<"Case #"<<i<<":"<<endl;
        if(m==0)
        {
            for(int j=0;j<r;j++)
            {
                for(int k=0;k<c;k++)
                {
                    if (j == 0 && k == 0)
                        cout << 'c';
                    else
                        cout<<'.';
                }

            cout<<endl;
            }
        }
        else if(n==1)
        {
            for(int j=0;j<r;j++)
            {
                for(int k=0;k<c;k++)
                {
                    if(j+k==0) cout<<'c';
                        else cout<<'*';
                }
                cout<<endl;
            }
        }
        else if(tmp==1)
        {
            for(int j=0;j<r;j++)
            {
                for(int k=0;k<c;k++)
                {
                    if(j==0 && k==0) cout<<'c';
                    else if(j*c+k<n) cout<<'.';
                    else cout<<'*';
                }
                cout<<endl;
            }
        }
        else if(n==2 || n==3 || n==5|| n==7 || (tmp==2 && m%2)) cout<<"Impossible"<<endl;
        else if(tmp>3)
        {
            int l=n/2;
            if(l<=c)
            {
                if(n%2==0)
                {
                    for(int j=0;j<r;j++)
                    {
                        for(int k=0;k<c;k++)
                        {
                            if(j==0 && k==0) cout<<'c';
                            else if(j<2 && k<l) cout<<'.';
                            else cout<<'*';
                        }
                    cout<<endl;
                    }
                }
                else
                {
                    for(int j=0;j<r;j++)
                    {
                        for(int k=0;k<c;k++)
                        {
                            if(j==0 && k==0) cout<<'c';
                            else if(j<2 && k<l-1) cout<<'.';
                            else if(j==2 && k<3) cout<<'.';
                            else cout<<'*';
                        }
                    cout<<endl;
                    }
                }
            }
        else
        {
            if(n%c==1)
            {
                for(int j=0;j<r;j++)
                {
                for(int k=0;k<c;k++)
                {
                if(j==0 && k==0) cout<<'c';
                else if(j<n/c-1) cout<<'.';
                else if(j<n/c && k<c-1) cout<<'.';
                else if(j==n/c && k<2) cout<<'.';
                else cout<<'*';
                }
                cout<<endl;
                }
            }
            else
            {
            for(int j=0;j<r;j++)
            {
            for(int k=0;k<c;k++)
            {
            if(j==0 && k==0) cout<<'c';
            else if(j<n/c) cout<<'.';
            else if(j==n/c && k<n%c) cout<<'.';
            else cout<<'*';
            }
            cout<<endl;
            }
            }
            }
            }
            else if(tmp==2)
            {
            if(r==2)
            {
            for(int j=0;j<r;j++)
            {
            for(int k=0;k<c;k++)
            {
            if(j==0 && k==0) cout<<'c';
            else if(k<n/2) cout<<'.';
            else cout<<'*';
            }
            cout<<endl;
            }
        }
        else
        {
            for(int j=0;j<r;j++)
            {
            for(int k=0;k<c;k++)
            {
            if(j==0 && k==0) cout<<'c';
            else if(j*c+k<n) cout<<'.';
            else cout<<'*';
            }
            cout<<endl;
            }
            }
            }
            else
            {
            if(c==3)
            {
            if(n%c==1)
            {
            for(int j=0;j<r;j++)
            {
            for(int k=0;k<c;k++)
            {
            if(j==0 && k==0) cout<<'c';
            else if(j<n/c-1) cout<<'.';
            else if(j<n/c && k<c-1) cout<<'.';
            else if(j==n/c && k<2) cout<<'.';
            else cout<<'*';
            }
            cout<<endl;
            }
        }
        else
        {
        for(int j=0;j<r;j++)
        {
        for(int k=0;k<c;k++)
        {
        if(j==0 && k==0) cout<<'c';
        else if(j<n/c) cout<<'.';
        else if(j==n/c && k<n%c) cout<<'.';
        else cout<<'*';
        }
        cout<<endl;
        }
        }
        }
        else
        {
        if(n%r==1)
        {
        for(int j=0;j<r;j++)
        {
        for(int k=0;k<c;k++)
        {
        if(j==0 && k==0) cout<<'c';
        else if(j<2 && k<n/r+1) cout<<'.';
        else if(j==2 && k<n/r-1) cout<<'.';
        else cout<<'*';
        }
        cout<<endl;
        }
        }
        else
        {
        for(int j=0;j<r;j++)
        {
        for(int k=0;k<c;k++)
        {
        if(j==0 && k==0) cout<<'c';
        else if(n%r && j<2 && k<n/r+1) cout<<'.';
        else if(n%r==0 && j<2 && k<n/r) cout<<'.';
        else if(j==2 && k<n/r) cout<<'.';
        else cout<<'*';
        }
        cout<<endl;
        }
        }
        }
        }
    }
    return 0;
}
