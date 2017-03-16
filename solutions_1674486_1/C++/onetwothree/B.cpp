#include<fstream>
#include<iostream>
#include<cstring>
#include<vector>
//#include<cmath>
using namespace std;

//ofstream out("output.txt");
FILE *out=fopen("output.txt", "w");
bool grafo[1000][1000];


int main(void)
{
	FILE *fp=fopen("input.txt", "r");

	int T;
	fscanf(fp, "%d\n", &T);
	for(int l=1;l<=T;l++)
	{
		fprintf(out, "Case #%d: ", l);
		memset(grafo, 0, sizeof(grafo));
		vector<int> vicini[1000];
		//read
		int N, M;
		fscanf(fp, "%d\n", &N);
		for(int i=0;i<N;i++)
		{
			fscanf(fp, "%d", &M);
			vicini[i].resize(M);
			for(int k=0;k<M;k++)
			{
				fscanf(fp, "%d", &vicini[i][k]);
				vicini[i][k]--;
				grafo[i][vicini[i][k]]=true;
			}
		}
		for(int i=0;i<N;i++)
			grafo[i][i]=true;
		for(int k=0;k<N;k++)
			for(int i=0;i<N;i++)
				for(int j=0;j<N;j++)
					if(grafo[i][k]&&grafo[k][j])
						grafo[i][j]=true;
		//cout << grafo[0][2] << endl;
		for(int D=0;D<N;D++)
			for(int A=0;A<N;A++)
			{
				if(A==D)
					continue;
				for(int b=0;b<vicini[D].size();b++)
					for(int c=b+1;c<vicini[D].size();c++)
					{
						int B=vicini[D][b], C=vicini[D][c];
						if(grafo[B][A]&&grafo[C][A])
						{
							fprintf(out, "Yes\n");
							goto next;
						}
					}
			}
		fprintf(out, "No");
		fprintf(out, "\n");
		next:;
	}
	//out.close();
	fclose(out);
	fclose(fp);
}
