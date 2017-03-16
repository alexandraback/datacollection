#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream fin;
	fin.open("A-small-attempt1.in");
	ofstream fout;
	fout.open("A-small-attempt1.out");

	int cnt;
	fin >> cnt;
	for (int T = 1; T <= cnt; T++){
		int a;
		fin >> a;

		int sum = 0;
		int add = 0;
		for (int i = 0; i < a+1; i++){
			char tmp;
			fin >> tmp;
			int data = tmp - '0';
			if (data > 0){
				if (sum + add < i){
					add += i - sum - add;
				}
				sum += data;
			}
		}



		fout << "Case #" << T << ": " << add;

		fout << endl;
	}

}