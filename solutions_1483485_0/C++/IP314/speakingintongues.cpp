#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

class speakingintongues
{
	private:
		static const int L = 100;

		const char *cmfile;
		string cfsubs;

		string sts;
		string sol;

	public:
		speakingintongues(const char *cmfile_) : cmfile(cmfile_) {
			cfsubs = string(26, ' ');
			FILE *cf = fopen(cmfile, "r");
			if (cf != NULL) {
				for (unsigned int f = 0; f < cfsubs.size(); ++f) {
					cfsubs.at(f) = fgetc(cf);
				}
				fclose(cf);
			}
		}

		void train() {
			input();
			sol = sts;
			input();
			swap(sts, sol);

			for (unsigned int f = 0; f < min(sts.size(), sol.size()); ++f) {
				if (('a' <= sts.at(f)) && (sts.at(f) <= 'z')) {
					cfsubs.at(sts.at(f) - 'a') = sol.at(f);
				}
			}

			int ccm = 0;
			for (unsigned int f = 0; f < cfsubs.size(); ++f) {
				if (cfsubs.at(f) == ' ') {
					++ccm;
				}
			}
			fprintf(stderr, "Missing substitutions: %d\n", ccm);

			FILE *cf = fopen(cmfile, "w");
			fputs(cfsubs.c_str(), cf);
			fclose(cf);
		}

		void input() {
			char *buf = new char[L + 4];
			fgets(buf, L + 2, stdin);
			buf[strlen(buf) - 1] = '\0';
			sts = buf;
			delete buf;
		}

		void solve() {
			sol = sts;
			for (unsigned int f = 0; f < sol.size(); ++f) {
				if (('a' <= sol.at(f)) && (sol.at(f) <= 'z')) {
					sol.at(f) = cfsubs.at(sol.at(f) - 'a');
				}
			}
		}

		void output(int caseno) {
			printf("Case #%d: %s\n", caseno, sol.c_str());
		}
};

int main(int argc, char **argv) {
	int nt;
	scanf("%d ", &nt);
	for(int znj = 1; znj <= nt; ++znj) {
		speakingintongues task("charmap.in");
		if (argc > 1) {
			task.train();
		} else {
			task.input();
			task.solve();
			task.output(znj);
		}
	}
	return 0;
}
