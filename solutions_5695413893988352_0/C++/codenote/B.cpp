#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <int,int> ii;
void Solve(int);
char cod[30],jam[30];
char x[30],y[30];
struct nod
{
    ll v1,v2;
} ans;
string fill(ll nu,int n)
{

    string res = "";
    for(int i = 1 ; i<=n ; i++)
    {
        char ch = nu%10 + '0';
        nu = nu/10;
        res = ch + res;
        //cout<< res <<" ";
    }
    //cout<<endl;
    return res;
}
void solve(int i,int n,ll v1,ll v2)
{
    //printf("%lld %lld\n",v1,v2);
    if(i == n)
    {
        if(ans.v1 == -1)
        {
            ans.v1 = v1;
            ans.v2 = v2;
        }
        else
        {
            ll diff = abs(ans.v1 - ans.v2) - abs(v1 - v2);
            if(diff > 0)
            {
                ans.v1 = v1;
                ans.v2 = v2;
            }
            else if(diff == 0)
            {
                if(ans.v1 > v1)
                {
                    ans.v1 = v1;
                    ans.v2 = v2;
                }
                else if(ans.v1 == v1)
                {
                    if(ans.v2 > v2) ans.v2 = v2;
                }
            }
        }
    }
    else
    {
        if(x[i] == '?' && y[i] == '?')
        {
            // solve(i+1,n,v1*10,v2*10);
            // solve(i+1,n,v1*10 + 1,v2*10);
            // solve(i+1,n,v1*10,v2*10 + 1);
            // solve(i+1,n,v1*10,v2*10 + 9);
            // solve(i+1,n,v1*10 + 9,v2*10);
            for(int d1 = 0; d1 <10 ; d1 ++)
            {
                for(int d2 = 0 ; d2 <10 ; d2++)
                {
                    solve(i+1,n,v1*10 + d1,v2*10 + d2);
                }
            }
        }
        else if(x[i] == '?')
        {
            ll d2 = y[i] - '0';
            // ll d1 = (d+1)%10;
            // ll d2 = (d+9)%10;
            // solve(i+1,n,v1*10 + d,v2*10 + d);
            // solve(i+1,n,v1*10 + d1,v2*10 + d);
            // solve(i+1,n,v1*10 + d2,v2*10 + d);
            for(int d1 = 0 ; d1 < 10 ; d1++)
            {
                solve(i+1,n,v1*10 + d1,v2*10 + d2);
            }
        }
        else if(y[i] == '?')
        {
            ll d1 = x[i] - '0';
            // ll d1 = (d+1)%10;
            // ll d2 = (d+9)%10;
            // solve(i+1,n,v1*10 + d,v2*10 + d);
            // solve(i+1,n,v1*10 + d,v2*10 + d1);
            // solve(i+1,n,v1*10 + d,v2*10 + d2);
            for(int d2 = 0 ; d2 < 10 ; d2++)
            {
                solve(i+1,n,v1*10 + d1,v2*10 + d2);
            }
        }
        else
        {
            ll d1 = x[i] - '0',d2 = y[i] - '0';
            solve(i+1,n,v1*10 + d1,v2*10 + d2);
        }
    }
}
int main()
{
    freopen("C:\\Users\\dell\\Downloads\\inputb.txt","r",stdin);
    freopen("C:\\Users\\dell\\Downloads\\outputb.txt","w",stdout);
    int tc,t;
    scanf("%d",&tc);
    for(t = 1 ; t<=tc ; t++) Solve(t);
    return 0;
}
void Solve(int TestCase)
{
    scanf("%s %s",x+1,y+1);
    ans.v1 = -1;
    ans.v2 = -1;
    int n = strlen(x+1);
    solve(1,n+1,0,0);
    //printf("%lld %lld %d\n",ans.v1,ans.v2,n);
    printf("Case #%d:",TestCase);
    cout<<" "<<fill(ans.v1,n)<<" "<<fill(ans.v2,n);
    printf("\n");
}
