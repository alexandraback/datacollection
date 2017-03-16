#include<stdio.h>

int main()
{
	FILE *ifp, *ofp;
	int t,z,n,i,key;
	float x,k;

	ifp = fopen("input11.in", "r");
	if (ifp == NULL) {
  		fprintf(stderr, "Can't open input file!\n");
 	 	exit(1);
	}

	ofp = fopen("output.txt", "w");
	if (ofp == NULL) {
  		fprintf(stderr, "Can't open output file!\n");
		fclose(ifp);
 	 	exit(2);
	}

	fscanf(ifp, "%d", &t);

	for(z=0;z<t;z++)
	{
		x=0;key=0;
		fscanf(ifp, "%d", &n);
		float s[n];
		int a[n];

		for(i=0;i<n;i++)
		{
			fscanf(ifp, "%f", &s[i]);
		}

		for(i=0;i<n;i++)	x=x+s[i];

		k=x;

		for(i=0;i<n;i++)
		{
			if(s[i]>(2*x)/n)	{a[i]=0;key++;k=k-s[i];}
			else	a[i]=1;
		}

		fprintf(ofp, "Case #%d:",z+1);
		
		for(i=0;i<n;i++)
		{
			if(a[i]==0)	fprintf(ofp, " %f",100 * 0.0);
			else	fprintf(ofp, " %f",((((k+x)/(n-key))-s[i])/x)*100);
		}

		if(z!=t)	fprintf(ofp, "\n");

	}

	fclose(ifp);
	fclose(ofp);

	return 0;

}

