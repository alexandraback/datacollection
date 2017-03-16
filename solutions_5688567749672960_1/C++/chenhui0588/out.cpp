//#pragma comment(linker,"/STACK:102400000,102400000")
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#define ll long long
#define db double
#define PB push_back
#define lson k<<1
#define rson k<<1|1
using namespace std;

const int N = 100005;
const int M = 25;
int length(ll k)
{
    int cnt(0);
    while(k)
    {
        cnt++;
        k /= 10;
    }
    return cnt;
}
int a[M], b[M];
bool same(ll i, ll j)
{
    int li = length(i), lj = length(j);
    if(li == lj)
    {
        int l = 0;
        for(; i; l++)
            a[l] = i % 10, i /= 10;
        for(int k = 0; k < l; k++)
            b[k] = j % 10, j /= 10;
        for(int k = 0; k < l; k++)
            if(a[k] == b[l - k - 1]) {}
            else return false;
        return true;
    }
    return false;
}

ll change(ll k)
{
    int l(0);
    for(;k;l++)
        a[l]=k%10,k/=10;
    ll nk=0;
    for(int i=0;i<l;i++)
        nk=nk*10+a[i];
    return nk;
}
ll pow10[22];
ll calc(ll k)
{
//    printf("k:  %I64d\n",k);
    int l = length(k);
    if(l == 1) return k;
    int len = (l + 1) / 2;
    ll m = pow10[len];
    ll nk = (k / m) * m + 1;
    ll cnt = k - nk + change(k / m) + 1;
    if(same(nk,nk)){}
    else cnt++;
//    printf("cnt: %I64d\n",cnt);
    return calc(pow10[l - 1] - 1) + cnt;
}

ll work(ll k)
{
    if(k % 10 == 0)
        return calc(k - 1) + 1;
    else return calc(k);
}
const int MAXN = 1000010;
int H[MAXN];
queue<int>Q;
void BFS(){
    while(!Q.empty()) Q.pop();
    memset(H,-1,sizeof(H));
    H[1] = 1;
    Q.push(1);
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();

        if(x+1<MAXN &&H[x+1]==-1){
            H[x+1] = H[x] + 1;
            Q.push(x+1);
        }

        int y = 0;
        int t = x;
        while(t){
            y = y*10 + t%10;
            t/=10;
        }

        if(y<MAXN &&H[y]==-1){
            H[y] = H[x] + 1;
            Q.push(y);
        }
    }

    for(int i=2; i<1000000; ++i){
        //if(H[i]!=H[i-1]+1)
        ll x = H[i];
        ll y = work((ll)i);
        if(x!=y){
            cout<<i<<"\t"<<x<<"\t"<<y<<endl;
            break;
        }
    }
}
int main()
{
    pow10[0] = 1LL;
    pow10[1] = 10LL;
    for(int i=2; i<20; ++i) pow10[i] = pow10[i-1]*10LL;
    //cout<<work(1001);
//    for(ll i=1; i<=10000; ++i)
//    printf("%I64d\n",work(i));
//    BFS();

    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T,ca=1;
    cin>>T;
    while(T--){
        ll x;
        cin>>x;
        cout<<"Case #"<<ca++<<": "<<work(x)<<endl;
    }
    return 0;
}
