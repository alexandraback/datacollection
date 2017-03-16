#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("A-large.in");
	FILE* fout;
	fout=fopen("Aans.txt","w");
	int T;
	fin>>T;
	int A;
	int B;
	double* P=new double[100000];
	double* S=new double[100000];
	double cor;

	for (int i=1;i<=T;i++)
	{
		fin>>A;
		fin>>B;
		for (int j=0;j<A;j++)
		{
			fin>>P[j];
		}

		S[0]=P[0];
		for (int j=1;j<A;j++)
		{
			S[j]=S[j-1]*P[j];			
		}
	    cor=S[A-1]*(B-A+1)+(1-S[A-1])*(B+1+B-A+1);
		for (int b=A-2;b>=0;b--)
		{
			if (S[b]*(B-b+A-1-b)+(1-S[b])*(B+1+B-b+A-1-b)<cor)
			{
				cor=S[b]*(B-b+A-1-b)+(1-S[b])*(B+1+B-b+A-1-b);
			}
		}
		if (B+2<cor)
		{
			cor=B+2;
		}
		fprintf(fout,"Case #%d: %lf\n",i,cor);
	}
	fin.close();
	fclose(fout);;
	return 0;
}