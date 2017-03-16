#include <iostream>
#include <string>
using namespace std;

	int n, temp;
	int n_key, n_chest;

	int open_chest[201];

	int in_chest[201][401];
	int n_in_chest[201];

	int keys[401];
	bool opened[201];

	int res[201];

	bool ok;
	int work(int);

int main() {

	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> n_key >> n_chest;

		ok=true;
		for (int k=1; k<=400; k++) keys[k]=0;
		for (int k=1; k<=200; k++) opened[k]=false;

		//input initial keys
		for (int k=1; k<=n_key; k++){
			cin >> temp;
			keys[temp]++;
		}

		//input chest
		for (int k=1; k<=n_chest; k++){
			cin >> open_chest[k] >> n_in_chest[k];
			for (int j=1; j<=n_in_chest[k]; j++){
				cin >> in_chest[k][j];
			}
		}

		//test
		for (int j=1; j<=n_chest; j++){
			for (int k=1; k<=n_in_chest[j]; k++)
				keys[in_chest[j][k]]++;
			keys[open_chest[j]]--;
		}
		for (int j=1; j<=400; j++)
			if (keys[j]<0){
				ok = false;
				break;
			}
		if (ok){
			ok=false;
			for (int p=1; p<=n_chest; p++){
				for (int k=1; k<=n_in_chest[p]; k++)
					keys[in_chest[p][k]]--;
				keys[open_chest[p]]++;
			}
			work(1);
		}

		//search
		if (ok){
			cout << "Case #" << i << ":";
			for (int k=1; k<=n_chest; k++) cout << ' ' << res[k];
			cout << endl;
		}
		else{
			cout << "Case #" << i << ": IMPOSSIBLE" << endl;
		}
		
	}
	return 0;
}

int work(int step) {
	if (step==n_chest+1){
		ok = true;
		return 0;
	}
	for (int i=1; i<=n_chest; i++)
		if (keys[open_chest[i]])
		if (!opened[i]){
			if (ok) return 0;
			opened[i]=true;
			keys[open_chest[i]]--;
			for (int k=1; k<=n_in_chest[i]; k++)
				keys[in_chest[i][k]]++;
			res[step]=i;
			work(step+1);
			if (ok) return 0;
			for (int k=1; k<=n_in_chest[i]; k++)
				keys[in_chest[i][k]]--;
			keys[open_chest[i]]++;
			opened[i]=false;
		}
	return 0;
}
