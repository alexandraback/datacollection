#include<iostream>
#include<fstream>
#include<algorithm>
#include<functional>
int arr[2048];
int main(){
	std::ifstream fin;

	std::ofstream fout;
	fin.open("B-small-attempt0.in", std::ios_base::in);
	fout.open("b.txt", std::ios_base::trunc);
	int T;
	fin >> T;
	std::cout << "Total case no:" << T << std::endl;
	for (int times = 1; times <= T; times++){
		int s;
		fin >> s;
		fin.get();
		for (int i = 0; i < s; i++){
			fin >> arr[i];
		}
		//sort
		std::sort(arr, arr + s, std::greater<int>());
		//do
		int ans = arr[0];
		int D = s;
		int max = ans;
		for (int i = 1; i < max*2; i++){
			//make plates
			arr[D] = arr[0] /2;
			arr[0] -= arr[D];
			D++;
			std::sort(arr, arr + D, std::greater<int>());
			int newans = i + arr[0];
			if (newans < ans)ans = newans;
		}

		fout << "Case #" << times << ": " << ans << "\n";
		std::cout << ans << std::endl;
	}
	fin.close();
	fout.close();
	system("PAUSE");
	return EXIT_SUCCESS;
}