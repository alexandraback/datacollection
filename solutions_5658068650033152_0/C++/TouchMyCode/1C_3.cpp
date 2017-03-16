#include<iostream>
#include<fstream>
using std::endl;


int main()
{

	std::ofstream fout;
	std::ifstream fin;
	fin.open("3.txt");
	if (fin.bad()){
		std::cout << "INPUT FILE OPEN ERROR" << std::endl;
		system("PAUSE");
		return 0;
	}
	fout.open("3.out.txt");
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
		int width, height, nopt, answer;
		fin >> width;
		fin >> height;
		if (width > height){
			int temp = width;
			width = height;
			height = temp;
		}
		fin >> nopt;
		if (nopt <= 4){
			answer = nopt;
		}
		else if (width == 1){
			answer = nopt;
			
		}
		else if (width == 2){
			answer = nopt;

		}
		else{
			//33격자 확보
			//brute force
			answer = 2 * (width + height);
			for (int i = 1; i < width - 1; i++){
				for (int j = 1; j < height - 1; j++){
					int temp = (i*j + 2 * i + 2 * j);
					if (temp >= nopt){
						if (answer>(2 * i + 2 * j))
							answer = (2 * i + 2 * j);
					}
					else if ((temp+4) >= (nopt)){
						if (answer>(2 * i + 2 * j+(nopt-temp)))
							answer = (2 * i + 2 * j + (nopt - temp));
					}
				}
			}
			//if (nopt == 9)answer = 7;
		}
		
		fout << "Case #" << caseNo+1 << ": " <<answer<<std::endl;
	}
	fout.close();
	fin.close();
}