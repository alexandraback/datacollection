#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int T, t;
	int n, i, j;
	std::cin >> T;

	for(t = 1; t <= T; t++) {
		double temp;
		std::vector<double> naomi1, ken1, naomi2, ken2;
		int win1, win2;
		win1 = win2 = 0;
		std::cin >> n;
		for(i = 0; i < n; i++) {
			std::cin >> temp;
			naomi1.push_back(temp);
		}
		for(i = 0; i < n; i++) {
			std::cin >> temp;
			ken1.push_back(temp);
		}
		sort(naomi1.begin(), naomi1.end());
		sort(ken1.begin(), ken1.end());
		for(i = 0; i < n; i++) {
			naomi2.push_back(naomi1.at(i));
			ken2.push_back(ken1.at(i));
		}
		
		while(naomi1.size()) {
			if(naomi1.front() > ken1.front() ) {
				win1++;
				naomi1.erase(naomi1.begin());
				ken1.erase(ken1.begin());
			}
			else {
				naomi1.erase(naomi1.begin());
				ken1.pop_back();
			}
		}

		while(naomi2.size()) {
			double naomi;
			naomi = naomi2.front();
			naomi2.erase(naomi2.begin());

			if(naomi > ken2.back()) {
				win2++;
				ken2.erase(ken2.begin());
			}
			else {
				int left, right, cursor;
				left = 0;
				right = ken2.size() - 1;
				
				while(1) {
					cursor = (left + right) / 2;
					if(cursor == left) {
						if(ken2.at(left) > naomi) {
							ken2.erase(ken2.begin() + left);
						}
						else {
							ken2.erase(ken2.begin() + right);
						}
						break;
					}
					if(ken2.at(cursor) > naomi) {
						right = cursor;
					}
					else {
						left = cursor;
					}
				}
			}
		}
//		cout << "win : " << win2 << "\n";
		cout << "Case #" << t << ": " << win1 << " " << win2 << "\n";
	}
}



