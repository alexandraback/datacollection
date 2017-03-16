#include<fstream>
#include<iostream>
#include<cstring>
//#include<cmath>
using namespace std;

//ofstream out("output.txt");
FILE *out=fopen("output.txt", "w");
int vet[20];
bool preso[20];
int somma;
bool solved;
bool mat[3000001][20];
bool seen[3000001];

void recursive(int da)
{
	if(solved)
		return;
	if(da==20)
	{
		//cout << somma << endl;
		if(seen[somma])//solved
		{
			int x=0;
			for(int i=0;i<20;i++)
				if(preso[i])
				{
					if(x==0){x++;
						fprintf(out, "%d", vet[i]);}
					else{
						fprintf(out, " %d", vet[i]);}
				}
			fprintf(out, "\n");
			x=0;
			for(int i=0;i<20;i++)
				if(mat[somma][i])
				{
					if(x==0){x++;
						fprintf(out, "%d", vet[i]);}
					else{
						fprintf(out, " %d", vet[i]);}
				}
			solved=true;
		}
		else{
			seen[somma]=true;
			memcpy(mat[somma], preso, sizeof(preso));
		}
		return;
	}
	somma+=vet[da];
	preso[da]=true;
	recursive(da+1);
	somma-=vet[da];
	preso[da]=false;
	recursive(da+1);
	
}

int main(void)
{
	//cout << 3741 +875+ 2463    << endl << 2259+ 4028 +792  ; 
	FILE *fp=fopen("input.txt", "r");

	int T;
	fscanf(fp, "%d\n", &T);
	for(int l=1;l<=T;l++)
	{
		fprintf(out, "Case #%d: \n", l);
		int N;
		fscanf(fp, "%d", &N);
		memset(preso, 0, sizeof(preso));
		memset(seen, 0, sizeof(seen));
		for(int i=0;i<20;i++)
			fscanf(fp, "%d", &vet[i]);
		for(int i=0;i<20;i++)
			cout << vet[i] << " ";
		cout << endl;
		somma=0;solved=false;
		recursive(0);
		if(!solved)
			fprintf(out, "Impossible");
		fprintf(out, "\n");
	}
	//out.close();
	fclose(out);
	fclose(fp);
}
