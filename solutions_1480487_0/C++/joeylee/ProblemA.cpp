#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("A-small.in");
	FILE* fout;
	fout=fopen("Aans.txt","w");
	int T;
	int N;
	int sum;
	int newsum;
	int count;
	int oldsum;
	int newcount;
	int S[200];
	bool index[200];
	bool again;
	fin>>T;
	for (int i=1;i<=20;i++)
	{
		fin>>N;
		sum=0;
		for (int j=0;j<N;j++)
		{
			fin>>S[j];
			sum+=S[j];
			index[j]=false;
		}			
		fprintf(fout,"Case #%d: ",i);

		again=true;
		count=0;
		oldsum=sum;
		while (again)
		{
			again=false;
			newcount=0;
			newsum=0;
			for (int j=0;j<N;j++)
			{
				if (index[j]==true)
				{
					continue;
				}
				if (2.0/(N-count)-(double)S[j]/sum<0)
				{
					index[j]=true;
					newcount++;
				}
				else
				{
					newsum+=S[j];
				}
			}
			sum=newsum;
			count+=newcount;
		}

		for (int j=0;j<N;j++)
		{
			if (index[j]==true)
			{
				fprintf(fout,"%lf ",0.0);
			}
			else
			{
				fprintf(fout,"%lf ",((double)(sum+oldsum)/(N-count)-S[j])/oldsum*100);
			}
		}		
		fprintf(fout,"\n");
	}
	fin.close();
	fclose(fout);
	return 0;
}