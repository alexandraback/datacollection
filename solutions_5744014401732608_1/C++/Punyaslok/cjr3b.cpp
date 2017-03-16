#include<bits/stdc++.h>
#define ll long long int
#define PB push_back
#define F first
#define S second
#define tr(c,i) for(typeof((c).begin())i = (c).begin(); i != (c).end(); i++) 
#define sint(n); scanf("%d",&n);
#define sll(n); scanf("%lld",&n);
#define pint(n); printf ("%d\n",n);
#define pll(n); printf ("%lld\n",n);
#define sst(n); scanf("%s",n);
#define pst(n); printf ("%s\n",n);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define set(a,b) memset(a, b, sizeof(a))


using namespace std;

    
ll b,m;
ll arr[60][60];

void unsetall( ll x )
{
  //  cout<<"setting "<<x<<endl;
    arr[1][x] = 0;
    return;
}

int main()
{
    ll t;
    cin>>t;
    f(tst, 1, t+1)
    {

        cin>>b>>m;
        printf("Case #%lld: ", tst);
        if (m>(1<<(b-2)))
        {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        
        cout<<"POSSIBLE"<<endl;
        set(arr, 0);

        ll total = 1<<(b-2);

        f(i, 1, b+1)
        {
            f(j, 1, b+1)
            {
                if (i<j)
                    arr[i][j]=1;
            }
        }
        /*f(i, 1, b+1)
        {
            f(j, 1, b+1)
            {
                cout<<arr[i][j];
            }
            cout<<endl;
        }*/

        //while (total>m)
        {
            ll diff = total - m;
         //   cout<<total<<" "<<diff<<endl;
            ll ct=0;
            while (diff)
            {
             //   cout<<diff<<" "<<ct<<endl;
                ll tmp = diff%2;
                diff/=2;
                if (tmp==1)
                    unsetall(b-ct-1);
                ct++;
            }
        }

        f(i, 1, b+1)
        {
            f(j, 1, b+1)
            {
                cout<<arr[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
