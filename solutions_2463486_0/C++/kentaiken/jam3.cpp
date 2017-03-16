#include<iostream>
#include<fstream>

using namespace std;

ifstream input("input.txt");
ofstream output("output.txt");
int tests;
int a,b;
int count;
int fsqr[1001];

int isPalin(int num)
{
	int rev = 0;
	int temp = num;
	while(temp)
	{
		rev = rev*10 + temp%10;
		temp/=10;
	}
	
	return num == rev;
}

void precompute()
{
	int i;
	
	for(i = 1; i*i <= 1000; ++i)
	{
		if(isPalin(i) and isPalin(i*i))
		{
			fsqr[i*i] = 1;
		}
	}
}


int main()
{
	int i;
	input>>tests;
	
	precompute();
	for(i =1 ; i <= tests; ++i)
	{
		input>>a>>b;
		count = 0;
		while(a<=b)
		{
			count += fsqr[a];
			a++;
		}
		output<<"Case #"<<i<<": "<<count<<"\n";
	}
	input.close();
	output.close();
	
	return 0;
}
		
		
	