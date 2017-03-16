#include<iostream>
#include<vector>

using namespace std;

int find_answer(vector<int> & shyness){
	int need = 0;
	shyness[0] -= '0';
	for(int i = 1; i < shyness.size(); ++i){
		shyness[i] -= '0';
		if(shyness[i] > 0 && shyness[i-1] < i){
			need += i - shyness[i-1];
			shyness[i-1] = i;
		}
		shyness[i] += shyness[i-1];
	}

	return need;
}

int main(){
	int cases;

	cin >> cases;

	for(int c = 1; c <= cases; ++c){
		int n;
		string shyness_str;
		cin >> n >> shyness_str;

		vector<int> shyness(shyness_str.begin(), shyness_str.end());


		int ans = find_answer(shyness);

		cout << "Case #" << c << ": " << ans << endl;

	}

	return 0;
}
