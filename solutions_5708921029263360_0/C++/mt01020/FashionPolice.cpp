#include<iostream>
using namespace std;

char JPS[11][11][11];
char JP[11][11];
char PS[11][11];
char JS[11][11];

int main(){
    int T, J, P, S, K;
    cin >> T;
    for(int t=1; t<=T; ++t){
	for(int i=1; i<11; ++i){
	    for(int j=1; j<11; ++j){
		JP[i][j] = 0;
		PS[i][j] = 0;
		JS[i][j] = 0;
		for(int k=1; k<11; ++k){
		    JPS[i][j][k] = 0;
		}
	    }
	}
	cin >> J >> P >> S >> K;
	int res = 0;
	for(int j=1; j<=J; ++j){
	    for(int p=1; p<=P; ++p){
		for(int s=1; s<=S; ++s){
		    if(JP[j][p] < K && PS[p][s] < K && JS[j][s] < K){
			++res;
			JPS[j][p][s] = 1;
			JP[j][p] += 1;
			PS[p][s] += 1;
			JS[j][s] += 1;
		    }
		}
	    }
	}
	cout << "Case #" << t << ": " << res << endl;
	for(int j=1; j<=J; ++j){
	    for(int p=1; p<=P; ++p){
		for(int s=1; s<=S; ++s){
		    if(JPS[j][p][s] == 1){
			cout << j << " " << p << " " << s << endl;
		    }
		}
	    }
	}
    }
    return 0;
}
