#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

int c2i(char x)
{
	if (x == 'i') return 2;
	if (x == 'j') return 3;
	if (x == 'k') return 4;
	return 100;
}

int mult[4][4] = {1, 2, 3, 4, 2, -1, 4, -3, 3, -4, -1, 2, 4, 3, -2, -1};

int m(int x, int y)
{
	int zn = 1;
	if (x < 0) {zn = -zn; x = -x; }
	if (y < 0) {zn = -zn; y = -y; }
	return zn*mult[x-1][y-1];
}

int main()
{
	int T;
	cin>>T;
	for(int test_num=1;test_num<=T;test_num++)
	{
		long long L, X;
		string r;
		cin>>L>>X>>r;
		int A=1, B=1, C=1;
		long long porno = 20;
		if (X <= porno)
		{
			int N = L*X;
			vector<int> a(N);
			for(int i=0;i<X;i++)
				for(int j=0;j<L;j++)
					a[i*L+j] = c2i(r[j]);
			int i=0;
			for(;i<N-2 && A!=2;i++) A = m(A, a[i]);
			for(;i<N-1 && B!=3;i++) B = m(B, a[i]);
			for(;i<N;i++) C = m(C, a[i]);
		}
		else
		{
			int N = L*porno;
			vector<int> a(N);
			for(int i=0;i<20;i++)
				for(int j=0;j<L;j++)
					a[i*L+j] = c2i(r[j]);
			int i=0;
			for(;i<N-2 && A!=2;i++) A = m(A, a[i]);
			for(;i<N-1 && B!=3;i++) B = m(B, a[i]);
			for(;i<N;i++) C = m(C, a[i]);
			X-=porno;
			vector<int> b(L);
			for(int j=0;j<L;j++)
				b[j] = c2i(r[j]);
			int D=1;	
			for(int j=0;j<L;j++) D = m(D, b[j]);
			if (D == -1)
			{
				if (X & 1) C = m(C, -1);
			}
			else if (D != 1)
			{
				if (X & 1) C = m(C, D);
				X>>=1;
				if (X & 1) C = m(C, -1);
			}	
		}
		bool ok = (A == 2 && B == 3 && C == 4);
		printf("Case #%d: %s\n", test_num, ok?"YES":"NO");	
	}
	
	return 0;
}
