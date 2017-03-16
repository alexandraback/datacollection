#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
//int Num[200];
int main()
{
	int T;
	scanf("%d",&T);
	int counter = 0;
	while(T--)
	{
		++counter;
		int N,S,P,num;
		scanf("%d",&N);
		scanf("%d",&S);
		scanf("%d",&P);
//		cout << N<<'\t'<<S<<'\t'<<P<<endl;
		int sup=0,nos = 0,max=0;
		for(int i=0;i<N;++i)
		{
			scanf("%d",&num);
			if(num<=1)
			{
				if(P<=num)
					++nos;
				continue;
			}
			if(num%3)
				max = num/3+1;
			else
				max = num/3;
			if(max>=P)
				++nos;
			else
			{
				if(num%3==2)
					max = num/3+2;
				else
					max = num/3+1;
				if(max>=P)
					++sup;
			}
		}
		cout << "Case #"<<counter<<": "<<(nos+min(sup,S))<<endl;
	}
	return 0;
}
