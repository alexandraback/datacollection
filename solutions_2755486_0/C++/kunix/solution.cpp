#include <windows.h>
#include <tchar.h>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
typedef unsigned uint;
typedef unsigned __int64 uint64;
typedef __int64 int64;
#define BRK {__asm int 3}

struct TRIBE
{
	int64 d, n, w, e, s, delta_d, delta_p, delta_s;
};
typedef vector<TRIBE> TRIBES;

struct ATTACK
{
	int64 w, e, d, s;
	int64 tribe;
};
typedef vector<ATTACK*> ATTACKS;

struct ATTACK_SORT
{
	bool operator()(const ATTACK* a, const ATTACK * b)
	{
		return a->d < b->d;
	}
};

int64 N, i, j, k;
TRIBES tribes;
ATTACKS attacks;
map<int64, int64> wall;

int64 solve()
{
	wall.clear();
	attacks.clear();

	int64 cAttacks = 0;
	for(i=0; i<N; i++)
		cAttacks += tribes[i].n;
	attacks.reserve(cAttacks);
	for(i=0; i<N; i++)
	{
		TRIBE & t = tribes[i];
		int64 d = t.d;
		int64 s = t.s;
		int64 w = t.w;
		int64 e = t.e;
		ATTACK * a = 0;
		for(j=0; j<t.n; j++)
		{
			a = new ATTACK();
			a->d = d;
			a->s = s;
			a->w = w;
			a->e = e;
			a->tribe = i;
			attacks.push_back(a);
			d += t.delta_d;
			s += t.delta_s;
			w += t.delta_p;
			e += t.delta_p;
		}
	}

	std::sort(attacks.begin(), attacks.end(), ATTACK_SORT());

	int64 succ = 0;
	for(i=0; i<cAttacks; i=j)
	{
		for(j=i+1; j<cAttacks && attacks[i]->d==attacks[j]->d; j++);

		for(k=i; k<j; k++)
		{
			ATTACK & atk = *attacks[k];
			for(int64 pos=atk.w; pos<atk.e; pos++)
			{
				if(wall[pos] < atk.s)
				{
					succ++;
					break;
				}
			}
		}

		for(k=i; k<j; k++)
		{
			ATTACK & atk = *attacks[k];
			for(int64 pos=atk.w; pos<atk.e; pos++)
			{
				wall[pos] = max(wall[pos], atk.s);
			}
		}
	}

	
	for(i=0; i<cAttacks; i++)
		delete attacks[i];
	return succ;
}

int _tmain(int argc, _TCHAR* argv[])
{
	uint cTask, iTask;

	FILE* fin  = fopen("task.in", "rt");
	FILE* fout = fopen("task.out", "wt");

	fscanf(fin, "%u", &cTask);
	for(iTask=1; iTask<=cTask; iTask++)
	{
		fscanf(fin, "%I64d", &N);
		tribes.clear();
		tribes.resize(N);
		for(i=0; i<N; i++)
		{
			TRIBE* p = &tribes[i];
			fscanf(fin, "%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d", 
				&p->d, &p->n, &p->w, &p->e, &p->s, &p->delta_d, &p->delta_p, &p->delta_s);
		}
		int64 ret = solve();
		fprintf(fout, "Case #%u: %I64d\n", iTask, ret);
	}
	fclose(fin);
	fclose(fout);
	printf("done\n");
	getch();
	TerminateProcess(GetCurrentProcess(), 0);
}
