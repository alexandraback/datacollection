#include<bits/stdc++.h>
using namespace std;
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("B-large.in","r",stdin);
    freopen("blarge.txt","w",stdout);
    int T;
    cin>>T;

    long long fact[21];
    memset(fact , 0,sizeof fact);
    fact[0]=1LL;
    for(long long i=1; i<21; i++)fact[i]=fact[i-1]*i;

    for(int t_c=1; t_c<=T; t_c++)
    {
        long long B,M;
        cin>>B>>M;
        if((1LL<<(B-2)<M))
        {
            cout<<"Case #"<<t_c<<": IMPOSSIBLE\n";
        }
        else
        {
            cout<<"Case #"<<t_c<<": POSSIBLE\n";
            long long ara[B+1];
            ara[B]=1;
            for(int i=B-1; i>=1; i--)
            {
                ara[i]=1LL<<(i-(B-1));
            }
            string str[B];
            for(int ii=0; ii<B; ii++)
            {
                for(int jj=0; jj<B; jj++)
                {
                    if(ii==0)str[ii]+='0';
                    else if(jj<=ii)str[ii]+='0';
                    else str[ii]+='1';
                }
            }
            if(M==((1LL<<(B-2))))
            {
                for(int i=1; i<B; i++)str[0][i]='1';
            }
            else
            {
                for(long long i=0; i<B; i++)
                {
                    if(M&(1LL<<i))
                    {
                        str[0][B-i-2]='1';
                    }
                }
            }
            for(int i=0; i<B; i++) cout<<str[i]<<"\n";

        }
    }
    return 0;
}
