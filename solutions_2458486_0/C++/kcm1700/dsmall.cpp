#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <functional>
#include <utility>

using namespace std;

int k,n;
int keys[512]; // number of keys obtained.
int req[200]; // key requirement for the i-th chest.
vector<int> add[200]; // the keys which will be obtained by using i-th chest.
vector<int> chestsfromkey[512]; // the chests which requires i-th key.
int used[200];

int need[512];
void usechest(int i)
{
	used[i] = 1;
	keys[req[i]]--;
	for(int j = 0; j < add[i].size(); j++) {
		keys[add[i][j]]++;
	}
	need[req[i]]--;
}
void unusechest(int i)
{
	used[i] = 0;
	keys[req[i]]++;
	for(int j = 0; j < add[i].size(); j++) {
		keys[add[i][j]]--;
	}
	need[req[i]]++;
}

int v[200],vcnt;
int vk[512];
int findcycle(int chest, int key)
{
	v[chest] = vcnt;
	for(int i = 0; i < add[chest].size(); i++) {
		int nkey = add[chest][i];
		if (nkey == key) return 1;
		if (vk[nkey] == vcnt) continue;
		vk[nkey] = vcnt;
		for(int j = 0; j < chestsfromkey[nkey].size(); j++) {
			int nchest = chestsfromkey[nkey][j];
			if (v[nchest] == vcnt) continue;
			if (findcycle(nchest, key)) return 1;
		}
	}
	return 0;
}

int checkPossible()
{
	static int _used[200];
	static int _keys[512];
	memcpy(_used, used, sizeof(used));
	memcpy(_keys, keys, sizeof(keys));
	memset(need,0,sizeof(need));

	for(int i = 0; i < n; i++) {
		if (used[i]) continue;
		need[req[i]]++;
	}

	for(int i = 0; i < n; i++) {
		if (used[i]) continue;
		if (keys[req[i]] == 0) continue;
		if (find(add[i].begin(), add[i].end(), req[i]) != add[i].end()) {
			usechest(i);
		}
	}

	while(1)
	{
		int flg = 0;
		for(int i = 0; i < n; i++) {
			int key = req[i];
			if (used[i]) continue;
			if (add[i].size() == 0) continue;
			if (keys[key] == 0) continue;
			if (keys[key] != 1) {
				flg = 1;
				usechest(i);
			} else {
				if (need[key] > 1) {
					++vcnt;
					if(findcycle(i,key)) {
						flg = 1;
						usechest(i);
					}
				} else {
					flg = 1;
					usechest(i);
				}
			}
		}
		if (flg == 0) break;
	}

	int ret = 1;
	for(int i = 0; i < n; i++){ 
		if (used[i]) continue;
		if (keys[req[i]] == 0) {
			ret = 0;
			break;
		}
		usechest(i);
	}

	memcpy(used, _used, sizeof(used));
	memcpy(keys, _keys, sizeof(keys));
	return ret;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int testcase=1; testcase<=T; testcase++){
		scanf("%d%d",&k,&n);
		memset(keys,0,sizeof(keys));
		memset(used,0,sizeof(used));
		for(int i = 0; i < 400; i++) {
			chestsfromkey[i].clear();
		}
		for(int i = 0; i < k; i++) {
			int v;
			scanf("%d",&v); v--;
			keys[v]++;
		}
		for(int i = 0; i < n; i++) {
			scanf("%d",&req[i]); req[i]--;
			chestsfromkey[req[i]].push_back(i);
			int cnt;
			scanf("%d",&cnt);
			add[i].clear();
			while(cnt-->0){
				int val;
				scanf("%d",&val); val--;
				add[i].push_back(val);
			}
		}
		vector<int> ans;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if (used[j]) continue;
				if (keys[req[j]] == 0) continue;
				usechest(j);
				if (checkPossible()) {
					ans.push_back(j);
					break;
				}
				unusechest(j);
			}
		}
		printf("Case #%d:", testcase);
		if (ans.size() != n) {
			printf(" IMPOSSIBLE\n");
		} else {
			for(int i = 0; i < n; i++) {
				printf(" %d", ans[i] + 1);
			}
			printf("\n");
		}
	}
	return 0;
}
