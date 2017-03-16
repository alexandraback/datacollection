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

int nod(int p, int q)
{
	while (p != 0)
	{
		q = q%p;
		swap(p, q);
	}
	return q;
}

int pt(int q)
{
	int r = 0;
	while (q > 1) { r++; q /= 2; }
	return r;
}

int _tmain(int argc, _TCHAR* argv[])
{
	in = fopen("1.in", "rt");
	out = fopen("out.txt", "wt");
	int T = ri();

	for (int tc = 1; tc <= T; tc++)
	{
		int p, q;
		fscanf(in,"%d/%d",&p,&q);
		int n = nod(p,q);

		p /= n; q /= n;

		int pq = pt(q);
		fprintf(out, "Case #%d: ", tc);
		if (q != (1 << pq))
			fprintf(out, "impossible\n");
		else if (p == q)
			fprintf(out, "1\n");
		else
			fprintf(out, "%d\n",pq-pt(p));

	}

	return 0;
}

