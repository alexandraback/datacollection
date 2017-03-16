#include <bits/stdc++.h>
#define _PB push_back
#define _F first
#define _S second
#define _MP make_pair
#define FOR(x,y) for(__typeof(y.begin())x=y.begin();x!=y.end();x++)
using namespace std;

typedef long long LL;

const LL MOD = 1000000007;

int N,old_N;
int cnt[105];
int fa[105];
string str[105],old_str[105];
vector<int> g[105];
int id[105];

void init(){
	for (int i=0; i<105; i++){
		fa[i] = i;
		id[i] = i;
		cnt[i] = 0;
		g[i].clear();

	}
}
int f(int u){ return u == fa[u] ? u : fa[u]=f(fa[u]); }
void uni(int u, int v){
	fa[f(v)] = f(u);

}
void input(){
	init();
	cin >> N;
	old_N = N;
	memset(cnt,0,sizeof(cnt));
	for (int i=0; i<N; i++){
		cin >> str[i];
		fa[i] = i;
		id[i] = i;
		old_str[i] = str[i];
		cnt[i] = 1;
	}
}
LL calc(int id){
	//puts("start calc");
	LL res=1;
	int cnt[26];
	memset(cnt,0,sizeof(cnt));
	for (int i=0; i<(int)g[id].size(); i++){
//		printf("%d ", g[id][i]);
		if (old_str[g[id][i]][0] == old_str[g[id][i]][old_str[g[id][i]].length()-1]){
			cnt[(int)(old_str[g[id][i]][0] - 'a')]++;
		}
	}
//	puts("");
	LL jie[105];
	jie[0] = 1;
	for (int i=1; i<105; i++){
		jie[i] = jie[i-1] * i % MOD;
	//	printf("jie[%d] = %lld\n", i, jie[i]);
	}
	for (int i=0; i<26; i++){
	//	printf("count %d : %d %lld\n", i, cnt[i], jie[cnt[i]]);
		res = res * jie[cnt[i]] % MOD;
	//	printf("res = %lld\n", res);
	}
	//printf("calc %d\n", res);
	//scanf("%c");
//	system("pause");
	return res;
}
void solve(int nT){
	while (true){
		int flg=1;
		for (int i=0; i<N; i++){
			if (str[i][0] == str[i][str[i].length()-1]){
				for (int j=0; j<N; j++){
					if (i == j)
						continue;
					if (str[i][0] != str[j][0])
						continue;
					if (str[j][0] == str[j][str[j].length()-1]){
						uni(id[i],id[j]);
						id[j] = id[N-1];
						str[i] = str[i] + str[j];
						swap(str[j],str[N-1]);
						N--;
						j--;
						flg=0;
					}
				}
				if (!flg)
					break;
			}
		}
		if (flg) break;
	}
	while (true){
		int flg=1;
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				if (i == j)
					continue;
				if (str[i][str[i].length()-1] != str[j][0])
					continue;
				if (str[j][0] == str[j][str[j].length()-1]){
					uni(id[i],id[j]);
					id[j] = id[N-1];
					swap(str[j],str[N-1]);
					N--;
					j--;
					flg=0;
					break;
				}
			}
			if (!flg)
				break;
		}
		if (flg) break;
	}
//	for (int i=0; i<N; i++){
//		cout << i << " : " << str[i] << endl;
//	}

	while (true){
		int flg = 1;
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				if (i == j)
					continue;
				if (str[i][str[i].length()-1] == str[j][0]){
		//			printf("uni %d %d\n", i, j);
					str[i] = str[i] + str[j];
					cnt[i] += cnt[j];
					uni(id[i],id[j]);
					id[j] = id[N-1];
					swap(str[j],str[N-1]);
					N--;
					flg = 0;
					break;
				}
			}
			if (flg == 0)
				break;
		}
	//	for (int i=0; i<N; i++){
	//		cout << i << " : " << str[i] << endl;
	//	}
		if (flg) break;
	}
//	for (int i=0; i<N; i++){
//		cout << i << " : " << str[i] << endl;
//	}
	int fail=0;
	for (int i=0; i<N; i++){
		int app[26];
		memset(app,-1,sizeof(app));
		int j=0;
		FOR(it,str[i]){
			int u = *it - 'a';
			if (app[u] != -1){
				if (app[u] != j-1){
					fail = 1;
					break;
				}
			}
			app[u] = j;
			j++;
		}
		if (fail) break;
	}
	LL res=0;
	if (!fail){
	//	puts("Ya");
		int app[26];
		memset(app,0,sizeof(app));
		for (int i=0; i<N; i++){
			FOR(it,str[i]){
				if (app[*it - 'a']){
					fail = 1;
					break;
				}
			}
			FOR(it,str[i]){
				app[*it - 'a'] = 1;
			}
			if (fail) break;
		}
	}
	if (!fail){
		res = 1;
	//	printf("N=%d\n", N);
		for (int i=1; i<=N; i++){
			res = res * i % MOD;
		}
		N = old_N;
		for (int i=0; i<N; i++){
			g[f(i)]._PB(i);
		}
		for (int i=0; i<N; i++){
			if (i == fa[i]){
//				printf("== %d ==\n", i);
				res = res * calc(i) % MOD;
				//printf("%I64d\n", res);
			}
		}
	} else {
		res = 0;
	}

	printf("Case #%d: %lld\n", nT, res);
}

int main(int argc, char** argv){
	int nT;
	cin >> nT;
	for (int i=1; i<=nT; i++)
	{
		input();
		solve(i);
	}
}