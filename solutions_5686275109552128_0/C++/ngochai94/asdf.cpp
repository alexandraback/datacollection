#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 0.0000001
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define maxn 32000

int t,d,val,cnt[1111],cur,res,hal,nex,tim;

int main( ){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>t;
    For(cas,1,1+t)
    {
        cin>>d;
        tim=cur=0;
        reset(cnt,0);
        while(d--)
        {
            cin>>val;
            //cout<<val<<' ';
            cur=max(cur,val);
            cnt[val]++;
        }
        //cout<<endl;
        res=cur;
        while(cur>2)
        {
            hal=(cur+1)/2;
            nex=cur-1;
            while(!cnt[nex]&&nex) nex--;
            nex=max(nex,hal);
            tim+=cnt[cur];
            cnt[cur]=0;
            cnt[cur/2]++;
            cnt[hal]++;
            cur=nex;
            res=min(res,tim+cur);
        }
        cout<<"Case #"<<cas<<": "<<res<<endl;
    }
}

