#include "headers.h"
int main(){
	int T,tab[60][60],B;
	long long m;

	cin >> T;
	REP(t,T){
		cout << "Case #" << t+1 << ": ";
		cin >> B >> m;

		REP(i,B)REP(j,B) tab[i][j] = 0;
		REP(i,B-1)REP(j,B-1){
			if(i<j) tab[i][j] = 1;
		}

		if(m > (1<<(B-2))) cout << "IMPOSSIBLE" << endl;
		else{
			cout << "POSSIBLE\n";
			if(m == ((long long)1<<(B-2))){
				REP(i,B-1){
					tab[i][B-1] = 1;
				}
			}

			else{
				REP(i,B-2){
					tab[i+1][B-1] = (m & ((long long)1 << i)) > 0;
				}
			}

			REP(i,B){
				REP(j,B){
					cout << tab[i][j];
				}
				cout << endl;
			}
		}
	}
}
