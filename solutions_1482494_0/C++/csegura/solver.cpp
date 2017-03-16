#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main(){
	int T;
	cin >> T;
	for (int t = 0; t < T; t++){
		int N;
		cin >> N;
		vector<int> oneStars, twoStars;
		vector<bool> oneCompleted, twoCompleted;
		for (int i = 0; i < N; i++){
			int value;
			cin >> value;
			oneStars.push_back(value);
			cin >> value;
			twoStars.push_back(value);
			oneCompleted.push_back(false);
			twoCompleted.push_back(false);
		}
		int nStars = 0;
		int games = 0;
		int completed = 0;

		while(completed < N){
			bool found = false;
			for (int i = 0; i < twoStars.size(); i++){
				
				if ((nStars >= twoStars[i]) && (!twoCompleted[i])){
					completed++;
					if (oneCompleted[i] == false){
						nStars += 2;
					} else {
						nStars++;
					}
					twoCompleted[i] = oneCompleted[i] = true;
					games++;
					found = true;
				}
			}
			if (!found){
				//Buscamos el maximo de twoStars que se pueda resolver
				int maxTwo = -1;
				int indexMaxTwo = -1;
				for (int i = 0; i < oneStars.size(); i++){
					if ((nStars >= oneStars[i]) && (!oneCompleted[i])){
						if (twoStars[i] > maxTwo){
							maxTwo = twoStars[i];
							indexMaxTwo = i;
						}
					}
				}
				if (indexMaxTwo != -1){
					oneCompleted[indexMaxTwo] = true;
					nStars ++;
					found = true;
					games++;
				}
			}
			if (!found){
				break;
			}
		}
		if (completed > N){
			cerr << "Error interno " << endl << flush;
		}
		if (completed == N){
			cout << "Case #" << (t + 1) << ": " << games << endl; 
		} else {
			cout << "Case #" << (t + 1) << ": " << "Too Bad" << endl; 
		}
	}
}
