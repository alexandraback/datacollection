#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;
int process(int N);
void upColor(vector<bool>& colors, int N);

int main() {
	int N;
	int i = 1, T;
	cin >> T;
	for(int l = 0 ; l < T ; l++) {
		cin >> N;
		//TRAITEMENT
		int ret = process(N);
		if(ret == -1)
			cout << "Case #" << i++ << ": INSOMNIA" << endl;
		else
			cout << "Case #" <<	i++ << ": " << ret << endl;
		///////////
	}
	return 0;
}

int process(int N){
	if(N == 0)
		return -1;
	vector<bool> color(10, false);
	int oldN = N;
	upColor(color, N);
	while(count(color.begin(), color.end(), false) != 0){
		N += oldN;
		upColor(color, N);
	}
	return N;
}

void upColor(vector<bool>& colors, int N){
	while(N >= 10){
		colors[(int)(N%10)] = true;
		N /= 10;
	}
	colors[N] = true;
}
