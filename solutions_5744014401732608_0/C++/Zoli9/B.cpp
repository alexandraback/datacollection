#include <bits/stdc++.h>
using namespace std;
int test;
long long b, m;
long long hat[52];
long long matrix[59][59];
int main()
{
    hat[0]=1;
    for(long long i=1; i<=51; i++)
    {
        hat[i]=2*hat[i-1];
    }
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>b>>m;
        cout<<"Case #"<<tt<<": ";
        if(m>hat[b-2])
        {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        vector<long long> bin;
        long long x=m;
        while(x>0)
        {
            bin.push_back(x%2);
            x/=2;
        }
        for(int i=1; i<=b; i++)
        {
            for(int j=1; j<=b; j++)
            {
                if(i==j)
                {
                    matrix[i][j]=0;
                    continue;
                }
                if(i>=b-bin.size() && j>=b-bin.size())
                {
                    if(i<j) matrix[i][j]=1;
                    else matrix[i][j]=0;
                }
                else
                {
                    matrix[i][j]=0;
                }
            }
        }
        if(m==hat[b-2])
        {
            for(int i=2; i<=b; i++)
            {
                matrix[1][i]=1;
            }
        }
        else
        {
            int cnt=b-1;
        for(int i=0; i<bin.size(); i++)
        {
            if(bin[i]==1)
            {
                matrix[1][cnt]=1;
            }
            cnt--;
        }
        }
        cout<<"POSSIBLE"<<endl;

        for(int i=1; i<=b; i++)
        {
            for(int j=1; j<=b; j++)
            {
                cout<<matrix[i][j];
            }
            cout<<endl;
        }
    }

    return 0;
}
