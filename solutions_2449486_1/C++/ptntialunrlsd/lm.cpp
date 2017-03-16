#include<iostream>
#include<map>
#include<fstream>
#include<vector>

using namespace std;

int main()
{
    ifstream cin("input");
    ofstream cout("output");

    int t,l,k,i,j,n,m,min,minn;
    cin>>t;

    for(k=1;k<=t;k++)
    {
        cin>>n>>m;

        int a[n][m],b[n][m];

        map<int,int> m1;

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                cin>>a[i][j];
                m1[a[i][j]]=1;
            }
    
        vector<int> v;
        for(i=1;i<=100;i++)
        {
            if(m1[i]==1)
                v.push_back(i);
        }

        for(l=0;l<v.size()-1;l++)
        {
            min=v[l];
            minn=v[l+1];

            for(i=0;i<n;i++)
                for(j=0;j<m;j++)
                    b[i][j]=a[i][j];

            for(i=0;i<n;i++)
            {
                m1.clear();
                for(j=0;j<m;j++)
                {
                    m1[a[i][j]]++;
                }
                if(m1.size()==1&&a[i][0]==min)
                {
                    for(j=0;j<m;j++)
                    {
                        b[i][j]=minn;
                    }
                }
            }

            for(j=0;j<m;j++)
            {
                m1.clear();
                for(i=0;i<n;i++)
                {
                    m1[a[i][j]]++;
                }
                if(m1.size()==1&&a[0][j]==min)
                {
                    for(i=0;i<n;i++)
                    {
                        b[i][j]=minn;
                    }
                }
            }

            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                    if(b[i][j]<minn)
                    {
                        //cout<<"Case #"<<k<<": NO\n";
                        break;
                    }
                if(j<m)
                    break;
            }

            if(i<n)
                break;

            for(i=0;i<n;i++)
                for(j=0;j<m;j++)
                    a[i][j]=b[i][j];

        }

        if(l==v.size()-1)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                    if(a[i][j]!=v[v.size()-1])
                        break;
                if(j<m)
                    break;
            }
            if(i<n)
                cout<<"Case #"<<k<<": NO\n";
            else
                cout<<"Case #"<<k<<": YES\n";
        }
        else
            cout<<"Case #"<<k<<": NO\n";
    }

    return 0;
}





