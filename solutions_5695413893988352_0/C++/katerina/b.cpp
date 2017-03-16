#include <iostream> 
#include <string> 
#include <vector> 
#include <stdlib.h>
#include <stdio.h>
using namespace std;

vector <int> sol1(0);
vector <int> sol2(0);


int main()
{
	int T;
	cin >> T;
	for	(int t=0; t<T; t++) {
		string C,J;
		cin >> C >> J;
		int num1 = 0;
		int num2 = 0;

		if (C.length() == 3) {
			for(int i=0 ;i<10; ++i){
				if (C[0] == '?')
					num1 = i*100;
				else num1 = (C[0]-'0')*100;
				for(int j=0 ;j<10; ++j){
					if (C[1] == '?')
						num1 += j*10;
					else num1 += (C[1]-'0')*10;
					for(int k=0 ;k<10; ++k){
						if (C[2] == '?')
							num1 += k;
						else num1 += (C[2]-'0');
						sol1.push_back(num1);
						if (C[2] == '?')
							num1 -= k;
						else num1 -= (C[2]-'0');

					}
					if (C[1] == '?')
						num1 -= j*10;
					else num1 -= (C[1]-'0')*10;

				}
			}
			for(int i=0 ;i<10; ++i){
				if (J[0] == '?')
					num2 = i*100;
				else num2 = (J[0]-'0')*100;
				for(int j=0 ;j<10; ++j){
					if (J[1] == '?')
						num2 += j*10;
					else num2 += (J[1]-'0')*10;
					for(int k=0 ;k<10; ++k){
						if (J[2] == '?')
							num2 += k;
						else num2 += (J[2]-'0');
						sol2.push_back(num2);
						if (J[2] == '?')
							num2 -= k;
						else num2 -= (J[2]-'0');

					}
					if (J[1] == '?')
						num2 -= j*10;
					else num2 -= (J[1]-'0')*10;

				}
			}
		}
		else if (C.length() == 2) {
			for(int i=0 ;i<10; ++i){
				if (C[0] == '?')
					num1 = i*10;
				else num1 = (C[0]-'0')*10;
				for(int j=0 ;j<10; ++j){
					if (C[1] == '?')
						num1 += j;
					else num1 += (C[1]-'0');
					sol1.push_back(num1);
					if (C[1] == '?')
						num1 -= j;
					else num1 -= (C[1]-'0');

				}
			}
			for(int i=0 ;i<10; ++i){
				if (J[0] == '?')
					num2 = i*10;
				else num2 = (J[0]-'0')*10;
				for(int j=0 ;j<10; ++j){
					if (J[1] == '?')
						num2 += j;
					else num2 += (J[1]-'0');
					sol2.push_back(num2);
					if (J[1] == '?')
						num2 -= j;
					else num2 -= (J[1]-'0');

				}
			}
		}
		else if (C.length() == 1) {
			for(int i=0 ;i<10; ++i){
				if (C[0] == '?')
					num1 = i;
				else num1 = (C[0]-'0');
				sol1.push_back(num1);
			}
			for(int i=0 ;i<10; ++i){
				if (J[0] == '?')
					num2 = i;
				else num2 = (J[0]-'0');
				sol2.push_back(num2);
			}
		}
		int res1 = sol1[0];
		int res2 = sol2[0];
		int dif = abs(res1 - res2);
		for(int i=0; i<sol1.size(); i++) {
			for(int j=0; j<sol2.size(); j++) {
				if (abs(sol1[i] - sol2[j])<dif) {
					res1 = sol1[i];
					res2 = sol2[j];
					dif  = abs(sol1[i] - sol2[j]);
				}
				else if (abs(sol1[i] - sol2[j]) == dif && sol1[i] < res1) {
					res1 = sol1[i];
					res2 = sol2[j];
					dif  = abs(sol1[i] - sol2[j]);
				}
				else if (abs(sol1[i] - sol2[j]) == dif && sol1[i] ==  res1 &&
					sol2[j] < res2) {
					res1 = sol1[i];
					res2 = sol2[j];
					dif  = abs(sol1[i] - sol2[j]);
				}
			}
		}
		cout << "Case #"<< t+1 << ": ";
		if (C.length() == 1)
		cout<< res1 << " "<< res2 << endl;
		else if (C.length() == 2)
			printf("%02d %02d\n", res1, res2);
		else if (C.length() == 3)
			printf("%03d %03d\n", res1, res2);

		sol1.clear();
		sol2.clear();
	}
	return 0;
}

