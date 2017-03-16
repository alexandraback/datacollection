#include<iostream>
#include<fstream>
char arr[1024];
int main(){
	std::ifstream fin;

	std::ofstream fout;
	fin.open("a.txt", std::ios_base::in);
	fout.open("b.txt", std::ios_base::trunc);
	int T;
	fin >> T;

	for (int times = 1; times <= T; times++){
		int s;
		fin >> s;
		fin.get();
		for (int i = 0; i <= s; i++){
			arr[i] = fin.get() - '0';
		}
		//do
		int ans = 0;
		int n = 0;
		for (int i = 0; i <= s; i++){
			n += arr[i];
			if (n <= i){
				n++;
				ans++;
			}
		}
		fout << "Case #"<<times<<": " << ans << "\n";
		std::cout << ans << std::endl;
	}
	fin.close();
	fout.close();
	system("PAUSE");
	return EXIT_SUCCESS;
}