// GoogleJam_Problem1.cpp : Defines the entry point for the console application.
//

//#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

#include "stdafx.h"
#include "StringHelpers.h"
#include "windows.h"
#include <queue>
#include <xmmintrin.h>
 

//vector<long long> ix;

char * g_hash = NULL; 
size_t g_hashSize = 500 * 1024 * 1024;

std::hash_map<unsigned long long, long long> g_h;

class Cmp
{
public:
    bool operator()(short l, short r)
    {
        return r < l;
    }
};

struct Point
{
    Point() : x(0), y(0), id(0)  {};
    Point(long long x1, long long y1, int id1) : x(x1), y(y1), id(id1)  {};

    long long x;
    long long y;
    int id;
};

double g_a[103][103];
double g_p[103][103]; 
//char g_os[20][100][3];
//
//int g_numo[20] = { 0, 1, 2, 6, 100 };




/// ---------------
//  SMALL
///

VLL g_primes;
long long g_maxp;

long long GetDivisor(long long t)
{
	long long mp = (long long)sqrt(t);

	for (unsigned int i = 0; i < g_primes.size(); ++i)
	{
		long long p = g_primes[i];
		if (t % p == 0)
			return p;
		if (p > mp)
			return 0;
	}

	return 0;
}


bool IsPrimeNew(long long t)
{
	if (t < g_maxp)
	{
		// use array
		return (*(g_hash + t / 8)) & (1 << (t&0x7));
	}
	else
	{
		long long d = GetDivisor(t);
		return d == 0;
	}
}


void getPrimes(long long m, VLL &vp, char * phash)
{
	memset(phash, 0, m / 8 + 1);

	long long l = (long long)(sqrt(m)) + 1;
	vp.reserve(l);
	vp.push_back(2);
	*(phash + 2 / 8) |= (1 << (2 & 0x7));

	for (long long i = 3; i <= m; i += 2)
	{
		unsigned int j = 0;
		bool good = true;
		for (; j < vp.size(); ++j)
		{
			long long p = vp[j];
			if (i % p == 0)
			{
				good = false;
				break;
			}

			if (p * (long long)p > i)
				break;
		}

		if (good)
		{
		    vp.push_back(i);
			*(phash + i/8) |= (1 << (i&0x7));
		}
	}

	g_maxp = m;
}

long long GetNumber(long long t, int base)
{
	long long p = t&0x1;
	long long b = base;

	long long t1 = t >> 1;
	while(t1)
	{
		if (t1 & 1)
		{
			p += b;
		}

		b *= base;
		t1 = t1 >> 1;
	}

	return p;
}


void SolveSmall(long long minn, long long maxn, int num, MLL &mr)
{
}

void SolveLarge(long long minn, long long maxn, int num, MLL &mr)
{
}


void Test()
{
}

void Init()
{

}

int _tmain(int argc, _TCHAR* argv[])
{
    __int64 start = GetTickCount64();

    char * outPath = "S:\\progs\\GoogleJam_Problem1\\out.txt";

    if(argc < 2)
    {
        printf("Error. Need in and out files\n");
        return -1;
    }

    if (argc >= 3)
    {
        outPath = argv[2];
    }

    FILE * fin = NULL;
    FILE * fout = NULL;

    fout = _fsopen(outPath, "w", _SH_DENYNO);
    if(fout == NULL)
    {
        printf("Can't open %s\n", outPath);
        return -1;
    }

    vector<string> l = fileToLines(argv[1]);
    int c = 0;
    if (l.size() == 0)
    {
        printf("Can't open %s\n", argv[1]);
        return -1;
    }
    int numTests = atoi(l[c++].c_str());

    g_hash = (char *)VirtualAlloc((LPVOID)NULL, g_hashSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    Init();



	// getPrimes((1ll << 19) - 1, g_primes, g_hash);

	Test();

	int vc[3001];

	VI vf;

	for(int t = 1; t <= numTests; ++t)
    {
		int nn = atoi(l[c++].c_str());
		VI v = splitInt(l[c++].c_str());

		int vl[1001][2];
		memset(vl, 0, sizeof(vl));

		int cn = 0;
		int rr = 0;

		int maxloop = 0;
	

		for(; cn < nn; ++cn)
		{
			memset(vc, 0, sizeof(vc));
			int e = cn;
			vf.clear();


			int cc = e;

			while (true)
			{
				if (vc[cc] > 0)
					break;
				vc[cc] = vf.size() + 1;
				vf.push_back(cc);
				cc = v[cc] - 1;
			}

			int l = vf.size();
			if (cc == vf[l - 2])
			{
				// length of loop at the end is 2
				int mine = min(vf[l - 1], vf[l - 2]);
				int id = (mine == vf[l - 1]) ? 0 : 1;
				if (l > vl[mine][id])
				{
					vl[mine][id] = l;
				}
			}
			else
			{
				// length of loop at the end > 2
				int len = l - vc[cc] + 1;
				if (maxloop < len)
					maxloop = len;
			}
		}

		int suml = 0;
		FOR(j, 0, 1000)
		{
			if (vl[j][0] > 0)
			{
				suml += vl[j][0] + vl[j][1] - 2;
			}
		}

		rr = max(suml, maxloop);

		fprintf(fout, "Case #%d: %d\n", t, rr);
		//std::sort(vr, vr + nn);
		//FOR(j, 0, nn)
		//{
		//	fprintf(fout, " %d", vr[j]);
		//}
		//fprintf(fout, "\n");
    }

    fclose(fout);

    __int64 end = GetTickCount64();

    printf("Time = %.3f sec\n", ((double)(end - start))/1000);

    return 0;
}

