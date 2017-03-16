#include <bits/stdc++.h>
using namespace std;

void solve(int test)
{
	int c, d, v, tmp;
	scanf("%d %d %d", &c, &d, &v);
	map <int, int> dmap;
	int den[d];
	for (int i = 0; i<d; i++){
		scanf("%d", &den[i]);
		dmap[den[i]] = 1;
	}
	int res = v;
	int f = (sqrt(1 + 8 * v) + 1)/2;
	for (int i = 0; i<(1<<(f+1)); i++){
		map <int, int> cm;
		bool done[v+1];
		memset(done, 0, sizeof(done));
		done[0]  = true;
		
		for (int j = 0; j<=f; j++){
			if (i & (1 << j)){
				if (j)cm[j] = 1;
				vector<int> ndone;
				for (int k = 0; k<=v; k++)
					if (done[k] && k + j <= v)
						ndone.push_back(k + j);
						
				for (int k = 0; k<ndone.size(); k++)
					done[ndone[k]] = true;
			}
		}
		bool ok = true;
		for (int k = 0; k <= v; k++)
			if (done[k] == false){
				ok = false;
				break;
			}
		if (ok){
			int extra = 0;
			for (auto it = cm.begin(); it != cm.end(); it++){
				if (dmap.find(it->first) == dmap.end())
					++extra;
			}

			res = min(res, extra);
		}
	}
	printf("Case #%d: %d\n", test, res);
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i<= t; i++)
		solve(i);
	return 0;
}