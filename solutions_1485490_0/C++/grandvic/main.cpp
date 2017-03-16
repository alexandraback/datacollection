#include <iostream>
#include <vector>

#pragma comment(linker, "/STACK:16777216")

using namespace std;

vector<long long> a, b;
vector<int> A,B;
int N, M;

long long get(long long xa, int XA, long long xb, int XB, int a_next, int b_next)
{
	if(XB==XA)
	{
		long long res = min(xa, xb);
		xa-=res; xb-=res;

		if(xa==0)
		{
			if(a_next==N)
				return res;
			else
			{
				return res+get(a[a_next], A[a_next], xb, XB, a_next+1, b_next);
			}
		}

		if(xb==0)
		{
			if(b_next==M)
				return res;
			else
			{
				return res+get(xa, XA, b[b_next], B[b_next], a_next, b_next+1);
			}
		}
	}

	else
	{
		long long res1 = 0;
		if(a_next!=N)
			res1 = get(a[a_next], A[a_next], xb, XB, a_next+1, b_next);

		long long res2 = 0;
		if(b_next!=M)
			res2 = get(xa, XA, b[b_next], B[b_next], a_next, b_next+1);

		return max(res1, res2);
	}
}

int main()
{
//	freopen("k:/input.txt", "rt", stdin);

	int T;

	cin>>T;

	for(int t=1; t<=T; ++t)
	{
		cin>>N>>M;

		a.resize(N); A.resize(N);
		b.resize(M); B.resize(M);

		for(int i=0; i<N; ++i)
		{
			cin>>a[i]>>A[i];
		}

		for(int i=0; i<M; ++i)
		{
			cin>>b[i]>>B[i];
		}


		long long res = get(0, 0, 0, 0, 0, 0);

		cout<<"Case #"<<t<<": "<<res<<endl;
	}
	
	return 0;
}