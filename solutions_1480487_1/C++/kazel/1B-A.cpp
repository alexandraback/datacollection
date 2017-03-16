#include<iostream>

double* foo(int N,int* s)
{
	double* out = new double[N];
	int X = 0;
	for(int i=0;i<N;i++) X += s[i];
	double x=X;
	double cutline = x/N;
	double sum = 0;
	double cutmax=X,cutmin=0;
	while(abs(sum-X)>0.00000001)
	{
		cutline = (cutmax+cutmin)/2;
		sum = 0;
		for(int i=0;i<N;i++)
		{
			if(s[i]<cutline)
			{
				sum += (cutline-s[i]);
			}
		}
		if(sum>X) cutmax = cutline;
		else if(sum<X) cutmin = cutline;
	}

	for(int i=0;i<N;i++)
	{
		if(s[i]>cutline) out[i] = 0;
		else out[i] = (cutline-s[i])*100/x;
	}

	return out;
}


int main()
{
	int T,N;
	int s[300];
	double* out;

	std::cin>>T;
	for(int i=1;i<=T;i++)
	{
		std::cin>>N;

		for(int n=0;n<N;n++)
		{
			std::cin>>s[n];
		}
		out = foo(N,s);
		std::cout<<"Case #"<<i<<": ";
		for(int n=0;n<N;n++)printf("%f ",out[n]);
		std::cout<<std::endl;
	}
}