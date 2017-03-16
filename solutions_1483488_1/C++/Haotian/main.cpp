#include <iostream>
#include <fstream>
using namespace std;
int change(int orig, int pow) {   
	return (orig%10)*pow+ (orig/10);
}
int main()
{
	ifstream fin;
	//fin.open("test.txt");
	fin.open("C-large.in");
	int T;
	fin>>T;
	ofstream fout;
	fout.open("C-large.out");
	//fout.open("res.txt");
	int A, B;
	for(int t = 1; t <= T; t++)
	{
		fout << "Case #" << t << ": ";
		fin >> A;
		fin >> B;
		int bit = 1, power = 0;
		if(A >= 1000000)
			{
				bit = 7;
				power = 1000000;
			}
		else if (A >= 100000)
		{
			bit = 6;
			power = 100000;
		}
		else if (A >= 10000)
		{
			bit = 5;
			power = 10000;
		}else if (A >= 1000)
		{
			bit = 4;
			power = 1000;
		}
		else if (A >= 100)
		{
			bit = 3;
			power = 100;
		}
		else if (A >= 10)
		{
			bit = 2;
			power = 10;
		}
		int count = 0;
        for(int num = A; num <= B; num++)
		{
			 int trans = num;
		     for(int i =0;  i <bit-1; i++)
			 {
				trans = change(trans, power);
				if(trans == num) break;
				if(trans > num && trans <= B)
					count++;
			 }
		}
		fout << count << std::endl;
	}
	return 0;
}
	
	