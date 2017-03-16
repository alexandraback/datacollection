#include<iostream>
#include<vector>

using namespace std;

double eps = 0.000001;
vector<int> ind;

int maxind(vector<double> &v) {
	
	double max = -10.0;
	int index = -1;
	for (int i = 0; i < v.size(); ++i) {
			if (v[i] >= max) {
				bool esta = false;
				for (int j = 0; j < ind.size(); ++j) {
					if (i == ind[j]) esta = true;
				}
				if (not esta) {
					max = v[i];
					index = i;
				}
		}
	}
	if (index == -1) cout << "ERROR" << endl;
	if (index >= v.size()) cout << "ERROR2" << endl;
	return index;
}

int main() {
	//cout.setf(ios::fixed);
	cout.precision(8);
	
	int T;
	cin >> T;
	int caso = 1;
	while (caso <= T) {
		int N;
		cin >> N;
		vector<double> s(N);
		vector<double> m(N);
		double sum = 0.0;

		for (int i = 0; i < N; ++i) {
			cin >> s[i];
			sum += s[i];

		}


		ind = vector<int> (0);

		double total = 1.0;
		for (int k = 0; k < N; ++k) {
			//cout << "ITERACION " << k << " ind size = " << ind.size() << endl;
			/*for (int l = 0; l < ind.size(); ++l) {
				cout << ind[l] << ' ';
			}
			cout << endl;*/
			
			int i = maxind(s);
			ind.push_back(i);
			//cout << "COJO " << s[i] << " EN " << i << endl;
			double beta = 0.0; //suma de lo que se necesita para igualar
			int iguales = 0; //cuantos hay por debajo

			for (int j = 0; j < N; ++j) {
				if (i != j) {
					if (s[j] < s[i] ) {
						iguales++;
						//y[j] = (s[i] - s[j])/sum;
						beta += (s[i] - s[j])/sum;					
					}
				}
			}
			//cout << "por debajo "  << N - k - 1 << " total " << total << endl;
			
			if ( k  <= N-2) {
				if (beta >= total) {
					m[i] = 0.0;
					//cout << "asignado* 0" << endl;
				}
				else {
					m[i] = (total-beta)/double( N - k - 1.0 + 1.0);
					//cout << "asignado " << m[i] << endl;
					total -= m[i];
				}
			}
			else {
				//cout << "ERROR" << endl;
				m[i] = total;
				//cout << "asignado t " << total << endl;
			}
		}
		
		cout << "Case #" << caso << ": ";
		for (int i = 0; i < N; ++i) {
			cout << m[i]*100 << ' ';
		}
		cout << endl;
		caso++;
	}
}