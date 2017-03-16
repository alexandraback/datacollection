#include<fstream>
using namespace std;
FILE*fin=fopen("input.txt","r");
FILE*fout=fopen("output.txt","w");
int n;
double a[10],b[10];
int main()
{
	int i,j,k,x,y,z,w,cnt,out;
	double t;
	fscanf(fin,"%d",&n);
	for(i=1;i<=n;++i)
	{
		fscanf(fin,"%d",&x);
		cnt=0;
		for(k=1;k<=x;++k)
		{
			fscanf(fin,"%d%d%d",&y,&z,&w);
			for(j=1;j<=z;++j)
			{
				a[++cnt]=w+j-1;
				b[cnt]=y;
			}
		}
		if(cnt==1)out=0;
		else
		{
			if(a[1]==a[2])out=0;
			else
			{
				if(a[1]<a[2])b[1]=b[1]-360;
				else b[2]=b[2]-360;
				t=(b[1]*a[1]-b[2]*a[2])/(a[1]-a[2]);
				if(t<=360)out=1;
				else out=0;
			}
		}
		fprintf(fout,"Case #%d: %d\n",i,out);
	}
	fcloseall();
	return 0;
}