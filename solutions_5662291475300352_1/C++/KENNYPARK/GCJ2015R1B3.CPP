#include<fstream>
using namespace std;
FILE*fin=fopen("input.txt","r");
FILE*fout=fopen("output.txt","w");
int n;
double a[20],b[20];
int plus(int i,int j)
{
	double t,a1=a[i],a2=a[j],b1=b[i],b2=b[j];
	if(a1<a2)b1=b1-360;
	else b2=b2-360;
	t=(b1*a1-b2*a2)/(a1-a2);
	return t<=360;
}
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
		out=0;
		if(cnt>=2)for(j=1;j<cnt;++j)for(k=j+1;k<=cnt;++k)out=out+plus(j,k);
		fprintf(fout,"Case #%d: %d\n",i,out);
	}
	fcloseall();
	return 0;
}