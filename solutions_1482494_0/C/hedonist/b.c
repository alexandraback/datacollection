#include <stdio.h>

int MAXN=1200;

int qsort(int a[], int b[], int h, int t)
{
	int mida, midb, i, j;
	if (h<t) {
		i=h; j=t;
		mida = a[i];
		midb = b[i];
		while (i<j) {
			while ((i<j) && (b[j]>midb)) j--;
			a[i] = a[j];
			b[i] = b[j];
			if (i<j) i++;
			while ((i<j) && (b[i]<midb)) i++;
			a[j] = a[i];
			b[j] = b[i];
			if (i<j) j--;
		}
		a[i] = mida;
		b[i] = midb;
		qsort(a, b, h, i-1);
		qsort(a, b, i+1, t);
	}
	return 0;
}

int main() 
{
	int T,i,j;
	int n,c,m;
	int a[MAXN], b[MAXN];
	int p;
	int f=0;
	
	scanf("%d", &T);
	for (i=0; i<T; i++)
	{
		scanf("%d", &n);
		for (j=0; j<n; j++)
			scanf("%d %d", &a[j], &b[j]);
		qsort(a,b,0,n-1); 
	//	for (j=0; j<n; j++) 
//		{printf("(%d,%d) ", a[j], b[j]);}
		
		c=0; m=0; p=0;
		while (1)
		{
			if (p==n) break;
			if (m>=b[p])
			{
				if (a[p]== MAXN*3)
					m++;
				else 
					m+=2;
				c++;				
				a[p] = MAXN*3;
		//		printf("b%d",p);
				p++;
			}
			else {
				f=0;
				for (j=n-1; j>=p; j--)
					if (m>=a[j]) {
						m++; c++;
						a[j] = MAXN*3;
			//		printf("a%d",j);
						f=1;
						if (m==b[p]) break;
					}
				if (f==0) {
					c=-1;
					break;
				}
			}
		}
		if (c>=0) 
			printf("Case #%d: %d\n", i+1, c);
		else
			printf("Case #%d: Too Bad\n", i+1);			
	}
	return 0;
}