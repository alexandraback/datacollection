#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Attack {
public:
	int d;
	int n;
	int delta_d;
	int w;
	int e;
	int	s;
	int delta_p;
	int delta_s;
public:
	void update() {
		if (n <= 0) {
			return;
		}
		n -- ;
		d += delta_d;
		w += delta_p;
		e += delta_p;
		s += delta_s;
	}

	bool hasAttack() {
		return (n > 0);
	}
};

int T;
int N;
vector<Attack> attList;
int lb = -5000;
int strength[10000];

int main(){
	cin >> T;
	for (int caseNum = 0; caseNum < T; ++caseNum) {
		cin >> N;
		memset(strength, 0, sizeof(strength));
		attList.clear();
		for (int i = 0; i < N; ++i) {
			Attack a;
			cin >> a.d >> a.n >> a.w >> a.e >> a.s 
				>> a.delta_d >> a.delta_p >> a.delta_s;
			attList.push_back(a);
		}
		int succCnt = 0;
		while (true) {
			int minInd = -1;
			int minDay = 1000000;
			for (int i = 0; i < N; ++i) {
				if (attList[i].hasAttack() && attList[i].d < minDay) {
					minDay = attList[i].d;
					minInd = i;
				}
			}
			if (minInd < 0) {
				break;
			}
			for (int i = 0; i < N; ++i) {
				if (!attList[i].hasAttack() || attList[i].d != minDay) {
					continue;
				}
				Attack a = attList[i];
				for (int j = a.w; j < a.e; ++j) {
					if (strength[j - lb] < a.s) {
						succCnt ++;
//						cout << a.d << ' ' << i <<' ' << a.w << ' ' << a.e << ' ' << a.s << ' ' << succCnt << endl;
//						for (int k = 0; k < 10; ++k) {
//							cout << strength[k - lb] << ' ';
//						}
//						cout << endl;
						break;
					}
				}
			}
			for (int i = 0; i < N; ++i) {
				if (!attList[i].hasAttack() || attList[i].d != minDay) {
					continue;
				}
				Attack a = attList[i];
				for (int j = a.w; j < a.e; ++j) {
					if (strength[j - lb] < a.s) {
						strength[j - lb] = a.s;
					}
				}
				attList[i].update();
			}
		}
		cout << "Case #" << caseNum + 1 << ": " << succCnt << endl;
	}
}