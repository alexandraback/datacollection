#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct mpair
{
	long long size,type;
	/*
	mpair(int s_,int t_)
	{
		size = s_;
		type = t_;
	}
	*/
};
mpair Box[120];
mpair Toy[120];
int main()
{
	int T;
	scanf("%d",&T);
	int TC=0;
	while(T--)
	{
		++TC;
		int N,M;
		scanf("%d",&N);
		scanf("%d",&M);
		for(int i=0;i<N;++i)
		{
			scanf("%lld",&(Box[i].size));
			scanf("%lld",&(Box[i].type));
		}
		for(int i=0;i<M;++i)
		{
			scanf("%lld",&(Toy[i].size));
			scanf("%lld",&(Toy[i].type));
		}
		/*
		for(int i=1;i<N;++i)
		{
			if(Box[i-1].type==Box[i].type)
				cerr<<TC<<"ERROR1"<<endl;
		}
		*/
		/*
		for(int i=1;i<M;++i)
		{
			if(Toy[i-1].type==Toy[i].type)
			{
				cerr<<"TC:\t"<<TC<<endl;
				cerr<<i<< "\tERROR2!\t"<< Toy[i].type<<endl;
				return 0;
			}
			cerr<<endl;
		}
		*/

		/*
		int sid=0;tid= 1;
		for(int i=0;i<N;++i)
		{
			if(Box[tid].type==Box[sid].type)
			{
				++tid;
				++sid;
			}
		}
		*/
		if(N==3 && Box[1].type==Box[2].type)
		{
			--N;
			Box[1].size += Box[2].size;
		}
		if(N>1 && Box[1].type==Box[0].type)
		{
			--N;
			Box[0].size += Box[1].size;
			Box[1].size = Box[2].size;
			Box[1].type = Box[2].type;
		}
		if(N<3)
		{
			Box[2].size=0;
			Box[2].type=-1;
		}
		if(N<2)
		{
			Box[1].size=0;
			Box[1].type=-1;
		}

		long long ans=0;
		int tp1=Box[0].type;
		int tp2=Box[1].type;
		int tp3=Box[2].type;
		for(int i=-1;i<M;++i)
		{
			for(int j=i;j<M;++j)
			{
				int s1=0,t1=i;
				int s2=i+1,t2=j;
				int s3=j+1,t3=M-1;
				long long max1=0;
				for(int k=s1;k<=t1;++k)
				{
					if(Toy[k].type==tp1)
						max1 += Toy[k].size;
				}
				if(Box[0].size < max1)
					max1 = Box[0].size;

				long long max2=0;
				for(int k=s2;k<=t2;++k)
				{
					if(Toy[k].type==tp2)
						max2 += Toy[k].size;
				}
				if(Box[1].size < max2)
					max2 = Box[1].size;

				long long max3=0;
				for(int k=s3;k<=t3;++k)
				{
					if(Toy[k].type==tp3)
						max3 += Toy[k].size;
				}
				if(Box[2].size < max3)
					max3 = Box[2].size;
				long long tans = max1+max2+max3;
				if(tans>ans)
					ans = tans;
			}
		}
		if(N==3 && tp1==tp3)
		{
			int tp = tp1;
			long long tm1 = Box[0].size+Box[2].size;
			long long tm2 = 0;
			for(int i=0;i<M;++i)
			{
				if(Toy[i].type==tp)
					tm2 += Toy[i].size;
			}
			long long tm = min(tm1,tm2);
			if(tm > ans)
				ans = tm;
		}
		cout << "Case #"<<TC<<": "<<ans<<endl;
	}
	return 0;
}
