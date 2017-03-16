#include <iostream>
using namespace std;
void prepare() {
	int total = 0;
	scanf("%d\n", &total);
	char a[1000]={0};
	char b[1000]={0};
	int i,j,n;
	char map[300]={0};
	for (int x = 0; x < total; ++x) {
		gets(a);
		gets(b);
		n  = strlen(a);
		for (i=0;i<n;++i) {
			map[a[i]] = b[i];
		}
	}
	for (i='a';i<='z';++i) {
		cout << "a['" << (char)i << "']='" << map[i] << "';\n";
	}
}
void solve() {
	char a[300]={0};
	a[' '] = ' ';
	a['a']='y';
	a['b']='h';
	a['c']='e';
	a['d']='s';
	a['e']='o';
	a['f']='c';
	a['g']='v';
	a['h']='x';
	a['i']='d';
	a['j']='u';
	a['k']='i';
	a['l']='g';
	a['m']='l';
	a['n']='b';
	a['o']='k';
	a['p']='r';
	a['q']='z';
	a['r']='t';
	a['s']='n';
	a['t']='w';
	a['u']='j';
	a['v']='p';
	a['w']='f';
	a['x']='m';
	a['y']='a';
	a['z']='q';
	int total = 0, n;
	scanf("%d\n", &total);
	char b[1000]={0};
	for (int x = 0; x < total; ++x) {
		gets(b);
		n  = strlen(b);
		cout << "Case #" << x + 1 << ": ";
		for (int i=0;i<n;++i) {
			cout << a[b[i]];
		}
		cout << "\n";
	}

}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//prepare();
	solve();

	return 0;
}