#include <tchar.h>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
typedef unsigned uint;
typedef unsigned __int64 uint64;


vector<uint> M;
uint A, N;


uint64 div1(uint64 a, uint64 b)
{
	return (a%b) ? (a/b) : ((a/b)+1);
}

uint64 bit_count(uint64 a)
{
	uint cnt = 0;
	for(; a!=0; )
	{
		a >>= 1;
		cnt++;
	}
	return cnt;
}

uint solve_truncated(uint count)
{
	uint cnt = 0;
	uint64 T = A;
	uint64 tmp;
	for(uint i=0; i<count; i++)
	{
		while(T <= M[i])
		{
			T = 2*T - 1;
			cnt++;
		}
		T += M[i];
		/*
		tmp = div1(M[i]-1, T-1);
		tmp = bit_count(tmp);
		cnt += tmp;
		T = (T-1)*(((uint64)1) << tmp) + 1;
		*/
	}
	return cnt;
}

uint solve()
{
	uint best = 0xFFFFFFFF;
	
	if(A==1) return N;

	sort(M.begin(), M.end());

	for(uint count = 0; count <= N; count++)
	{
		uint cur = (N-count) + solve_truncated(count);
		if(cur < best) best = cur;
	}
	return best;
}

int _tmain(int argc, _TCHAR* argv[])
{
	uint cTask, iTask;
	uint ret, ret1;

	FILE* fin  = fopen("task.in", "rt");
	FILE* fout = fopen("task.out", "wt");

	fscanf(fin, "%u", &cTask);
	for(iTask=1; iTask<=cTask; iTask++)
	{
		fscanf(fin, "%u %u", &A, &N);
		M.resize(N);
		for(uint i=0; i<N; i++)
			fscanf(fin, "%u", &M[i]);
		ret = solve();
		fprintf(fout, "Case #%u: %u\n", iTask, ret);
	}
	fclose(fin);
	fclose(fout);
	printf("done\n");
	getch();
}
