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
		int L, X;
		string r;
		cin>>L>>X>>r;
		vector<int> a(L*X);
		for(int i=0;i<X;i++)
			for(int j=0;j<L;j++)
				a[i*L+j] = c2i(r[j]);
				 
		int N = L*X;
		bool ok = false;
		int A=1, B=1, C=1;
		int i=0;
		for(;i<N-2 && A!=2;i++) A = m(A, a[i]);
		for(;i<N-1 && B!=3;i++) B = m(B, a[i]);
		for(;i<N;i++) C = m(C, a[i]);
		ok = (A == 2 && B == 3 && C == 4);
		printf("Case #%d: %s\n", test_num, ok?"YES":"NO");	
	}
	
	return 0;
}
