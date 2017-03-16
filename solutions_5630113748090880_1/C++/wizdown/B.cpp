#include<bits/stdc++.h>
#define scd(x) scanf("%d",&x)
#define prd(x) printf("%d",x)
#define sclld(x) scanf("%lld",&x)
#define prlld(x) printf("%lld",x)
#define f_in(x) freopen(x,"r",stdin)
#define f_out(x) freopen(x,"w",stdout)

using namespace std;

typedef long long int llt;

int main()
{
    ios::sync_with_stdio(false);
    vector<int> table;
    int t,x,n;
    //f_in("input.txt");
    //f_out("output.txt");
    cin>>t;
    for(int j = 1 ; j<=t ; j++)
    {
        cin>>n;
        table.assign(2501,0);
        for(int i = 1 ; i <= 2*n - 1 ; i++)
        {
            for(int k = 1 ; k<= n ; k++)
            {
            cin>>x;
            table[x]++;
            }
        }

        cout<<"Case #"<<j<<": ";
        for(int i= 1 ; i<=2500 ; i++)
        {
            if(table[i]&1)
                cout<<i<<" ";
        }
        cout<<"\n";
        table.clear();

    }



    return 0;
}
