#include <iostream>
#include <set>
using namespace std;
int d[50]={0};
int p[50]={0};
int len;
int ten[50]={1};
void prepare(int a) {
	len = 0;
	int i,j;
	while (a) {
		d[len++] = a % 10;
		a /= 10;
	}
	for (int i = 0; i < len / 2; ++i) {
		swap(d[i], d[len - 1 - i]);
	}
	int ten = 1;
	for (i=0;i<len-1;++i) {
		ten *= 10;
	}
	for (i=0;i<len;++i) {
		p[i] = ten * d[i];
		ten /= 10;
	}
}
set <pair<int,int> > was;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t,q,a,b,n,i,l,r,c,res,j;
	for (i=1;i<=20;++i) {
		ten[i] = ten[i-1] * 10;
	}

	cin >> t;
	pair <int, int> w;
	for (q=1;q<=t;++q) {
		cin >> a >> b;
		res = 0;
		for (i=a;i<=b;++i) {
			prepare(i);
			l = 0;
			r = i;
			was.clear();
			for (j=0;j<len-1;++j) {
				l *= 10;
				l += d[j];
				r -= p[j];
				c = r * ten[j + 1] + l;
				w = make_pair(i, c);
				if (c >= a && c <= b && c > i) {
					if (was.find(w)==was.end()) {
						++res;
						was.insert(w);
						//cout << "\t" << i << " " << c << "\n";
					} else {
						//cout << i << " ! " << c << "\n";
					}
				}
			}
		}
		cout << "Case #" << q << ": " << res << "\n";
	}
	return 0;
}