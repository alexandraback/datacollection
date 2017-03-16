#include <iostream>
#include <fstream>
using namespace std;
int energy;
int regain;
int counter;
int gain;
int* event=new int[10];
int maxgain=0;
void manage();
int main(int argc,char* argv[])
{
	ifstream filein(argv[1]);
	ofstream fileout("manage.out");
	int count;
	filein>>count;
	for(int i=0;i<count;i++)
	{
		filein>>energy>>regain>>counter;
		for(int j=0;j<counter;j++)
		{
			filein>>event[j];
		}
		manage();
		gain=maxgain;
		fileout<<"Case #"<<(i+1)<<": "<<gain<<endl;
		maxgain=0;
		gain=0;
	}
	return 0;
}
void compute(int index,int cgain,int cE)
{
	int spend;
	int tcgain,tcE;
	for(spend=regain+cE-energy;spend<=cE;spend++)
	{
		if(spend<0)
			continue;
		tcgain=cgain+spend*event[index];
		tcE=regain+cE-spend;
		if(index==counter-1)
		{
			if(tcgain>maxgain)
			{
				maxgain=tcgain;
			}
			continue;
		}
		else
		{
			compute(index+1,tcgain,tcE);
		}
	}
	return;
}

void manage()
{
	int cgain=gain;
	if(energy<=regain)
	{
		int sum=0;
		for(int i=0;i<counter;i++)
		{
			sum=sum+event[i];
		}
		maxgain=sum*energy;
		return;
	}
	compute(0,cgain,energy);
	return;
}

