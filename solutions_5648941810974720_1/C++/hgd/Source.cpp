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
#include <list>
using namespace std;

char buf[2048];

int main() {
	FILE *fp = fopen("A-large.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int T;
	fscanf(fp, "%d", &T);
	for (int iii = 0; iii < T; ++iii) {
		fscanf(fp, "%s", buf);
		vector<int> ans;
		vector<int> num(256, 0);
		for (int i = 0; buf[i]; ++i) num[buf[i]]++;
		while (num['Z'] > 0) {
			ans.push_back(0);
			num['Z']--;
			num['E']--;
			num['R']--;
			num['O']--;
		}
		while (num['X'] > 0) {
			ans.push_back(6);
			num['S']--;
			num['I']--;
			num['X']--;
		}
		while (num['S'] > 0) {
			ans.push_back(7);
			num['S']--;
			num['E']--;
			num['V']--;
			num['E']--;
			num['N']--;
		}
		while (num['V'] > 0) {
			ans.push_back(5);
			num['F']--;
			num['I']--;
			num['V']--;
			num['E']--;
		}
		while (num['G'] > 0) {
			ans.push_back(8);
			num['E']--;
			num['I']--;
			num['G']--;
			num['H']--;
			num['T']--;
		}
		while (num['H'] > 0) {
			ans.push_back(3);
			num['T']--;
			num['H']--;
			num['R']--;
			num['E']--;
			num['E']--;
		}
		while (num['F'] > 0) {
			ans.push_back(4);
			num['F']--;
			num['O']--;
			num['U']--;
			num['R']--;
		}
		while (num['T'] > 0) {
			ans.push_back(2);
			num['T']--;
			num['W']--;
			num['O']--;
		}
		while (num['O'] > 0) {
			ans.push_back(1);
			num['O']--;
			num['N']--;
			num['E']--;
		}
		while (num['I'] > 0) {
			ans.push_back(9);
			num['N']--;
			num['I']--;
			num['N']--;
			num['E']--;
		}
		sort(ans.begin(), ans.end());
		fprintf(fout, "Case #%d: ", iii + 1);
		for (int i = 0; i < ans.size(); ++i) fprintf(fout, "%d", ans[i]);
		fprintf(fout, "\n");
	}
	fclose(fp);
	fclose(fout);
	return 0;
}