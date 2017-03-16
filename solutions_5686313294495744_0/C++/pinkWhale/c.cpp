#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<set>
using namespace std;

int main() {
	int test;
	ifstream in;
	in.open("C-small-attempt0.in");
	FILE *fp2 = NULL;
	fp2 = fopen("output.txt", "w");
	in >> test;

	for (int t = 1; t <= test; t++) {
		int n;
		string first, second, combine;

		set<string> a;
		set<string> b;
		set<string> c;

		in >> n;
		while (n--) {
			in >> first >> second;
			combine = first + " " + second;
			a.insert(first);
			b.insert(second);
			c.insert(combine);
		}
		
		int ans = 0;
		for (auto i = a.begin(); i != a.end(); i++) {
			for (auto j = b.begin(); j != b.end(); j++) {
				if ((*i) == (*j))
					continue;
				combine = (*i) + " " + (*j);
				auto k = c.find(combine);
				if (k == c.end()) {
					ans++;
					c.insert(combine);
				}
			}
		}


		fprintf(fp2, "Case #%d: %d\n", t, ans);
	}

	return 0;
}