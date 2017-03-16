#include<iostream>
#include<fstream>
#include<math.h>
#include<string.h>
#include <sstream>
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

int primenum(int p,int num)
{
	int count = 0;
	while(num%p == 0)
	{
		num=num/p;
		count++;
	}
	return count;
}


void main()
{

	int T=0;
	int R = 0;
	int N= 0;
	int M=5;
	int K=7;
	ifstream in("C-small-1-attempt0.in");
	//ifstream in("A-small-attempt0.in");
	ofstream save("result3.txt");
	in >> T;
	in >> R;
	in >> N;
	in >> M;
	in >> K;
		save << "Case #1:"<<"\n";

	for(int p=0 ; p<R;p++)
	{
		int number = N;
		int p2=0;
		int p3=0;
		int p4=0;
		int p5=0;

		int k[7];
		for(int i=0;i<7;i++)
		{
			in >> k[i];
			if(p2<primenum(2,k[i]))
			{
				p2 = primenum(2,k[i]);
			}
			if(p3<primenum(3,k[i]))
			{
				p3 = primenum(3,k[i]);
			}
			//if(p4<primenum(4,k[i]))
			//{
			//	p4 = primenum(4,k[i]);
			//}
			if(p5<primenum(5,k[i]))
			{
				p5 = primenum(5,k[i]);
			}
		}
		if(p3>0)
		{
			number=number-p3;
		}
		if(p5>0)
		{
			number=number-p5;
		}
		if(number<p2)
		{
			p4 = p2-number;
			p2= p2-2*p4;
		}
		else if(number>p2)
		{
			p2=number;
		}
		for(int i=0;i<p2;i++)
		{
			save<<2;
		}
		for(int i=0;i<p3;i++)
		{
			save<<3;
		}
		for(int i=0;i<p4;i++)
		{
			save<<4;
		}
		for(int i=0;i<p5;i++)
		{
			save<<5;
		}
		save<<"\n";
	}
	
	in.close();
	save.close();
}
