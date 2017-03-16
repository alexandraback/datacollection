#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct letter{
	int r, l;
	int mid;
};

struct car{
	char l, r;
};

int par[105];
int rep(int a){
	return (par[a]==a)?a:par[a] = rep(par[a]);
}
bool uni(int a, int b){
	if(rep(a) == rep(b)) return 0;
	par[rep(a)] = rep(b);
	return 1;
}

int main(){
	int t;
	scanf(" %d ", &t);
	for(int x = 1; x <= t; x++){
		printf("Case #%d: ", x);
		int n, ls[30], rs[30], intn[30]; char in[105][105];
		bool pos = 1;
		letter ar[30];
		vector<car> carr;
		for(int i = 0; i < 30; i++){
			intn[i] = ls[i] = rs[i] = 0;
			ar[i].mid = 0;
			ar[i].r = ar[i].l = -1;
		}

		scanf(" %d ",&n);
		for(int i = 0; i < n; i++){
			scanf(" %s ", in[i]);
			char l = in[i][0], r = in[i][strlen(in[i])-1], prev = 0;
			if(l == r){
				for(int j = 1; j < strlen(in[i])-1; j++){
					if(in[i][j] != l) pos = 0;
				}
				if(pos) ar[l-'a'].mid++;
			}
			else{
				int sv = 0, ev = strlen(in[i])-1;				
				while(in[i][sv] == l) sv++;
				while(in[i][ev] == r) ev--;
				while(sv <= ev){
					char pr = in[i][sv];
					while(sv <= ev && in[i][sv] == pr) sv++;
					intn[pr-'a']++;
				}
				ls[l-'a']++;
				rs[r-'a']++;
				car temp;
				temp.l = l;
				temp.r = r;
				carr.push_back(temp);
				ar[l-'a'].l = carr.size()-1;
				ar[r-'a'].r = carr.size()-1;
			}
			if(!pos) break;
		}

		for(int i = 0; i < 26; i++){
			//printf("%d %d %d\n", intn[i], ls[i], rs[i]);
			if(intn[i]){
				if(intn[i] > 1) pos = 0;
				if(ls[i] > 0 || rs[i] > 0) pos = 0;
			}
			if(ls[i] > 1 || rs[i] > 1) pos = 0;
		}
		if(!pos){
			printf("0\n");
			continue;
		}
		
		int count = 0;
		for(int i = 0; i < carr.size(); i++) par[i] = i;
		for(int i = 0; i < 26; i++){
			if(ar[i].l == -1 && ar[i].r == -1){
				if(ar[i].mid > 0) count++;
				continue;
			}
			if(ar[i].l != -1 && ar[i].r != -1){
				if(!uni(ar[i].l, ar[i].r)) pos = 0;
			}
		}
		if(!pos){
			printf("0\n");
			continue;
		}

		bool seen[105];
		memset(seen, 0, sizeof seen);
		for(int i = 0; i < carr.size(); i++){
			if(!seen[rep(i)]){
				seen[rep(i)] = 1;
				count++;
			}
		}
		
		long long fact[105];
		fact[0] = 1;
		for(int i = 1; i < 105; i++){
			fact[i] = (fact[i-1]*i)%1000000007;
		}
		long long ans = fact[count];
		for(int i = 0; i < 26; i++){
			ans = (ans*fact[ar[i].mid])%1000000007;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
	
