#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int nt;
	scanf("%d", &nt);
	for (int t = 1; t <= nt; t++) {
		int n;
		scanf("%d", &n);

		vector<double> naomi, ken;
		double weight;
		for (int it = 0; it < n; it++) {
			scanf("%lf", &weight);
			naomi.push_back(weight);
		}
		for (int it = 0; it < n; it++) {
			scanf("%lf", &weight);
			ken.push_back(weight);
		}
		sort(naomi.begin(), naomi.end());
		sort(ken.begin(), ken.end());

		int dec_war = 0, war = 0;

		int j = 0;
		for (int i = 0; i < n; i++) {
			if (naomi[i] > ken[j]) {
				dec_war++;
				j++;
			}
		}
		int lower_bound = 0, upper_bound = n-1;
		for (int i = n-1; i >= 0; i--) {
			if (naomi[i] > ken[upper_bound]) {
				war++;
				lower_bound++;
			}
			else {
				upper_bound--;
			}
		}
		printf("Case #%d: %d %d\n", t, dec_war, war);
	}
}