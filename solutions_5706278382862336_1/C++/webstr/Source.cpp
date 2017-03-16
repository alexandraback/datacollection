#include <fstream>
#include <string>
#include <cmath>
using namespace std;

bool isTwo(long long x){
	bool ok = true;
	int k = 0;
	while(x > 1){
		if (x % 2 == 1 || k >= 40){
			ok = false;
			break;
		} else {
			x /= 2;
			k++;
		}
	}


	return ok;
}

int main(){
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");

	int T;
	fin >> T;
	for (int k = 1; k <= T; k++){
		string str;
		fin >> str;
		int z = str.length() - 1;
		long long p = 1;
		long long a = 0, b = 0;;
		while (str[z] != '/'){
			a += (str[z] - '0') * p;
			p *= 10;
			z--;
		}
		z--;
		p = 1;
		while (z >= 0){
			b += (str[z] - '0') * p;
			z--;
			p *= 10;
		}

		fout << "Case #" << k << ": ";
		bool ok = true;

		int s = 0;
		int s1 = 0;
		
		while (b >= 1){
		while (a % 2 == 0 && b < a / 2){
			a /= 2;
			if (ok)
			s++;
			s1++;
		}

		
		if (a % 2 == 0 && b == a / 2){
			if (ok)
			s++;
			s1++;
			break;
		} else if (a % 2 == 0 && b < a / 2){
			if (ok)
			s += 41;
			s1+=41;
			break;
		} else if (a % 2 == 0 && b > a / 2){
			a /= 2;
			b -= a;
			if (ok)
			s++;
			s1++;
			ok = false;
		} else {
			s1 += 41;
			break;
		}
		}
		if (s <= 40 && s1 <= 40){
			fout << s << endl;
		} else {
			fout << "impossible" << endl;
		}
	}
}