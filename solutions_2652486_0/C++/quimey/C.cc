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

int main()
{
    int T,R,N,M,K;
    cin>>T>>R>>N>>M>>K;
    cout<<"Case #1:"<<endl;
    int cnt=0;
    forn(t,R)
    {
        vector<int> v(K);
        forn(i,K)cin>>v[i];
        vector<int>p;
        forn(i,K)if(v[i]%3==0){p.pb(3);break;}
        forn(i,K)if(v[i]%9==0){p.pb(3);break;}
        forn(i,K)if(v[i]%5==0){p.pb(5);break;}
        forn(i,K)if(v[i]%25==0){p.pb(5);break;}
        forn(i,K)if(v[i]%8==0 and p.size()){p.pb(4);break;}
        forn(i,K)if(v[i]%2==0 and v[i]%4!=0){p.pb(2);break;}
        forn(i,K)if(v[i]%16==0){p.pb(4);break;}
        if(p.size()==2)
        {
            int x=p[0]*p[1];
            forn(i,K)if(v[i]%x==0 and v[i]>x){p.pb(v[i]/x);break;}
        }
        if(p.size()==3)
        {
            //cout<<"voila!"<<endl;
            cnt++;
        }
        while(p.size()<3)p.pb(2+rand()%4);
        forn(i,p.size())cout<<p[i];
        cout<<endl;
    }
    //cout<<cnt<<endl;
}
