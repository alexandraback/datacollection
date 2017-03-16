#include <fstream>
using namespace std;

ifstream fin;
ofstream fout;

int T, R, C, M;
int NM;

int nmines[50];
int possible;

void solve()
{
	possible = 0;
	for (int i = 0; i < 50; i++)
		nmines[i] = 0;
	if(NM == 1)
	{
		nmines[0] = 1;
		possible = 1;
		return;
	}
	if(R == 1)
	{
		nmines[0] = NM;
		possible = 1;
		return;
	}
	if(C == 1)
	{
		for(int i = 0; i < NM; i++)
			nmines[i] = 1;
		possible = 1;
		return;
	}
	if(NM < 4)
		return;
	int m,n;
	for (m = 2; m <= R; m++)
	{
		n = NM/m;
		if (n*m < NM)
			n++;
		if(n < 2)
			n = 2;
		if(n > C)
			continue;
		if(2*(m+n-2) <= NM)
		{
			possible = 1;
			break;
		}
	}
	if(possible == 1)
	{
		nmines[0] = n;
		nmines[1] = n;
		if(m > 2)
		{
			int average = (NM-2*n)/(m-2);
			int residule = (NM-2*n)-(m-2)*average;
			for (int i = 0; i < m-2; i++)
				nmines[i+2] = average + ((i < residule)?1:0);
		}	
	}
}

void main()
{
	fin.open("in.txt");
	fout.open("out.txt");
	fin >> T;
	int i,j,k;
	for (i = 0; i < T; i++)
	{
		fin >> R >> C >> M;
		NM = R*C-M;
		solve();
		fout << "Case #" << i+1 << ":" << endl;
		if(possible == 0)
			fout << "Impossible"<<endl;
		else
		{
			for(k = 0; k < R; k++)
			{
				if(k == 0)
					fout << "c";
				if(k != 0 && nmines[k] > 0)
					fout << ".";
				for (j = 0; j < nmines[k]-1; j++)
					fout << ".";
				for (j = 0; j < C-nmines[k]; j++)
					fout << "*";
				fout << endl;
			}	
		}
	}


	fin.close();
	fout.close();
}