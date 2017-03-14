#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>

using namespace std;

void main()
{
	ofstream out("D.out");
	ifstream in("D.in");
	int T,t;

	in>>T;
	for(t=1;t<=T;t++)
	{
		cout<<t<<endl;
		int H,W,D,i,ii,j,jj,h,w,r=0,k;
		int d(int,int);
		char *tmp;
		char m[30][31];
		char map[115][115];
		in>>H>>W>>D;
		in.getline(m[0],35);
		for(i=0;i<H;i++)
		{
			in.getline(m[i],31);
			tmp=strchr(m[i],'X');
			if(tmp)
			{
				h=i;
				w=tmp-m[i];
			}
		}
//		for(i=0;i<H;i++)
//		{
//			for(j=0;j<W;j++)
//				cout<<m[i][j];
//			cout<<endl;
//		}

		H-=2;
		W-=2;

		for(i=0;i<2*H;i++)
			for(j=0;j<2*W;j++)
			{
				ii=(i+h)%(2*H);
				if(ii>H)
					ii=2*H-ii+1;
				if(!ii)
					ii=1;
				jj=(j+w)%(2*W);
				if(jj>W)
					jj=2*W-jj+1;
				if(!jj)
					jj=1;
				map[i+50][j+50]=m[ii][jj];
			}

		for(i=-50;i<=50;i++)
			for(j=-50;j<=50;j++)
			{
				ii=i%(2*H);
				if(ii<0)
					ii+=2*H;
				jj=j%(2*W);
				if(jj<0)
					jj+=2*W;
				map[50+i][50+j]=map[50+ii][50+jj];
			}

		map[50][50]='0';
		
//		for(i=-D;i<=D;i++)
//		{
//			for(j=-D;j<=D;j++)
//				cout<<map[i+50][j+50];
//			cout<<endl;
//		}getchar();

		for(i=0;i<=D;i++)
			for(j=0;j<=D;j++)
			{
				if((map[i+50][j+50]=='X') &&
					(i*i+j*j <= D*D))
				{
					r++;
					k=d(i,j);
					ii=i/k;
					jj=j/k;
					for(k=1;k*k*(ii*ii+jj*jj)<=D*D;k++)
						map[50+k*ii][50+k*jj]='0';
				}
				if((map[i+50][-j+50]=='X') &&
					(i*i+j*j <= D*D))
				{
					r++;
					k=d(i,j);
					ii=i/k;
					jj=j/k;
					for(k=1;k*k*(ii*ii+jj*jj)<=D*D;k++)
						map[50+k*ii][50-k*jj]='0';
				}
				if((map[-i+50][j+50]=='X') &&
					(i*i+j*j <= D*D))
				{
					r++;
					k=d(i,j);
					ii=i/k;
					jj=j/k;
					for(k=1;k*k*(ii*ii+jj*jj)<=D*D;k++)
						map[50-k*ii][50+k*jj]='0';
				}
				if((map[-i+50][-j+50]=='X') &&
					(i*i+j*j <= D*D))
				{
					r++;
					k=d(i,j);
					ii=i/k;
					jj=j/k;
					for(k=1;k*k*(ii*ii+jj*jj)<=D*D;k++)
						map[50-k*ii][50-k*jj]='0';
				}
			}

//		for(i=-D;i<=D;i++)
//		{
//			for(j=-D;j<=D;j++)
//				cout<<map[i+50][j+50];
//			cout<<endl;
//		}getchar();

		out<<"Case #"<<t<<": "<<r<<endl;
	}

	in.close();
	out.close();
}

int d(int a,int b)
{
	int c;
	do{
		if(a<b)
		{
			c=a;
			a=b;
			b=c;
		}
		if(!b)
			return a;
		a=a%b;
	}while(1);
}