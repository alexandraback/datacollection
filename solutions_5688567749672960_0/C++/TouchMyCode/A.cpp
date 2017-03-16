#include<iostream>
#include<fstream>
#include<queue>
using std::cout;
using std::endl;
int num[1024000];
int reverse[1024000];
int revDec(int n){
	char num[20];
	int i = 0;
	while (true){
		num[i] = n % 10;
		n = n / 10;
		
		if (n < 1)break;
		i++;
	}

	//i자리

	//reverse
	int result = 0;
	//char rev[20];
	for (int j = 0; j <= i; j++){
		result *= 10;
		result+=num[j];
	}
	return result;
}
int main(){
	std::ifstream fin;

	std::ofstream fout;
	for (int i = 0; i < 100; i++){
		printf("%d 뒤집으면 %d\n", i, revDec(i));
	}
	//precalculation
	std::queue<int>que;
	que.push(1);
	
	for (int i = 0; i <= 1000000; i++){
		num[i] = 987654321;
	}
	num[1] = 01;
	while (que.empty() == false){
		int no = que.front();
		que.pop();
		//find next
		int len = num[no] + 1;
		if (num[no + 1] > len){
			num[no + 1] = len;
			que.push(no+1);
		}
		int revD = revDec(no);
		if (num[revD] > len){
			num[revD] = len;
			que.push(revD);
		}
		
	}
	//calculate

	//
	cout << "파일 넣으라고" << endl;
	system("PAUSE");
	
	fin.open("A-small-attempt0.in", std::ios_base::in);
	fout.open("a.out.txt", std::ios_base::trunc);
	int T;
	fin >> T;

	for (int times = 1; times <= T; times++){
		int N;
		fin >> N;

		
		int ans = num[N];
		fout << "Case #" << times << ": " << ans  << "\n";
		std::cout << ans << std::endl;
	}
	fin.close();
	fout.close();
	system("PAUSE");
	return EXIT_SUCCESS;
}