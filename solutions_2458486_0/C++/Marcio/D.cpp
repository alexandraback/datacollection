#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i = a; i < b; ++i)
#define rep(i,n) fr(i,0,n)
#define N 21
typedef long long ll;
#define pb push_back

int mk[1<<N];
int pd[1<<N];
int nt[1<<N];
int passo;
int n, k;
int open[N];
vector<int> keys[N], start;

void muda(vector<int>& disp, int box, int fat = 1){
	rep(i, keys[box].size()) disp[keys[box][i]] += fat;
	disp[open[box]] -= fat;
}

int memo(int mask, vector<int> disp){
	if(mask == (1<<n) - 1) return pd[mask] = 1;
	// if(~pd[mask]) return pd[mask];
	if(mk[mask] == passo) return pd[mask];
	mk[mask] = passo;
	
	rep(i, n){
		if(mask & (1<<i)) continue;
		if(disp[open[i]]){
			muda(disp, i);
			if(memo(mask | (1<<i), disp)){
				nt[mask] = i;
				return pd[mask] = 1;
			}
			muda(disp, i, -1);
		}
	}
	return pd[mask] = 0;
}

void reconstroi(vector<int>& resp, int mask){
	if(mask == (1<<n) -1) return;
	// cout << mask <<  " " << n << " " << nt[mask] << endl;
	resp.pb(nt[mask]);
	reconstroi(resp, mask | (1 << nt[mask]));
}

int main(){
	int t;
	scanf("%d", &t);
	
	rep(cas, t){
		++passo;
		scanf("%d %d", &k, &n);
		start = vector<int>(300, 0);
		rep(i, n) keys[i].clear();
		
		rep(i, k){
			int tmp;
			scanf("%d", &tmp);
			++start[tmp-1];
		}
		rep(i, n){
			int qtd;
			scanf("%d%d", open + i, &qtd);
			--open[i];
			while(qtd--){
				int tmp;
				scanf("%d", &tmp);
				keys[i].pb(tmp-1);
			}
		}
		// memset(pd, -1, sizeof pd);
		vector<int> resp;
		if(memo(0, start))
			reconstroi(resp, 0);
		printf("Case #%d: ", cas+1);
		if(resp.size()){
			rep(i, resp.size()){
				if(i) printf(" ");
				printf("%d", 1+resp[i]);
			}
			printf("\n");
			
		}else printf("IMPOSSIBLE\n");	
	}
}

