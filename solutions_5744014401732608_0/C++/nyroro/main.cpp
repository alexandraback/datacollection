#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;
int b;
long long m;

int mat[100][100];
long long arr[100];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int t;
    cin>>t;

    arr[0]=arr[1]=1;

    for(int i=2;i<=50;i++)
    {
        arr[i]=arr[i-1]*2;
    }
    for(int ti=1;ti<=t;ti++)
    {
        cout<<"Case #"<<ti<<": ";
        cin>>b>>m;

        long long maxM = (1ll<<(b-2));
        if(maxM<m)
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
        else
        {
            memset(mat,0,sizeof(mat));
            int i;
            for(i=0;i<=b-2;i++)
            {
                if(m>=arr[i])
                {
                    m-=arr[i];
                    mat[i][b-1]=1;
                    for(int j=0;j<i;j++)
                    {
                        mat[j][i]=1;
                    }
                }
                else
                {
                    break;
                }
            }
            int j=1;
            if(m>0)
            {
                mat[i][b-1]=1;
            }
            while(m>0)
            {
                if(m%2==1)
                {
                    mat[j][i]=1;
                }
                j++;
                m/=2;
            }
            cout<<"POSSIBLE"<<endl;

            for(int i=0;i<b;i++)
            {
                for(int j=0;j<b;j++)
                {
                    cout<<mat[i][j];
                }
                cout<<endl;
            }
        }

    }


    return 0;
}
