#include <iostream>
#include <fstream>
using namespace std;
int digits;
int A;
int B;
int FA;
int FB;
int count;
int number[7];
bool globaluse[2000000];

int check()
{
	int localcounter=0;
	int accumulator;
	int appear[7];
	for (int i=0;i<digits;i++)
	{
		accumulator=0;
		for (int j=0;j<digits;j++)
		{
			accumulator=accumulator*10+number[(i+j)%digits];
		}
		appear[i]=accumulator;
	}

	for (int i=0;i<digits;i++)
	{
		if (appear[i]>=A && appear[i]<=B)
		{
			if (globaluse[appear[i]]==false)
			{
				localcounter++;
				globaluse[appear[i]]=true;
			}
		}
	}

	return localcounter*(localcounter-1)/2;
}

void dealing(int curdigit)
{
	if (curdigit==digits)
	{
		count+=check();
		return;
	}
	else
	{
		if (curdigit==0)
		{
			for (int i=FA;i<=FB;i++)
			{
				number[0]=i;
				dealing(1);
			}
		}
		else
		{
			for (int i=0;i<=9;i++)
			{
				number[curdigit]=i;
				dealing(curdigit+1);
			}
		}
	}
}



int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("C-small.in");
	fout.open("Cans.txt");
	int T;
	int temp;
	int curdigit;
	fin>>T;
	for (int i=1;i<=T;i++)
	{
		fin>>A;
		fin>>B;
		digits=0;
		count=0;
		temp=A;
		while (temp>0)
		{
			digits++;
			temp/=10;
		}
		temp=A;
		for (int j=1;j<=digits-1;j++)
		{
			temp/=10;
		}
		FA=temp;
		temp=B;
		for (int j=1;j<=digits-1;j++)
		{
			temp/=10;
		}
		FB=temp;
		for (int j=A;j<=B;j++)
		{
			globaluse[j]=false;
		}
		curdigit=0;
		dealing(curdigit);
		fout<<"Case #"<<i<<": "<<count<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}