#include <stdio.h>
#include <algorithm>

using namespace std;

double myabs(double x)
{
	if(x<0) return -1*x;
	else return x;
}
int main()
{
	int n;
	double num[202],temp,re[202],chk[202];
	int t,tcase,i,j,sum,maxx,st,ed,mid;

	FILE *in,*out;
	in=fopen("A-small-attempt1.in","r");
	out=fopen("output.txt","w");

	fscanf(in,"%d",&tcase);
	for(t=0;t<tcase;t++)
	{
		for(i=0;i<202;i++)
			re[i]=0;

		fscanf(in,"%d",&n);
		sum=0;
		maxx=0;
		for(i=0;i<n;i++)
		{
			fscanf(in,"%lf",&num[i]);
			if(num[maxx]<num[i])
				maxx=i;
			num[i]*=100000;
			sum+=num[i];
		}
		st=0;
		ed=sum;

		while(1)
		{
			mid=(st+ed)/2;

			temp=0;
			for(i=0;i<n;i++)
			{
				chk[i]=(mid-num[i])/(double)sum;
				if(chk[i]<0)
					chk[i]=0;
				temp+=chk[i];
			}
			if(myabs(temp-1)<0.000001)
				break;
			else if(temp<1)
				st=mid+1;
			else
				ed=mid-1;
		}
		for(i=0;i<n;i++)
			re[i]=chk[i]*100;
		
		fprintf(out,"Case #%d: ",t+1);
		for(i=0;i<n;i++)
			fprintf(out,"%.5lf ",re[i]);
		fprintf(out,"\n");
	}

	return 0;
}

/*

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	double num[202],temp,re[202],minx1,miny1;
	int t,tcase,i,j,sum,minx,miny;

	FILE *in,*out;
	in=fopen("A-small-attempt0.in","r");
	out=fopen("output.txt","w");

	fscanf(in,"%d",&tcase);
	for(t=0;t<tcase;t++)
	{
		for(i=0;i<202;i++)
			re[i]=0;

		fscanf(in,"%d",&n);
		sum=0;
		for(i=0;i<n;i++)
		{
			fscanf(in,"%lf",&num[i]);
			sum+=num[i];
		}
		if(n>2)
		{
			minx=0;
			for(i=0;i<n;i++)
			{
				if(num[minx]>num[i])
					minx=i;
			}
			miny=0;
			if(minx==miny)
				miny=1;
			for(i=0;i<n;i++)
			{
				if(num[miny]>num[i] && minx!=i)
					miny=i;
			}

			temp=(num[miny]-num[minx])/sum*100;
			re[minx]=temp;
			re[miny]=0;
			temp=100-temp;
			temp/=n-2;
			for(i=0;i<n;i++)
			{
				if(i!=minx && i!=miny)
					re[i]=temp;
			}
		}
		else
		{
			if(num[0]>num[1])
			{
				minx1=num[0];
				miny1=num[1];
			}
			else
			{
				minx1=num[1];
				miny1=num[0];
			}

			temp=(1-(minx1-miny1)/(minx1+miny1))/2;
			if(num[0]>num[1])
			{
				if(temp>0.5)
				{
					re[1]=temp;
					re[0]=1-temp;
				}
				else
				{
					re[0]=temp;
					re[1]=1-temp;
				}
			}
			else
			{
				if(temp>0.5)
				{
					re[0]=temp;
					re[1]=1-temp;
				}
				else
				{
					re[1]=temp;
					re[0]=1-temp;
				}
			}
			re[0]*=100;
			re[1]*=100;
		}
		fprintf(out,"Case #%d: ",t+1);
		for(i=0;i<n;i++)
			fprintf(out,"%lf ",re[i]);
		fprintf(out,"\n");
	}

	return 0;
}*/