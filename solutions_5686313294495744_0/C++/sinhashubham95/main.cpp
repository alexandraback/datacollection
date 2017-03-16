/*    SHUBHAM SINHA    */



#include <bits/stdc++.h>

#define ll long long int
#define maxN 1000
#define maxVal 100000000
#define minVal -100000000
#define mod 1000000007LL

#define gcd(a,b) __gcd(a,b)

using namespace std;

struct data
{
	string a,b;
};

data p[maxN+5];
map<string,int> m1;
map<string,int> m2;
set<pair<int,int> > l,r;
set<pair<int,int> >::iterator li,ri;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef LOCAL_SYS
        freopen("C-small-attempt0.in","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t,i,j,n,c1,c2,ans,x,y;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        m1.clear();
        m2.clear();
        l.clear();
        r.clear();
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>p[j].a>>p[j].b;
            m1[p[j].a]++;
            m2[p[j].b]++;
        }
        c1=c2=0;
        for(j=0;j<n;j++)
        {
            if(m1[p[j].a]-1>0)
                l.insert(make_pair(m1[p[j].a]-1,c1++));
            if(m2[p[j].b]-1>0)
                r.insert(make_pair(m2[p[j].b]-1,c2++));
            m1[p[j].a]=0;
            m2[p[j].b]=0;
        }
        ans=0;
        while((!l.empty())&&(!r.empty()))
        {
            li=l.begin();
            ri=r.begin();
            c1=(*li).first;
            c2=(*ri).first;
            x=(*li).second;
            y=(*ri).second;
            if(c1>c2)
            {
                l.erase(li);
                r.erase(ri);
                ans=ans+c2;
                l.insert(make_pair(c1-c2,x));
            }
            else if(c1<c2)
            {
                l.erase(li);
                r.erase(ri);
                ans=ans+c1;
                r.insert(make_pair(c2-c1,y));
            }
            else
            {
                l.erase(li);
                r.erase(ri);
                ans=ans+c2;
            }
        }
        cout<<"Case #"<<i<<": "<<ans<<"\n";
    }
    return 0;
}