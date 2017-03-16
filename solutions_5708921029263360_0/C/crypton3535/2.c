#include<stdio.h>
int main()
{
	int test;
	int q,z,num,i,l,a,b,c,d,j,s,p,k,n,m;
	//int arr[100][100][100][100];
	int js[105][105] , jp[105][105] , sp [105][105], store[105];
	int one[10000],two[10000],three[10000];
	FILE *r = fopen("a.in","r");
	FILE *w =fopen("b.txt","w");
	fscanf(r,"%d",&test);
	for(l=1;l<=test;l++)
	{
		z=1;
		num=0;
		for(i=0;i<103;i++)
		{
			store[i]=0;
		}
		fprintf(w,"Case #%d: ",l);
	for(a=0;a<=100;a++)
	{
		for(b=0;b<=100;b++)
		{
			for(c=0;c<=100;c++)
			{
				
					//arr[a][b][c][n]=0;
					js[a][b]=0; sp[b][c] =0; jp[a][c] = 0;
				
			}
		}
	}
	fscanf(r,"%d%d%d",&j,&s,&p);
	fscanf(r,"%d",&k);
		for(c=p;c>0;c--)
	{
		for(b=s;b>0;b--)
		{
			for(a=j;a>0;a--)
			{
				if(js[a][b]<k && sp[b][c]<k && jp[a][c]<k )
				{
					one[z]=a; two[z]=b;three[z++]=c;
				// fprintf(w,"%d %d %d\n",a,b,c);
				 	js[a][b]++;  sp[b][c]++;  jp[a][c]++;	
				 	num++;			
				}
			}
		}
	}
//fseek(w,-(num*6),SEEK_CUR);
	fprintf(w,"%d\n",num);
	for(q=1;q<z;q++)
	{
		fprintf(w,"%d %d %d\n",one[q],two[q],three[q]);
	}


	/*
	m=1;
	fseek( w, 0, SEEK_SET );
	while((c=fgetc(w))!=EOF)
	{
		if(c==':')
		{
			fseek(w,2,SEEK_CUR);
			fprintf(w,"%d \n",store[m++]);
		}
	}*/
	}
	return 0;
}