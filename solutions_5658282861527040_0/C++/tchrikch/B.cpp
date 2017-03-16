#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<sstream>
#define REP(i,n) for(int i=0;i<n;++i)
#define FOR(i,j,k) for(int i=j;i<k;++i)
#define REPD(i,n) for(int i=n;i>-1;--i)
#define ALL(v) v.begin(),v.end()
#define ll long long
#define PB push_back
using namespace std;



int main()
{
    int ts;cin>>ts;
    REP(tn,ts)
    {
          cout<<"Case #"<<(tn+1)<<": ";
          int ret = 0;
              int a,b,k; cin>>a>>b>>k;
           
           REP(i,a) 
            REP(j,b)
             {
                    int r = i&j;
                 //   cout<<endl<<i<<" "<<j<<" "<<(i&j)<<" "<<k<<endl;
                    if( r < k) ++ret;}
              
             cout<<ret<<endl;
        
    }
    
    return 0;
}
