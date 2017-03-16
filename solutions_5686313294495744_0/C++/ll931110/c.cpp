#include <cstdio>
#include <map>
#include <iostream>
#include <cstring>
#include <vector>
#define maxn 1005
using namespace std;

vector<int> G[maxn];
bool seen[50000+5];
int matchL[50000+5],matchR[1000+5];
int T, n;
map<string, int> mp_left, mp_right;

bool bpm(int u)
{
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(seen[v])
            continue;
        seen[v]=true;

        if(matchR[v]<0 || bpm( matchR[v] ))
        {
            matchR[v]=u;
            matchL[u]=v;
            return true;
        }


    }
    return false;
}

int find_max_matching() {
	int cnt = 0;
	for (int i = 0; i < mp_left.size(); i++) {
		memset(seen, false, sizeof seen);
		if (bpm(i)) {
			cnt++;
		}
	}
	return cnt;
}

int get_left(string s) {
	if (mp_left.find(s) == mp_left.end()) {
		mp_left[s] = mp_left.size();
	}
	return mp_left[s];
}

int get_right(string s) {
	if (mp_right.find(s) == mp_right.end()) {
		mp_right[s] = mp_right.size();
	}
	return mp_right[s];
}

int main() {
	scanf("%d", &T);
	for (int it = 1; it <= T; it++) {
		scanf("%d", &n);
		
		for (int i = 0; i < mp_left.size(); i++) {
			G[i].clear();
		}
		mp_left.clear();
		mp_right.clear();

		// memset(seen, false, sizeof(seen));
		memset(matchL, -1, sizeof matchL);
		memset(matchR, -1, sizeof matchR);

		for (int i = 0; i < n; i++) {
			string l, r;
			cin >> l >> r;
			int l_index = get_left(l);
			int r_index = get_right(r);
			G[l_index].push_back(r_index);
		}
		int r_count = find_max_matching();
		int real_count = mp_left.size() + mp_right.size() - r_count;
		printf("Case #%d: %d\n", it, n - real_count);
	}
	return 0;
}