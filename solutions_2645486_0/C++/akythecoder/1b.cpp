#include <iostream>
using namespace std;

int main()
{
	long long t;
	cin>>t;
	for (long long i1 = 1; i1 <= t; ++i1)
	{
		long long E,R,N;
		cin>>E>>R>>N;
		long long* v=new long long[N];
		for (long long i = 0; i < N; ++i)
		  cin>>v[i];
		long long** opt=new long long*[E+1];
		for (long long i = 0; i <= E; ++i)
			opt[i]=new long long[N];
		for (long long i = 0; i <= E; ++i)
		{
			opt[i][0]=i*v[0];
		}
		for (long long j = 1; j <N ; ++j)
		{
			for (long long i = 0; i <= E; ++i)
			{
				opt[i][j]=-1;
				for (long long k = 0; k <= i; ++k)
				{
					long long newe;
					if(i-k+R<=E)
					 newe=i-k+R;
					else
						newe=E;
					if(opt[i][j]<opt[newe][j-1]+k*v[j])
						opt[i][j]=opt[newe][j-1]+k*v[j];
				}
			}
		}
		long long max=-1;
		for (long long i = 0; i <= E; ++i)
		{
			if(max<opt[i][N-1])
				max=opt[i][N-1];
		}
		cout<<"Case #"<<i1<<": "<<max<<endl;
	}
}