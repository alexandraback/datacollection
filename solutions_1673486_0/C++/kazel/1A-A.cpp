#include<iostream>
#include<cstdio>
double foo(int A, int B, double*p)
{
	double out;
	double tmp;
	double pb;

	//choice 1. press Enter
	tmp = 1 + B + 1;//Enter + whole pw + Enter
	out = tmp;

	//choice 2. keep typing
	pb = 1;
	for(int i=0;i<A;i++) pb *= p[i];
	tmp = pb*(B - A + 1) + (1 - pb)*(B*2 - A + 2);
	if(tmp < out) out = tmp;

	//choice 3. backspace some times
	for (int i=1; i<A; i++)
	{
		pb /= p[A-i];
		tmp = pb*(B - A + 2*i + 1) + (1 - pb)*(B*2 - A + 2*i + 2);
		if(tmp < out) out = tmp;
	}
	return out;
}
int main()
{
	int T;
	int A, B;
	double p[10000];
	std::cin>>T;
	for(int i=1;i<=T;i++)
	{
		std::cin>>A>>B;
		for(int n=0;n<A;n++)std::cin>>p[n];
		std::cout<<"Case #"<<i<<": ";
		printf("%f\n",foo(A,B,p));
	}
	return 0;
}