#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>
#include<cmath>
#include<cstdio>
using namespace std;
#define REP(i,n) for(int i=0;i<n;++i)
#define REPD(i,n) for(int i=n;i>-1;--i)
#define FOR(i,j,k) for(int i=j;i<k;++i)
#define PB push_back
#define LL unsigned long long
#define MAX_S 101
#define MP make_pair

int main(){
	 int ts=0; cin>>ts;
	 REP(ww,ts)
	 {
	    LL ret = 0;
	    LL r,t;cin>>r>>t;
	    
	    LL a = 1 , b = 10000000000;
	    
	    while(a<b)
	    {
			
			LL m = (a+b)/2;
		    LL total = m * (2*r+1) + 2*m*(m-1);
			if(total<=t)
			{
				a = m + 1;
				ret = m;
			}
			else {
				b=m;
			}
		}
		
		cout<<"Case #"<<(ww+1)<<": "<<ret<<endl;
	 }
	
	return 0;
}
