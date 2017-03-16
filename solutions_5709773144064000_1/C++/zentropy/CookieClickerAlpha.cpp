#include <stdio.h>

double calc(unsigned int n,float c,float f,float x)
{
	double ret = 0;
	for(unsigned int i = 0;i < n;++i)
	{
		double x = 2.0 + i*f;
		ret += c/x;
	}
	ret += x/(2.0+n*f);
	return ret;
}

int main()
{
	// 
	// f(n) = C/2.0 + C/(2.0+F) + ... + C/(2.0 + (n-1)*F) + X/(2.0 + n*F)
	//
	// f(n) - f(n-1) = C/(2.0 + (n-1)*F) + X/(2.0 + n*F) - X/(2.0 + (n-1)*F) = (C - X)/(2.0 + (n-1)*F) + X/(2.0 + n*F)
	// 
	// 由于(C - X)*(2.0+n*F) + X*(2.0 + (n-1)*F) = (2.0+n*F)*C - X*F = 2.0*C - X*F + n*F*C,因此f(n)在(X*F - 2.0*C)/(F*C)左边递减,右边递增
	//
	// 如果 X*F < 2.0*C,则f(n)在n = 0的时候取得最小值
	// 否则,f(n)的最小值必然在n = (X*F - 2.0*C)/(F*C)上取整,下取整

	unsigned int nCases = 0;scanf("%d",&nCases);						// 1 <= nCases <= 100
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		float c = 0,f = 0,x = 0;scanf("%f%f%f",&c,&f,&x);				// 1 <= C <= 10000,1 <= F <= 100,1 <= X <= 100000.

		double key = (x*f - 2.0*c)/(f*c);								// key <= x/c <= x
		double ans = calc(0,c,f,x);
		if(key >= 0)
		{
			double r = calc((unsigned int)(key),c,f,x);
			if(r < ans) ans = r;
			r = calc((unsigned int)(key+1),c,f,x);
			if(r < ans) ans = r;
		}

		printf("Case #%u: %.7f\n",iCases,ans);
	}
	return 0;
}