#include <iostream>
#include <iomanip>
#include <string>
#include <queue>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int ct = 1; ct <= T; ct++) {
		string a, b;
		size_t found;

		cin >> a >> b;
		int tam = a.size();

		queue<string> posa;
		posa.push(a);
		found = posa.front().find('?');
		while (found != string::npos) {
			int p = (int)found;
			string pos = posa.front();
			posa.pop();
			pos[p] = '0';
			posa.push(pos);
			for (int i = 0; i < 9; i++) {
				pos[p]++;
				posa.push(pos);
			}

			found = posa.front().find('?');
		}

		queue<string> posb;
		posb.push(b);
		found = posb.front().find('?');
		while (found != string::npos) {
			int p = (int)found;
			string pos = posb.front();
			posb.pop();
			pos[p] = '0';
			posb.push(pos);
			for (int i = 0; i < 9; i++) {
				pos[p]++;
				posb.push(pos);
			}

			found = posb.front().find('?');
		}

		vector<int> A, B;
		while (!posa.empty()) {
			A.push_back(stoi(posa.front()));
			posa.pop();
		}
		while (!posb.empty()) {
			B.push_back(stoi(posb.front()));
			posb.pop();
		}

		vector<int>::iterator ait, bit;

		// for (ait = A.begin(); ait != A.end(); ait++) {
		// 	cout << *ait << " ";
		// }
		// cout << endl;
		// for (bit = B.begin(); bit != B.end(); bit++) {
		// 	cout << *bit << " ";
		// }

		ait = A.begin();
		bit = B.begin();
		int menor = 10000;
		int ansa, ansb;
		ansa = ansb = 0;

		while (ait != A.end()) {
			bit = B.begin();
			while (bit != B.end()) {
				int dif = abs(*ait - *bit);
				if (dif < menor) {
					menor = dif;
					ansa = *ait;
					ansb = *bit;
				} else if (dif == menor) {
					if (*ait < ansa) {
						ansa = *ait;
						ansb = *bit;
					} else if (*ait == ansa) {
						if (*bit < ansb) {
							ansb = *bit;
						}
					}
				}
				bit++;
			}
			ait++;
		}

		cout << "Case #" << ct << ": " << \
				setw(tam) << setfill('0') << ansa << " " << \
				setw(tam) << setfill('0') << ansb << endl;
	}

	return 0;
}