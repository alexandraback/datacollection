#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
typedef long long ll;
const int MOD = 1000003;

ll mymap[10000001];
int ctr;

void reverse(ll &val)
{
    ll n,rev=0,d;
    n = val;
    while(n!=0)
    {
        d=n%10;
        rev=(rev*10)+d;
        n=n/10;
    }
    val = rev;
}


void bfs(ll n)
{
    queue<ll>Q;
    Q.push(1);
    mymap[1] = 1;
    ll tmp,tem1,tem2;
    while(!Q.empty())
    {
        tmp = Q.front();
        Q.pop();
        if(tmp==n)
        {
            printf("Case #%d: %d\n",ctr++,mymap[tmp]);
            return;
        }
        tem1 = tmp;
        reverse(tem1);
        tem2 = tmp +1;
        if(!mymap[tem1])
        {
            Q.push(tem1);
            mymap[tem1] = mymap[tmp]+1;
        }
        if(!mymap[tem2])
        {
            Q.push(tem2);
            mymap[tem2] = mymap[tmp]+1;
        }
    }
}

int main(int argc, char *argv[]) {
    //ios_base::sync_with_stdio(false);
    freopen("A-small-attempt1.in","r",stdin);
	freopen("output.out","w",stdout);
    ll t,l,k,i,j,n;
    //string str;
    cin>>t;
    ctr = 1;
    while(t--)
    {
        memset(mymap,0,sizeof(mymap));
        cin>>n;
        bfs(n);
    }
    return 0;
}
