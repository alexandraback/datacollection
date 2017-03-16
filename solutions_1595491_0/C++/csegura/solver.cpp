#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <map>

using namespace std;

bool reachValueWithoutSurprise(int p, int t){
	if (p == 0){
		return true;
	}
	return (t >= ((p-1)* 2 + p));
}

bool reachValueWithSurprise(int p, int t){
	if (p == 1){
		return false;
	}
	return (t >= ((p-2)* 2 + p));
}

int main(int argc, char *argv[]){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		cout << "Case #" << (i+1) << ": ";
		int N;//Number of googlers
		cin >> N;
		int S;//Surprising
		cin >> S;
		int p;
		cin >> p;
		int reach = 0;
		for (int i = 0; i < N; i++){
			int ti;
			cin >> ti;
			if (reachValueWithoutSurprise(p, ti)){
				reach++;
			} else if ((S != 0) && (reachValueWithSurprise(p, ti))){
				S--;
				reach++;
			}
		}
		cout << reach << endl;
	}
}
