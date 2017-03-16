#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)
#define all(v) v.begin(),v.end()

typedef long long int tint;

tint pow(int x,int y)
{
    return y==0?1:x*pow(x,y-1);
}

vector<vector<vector<int> > >facts;

void bt(int x,vector<int>&f,int p,int m)
{
    if(x==1)
    {
        facts[p].pb(f);
        return;
    }
    f.pb(1);
    for(int i=m;i<9;i++)if(x%i==0)
    {
        f[f.size()-1]=i;
        x/=i;
        bt(x,f,p,i);
        x*=i;
    }
    f.pop_back();
}

int main()
{
    int T,R,N,M,K;
    cin>>T>>R>>N>>M>>K;
    cout<<"Case #1:"<<endl;
    int cnt=0;
    forn(t,R)
    {
        vector<tint> v(K);
        forn(i,K)cin>>v[i];
        vector<int>p;
        vector<int>f;
        facts.clear();
        facts.resize(K);
        int calc[10];
        forn(i,10)calc[i]=0;
        forn(i,K)bt(v[i],f,i,2);
        forn(i,K)
        {
            forn(d,10)
            {
                int c=100;
                forn(j,facts[i].size())if(rand()%3==0)
                {
                    int a=0;
                    forn(k,facts[i][j].size())if(facts[i][j][k]==d)a++;
                    c=min(c,a);
                }
                if(c==100)c=0;
                calc[d]=max(c,calc[d]);
            }
        }
        //forn(d,10)cout<<calc[d]<<endl;
        /*forn(i,K)
        {
            forn(j,facts[i].size())
            {
                forn(k,facts[i][j].size())cout<<facts[i][j][k];
                cout<<endl;
            }
            cout<<endl;
        }*/
        forn(i,10)forn(j,calc[i])p.pb(i);
        if(p.size()>=12)cnt++;
        //cout<<p.size()<<endl;
        while(p.size()<12)p.pb(2+rand()%7);
        //if(p.size()>12)cnt--;
        p.resize(12);
        forn(i,p.size())cout<<p[i];
        cout<<endl;
    }
    cerr<<cnt<<endl;
}
