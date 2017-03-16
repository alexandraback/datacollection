#include <iostream>
#include <vector>
#include <map>
#include <fstream>

#define mod 1000000007

using namespace std;

int main()
{
    /*freopen("in.in", "r", stdin);
    freopen("out.txt", "w", stdout);*/

    ifstream fin;
    ofstream fout;

    fin.open("in.in");
    fout.open("out.txt");

    int t,n,k,i,c,j,m;
    long long p;
    fin>>t;
    for(k=1;k<=t;k++)
    {
        fin>>n;
        p=1;
        vector<string> crs(n);
        char st[n],en[n];
        int flag[n];
        map <char, long long> x;

        for(i=0;i<n;i++)
        {
            fin>>crs[i];
            st[i]=crs[i][0];
            en[i]=crs[i][crs[i].size()-1];
            flag[i]=i+1;
        }


        m=crs[0].size();
        x[crs[0][0]]++;
        for(j=1;j<m;j++)
            if(crs[0][j]!=crs[0][j-1])
                x[crs[0][j]]++;

        for(i=1;i<n;i++)
        {
            m=crs[i].size();
            for(j=0;j<m;j++)
            {
                if(j==0 || j==(m-1))
                    continue;

                if(crs[i][j]!=crs[i][j-1])
                {
                    if(x[crs[i][j]]!=0)
                        {p=0;
                        break;}
                    x[crs[i][j]]++;
                }
            }
        }

        if(p)
        {for(i=0;i<n;i++)
        {
            c=1;
            for(j=i+1;j<n;j++)
            {
                if(i==j)
                    continue;
                if(en[i]==st[j] && en[j]==st[i])
                {
                    c++;
                    flag[j]=flag[i];
                }
                if(en[i]==st[j])
                    flag[j]=flag[i];
                else if(en[j]==st[i])
                    flag[i]=flag[j];
            }
            p=((p%mod)*(c%mod))%mod;
        }

        c=n;
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
            {
                if(flag[i]==flag[j])
                    {crs[i]=crs[i]+crs[j];
                    c--;}
            }

        if(c>1)
            {
                n=1;
                while(c>1)
                {
                    n*=c;
                    c--;
                }
                p=((p%mod)*(n%mod))%mod;
            }
        }
        fout<<"Case #"<<k<<": "<<p<<endl;
    }
    return 0;
}
