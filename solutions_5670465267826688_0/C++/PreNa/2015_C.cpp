#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class word{
public:
	char w;
	bool s;
	void mul(char a);
};

void word::mul(char a){
	switch (w){
	case 1:
		w = a;
		break;
	case 'i':
		switch (a){
		case 'i':
			w = 1;
			s ^= 1;
			break;
		case 'j':
			w = 'k';
			break;
		case 'k':
			w = 'j';
			s ^= 1;
			break;
		}
		break;
	case 'j':
		switch (a){
		case 'i':
			w = 'k';
			s ^= 1;
			break;
		case 'j':
			w = 1;
			s ^= 1;
			break;
		case 'k':
			w = 'i';
			break;
		}
		break;
	case 'k':
		switch (a){
		case 'i':
			w = 'j';
			break;
		case 'j':
			w = 'i';
			s ^= 1;
			break;
		case 'k':
			w = 1;
			s ^= 1;
			break;
		}
		break;
	}
}

int main(){
	ifstream fin;
	fin.open("C-small-attempt0.in");
	ofstream fout;
	fout.open("C-small-attempt0.out");

	int cnt;
	fin >> cnt;
	for (int T = 1; T <= cnt; T++){
		long long l, x;
		fin >> l >> x;
		string data;
		fin >> data;
		word status;
		status.w = 1;
		status.s = true;
		int step = 0;
		for (long long i = 0; i < x; i++){
			for (long long j = 0; j < l; j++){
				status.mul(data[j]);
				switch (step){
				case 0:
					if (status.w == 'i' && status.s == true){
						step++;
						status.w = 1;
						status.s = true;
					}
					break;
				case 1:
					if (status.w == 'j' && status.s == true){
						step++;
						status.w = 1;
						status.s = true;
					}
					break;
				case 2:
					if (status.w == 'k' && status.s == true){
						step++;
						status.w = 1;
						status.s = true;
					}
					break;
				}
			}
		}
		fout << "Case #" << T << ": ";
		if (step == 3 && status.w == 1 && status.s == true){
			fout << "YES";
		}
		else{
			fout << "NO";
		}
		fout << endl;
	}

}