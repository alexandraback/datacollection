#include<fstream>
using namespace std;
FILE*fin=fopen("input.txt","r");
FILE*fout=fopen("output.txt","w");
int n,a[1010];
inline int mx2(int a,int b)
{
	if(a>b)return a;
	else return b;
}
int main()
{
	int i,j,k,x,t,out;
 	fscanf(fin,"%d",&n);
	for(i=1;i<=n;++i)
	{
		fscanf(fin,"%d",&x);
		out=999999999;
		for(j=1;j<=x;++j)fscanf(fin,"%d",&a[j]);
		for(j=1;j<=1000;++j)
		{
			t=j;
			for(k=1;k<=x;++k)t=t+(a[k]-1)/j;
			if(t<out)out=t;
		}
		fprintf(fout,"Case #%d: %d\n",i,out);
	}
	fcloseall();
	return 0;
}
