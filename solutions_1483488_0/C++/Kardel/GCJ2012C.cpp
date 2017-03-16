#include <iostream>
#include <fstream>

using namespace std;

int cas, index =1;
int A,B;
int result ;

ifstream fin("C-small-attempt0.in");
ofstream fout("C-SMALL.OUT");

void calculate(int num)
{
	int cycle = 0;
	int digit = 1;
	int temp = num;
	while (temp >= 10)
	{
		cycle ++;
		digit = digit * 10;
		temp = temp /10;
	}

	temp = num;
	for (int i=0; i < cycle; i ++)
	{
		int post = (temp % 10) * digit;
		temp = post + temp/10;
		
		if(temp > num && temp <= B)
		{
			//fout << "num: " << num << " temp: " << temp<<endl;
			result ++;
		}//end if
	}//end fro i
}

void read()
{
	fin >> A >> B;
	result = 0;

	for (int i=A; i< B;i ++)
	{
		calculate(i);
	}
	fout << "Case #"<<index << ": "<<result <<endl;
}

int main()
{
	fin >> cas;

	while(index<=cas)
	{
		read();		
		index ++;
	}

	return 0;
}
