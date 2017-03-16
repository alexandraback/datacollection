#include<stdlib.h>
#include<math.h>
#include<stdio.h>


int no_digits(int n)
{
	int d;
	
	for(d=0;n!=0;n=n/10,d++);

	return d;
}

int shift(n,k)
{
	int p = pow(10,k);
	int temp = n%p;
	n = n/p;
	n = temp*((int)pow(10,no_digits(n)))+n;
	return n;
}
	

main()
{
	int t,n,a,b,x,y,temp,nd;
	FILE *ifile;
	FILE *ofile;
	ifile = fopen("input.txt", "r");
	ofile = fopen("output.txt", "w");
	int ctr=0;
	int i;
	fscanf(ifile,"%i", &t);
	int akhil=t;
	while(t>0)
	{
		ctr=0;
		fscanf(ifile,"%d %d",&a,&b);
		
		for(x=a;x<=b;x++)
		{
			nd = no_digits(x);
			int p;
			p = pow(10,nd-1);
			for(i=1;x!=y;i++)
			{
				y = shift(x,i);				
				if(y>x && y<=b)
					ctr++;
			}
		}		
		fprintf(ofile,"Case #%d: %d\n", akhil-t+1, ctr);
		t--;
	}
} 			
