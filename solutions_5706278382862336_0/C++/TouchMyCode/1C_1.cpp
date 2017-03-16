#include<iostream>
#include<fstream>
using std::endl;
unsigned long long GCD(unsigned long long a, unsigned long long b);
int main()
{

	std::ofstream fout;
	std::ifstream fin;
	fin.open("1.txt");
	if (fin.bad()){
		std::cout << "INPUT FILE OPEN ERROR" << std::endl;
		system("PAUSE");
		return 0;
	}
	fout.open("1.out");
	if (fout.bad()){
		std::cout << "OUTPUT FILE OPEN ERROR" << std::endl;
		fin.close();
		system("PAUSE");
		return 0;
	}
	int noQuestion;
	fin >> noQuestion;

	for (int caseNo = 0; caseNo < noQuestion; caseNo++)
	{
		//todo:각 문제 풀기
		bool possible = true;
		unsigned long long v1, v2;
		fin >> v1;
		fin.get();
		fin >> v2;

		unsigned long long v3 = GCD(v1, v2);
		v1 /= v3;
		v2 /= v3;
		v3 = 1;

		while (v2>v3) v3 *= 2;
		if (v2 != v3)possible = false;

		int answer = 1;
		while (answer<50){
			unsigned long long v4 = v2 >> answer;
			if ((v4&v1) != 0)
				break;
			answer++;
		}


		if(possible)
			fout << "Case #" << caseNo+1 << ": " << answer << std::endl;
		else{
			fout << "Case #" << caseNo + 1 << ": " << "impossible" << std::endl;

		}
	}
	fout.close();
	fin.close();
}

unsigned long long GCD(unsigned long long a, unsigned long long b){
	if (a > b){
		long long c = a%b;
		if (c == 0)return b;
		return GCD(b, c);
	}
	else if (a<b){
		long long c = b%a;
		if (c == 0)return a;
		return GCD(a, c);
	}
	else return a;
}