//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<bitset>
#include<time.h>

#define Msn(x,y) (memset((x),0,sizeof((x[0]))*(y+1)))
#define msn(x) (memset((x),0,sizeof((x))))
#define msx(x) (memset((x),0x7f,sizeof((x[0]))))
#define fuck(x) cerr << #x << " <- " << x << endl
#define acer cout<<"sb"<<endl
#define mkp(x,y) (make_pair(x,y))
#define fi first
#define se second
#define ture true
#define lch  (id<<1)
#define rch (id<<1|1)

typedef long long ll;
using namespace std;

map<int,int>mp;
map<int,int>::iterator it;
int n;

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("Bans.out","w",stdout);
    int T;
    scanf("%d",&T);
     for(int _=1;_<=T;_++)
    {
        scanf("%d",&n);
        mp.clear();
        int d;
        for(int i=0;i<2*n-1;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&d);
                mp[d]++;
            }
        }
        vector<int>p;
        for(it =mp.begin();it!=mp.end();it++)
        {
            if(it->second%2)
            {
                p.push_back(it->first);
            }
        }
        sort(p.begin(),p.end());
        cout<<"Case #"<<_<<":";
        for(int i=0;i<p.size();i++)printf(" %d",p[i]);
        cout<<endl;
    }
    return 0;
}
