#include<cstdlib>
#include<cstdio>
#include<vector>
using namespace std;

int main() {
	FILE* in = fopen("A-small.in", "r");
	FILE* out = fopen("A-small.out", "w");

	int n;
	fscanf(in, "%d", &n);
	for(int i = 0; i < n; ++i) {
		int nContestants;
		double sum = 0;
		double final;
		vector<double> s;
		fscanf(in, "%d", &nContestants);
		for(int j = 0; j < nContestants; ++j) {
			double tmp;
			fscanf(in, "%lf", &tmp);
			s.push_back(tmp);
			sum += tmp;
		}

		final = 2.0 * sum / (double)nContestants;

		fprintf(out, "Case #%d:", i + 1);
		double dist = 0.0;
		int below = 0;
		vector<double> res;
		for(int j = 0; j < s.size(); ++j) {
			double ret = ((final - s[j]) / sum) * 100;
			if(ret < 0.0) {
				dist += ret;
				++below;
			}
		}
		dist /= (nContestants - below);
		for(int j = 0; j < s.size(); ++j) {
			double ret = ((final - s[j]) / sum) * 100;
			if(ret < 0.0) {
				fprintf(out, " %.6lf", 0.0);
			}
			else {
				fprintf(out, " %.6lf", ret + dist);
			}

		}
		fprintf(out, "\n");
	}

	fclose(in);
	fclose(out);

	return 0;
}
