#include<iostream>
#include<vector>
#include<algorithm>
#include <iomanip>  
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
        int n; cin>>n;
        vector<double> a(n,.0);
        vector<double> b(n,.0);
        REP(i,n) cin>>a[i];
        REP(i,n) cin>>b[i];
        
        sort(ALL(a));
        sort(ALL(b));
        
        int r1 =0 , r2 = 0;
        
        //fair game
        int b1 = 0 , b2 = b.size()-1;
        REPD(i,a.size()-1)
        {
          if(a[i]>b[b2]) { ++r2; ++b1; }
          else { --b2; }
        }
        
        b1 = 0 , b2 = b.size()-1;
        REP(i,a.size())
        {
           if(a[i]>b[b1]) { ++r1; ++b1; }
        }
        
        //unfair game
        
        cout<<"Case #"<<(tn+1)<<": "<<r1<<" "<<r2<<endl;
    }
    
    return 0;
}
