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

ll arr[1000], ans[10];

void initial( ll x )
{
    if (x==0)
    {
        ans[x]+=arr['Z'];
        ll num = arr['Z'];
        arr['Z'] -= num;
        arr['E'] -= num;
        arr['R'] -= num;
        arr['O'] -= num;
    }
    else if (x==8)
    {
        ans[x]+=arr['G'];
        ll num = arr['G'];
        arr['E'] -= num;
        arr['I'] -= num;
        arr['G'] -= num;
        arr['H'] -= num;
        arr['T'] -= num;
    }
    else if (x==6)
    {
        ans[x]+=arr['X'];
        ll num = arr['X'];
        arr['S'] -= num;
        arr['I'] -= num;
        arr['X'] -= num;
    }
    else if (x==4)
    {
        ans[x]+=arr['U'];
        ll num = arr['U'];
        arr['F'] -= num;
        arr['O'] -= num;
        arr['U'] -= num;
        arr['R'] -= num;
    }
    else if (x==2)
    {
        ans[x]+=arr['W'];
        ll num = arr['W'];
        arr['T'] -= num;
        arr['W'] -= num;
        arr['O'] -= num;
    }
    else if (x==1)
    {
        ans[x]+=arr['O'];
        ll num = arr['O'];
        arr['O'] -= num;
        arr['N'] -= num;
        arr['E'] -= num;
    }
    else if (x==3)
    {
        ans[x]+=arr['T'];
        ll num = arr['T'];
        arr['T'] -= num;
        arr['H'] -= num;
        arr['R'] -= num;
        arr['E'] -= num;
        arr['E'] -= num;
    }
    else if (x==5)
    {
        ans[x]+=arr['F'];
        ll num = arr['F'];
        arr['F'] -= num;
        arr['I'] -= num;
        arr['V'] -= num;
        arr['E'] -= num;
    }    
    else if (x==7)
    {
        ans[x]+=arr['S'];
        ll num = arr['S'];
        arr['S'] -= num;
        arr['E'] -= num;
        arr['V'] -= num;
        arr['E'] -= num;
        arr['N'] -= num;
    }
    else if (x==9)
    {
        ans[x] += (arr['N']/2);
        ll num = (arr['N']/2);
        arr['N'] -= num;
        arr['I'] -= num;
        arr['N'] -= num;
        arr['E'] -= num;
    }    
    return;
}


int main()
{
    ll t;
    cin>>t;
    char s[2005];
    f(tst, 1, t+1)
    {
        sst(s);
        ll len = strlen(s);
        set(arr, 0);    set(ans, 0);
        f(i,0,len)
        {
            arr[s[i]]++;
        }
        initial(0);
        initial(8);
        initial(6);
        initial(4);
        initial(2);
        
        initial(1);
        initial(3);
        initial(5);
        initial(7);
        initial(9);

        cout<<"Case #"<<tst<<": ";
        f(i,0,10)
        {
            f(j,0,ans[i])
            {
                cout<<i;
            }
        }
        cout<<endl;
    }
    return 0;
}
