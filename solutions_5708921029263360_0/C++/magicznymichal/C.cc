#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

struct three {
	three(int a, int b, int c) {
		he[0] = a;
		he[1] = b;
		he[2] = c;
	}
	int he[3];
};

int main() {
	
	int t;
	std::cin >> t;

	for (int test = 0; test < t; ++test) {
		std::cout << "Case #" << (test + 1) << ": ";

		int J, P, S, K;
		std::cin >> J >> P >> S >> K;

		int j, p, s;
		j = J;
		p = P;
		s = S;

		std::vector<three> sets;

		int maxj, maxp, maxs;

		{
			int firstj = std::min(j, K);
			int firstp = std::min(p, K);
			int firsts = std::min(s, K);
			for (int i1 = 0; i1 < firstj; ++i1) {
				for (int i2 = 0; i2 < firstp; ++i2) {
					for (int i3 = 0; i3 < firsts; ++i3) {
						three new_three(j-i1, p-i2, s-i3);
						sets.push_back(new_three);
					}
				}
			}
			j -= firstj;
			p -= firstp;
			s -= firsts;
			maxj = firstj;
			maxp = firstp;
			maxs = firsts;
		}


		while (j >= K) {
			int firstj = std::min(j, K);
			int firstp = std::min(p, K);
			int firsts = std::min(s, K);
			for (int i1 = 0; i1 < firstj; ++i1) {
				for (int i2 = 0; i2 < firstp; ++i2) {
					for (int i3 = 0; i3 < firsts; ++i3) {
						three new_three(j-i1, p-i2, s-i3);
						sets.push_back(new_three);
					}
				}
			}
			j -= firstj;
			p -= firstp;
			s -= firsts;
		}

		if (j < K) {
			while (p > 0) {
				int firstp = std::min(p, K);
				int firsts = std::min(s, K);
				for (int i1 = 0; i1 < maxj; ++i1) {
					for (int i2 = 0; i2 < firstp; ++i2) {
						for (int i3 = 0; i3 < firsts; ++i3) {
							three new_three(J-i1, p-i2, s-i3);
							sets.push_back(new_three);
						}
					}
				}
				p -= firstp;
				s -= firsts;
			}
		} 

		if (s > 0 && j > 0) {
			while (s > 0 && j > 0) {
				int firstj = std::min(j, K);
				int firsts = std::min(s, K);

				for (int i1 = 0; i1 < firstj; ++i1) {
					for (int i2 = 0; i2 < maxp; ++i2) {
						for (int i3 = 0; i3 < firsts; ++i3) {
							three new_three(j-i1, P-i2, s-i3);
							sets.push_back(new_three);
						}
					}
				}

				j -= firstj;
				s -= firsts;
			}
		}



		std::cout << sets.size() << std::endl;
		for (three& t : sets) {
			std::cout << t.he[0] << " " << t.he[1] << " " << t.he[2] << std::endl;
		}




	}

}