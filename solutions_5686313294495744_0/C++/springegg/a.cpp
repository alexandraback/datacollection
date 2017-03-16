#include <iostream>
#include <vector>
#include <map>
#define maxn 1010
#define maxm 1010
using namespace std;

map<string, int> mm1, mm2;
int tot1, tot2;
int tot;
int first[maxn], match[maxn]; 
int nxt[maxm], en[maxm];
bool visit[maxn];

int add_edge(int x, int y){
//	cout << x << " " << y << endl;
	nxt[tot] = first[x];
	first[x] = tot;
	en[tot] = y;
	++tot;
}

int find(map<string, int> &mm, const string &s, int &tot)
{
	if(!mm.count(s)){
		first[tot] = -1;
		mm[s] = tot++;
	}
	return mm[s];
}

bool get_match(int x){
	int k = first[x];
	while(k != -1){
		int j = en[k];
		if (!visit[j]) {
			visit[j] = true;
			if(match[j] == -1 || get_match(match[j])){
				match[j] = x;
				return true;
			}
		}
		k = nxt[k];
	}
	return false;
}

void solve()
{
	int n;
	cin >> n;
	tot = 0;
	tot1 = tot2 = 0;
	for(int i = 0; i < n; ++i){
		string s1, s2;
		cin >> s1 >> s2;
		int x = find(mm1, s1, tot1), y = find(mm2, s2, tot2);
		add_edge(x, y);
	}
	int	res = 0;
	for (int i = 0; i < tot2; ++i){
		match[i] = -1;
	}
	for (int i = 0; i < tot1; ++i){
		for(int j = 0; j < tot2; ++j) visit[j] = false;
		if(get_match(i)) ++res;
	}
	//cout << tot1 << endl;
	//cout << tot2 << endl;
	//cout << res << endl;
	cout << n - (tot1 + tot2 - res) << endl;
}

int main() 
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
