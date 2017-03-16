#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/miller_rabin.hpp>

using namespace std;
using namespace boost::multiprecision;
void process(int N, int J);
void isJamCoin(vector<cpp_int>&, vector<int>&);

int main() {
	srand(time(0));
	int N, J;
	int i = 1, T;
	cin >> T;
	for(int l = 0 ; l < T ; l++) {
		cin >> N >> J;
		//TRAITEMENT
		cout << "Case #" << i++ << ":" << endl;
		process(N, J);
		///////////
	}
	return 0;
}

void process(int N, int J){
	vector<int> nb(N, 0);
	vector<cpp_int> div;
	nb[0] = 1;
	nb[N-1] = 1;
	for(int i = 0 ; i < J ; i++){
		do{
			for(int j = 1 ; j < N-1 ; j++){
				if(nb[j] == 0){
					nb[j] = 1;
					break;
				}
				if(nb[j] == 1)
					nb[j] = 0;
			}
			for(int j = 1 ; j < N-1 ;j++)
				nb[N-j-1] = nb[j];
			//for(int j = N/3 ; j < N-1 ; j++)
			//	nb[j] = rand()%2;
			isJamCoin(div, nb);
		}while(div.empty());
		for(int j = 0 ; j < N ; j++) cout << nb[j];
		for(int j = 0 ; j < div.size() ; j++)
			cout << " " << div[j];
		cout << endl;
	}
}

void isJamCoin(vector<cpp_int>& div, vector<int>& nb){
	cpp_int interp;
	bool wrong;
	div.resize(9);
	for(int b = 2 ; b <= 10 ; b++){
		interp = 1;
		for(int i = 1 ; i < nb.size() ; i++)
			interp = interp * b + nb[i];
		if(miller_rabin_test(interp, 25)){
			div.clear();
			return;
		}
		//cout << "b "<< interp << " ; ";
		wrong = true;
		for(cpp_int i = 2 ; i <= interp ; i++)
			if(interp % i == 0){
				wrong = false;
				div[b-2] = i;
				break;}
		if(wrong) { div.clear(); return; }
	}
}

