using namespace std;
#include <iostream>
int main()
{
	FILE *fp1,*fp2;
	if((fp1=fopen("A-small-attempt2.in","r"))==NULL)
	{
		printf("cannot open this file!\n");
	};
	fp2=fopen("A-small-attempt2.out","w");

	int *p;
	int n,m,i;
	fscanf(fp1,"%d",&m);
	for(int j=0;j<m;j++)
	{
		fscanf(fp1,"%d",&n);
		n++;
		p=new int[n];
		int s=0,l=0;
		for(i=0;i<n;i++)
			fscanf(fp1,"%1d",&p[i]);
		for(i=0;i<n;i++)
		{
			if(s<i)
			{
				l+=i-s;
				s=i;
			}
			s=s+p[i];
		}
		printf("Case #%d: %d\n",j+1,l);
		fprintf(fp2,"Case #%d: %d\n",j+1,l);
	}
	fclose(fp1);
	fclose(fp2);
	getchar();
	getchar();
	return 0;
}