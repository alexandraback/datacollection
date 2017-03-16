#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int Num[1000];
int Back[1000];
int main()
{
	int T;
	scanf("%d",&T);
	int TC=0;
	while(T--)
	{
		++TC;
		int N;
		scanf("%d",&N);
		for(int i=0;i<N;++i)
			scanf("%d",&Num[i]);
		int sum=0;
		for(int i=0;i<N;++i)
			sum += Num[i];
		for(int i=0;i<N;++i)
			Back[i]=Num[i];
		sort(Num,Num+N);
		int ts=sum;
		int s=0,t=1;
		double hight = Num[0];
		while(t<N)
		{
			while(s<N-1 && Num[s+1]==Num[s])
				++s;
			t=s+1;
			int d=t;
			int delta = Num[t]-Num[s];
			if(d*delta <= ts)
			{
				ts -= d*delta;
				hight += delta;
			}
			else
			{
				hight += ts/(double)d;
				ts = 0;
				break;
			}
			s=t;
		}
		if(ts>0)
			hight += ts/(double)N;
//		cout <<sum<<endl;
//		cout << "h:\t"<<hight<<endl;
		cout <<"Case #"<<TC<<":";
		for(int i=0;i<N;++i)
		{
			double r= 100*(hight-Back[i])/sum;
			if(r>=0)
				printf(" %.6lf",r);
			else 
				printf(" 0.000000");
		}
		cout << endl;
	}
	return 0;
}
