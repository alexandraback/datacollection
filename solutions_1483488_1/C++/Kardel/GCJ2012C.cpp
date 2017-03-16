#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int cas, index =1;
int A,B;
int result ;
map<int, int> mymap;

ifstream fin("C-large (1).in");
ofstream fout("C-LARGE.OUT");

void calculate(int num)
{
	mymap.clear();
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
			if (mymap.find(temp)!=mymap.end())
			{

			}
			else
			{
				mymap[temp] = temp;
				//fout << "num: " << num << " temp: " << temp<<endl;
				result ++;
			}

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
