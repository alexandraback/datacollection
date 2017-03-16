#include<iostream>
#include<fstream>
using namespace std;
int main(){
	int i, j, k, test_cases, gen, arr[100],yes;
	for (j = 0; j < 100; j++)
		arr[j] = j;
	double X, temp, c;
	double P = 1e30, Q = 1e30;

	bool is;
	ifstream fin("lar.in");
	ofstream fout("long_output.txt");
	fin >> test_cases;
	for (i = 0; i < test_cases; i++){
		is = false;
		fin >> P;
		fin.ignore(1, '/');
		fin >> Q;
		X = P / Q;
		//cout << X<< endl;
		gen = 1;
		yes = -1;
		while (gen <= 40){
			temp = X*2.0;
			c = temp - 1.0;
			if (c < 0){
				X = temp;
				gen++;
			}
			else{
				if (!is){
					is = true;
					yes = gen;
				}
				X = c;
				gen++;
			}
			
			if (c == 0 || c == 1)
				break;
			
			
			//c = temp - 1.0;

		/*	if (c >= 0){

				for (k = 1; k <= 40 - gen; k++){
					for (j = 0; j < 100; j++){
						if (c == arr[j])
							break;
					}
					if (j < 100)
						break;
					c *= 2.0;
				}


				if (k < 40 - gen)
					break;
			}
			X = temp;
			gen++;*/
		}
		fout << "Case #" << i + 1 << ": ";
		if (gen > 40)
			fout << "impossible" << endl;
		else
			fout << yes << endl;
	}
	system("pause");
	return 0;
}