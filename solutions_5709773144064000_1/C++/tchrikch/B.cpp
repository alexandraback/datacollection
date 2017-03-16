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
    cout.precision(7);
    std::cout.setf( std::ios::fixed, std:: ios::floatfield );
    int ts;cin>>ts;
    REP(tn,ts)
    {
        double ret = .0;
        double c,f,x; cin>>c>>f>>x;
        
        double cf = .0;
        double cs = .0;
        
        ret = x / 2.0;
        
        int a = 1;
        
        while(true)
        {
           double part = .0;
           for(int i=1;i<=a;++i) part+=1.0/(2.0+((double)i-1.0)*f);
           part*=c;
           double cost = part + x/(2.0+((double)a)*f);
           if(cost<ret) { ret = cost; ++a;}
           else break;
        }
        
        cout<<"Case #"<<(tn+1)<<": "<<ret<<endl;
    }
    
    return 0;
}
