#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

int main() {
	FILE *fp = fopen("B-small-attempt0.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int T;
	fscanf(fp, "%d", &T);
	for (int iii = 0; iii < T; ++iii) {
		char tmp[256];
		fscanf(fp, "%s", tmp);
		string start(tmp), goal(start);
		for (char &c : goal) c = '+';
		if (start == goal) {
			fprintf(fout, "Case #%d: 0\n", iii + 1);
			continue;
		}
		unordered_set<string> v;
		struct data {
			string s;
			int step;
		};
		queue<data> q;
		q.push({ start, 0 });
		v.insert(start);
		bool done = false;
		while (!done) {
			data t = q.front();
			q.pop();
			for (int i = 0; i < t.s.size(); ++i) {
				string news = t.s;
				for (int j = 0; j <= i; ++j) news[j] = '+' + '-' - news[j];
				for (int j = 0; j < i - j; ++j) swap(news[j], news[i - j]);
				if (news == goal) {
					fprintf(fout, "Case #%d: %d\n", iii + 1, t.step + 1);
					done = true;
					break;
				}
				if (v.find(news) != v.end()) continue;
				q.push({ news, t.step + 1 });
				v.insert(news);
			}
		}
	}
	fclose(fp);
	fclose(fout);
	return 0;
}