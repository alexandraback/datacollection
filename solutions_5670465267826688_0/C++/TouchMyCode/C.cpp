#include<iostream>
#include<fstream>
#include<vector>
char arr[1024];
char convert[8][8] = { { 0, 1, 2, 3, 4, 5, 6, 7 }, { 1, 4, 3, 6, 5, 0, 7, 2 },
{ 2, 7, 4, 1, 6, 3, 0, 5 }, { 3, 2, 5, 4, 7, 6, 1, 0 },
{ 4, 5, 6, 7, 0, 1, 2, 3 }, { 5, 0, 7, 2, 1, 4, 3, 6 },
{ 6, 3, 0, 5, 2, 7, 4, 1 }, { 7, 6, 1, 0, 3, 2, 5, 4 } };
int main(){
	std::ifstream fin;

	std::ofstream fout;
	fin.open("C-small-attempt0.in", std::ios_base::in);
	fout.open("c.out", std::ios_base::trunc);
	int T;
	fin >> T;

	for (int times = 1; times <= T; times++){
		long long l, x;
		fin >> l >> x;
		std::vector<char> arr;
		arr.reserve(l);
		fin.get();
		char state = 0;
		for (int i = 0; i < l; i++){
			char ch = fin.get();
			char in=0;
			switch (ch){
			case '1':
				in = 0;
				break;
			case 'i':
				in = 1;
				break;
			case 'j':
				in = 2;
				break;
			case 'k':
				in = 3;
				break;
			}
			state = convert[state][in];
			arr.push_back(in);
		}
		//judge state
		char ns = 0;
		int iter = (int)(x % (long long)128);
		bool i1 = false, i2 = false;
		for (int i = 0; i <iter ; i++){
			//do calc
			for (int j = 0; j < l; j++){
				//
				char p = arr[j];
				char pv = convert[ns][arr[j]];
				ns = convert[ns][arr[j]];
				if (i1){
					if (ns == 3)i2 = true;
				}
				else{
					if (ns == 1)i1 = true;
				}
			}

		}
		bool ans = i1&&i2;
		if (ns != 4)ans = false;
		else if (l*x < 3)ans = false;
		//check for 
		if (ans){
			fout << "Case #" << times << ": YES\n";
		}
		else{
			fout << "Case #"<<times <<": NO\n";
		}
		std::cout << ans << std::endl;
	}
	fin.close();
	fout.close();
	system("PAUSE");
	return EXIT_SUCCESS;
}