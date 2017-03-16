#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int E,R;
int proc(int* V,int N,int r)
{
		if(N==0)return 0;
		int maxr=0;
		for(int i=0;i<=r;++i)
		{
				int t=V[0]*i + proc(V+1,N-1,min(E,r-i+R));
				if(t>maxr)maxr=t;
		}
		return maxr;
}
int N;
int main()
{
		int T;
		int* V=new int[100];
		int idx=0;
		cin >> T;
		while(T--)
		{
				++idx;
				cin >> E >> R >> N;
				for(int i=0;i<N;++i)
						cin >> V[i];
				cout << "Case #"<<idx<<": "<<proc(V,N,E)<<endl;
		}
		return 0;
}
