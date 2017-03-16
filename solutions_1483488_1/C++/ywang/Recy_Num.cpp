#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;
/*
int getnd(int x)
{
	int r = 0;
	while(x)
	{
		++r;
		x/=10;
	}
	return r;
}
*/
int TEN[]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
int main()
{
	int T=50;
	scanf("%d",&T);
	int counter= 0 ;
	while(T--)
	{
		int count = 0;
		int A=1,B=2000000;
		scanf("%d",&A);
		scanf("%d",&B);
		///////////////////////////////////
		for(int d=1;d<7;++d)
		{
			int start = max(A,TEN[d]);
			int end = min(B,TEN[d+1]);
			int k = d+1;
			for(int i=start;i<end;++i)
			{
				set<int> r;
				for(int j=1;j<k;++j)
				{
					int n = i/TEN[j];
					n += TEN[k-j]*(i%TEN[j]);
					if(n<=B && n>=A && i<n)
					{
						r.insert(n);
					}
				}
				count += r.size();
			}
		}
		///////////////////////////////////
		/*
		for(int i=max(A,12);i<=B;++i)
		{
			int k = getnd(i);
			set<int> r;
			for(int j=1;j<k;++j)
			{
				int n = i/TEN[j];
				n += TEN[k-j]*(i%TEN[j]);
				if(n<=B && n>=A && i<n)
				{
					r.insert(n);
				}
			}
			count += r.size();
		}
		*/
		++counter;
		cout << "Case #"<<counter<<": ";
		cout <<count<<endl;
	}
}
