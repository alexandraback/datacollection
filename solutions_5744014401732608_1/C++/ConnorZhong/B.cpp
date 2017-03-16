#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long a[51];

long long edge[50][50];
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    a[0] = 1;
    long long tp = 1;
    for (long long i = 1; i < 51; i++)
    {

        a[i] = tp;
        tp += a[i];
    }
//    for (int i = 0; i < 51; i++)
//        cout<<a[i]<<" ";
//    cout<<endl;
    long long T;
    cin>>T;
    for (long long k = 1; k <= T; k++)
    {

        long long B,M;
        cin>>B>>M;
        cout<<"Case #"<<k<<": ";
        if ( M > a[B-1] )
            cout<<"IMPOSSIBLE"<<endl;
        else
        {
            cout<<"POSSIBLE"<<endl;
            memset(edge,0,sizeof edge);
            for (int i = 0; i < B-1; i++)
            {
                for (int j = i+1; j < B-1; j++)
                    edge[i][j] = 1;
            }
            M--;
            for (int i = 1; i < B-1; i++)
            {
                if (M & 1) edge[i][B-1]=1;
                M >>= 1;
            }
            edge[0][B-1] = 1;
            for (int i = 0; i < B; i++)
            {
                for (int j = 0; j < B; j++)
                    cout<<edge[i][j];
                cout<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
}

