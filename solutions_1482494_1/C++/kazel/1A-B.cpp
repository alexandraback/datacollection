#include<iostream>
#include<algorithm>
int foo(int N, int* o, int* t)
{
	int stars = 0;
	int games = 2*N;
	int old = -1;
	int tmppt;
	bool c1[1001];
	bool c2[1001];
	for(int n=0;n<N;n++){c1[n] = false;c2[n] = false;}
	for(int i=0;;i++)
	{
		//if stars unchanged, Too Bad
		if(stars == games) return i;
		if(stars == old) return -1;
		old = stars;

		//2-star
		for(int n=0;n<N;n++)
		{
			if(!c1[n] && !c2[n] && stars >= t[n])
			{
				c1[n] = true;
				c2[n] = true;
				stars += 2;
				break;
			}
		}
		//1-star
		if(stars == old)for(int n=0;n<N;n++)
		{
			if(c1[n] && !c2[n] && stars >= t[n])
			{
				c2[n] = true;
				stars++;
				break;
			}
		}
		
		if(stars == old)
		{
			tmppt = -1;
			for(int n=0;n<N;n++)
			{
				if(!c1[n] && stars >= o[n])
				{
					if(t[tmppt] < t[n])tmppt = n;
				}
			}
			if(tmppt != -1)
			{
				c1[tmppt] = true;
				stars++;
			}
		}
	}

}
int main()
{
	int T,N;
	int a[1001];
	int b[1001];

	std::cin>>T;
	for(int i=1;i<=T;i++)
	{
		std::cin>>N;
		for(int n=0;n<N;n++) std::cin>>a[n]>>b[n];
		int tmp = foo(N,a,b);
		if(tmp < 0)std::cout<<"Case #"<<i<<": Too Bad"<<std::endl;
		else std::cout<<"Case #"<<i<<": "<<tmp<<std::endl;
	}
}