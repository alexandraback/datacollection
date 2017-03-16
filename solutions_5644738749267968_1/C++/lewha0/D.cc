#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int T;
vector<double> A, B;
vector<int> C;
int N;
int Ret1, Ret2;

int Go(int l1)
{
	int l2;

	int ret = 0;

	for( ; l1 < N; l1++)
	{
		for(l2 = 0; l2 < N; l2++)
		{
			if(C[l2] == 0 && B[l2] > A[l1]) break;
		}
		if(l2 == N)
		{
			for(l2 = 0; l2 < N; l2++) if(C[l2] == 0) break;
		}
		C[l2] = 1;
		if(A[l1] > B[l2]) ret++;
	}	
	return ret;
}

int main(void)
{
	int l0, l1, l2, l3;
	int temp;

	scanf("%d", &T);
	for(l0 = 1; l0 <= T; l0++)
	{
		scanf("%d", &N);
		A.resize(N); B.resize(N); C.resize(N);
		for(l1 = 0; l1 < N; l1++) scanf("%lf", &A[l1]);
		for(l1 = 0; l1 < N; l1++) scanf("%lf", &B[l1]);
		for(l1 = 0; l1 < N; l1++) C[l1] = 0;

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		Ret1 = Ret2 = Go(0);

		/*
		for(l1 = 1; l1 <= N; l1++)
		{
			for(l2 = 0; l2 < N; l2++) C[l2] = 0;
			for(l2 = 0; l2 < l1; l2++) C[N-l2-1] = 1;

			temp = 0;
			for(l2 = l1; l2 < N; l2++) if(A[l2] > B[l2-l1]) temp++;
			if(temp > Ret1) Ret1 = temp;

			temp = Go(l1);
			if(temp > Ret1) Ret1 = temp;
		}
		*/

		Ret1 = 0;
		for(l1 = 0; l1 < N; l1++) C[l1] = 0;
		for(l1 = 0; l1 < N; l1++)
		{
			for(l2 = 0; l2 < N; l2++) if(C[l2] == 0) l3 = l2;
			for(l2 = 0; l2 < N; l2++)
			{
				if(C[l2]) continue;
				if(A[l1] > B[l2]) l3 = l2;
			}
			C[l3] = 1;
			if(A[l1] > B[l3]) Ret1++;
		}

		printf("Case #%d: %d %d\n", l0, Ret1, Ret2);
	}

	return 0;
}
