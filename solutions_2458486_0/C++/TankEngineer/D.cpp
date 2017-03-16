#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int k, n, tmp, key[22], nowkey[22];
vector<int> st, ret[22];

int choose[1 << 22];
bool f[1 << 22], g[1 << 22];

int main() {
	
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for (int V = 1; V <= T; ++V) {
	  scanf("%d %d", &k, &n);
	  st.clear();
		for (int i = 1; i <= k; ++i) {
			scanf("%d", &tmp);
			st.push_back(tmp);
	  }
	  
	  for (int i = 0; i < n; ++i) {
	  	ret[i].clear();
	    scanf("%d", &key[i]);
	    int t;
			scanf("%d", &t);
	    for (int j = 1; j <= t; ++j) {
	      scanf("%d", &tmp);
	      ret[i].push_back(tmp);
			}
		}
		
		//cout << "F strat" << endl;
		
		memset(f, 0, sizeof(f));
		f[0] = true;
		for (int i = 0; i < (1 << n); ++i) {
		  if (f[i]) {
		    //get key status
		    memset(nowkey, 0, sizeof(nowkey));
		    for (int j = 0; j < st.size(); ++j) {
		      nowkey[st[j]]++;
				}
				for (int j = 0; j < n; ++j) {
				  if (i & (1 << j)) {
				    nowkey[key[j]]--;
						for (int k = 0; k < ret[j].size(); ++k) {
				      nowkey[ret[j][k]]++;
						}
					}
				}
		    
		    //enum next chest
		    for (int j = 0; j < n; ++j) {
		      if ((i & (1 << j)) == 0) {
		        if (nowkey[key[j]]) {
		          f[i | (1 << j)] = true;
						}
					}
				}
			}
		}
		
		if (!f[(1 << n) - 1]) {
		  printf("Case #%d: IMPOSSIBLE\n", V);
		  continue;
		}
		
		//cout << "G start" << endl;
		
		memset(g, 0, sizeof(g));
		g[(1 << n) - 1] = true;
		for (int i = (1 << n) - 1; i >= 0; --i) {
		  if (f[i]) {
		    //get key status
		    memset(nowkey, 0, sizeof(nowkey));
		    for (int j = 0; j < st.size(); ++j) {
		      nowkey[st[j]]++;
				}
				for (int j = 0; j < n; ++j) {
				  if (i & (1 << j)) {
				    nowkey[key[j]]--;
						for (int k = 0; k < ret[j].size(); ++k) {
				      nowkey[ret[j][k]]++;
						}
					}
				}
		    
		    //enum next chest
		    for (int j = 0; j < n; ++j) {
		      if ((i & (1 << j)) == 0) {
		        if (nowkey[key[j]] && g[i | (1 << j)]) {
		        	g[i] = true;
		        	choose[i] = j + 1;
		        	break;
						}
					}
				}		    
			}
		}
		
		printf("Case #%d:", V);
	  int t = 0;
		for (int i = 1; i <= n; ++i) {
		  printf(" %d", choose[t]);
		  t = t | (1 << (choose[t] - 1));
		}
		printf("\n");
	}
	return 0;
}

