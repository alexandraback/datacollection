#include <iostream>
#include <fstream>
using namespace std;
long long radius;
long long capacity;
long long result;
long long ring();
int main(int argc,char* argv[])
{
	ifstream filein(argv[1]);
	ofstream fileout("bullseye.out");
	int count;
	filein>>count;
	for(int i=0;i<count;i++)
	{
		filein>>radius>>capacity;
		result=ring();
		fileout<<"Case #"<<(i+1)<<": "<<result<<endl;
	}
	return 0;
}

long long ring()
{
	long long cr=radius+1;
	long long sum=0;
	long long step=2;
	long long cc=capacity;
	long long nextc=cr*cr-(cr-1)*(cr-1);
	while(cc>=nextc)
	{
		sum++;
		cr=cr+step;
		cc=cc-nextc;
		nextc=cr*cr-(cr-1)*(cr-1);
	}
	return sum;
}
