#pragma comment(linker, "/STACK:36777216")
#include <bits/stdc++.h>
using namespace std;
//----------------------------
#define fori(i, n) for (int i = 0; i < (int)(n); i++)
//#define p_b push_back
//FILE *in = fopen("input.txt", "r");
FILE *in = fopen("C-small-attempt0.in", "r");
FILE *out = fopen("output.txt", "w");
const int nMax = 1000 + 5;
int bff[nMax];
set <int> myFans[nMax];
bool stillCount[nMax];
bool globalCount[nMax];
bool used[nMax];
set <int> pairV;
int tail[nMax];
//----------------------------
void solve() {
	fori(i, nMax) {
		bff[i] = -1;
		myFans[i].clear();
		pairV.clear();
		stillCount[i] = true;
		globalCount[i] = true;
		used[i] = false;
	}
	int n, x; 
	fscanf(in, "%d", &n);
	fori(i, n) {
		fscanf(in, "%d", &x);
		bff[i+1] = x;
		myFans[x].insert(i+1);
	}
	for (int k = 0; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (stillCount[i] && myFans[i].empty()) {
				stillCount[i] = false;
				for (int j = 1; j <= n; j++) {
					if (myFans[j].find(i)!=myFans[j].end()) {
						myFans[j].erase(i);
						break;
					}
				}
			}
		}
	}
	//find max cycle
	int maxL = 0;
	for (int i = 1; i <= n; i++) {
		if (stillCount[i] && !used[i]) {
			used[i] = true;
			int p = i, cur = bff[i], l = 2;
			used[cur] = true;
			while (bff[cur] != p) {
				cur = bff[cur];
				used[cur] = true;
				l++;
			}
			if (l > 2) {
				cur = i;
				globalCount[cur] = false;
				while (globalCount[bff[cur]]) {
					cur = bff[cur];
					globalCount[cur] = false;
				}
				
			}
			if (l == 2){
				pairV.insert(i);				
			}
			maxL = max(maxL, l);
		}
	}
	//find all tails
	fori(i, nMax) {
		tail[i] = 0;
		used[i] = false;
	}
	for (int i = 1; i <= n; i++) {
		if (globalCount[i]) {
			int cur = i, next = bff[cur];
			
			while (globalCount[next] && bff[next] != cur) {
				tail[next] = max(tail[next], tail[cur] + 1);
				cur = next;
				next = bff[cur];
			}
		}
	}
	
	int maxTail = 0;
	while (!pairV.empty()) {
		int v = *(pairV.begin());
		maxTail = max(maxTail, tail[v] + tail[bff[v]]);
		pairV.erase(v);
	}
	fprintf(out, "%d\n", max(maxL, maxTail+2));
}
//----------------------------
int main()
{
	int tn;
  	fscanf(in, "%d", &tn);
  	fori(t, tn) {
	  	fprintf(out, "Case #%d: ", t + 1);
    	solve();
  	}
  	fclose(in);
    fclose(out);
  	return 0;
}
