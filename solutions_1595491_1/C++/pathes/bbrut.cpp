#include<iostream>
#include<vector>
using namespace std;

int T, N, S, p, a, normalMax, surpMax, used, res;
vector<int> sums; //sumy
vector<int> whenNormal;
vector<int> whenSurprising;

int main(){
	cin >> T; //ilosc przypadkow
	for (int t = 0; t < T; ++t){
		cin >> N; //ile googlerow
		cin >> S; //ile zaskakujacych
		cin >> p; //bariera
		used = 0;
		res = 0;
		for (int n = 0; n < N; ++n) {
			cin >> a;
			if (a == 0) {
				normalMax = 0;
				surpMax = 0;
			} else if (a == 1) {
				normalMax = 1;
				surpMax = 0;
			} else if (a == 2) {
				normalMax = 1;
				surpMax = 2;
			} else {
				normalMax = a/3;
				if ((a/3)*3 != a)
					normalMax++;
				surpMax = (a-2)/3 + 2;
			}
			if (normalMax >= p)
				res++;
			else if (surpMax >= p && used < S) {
				res++;
				used++;
			}
		}
		cout << "Case #" << (t+1) << ": " << res << endl;
	}
}
