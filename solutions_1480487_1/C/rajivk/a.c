#include<stdio.h>

void Insert_Sort(int XI[], int N)
{
	int temp, i, j;
	for(i=1;i<N;i++)
	{
		temp=XI[i];
		for(j=i;j>0 && XI[j-1]>temp;j--)
			XI[j]=XI[j-1];
		XI[j]=temp;
	}
}


int main()
{
	int i, j, k, n, flag, t, T, J[200], C[200], check, X, S[200];
	double m, R[200];
	scanf("%d", &T);
	for(t=0;t<T;t++)
	{
		scanf("%d", &n);
		for(i=0;i<n;i++)
		{
			scanf("%d", J+i);
			C[i]=J[i];
		}
		Insert_Sort(J, n);
		S[n]=0;
		for(i=n-1;i>=0;i--)
			S[i]=S[i+1]+J[i];
		X=S[0];
		for(k=0;k<n;k++)
		{
			check=S[k+1]+(k+1)*J[k]-2*X;
			if(check==0)
			{
				flag=1;
				break;
			}
			else if(check>0)
			{
				flag=0;
				break;
			}
		}
		k--;
		if(flag==1 && k!=n-1)
			m=(double)J[k+1];
		else if(flag==0 && k!=n-1)
			m=((double)(2*X-S[k+1])/(k+1));
		else
			m=(double)(2*X)/n;
		printf("Case #%d: ", t+1, m);
		for(i=0;i<n;i++)
		{
			if(C[i]>m)
				printf("%lf ", 0.0);
			else
				printf("%lf ", 100*(m-C[i])/X);
		}
		printf("\n");
	}
}
