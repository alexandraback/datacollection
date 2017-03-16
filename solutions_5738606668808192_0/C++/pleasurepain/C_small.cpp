#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <string>
#include <ctime>
//#include <string.h>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>


using namespace std;


long long int cal_power(int base, int exponent)
{
	long long int result=1;
	for (int i=1; i<=exponent; i++)
		result=result*base;
	return result;

}

void generate_temp(int *temp)
{
	int extra=1;
	for (int i=12; i>=0; i--)
	{
		int sum=temp[i]+extra;
		if (sum<2)
		{
			temp[i]=sum;
			extra=0;
		}
		else
		{
			temp[i]=0;
			extra=1;
		}
	}
}


int main() 
{

	ifstream fin("C-small-attempt0.in");  
	ofstream fout("output.out");

	/*ifstream fin("input.txt");  
	ofstream fout("output.txt");*/
	
	int T,N,J;
	fin>>T;

	fout<<"Case #1:"<<endl;

	fin>>N>>J;

	

	//-------first 7-------(B^{15-t}+1)(B^t+1)//

	for (int exp1=1; exp1<=7; exp1++)
	{
		int number[16];
		for (int i=0; i<16; i++)
			number[i]=0;
		number[0]=number[15]=1;

		int exp2=15-exp1;
		number[15-exp2]=number[15-exp1]=1;
		for (int i=0; i<16; i++)
			fout<<number[i];
		
		for (int base=2; base<=10; base++)
		{
			long long int result;
			result=cal_power(base,exp1);
			fout<<" "<<result+1;
		}
		fout<<endl;
	}

	int havefound=7;

	int temp[13];
	for (int i=0; i<13; i++)
		temp[i]=0;

	/*for (int x=1; x<=10; x++)
	{
		generate_temp(temp);
		for (int i=0; i<13; i++)
			cout<<temp[i];
		cout<<endl;
	}
	getchar();*/


	while (havefound<J)
	{
		generate_temp(temp);
		int number1[16];
		for (int i=0; i<16; i++)
			number1[i]=0;
		number1[1]=1;
		number1[15]=1;
		for (int i=0; i<13; i++)
			number1[i+2]=temp[i];
		int number2[16];
		for (int i=0; i<16; i++)
			number2[i]=0;
		for (int i=1; i<16; i++)
			number2[i-1]=number1[i];
		bool ok=true;
		for (int i=0; i<16; i++)
		{
			if (number1[i]==1 && number2[i]==1)
			{
				ok=false;
				break;
			}
		}

		if (ok==true)
		{
			/*for (int i=0; i<16; i++)
				cout<<number1[i];
			cout<<endl;
			for (int i=0; i<16; i++)
				cout<<number2[i];
			cout<<endl;
			getchar();*/
			int number[16];
			for (int i=0; i<16; i++)
			{
				number[i]=number1[i]+number2[i];
				fout<<number[i];
			}
			for (int base=2; base<=10; base++)
				fout<<" "<<base+1;
			fout<<endl;
			havefound++;

		}



	}
		



	//system("pause");
	//return 0;
}
