#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

unsigned long long A,B,K;

unsigned long long dp_f(int k, int res_a, int res_b, int res_k)
{
	unsigned long long t=1;
	t = t<<k;
	unsigned long long K_k = (K&t)>>k;
	unsigned long long A_k = (A&t)>>k;
	unsigned long long B_k = (B&t)>>k;
	unsigned long long count = 0;
	if (k==0)
	{
		for (int ik=0;ik<=1;ik++)
			for (int ia=0;ia<=1;ia++)
				for (int ib=0;ib<=1;ib++)
				{
					if ((ia&ib)==ik)
					{
						int ra=0,rb=0,rk=0;
						if (res_a==1 && ia>A_k) break;
						if (res_b==1 && ib>B_k) break;
						if (res_k==1 && ik>K_k) break;
						count += 1;
					}
				}
	}
	else
	{
		for (int ik=0;ik<=1;ik++)
			for (int ia=0;ia<=1;ia++)
				for (int ib=0;ib<=1;ib++)
				{
					if ((ia&ib)==ik)
					{
						int ra=0,rb=0,rk=0;
						if (res_a==1 && ia>A_k) break;
						if (res_b==1 && ib>B_k) break;
						if (res_k==1 && ik>K_k) break;

						if (res_a==1 && ia==A_k) ra=1;
						if (res_b==1 && ib==B_k) rb=1;
						if (res_k==1 && ik==K_k) rk=1;
						count += dp_f(k-1,ra,rb,rk);
					}
				}

	}
	return count;
}

int main()
{
	ofstream ofile;
	ifstream ifile;

	ofile.open("B-small-attempt0-out.txt");		
	ifile.open("B-small-attempt0.in");			
	//ifile.open("B-small.txt");	

	long T;
	long N;

	ifile>>T;
	for (int iT=1; iT<=T;iT++)
	{
		
		ifile>>A>>B>>K;
		A -= 1;
		B -= 1;
		K -= 1;

		
		

		ofile<<"Case #"<<iT<<": "<<dp_f(40,1,1,1)<<endl;
	}
	ifile.close();
	ofile.close();
	system("pause");
}