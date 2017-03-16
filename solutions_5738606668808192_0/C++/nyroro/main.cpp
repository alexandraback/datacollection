#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n,j;

int str[100];

int gao(int base,int d)
{
    int nb=1;
    int ret=0;
    for(int i=0;i<n;i++)
    {
        ret+=str[i]*nb;
        ret%=d;
        nb=nb*base%d;
    }
    return ret;
}
int main()
{
    freopen("out.txt","w",stdout);
    int t=1;
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cin>>n>>j;


        cout<<"Case #"<<ti<<":"<<endl;
        for(int i=(1<<(n-2));i<(1<<(n-1));i++)
        {
            int sn=0;
            str[sn++]=1;
            int x=i;
            while(x>0)
            {
                str[sn++]=x%2;
                x/=2;
            }
            bool flag = true;
            vector<int> v;
            for(int base = 2;base<=10;base++)
            {
                if(gao(base,2)==0)
                {
                    v.push_back(2);
                }
                else if(gao(base,3)==0)
                {
                    v.push_back(3);
                }
                else if(gao(base,5)==0)
                {
                    v.push_back(5);
                }
                else if(gao(base,7)==0)
                {
                    v.push_back(7);
                }
                else if(gao(base,11)==0)
                {
                    v.push_back(11);
                }
                else
                {
                    flag=false;
                    break;
                }
            }

            if(flag)
            {
                //cout<<j<<' ';
                for(int k=n-1;k>=0;k--)
                {
                    cout<<str[k];
                }
                for(int k=0;k<v.size();k++)
                {
                    cout<<' '<<v[k];
                }
                cout<<endl;
                j--;
            }
            if(j<=0)
            {
                break;
            }
        }


    }
}
