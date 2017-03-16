#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>

#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORD(i,n) for(int i=n;i>=0;i--)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define FORRD(i,n,s) for(int i=n,_s=s;i>=_s;i--)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define vi vector<int>
#define fs first
#define sec second

#define maxn 100000
using namespace std;
typedef long long ll;

struct path{
	vi pth;
	ll used_keys;
	ll box;
};


vi keys;
vi kk[22];

ll uid[22];
ll can_unlock[22];
ll has[22];

bool vis[1 << 21];
deque<path> dq;

int main(){
	int t,k,n,tmp,key,keycnt;
	ll start;
	
	cin>>t;
	FOR(ttt,t){
		cin>>k>>n;

		memset(vis,0,sizeof vis);
		memset(can_unlock,0LL,sizeof can_unlock);
		memset(has,0LL,sizeof has);
		
		dq.clear();	
		keys.clear();
		
		FOR(i,20) kk[i].clear();
		
		start=0LL;
		FOR(i,k){
			cin>>key;
			keys.pb(key);
			start |= (1LL << i);
		}
		FOR(i,n){
			cin>>uid[i]>>keycnt;
			while(keycnt--){
				cin>>key;
				keys.pb(key);
				kk[i].pb(keys.size() - 1);
			}
		}
		
		FOR(i,n){
			FOR(j,keys.size())
				if(keys[j]==uid[i]) can_unlock[i] |= (1LL << j);
			FOR(j,kk[i].size())
				has[i] |= (1LL << kk[i][j]);
		}
		
		cout<<"Case #"<<ttt + 1<<":";

		dq.pb((path){vector<int>(),0,0});
		
		vi best;
		while(!dq.empty()){
			path top=dq.front();
			dq.pop_front();
						
			if(top.box == ((1LL << n) - 1LL)){		
				if(best.size() == 0)
					best.assign(top.pth.begin(),top.pth.end());
				break;
			}

			if(vis[top.box]) continue;
			vis[top.box]=true;
			ll active_keys=start;
			
			FOR(i,n) 
				if(top.box & (1LL << i))
					active_keys |= has[i];
			
			active_keys &= (~top.used_keys);
		
			FOR(i,n)
				if(((top.box & (1 << i)) == 0) && ((active_keys & can_unlock[i]) != 0)){
					ll t_used=top.used_keys;
					FOR(jj,keys.size())
						if((active_keys & can_unlock[i]) & (1LL << jj))
						{ t_used |= (1LL << jj); break; }
					ll b_box=top.box | (1LL << i);
					vi t_vec;
					t_vec.assign(top.pth.begin(),top.pth.end());
					t_vec.pb(i);
					dq.pb((path){t_vec,t_used,b_box});
				}
		}
		if(best.size() == 0) cout<<" IMPOSSIBLE\n";
		else{
			FOR(i,best.size()) cout<<" "<<best[i] + 1;
			cout<<"\n";
		}
		
	}
	return 0;
}
