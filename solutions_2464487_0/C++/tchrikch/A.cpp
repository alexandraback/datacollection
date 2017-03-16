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
#define LL long long
#define MAX_S 101
#define MP make_pair

int main(){
	
	
	 int ts; cin>>ts;
	 REP(ww,ts)
	 {
	    LL ret = 0;
	    LL r,t;cin>>r>>t;
		
		while(true)
		{
			LL cost = 2 * r +1;
			if(t>=cost) {++ret;t-=cost;
			}
			else break;
			
			r+=2;
			
		}
		
		cout<<"Case #"<<(ww+1)<<": "<<ret<<endl;
	 }
	
	return 0;
}
