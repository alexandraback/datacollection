#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>
#include<stack>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
#define REP(i,n) for(int i=0;i<n;++i)
#define REPD(i,n) for(int i=n;i>-1;--i)
#define FOR(i,j,k) for(int i=j;i<k;++i)
#define PB push_back
#define LL unsigned long long
#define MAX_S 101
#define MP make_pair
#define ALL(v) v.begin(),v.end()
#define MAXX 100
#define MAXY 100

struct wall{
	int x;
	int y;
	int h;
};

int main(){
	 int ts=0; cin>>ts;
	 REP(ww,ts)
	 {
	    LL ret = 0;
	    
	    int N;cin>>N;
	    
	    vector<int> d(N,0),n(N,0),w(N,0),e(N,0),s(N,0),deltaD(N,0),deltaP(N,0),deltaS(N,0);
	    REP(i,N) cin>>d[i]>>n[i]>>w[i]>>e[i]>>s[i]>>deltaD[i]>>deltaP[i]>>deltaS[i];
	    vector<int> pA(N,0);
	    vector<int> level(600,0);
	    vector<int> interval(600,0);
	    vector<pair<int,int> > attack;
	    REP(i,N)REP(j,n[i]) attack.PB(MP(d[i]+j*deltaD[i],i));
	   // REP(i,attack.size()) cout<<attack[i].first<<" "<<(attack[i].second+1)<<endl;
		sort(ALL(attack));
		//REP(i,attack.size()) cout<<attack[i].first<<" "<<(attack[i].second+1)<<endl;
		//cout<<endl;
		int wsk = 0;
		
		while(wsk<attack.size())
		{
			vector<int> tribes; tribes.PB(attack[wsk].second);
			while(wsk+1<attack.size() && attack[wsk+1].first==attack[wsk].first)
			 {
					tribes.PB(attack[wsk+1].second);
					++wsk;
			 }
			 
			 vector<wall> aWs;
			 
			 REP(i,tribes.size())
			 {
					int tN = tribes[i];
					int aN = pA[tN];
					pA[tN]++;
					int aS = s[tN] + deltaS[tN]  * aN;
					int lw = w[tN] + aN * deltaP[tN];
					int le = e[tN] + aN * deltaP[tN];
										
					wall aW; aW.x = lw; aW.y = le; aW.h = aS;
				    aWs.PB(aW);
					
				//	cout<<(tN+1)<<" "<<aN<<" "<<aS<<" "<<lw<<" "<<le<<endl;
				//	FOR(j,0,10) cout<<level[j+300]<<" "; cout<<endl;
				//	FOR(j,0,10) cout<<interval[j+300]<<" "; cout<<endl;

				    FOR(j,lw,le+1) 
				    {
						if(level[j+300]<aS ||( interval[j+300]<aS && j!=lw)) {
							
					//	cout<<"!"<<j<<" "<<level[j+300]<<" "<<interval[j+300]<<" "<<aS<<endl;
							 
						 ++ret;break;
						}
					}
								//		cout<<"---"<<endl;
			 }
			 
			 REP(j,aWs.size())
			 {
					FOR(k,aWs[j].x,aWs[j].y+1) 
					{	  
						level[k+300] = max(level[k+300],aWs[j].h);
					}
					
					FOR(k,aWs[j].x+1,aWs[j].y+1)
					 interval[k+300] = max(interval[k+300],aWs[j].h);
			 }

			 ++wsk;
		}
	    
		cout<<"Case #"<<(ww+1)<<": "<<ret<<endl;
	 }
	
	return 0;
}
