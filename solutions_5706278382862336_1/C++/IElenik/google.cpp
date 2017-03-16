// google.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "algorithm"
#include "vector"
using namespace std;

FILE * in, * out;
int ri()
{
	int r;
	fscanf(in,"%d", &r);
	return r;
}

__int64 nod(__int64 p, __int64 q)
{
	while (p != 0)
	{
		q = q%p;
		swap(p, q);
	}
	return q;
}

int pt(__int64 q)
{
	int r = 0;
	while (q > 1) { r++; q /= 2; }
	return r;
}

int _tmain(int argc, _TCHAR* argv[])
{
	in = fopen("2.in", "rt");
	out = fopen("out.txt", "wt");
	int T = ri();

	for (int tc = 1; tc <= T; tc++)
	{
		__int64 p, q;
		fscanf(in,"%lld/%lld",&p,&q);
		__int64 n = nod(p,q);

		p /= n; q /= n;

		int pq = pt(q);
		fprintf(out, "Case #%d: ", tc);
		if (q != (((__int64)1) << pq))
			fprintf(out, "impossible\n");
		else if (p == q)
			fprintf(out, "1\n");
		else
			fprintf(out, "%d\n",pq-pt(p));

	}

	return 0;
}

