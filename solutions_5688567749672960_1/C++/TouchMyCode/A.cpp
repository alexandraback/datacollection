#include<iostream>
#include<fstream>
#include<queue>
using std::cout;
using std::endl;
int num[2024000];
int reverse[2024000];
long long revDec(long long n){
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
	long long result = 0;
	//char rev[20];
	for (int j = 0; j <= i; j++){
		result *= 10;
		result+=num[j];
	}
	return result;
}
long long getVal(long long n){
	if (n == 1)return 1;
	if (n == 10)return 10;
	if (n == 100)return 29;
	if (n == 1000)return 138;
	
	if (n % 10 == 0)return getVal(n - 1) + 1;
	//자리수 세기
	const long long orgN = n;
	char num[20];
	int i = 1;
	while (true){
		num[i] = n % 10;
		n = n / 10;

		if (n < 1)break;
		i++;
	}
	//a;
	int first = i / 2;
	int last = i - first;
	long long s = 1;
	for (int t = 1; t < i; t++)s *= 10;
	//seperation
	long long spt = 1;
	for (int i = 0; i < last; i++)spt *= 10;
	long long orgR = orgN - (orgN%spt);
	if (orgR == s)return orgN - s+getVal(s);
	long long revVal = revDec(orgR+1);
	return (orgN%spt)  + getVal(revVal);
	//
}
int main(){
	std::ifstream fin;

	std::ofstream fout;
	//test
	getVal(99);
	getVal(99999999);
	//
	cout << "파일 넣으라고" << endl;
	system("PAUSE");
	//return 0;
	fin.open("A-large.in", std::ios_base::in);
	fout.open("a-large.out.txt", std::ios_base::trunc);
	int T;
	fin >> T;

	for (int times = 1; times <= T; times++){
		long long N;
		fin >> N;

		
		long long ans = getVal(N);
		fout << "Case #" << times << ": " << getVal(N)  << "\n";
		std::cout << ans << std::endl;
	}
	fin.close();
	fout.close();
	system("PAUSE");
	return EXIT_SUCCESS;
}