#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
	fstream fin (argv[1], fstream::in);

	int T;
	fin >> T;
	for (int i = 0; i != T; ++i){
		int N, S, p,
		    out = 0;
		fin >> N;
		fin >> S;
		fin >> p;
		for(int j = 0; j != N; ++j){
			int t;
			fin >> t;
			int a = t/3;
			int l = t%3;
//			cout << t << " " << a << " " << l << " " << p << endl;
			if (a >= p){
				++out;
			}else if (l >= 1 && a+1 >= p){
				++out;
			}else if (l == 2 && a+2 >= p && S >0){
				--S;
				++out;
			}else if (S >0 && a >= 1 &&a+1>=p){
				--S;
				++out;
			}
		}
		cout << "Case #" << i+1<< ": " << out  << endl;
	}
	return 0;
}
