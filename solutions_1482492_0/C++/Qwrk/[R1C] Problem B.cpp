#include <iostream>
#include <vector>

typedef std::pair<double, double> DD;
std::vector<DD> C;
std::vector<double> a;
int T;

int main()
{
	std::cout.setf (std::ios::fixed);
	std::cout.precision (6);

	std::cin >> T;
	for (int c = 1; c <= T; ++c) {
		double D; C.clear();
		int N, M;
		std::cin >> D >> N >> M;
		for (int i = 0; i < N; ++i) {
			DD p; std::cin >> p.first >> p.second;
			C.push_back (p);
		}
		a.resize (M);
		for (int i = 0; i < M; ++i) {
			std::cin >> a[i];
		}
		double v = 0.0;
		if (C.size() > 1) {
			v = (C.back().second - C[C.size()-2].second) / (C.back().first - C[C.size()-2].first);
		} else {
			v = C[0].second / C[0].first;
		}

		std::cout << "Case #" << c << ": \n";
		for (int i = 0; i < a.size(); ++i) {
			if (C.size() == 1) {
				double t1 = D / v;
				double t2 = sqrt ((2 * D) / a[i]);
				if (t1 > t2) {
					std::cout << t1 << '\n';
				} else {
					std::cout << t2 << '\n';
				}
			} else {
				v = C[0].second / C[0].first;
				double t1 = C[0].first;
				double t2 = sqrt ((2 * C[0].second) / a[i]);
				v = (C[1].second - C[0].second) / (C[1].first - C[0].first);
				if (t1 > t2) { // Dogonil
					if (C[1].second < D) {
						t1 = C[1].first;
						t2 = C[0].first + sqrt ((2 * (C[1].second - C[0].second)) / a[i]);
					} else {
						t1 = D / v;
						t2 = C[0].first + ((2 * (D - C[0].second)) / a[i]);
					}
					if (t1 > t2) {
						std::cout << t1 << '\n';
					} else {
						std::cout << t2 << '\n';
					}
				} else { // Nie dogonil
					if (C[1].second < D) {
						t1 = C[1].first;
						t2 = sqrt ((2 * C[1].second) / a[i]);
					} else {
						t1 = D / v;
						t2 = sqrt ((2 * D) / a[i]);
					}
					if (t1 > t2) {
						std::cout << t1 << '\n';
					} else {
						std::cout << t2 << '\n';
					}
				}
			}
		}
	}

	return 0;
}