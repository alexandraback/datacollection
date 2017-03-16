#include<fstream>
using namespace std;
FILE*fin=fopen("input.txt","r");
FILE*fout=fopen("output.txt","w");
int n;
char str[1010];
int main()
{
	int i,j,x,now,out;
	fscanf(fin,"%d",&n);
	for(i=1;i<=n;++i)
	{
		fscanf(fin,"%d%s",&x,str);
		now=0;
		out=0;
		for(j=0;j<=x;++j)
		{
			if(now<j)
			{
				out=out+j-now;
				now=j;
			}
			now=now+str[j]-'0';
		}
		fprintf(fout,"Case #%d: %d\n",i,out);
	}
	fcloseall();
	return 0;
}