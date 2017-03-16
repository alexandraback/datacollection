#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

int main() {
	FILE *fp = fopen("A-large.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int T;
	fscanf(fp, "%d", &T);
	for (int iii = 0; iii < T; ++iii) {
		char buf[1024];
		fscanf(fp, "%s", buf);
		string ans;
		for (int i = 0; buf[i]; ++i) {
			string a = ans + buf[i], b = buf[i] + ans;
			if (a > b) ans = a;
			else ans = b;
		}
		fprintf(fout, "Case #%d: %s\n", iii + 1, ans.c_str());
	}
	fclose(fp);
	fclose(fout);
	return 0;
}