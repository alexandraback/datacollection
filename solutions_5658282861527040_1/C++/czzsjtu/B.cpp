#include <fstream>
#include <cmath>
using namespace std;

int n, a, b, m;
int p[11] = {1,2,4,8,16,32,64,128,256,512,1024};
long long ans;

void dfs(int a, int b, int m, int dep) {
	if (dep == -1) return;
	if ((m&p[dep]) > 0) {
		ans += min(a+1, p[dep]) * min(b+1, p[dep]);
		if (a>=p[dep]) ans += min(a-p[dep]+1, p[dep])*min(b+1,p[dep]);
		if (b>=p[dep]) ans += min(a+1, p[dep]) * min(b-p[dep]+1, p[dep]);
		if (a>=p[dep] && b>=p[dep]) dfs(a-p[dep], b-p[dep], m, dep-1);
	} else {
		dfs(a, b, m, dep-1);
		if (a>=p[dep]) dfs(a-p[dep], b, m, dep-1);
		if (b>=p[dep]) dfs(a, b-p[dep], m, dep-1);
	}
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin >> n;
	for (int i=1; i<=n; i++) {
		ans = 0;
		fin >>a >> b >> m;
		dfs(a-1, b-1, m, 10);
		fout << "Case #" << i << ": " << ans << endl;
	}
}
