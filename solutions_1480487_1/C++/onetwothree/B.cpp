#include<fstream>
#include<iostream>
//#include<cmath>
using namespace std;

//ofstream out("output.txt");
FILE *out=fopen("output.txt", "w");
double vet[100];
inline double fabs(double a)
{
	if(a>=0)
		return a;
	return -a;
}
int main(void)
{
	FILE *fp=fopen("input.txt", "r");

	int T;
	fscanf(fp, "%d\n", &T);
	for(int l=1;l<=T;l++)
	{
		//out << "Case #" << l << ": ";
		fprintf(out, "Case #%d: ", l);
		int N, somma=0;
		fscanf(fp, "%d", &N);
		
		for(int i=0;i<N;i++)
		{
			fscanf(fp, "%lf", &vet[i]);
			somma+=vet[i];
		}
		for(int i=0;i<N;i++)
			vet[i]/=(double)somma;
			
		//for(int i=0;i<N;i++)
	//		cout << vet[i] << " " ;
		for(int i=0;i<N;i++)
		{
			double da=0, a=1;
			while(1)
			{
				//cout << da << " " << a << " " << fabs(a-da) << endl;
				if(fabs(a-da)<=0.000000001)
				{
					//out << (da+a)/2*100 << " ";
					fprintf(out, "%f ", (da+a)/2*100);
					break;
				}
				double m=(a+da)/2;
				double rem=1-m;
				for(int k=0;k<N;k++)
				{
					if(k==i)
						continue;
					double diff=vet[i]+m-vet[k];
					if(diff>0&&diff<=rem)
						rem-=diff;
					else if(diff>0&&diff>rem)
					{
						//cout << "h";
						a=m;//vinto
						goto change;
					}
				}
				if(fabs(rem)<0.0000001)
					a=m;//vinto
				else da=m;//perso
				change:;
			}
		}
		fprintf(out, "\n");
	}
	//out.close();
	fclose(out);
	fclose(fp);
}
