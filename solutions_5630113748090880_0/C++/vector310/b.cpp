#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#define rep(i, l, r) for(int i = l; i <= r; ++i)
using namespace std;
int n;
map<int, int> m;
int ans[101];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int cas;
	cin >> cas;
	rep(Cas, 1, cas){
		cin >> n;
		m.clear();
		rep(i, 1, 2 * n - 1)
			rep(j, 1, n){
				int v;
				scanf("%d", &v);
				if(!m.count(v)) m[v] = 1;
				else ++m[v];
			}
		int p = 0;
		for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
			if((*it).second & 1){
				ans[++p] = (*it).first;
			}
		sort(ans + 1, ans + p + 1);
		printf("Case #%d: ", Cas);
		rep(i, 1, p) printf("%d%c", ans[i], i == p ? '\n' : ' ');
	}
	return 0;
}
