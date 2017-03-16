#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<long> QA ;
vector<long> TA ;
vector<long> QB ;
vector<long> TB ;

long best (long posa, long posb, long quantb) {

	if (posb > TB.size()-1 || posa > TA.size()-1) {
		return 0 ;
	}
		
	long type = TA[posa] ;
	long full = QA[posa] ;
	long now = 0 ;
	
	long retour = 0 ;
	long futur = 0 ;
		futur = best(posa+1, posb, quantb) ;
		if (futur > retour) {
			retour = futur ;
		}
		
		if (type == TB[posb]) {
			now = QB[posb] - quantb ;
			if (now > full) {
				futur = full + best(posa+1,posb,quantb + full) ;
				if (futur > retour) {
					retour = futur ;
				}
				return retour ;
			}
			else {
				futur = now + best(posa+1,posb+1,0) ;
				if (futur > retour) {
					retour = futur ;
				}
			}
		}
		
		for (int i = posb+1 ; i < TB.size() ; i++) {
			if (type == TB[i]) {
				int newnow = now + QB[i] ;
				if (newnow > full) {
					futur = full + best(posa+1,i,full-now) ;
					if (futur > retour) {
						retour = futur ;
					}
					return retour ;
				}
				else {
					now = newnow ;
					futur = now + best(posa+1,i+1,0) ;
					if (futur > retour) {
						retour = futur ;
					}
				}
			}
		}
		
		return retour ;
	
}

int main() {
	
	int T ;
	
	cin >> T ;
	for (int _i = 1 ; _i <= T ; _i++ ) {
		
		int N, M ;
		cin >> N >> M ;
		QA.resize(100,0) ;
		TA.resize(100,0) ;
		QB.resize(100,0) ;
		TB.resize(100,0) ;
		QA.resize(N,0) ;
		TA.resize(N,0) ;
		QB.resize(M,0) ;
		TB.resize(M,0) ;
		for (int i = 0 ; i < N ; i++)
		{
			cin >> QA[i] >> TA[i] ;
		}
		for (int i = 0 ; i < M ; i++) {
			cin >> QB[i] >> TB[i] ;
		}

		long result = best(0,0,0) ;
		
		cout << "Case #" << _i << ": " << result << endl ;
		
	}
	
	return 0 ;
}
