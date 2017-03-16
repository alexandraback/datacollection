#include <iostream>
#include <set>
#include <vector>
#include <set>
using namespace std;
vector<int> dp[1048576]={};				//2shin bit 0ketame 0
vector<int> vcit;
multiset<int> key[1048576];
multiset<int> getkey[200];
multiset<int>::iterator it;
void init(){
	for(int i=0;i<1048576;i++) dp[i].clear();
	for(int i=0;i<1048576;i++) key[i].clear();
	for(int i=0;i<200;i++) getkey[i].clear();
}
int main(){
	int times;
	cin >> times;
	for(int i=1;i<=times;i++){
		init();
		int k,n;
		int t[200]={};
		cin >> k >> n;
		for(int j=0;j<k;j++){
			int hoge;
			cin >> hoge;
			hoge--;
			key[0].insert(hoge);
		}
		for(int j=0;j<n;j++){
			int kj;
			cin >> t[j] >> kj;
			t[j]--;
			for(int h=0;h<kj;h++){
				int hoge;
				cin >> hoge;
				hoge--;
				getkey[j].insert(hoge);
			}
		}
		for(int open=0;open<n;open++){			//the num of opened boxes
			int comb=(1 << open)-1;
			while(comb < (1 << n)){
				if(!dp[comb].empty() || comb==0){
					for(int j=0;j<n;j++){
						if(comb >> j & 1) continue;
						if(key[comb].count(t[j])==0) continue;
						int next=comb | (1<<j);
						if( dp[next].empty() ){
							for(it=key[comb].begin();it!=key[comb].end();it++){
								key[next].insert(*it);
							}
							for(it=getkey[j].begin();it!=getkey[j].end();it++){
								key[next].insert(*it);
							}
							key[next].erase( key[next].lower_bound(t[j]) );
							dp[next]=dp[comb];
							dp[next].push_back(j);
						}
						else{
							vector<int> hoge=dp[comb];
							hoge.push_back(j);
							if(dp[next]>hoge) dp[next]=hoge;
						}
/*						cout << next << "  :";
						for(int ddd=0;ddd<dp[next].size();ddd++){
							cout << dp[next][ddd]+1 << " ";
						}
						cout << "      keys:";
						for(it=key[next].begin();it!=key[next].end();it++){
							cout << (*it)+1 << " ";
						}
						cout << endl;
*/
					}
				}
				if(comb==0) break;
				int x=(comb)&(-comb),y=comb+x;
				comb=(  ( (comb & ~y)/x ) >> 1  ) | y;
			}
		}
		cout << "Case #" << i << ": ";
		if(dp[(1<<n)-1].empty()) cout << "IMPOSSIBLE" << endl;
		else{
			for(int j=0;j<n;j++) cout << dp[(1<<n)-1][j]+1 << " ";
			cout << endl;
		}
/*
		for(int dd=0;dd<(1 << n);dd++){
			for(int hoge=0;hoge<dp[dd].size();hoge++) cout << dp[dd][hoge] << " ";
			cout << endl;
		}
*/
	}
	return 0;
}