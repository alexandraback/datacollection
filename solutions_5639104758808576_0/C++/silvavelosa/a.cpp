#include<bits/stdc++.h>
using namespace std;
int n[1100],ret,nCases,m,s;
string sh;
int main (void)
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    cin>>nCases;
    for(int aCase = 1;aCase<=nCases;aCase++)
    {
        cin>>m>>sh;
        ret=0;
        s=0;
        for(int i=0;i<=m;i++)
        {
            n[i] = sh[i] - '0';
            if(s < i)
            {
                ret+= i-s;
                s = i;
            }
            s+=n[i];
        }
        cout<<"Case #"<<aCase<<": "<<ret<<endl;
    }
    return 0;
}
