// GoogleJam_Problem1.cpp : Defines the entry point for the console application.
//

//#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

#include "stdafx.h"
#include "StringHelpers.h"
#include "windows.h"
#include <queue>
 

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


// ----------
// LARGE
//


void SolveLarge(long long k, long long c, long long s, VLL &res)
{
	long long m = (k + c - 1) / c;
	if (m > s)
	{
		return;
	}

	int i = 0;
	for (; i < k - c + 1; i += c)
	{
		long long p = i;
		FOR(j, 1, c)
		{
			p = p * k + j + i;
		}

		p = p + 1;

		res.push_back(p);
	}

	if (i < k)
	{
		long long p = i;
		FOR(j, 1, k - i)
		{
			p = p * k + j + i;
		}

		FOR(j, k - i, c)
		{
			p = p * k;
		}

		p = p + 1;

		res.push_back(p);
	}
}


/// ---------------
//  SMALL
///

void getPrimes(VLL &vp, long long m, FILE * fout)
{
	long long l = (long long)(sqrt(m)) + 1;
	vp.reserve(l);
	vp.push_back(2);
	fprintf(fout, "2\n");

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
		}
	}

}

VLL g_primes;
long long g_maxp;

bool IsPrime(long long t)
{
	if (t < g_maxp)
	{
		// use array
	}
	else
	{
		// do loop for check
		for (unsigned int i = 0; i < g_primes.size(); ++i)
		{
			unsigned p = g_primes[i];
			if (t % p == 0)
				return false;
			if (p * (long long)p > t)
				return true;
		}

		return true;
	}
}

void SolveSmall(long long k, long long c, long long s, VLL &res)
{
	FOR(i, 0, k)
	{
		res.push_back(i + 1);
	}
	
	return;

	long long kk = 1;

	FOR(i, 0, c - 1)
	{
		kk *= k;
	}

	FOR(i, 0, k)
	{
		res.push_back(i * kk + 1);
	}
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

	//vp.reserve(10000);
	//getPrimes(vp, (1ll << 32) - 1, fout);


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

    Test();

    for(int t = 1; t <= numTests; ++t)
    {
        //int n = atoi(l[c++].c_str());
        VI v = splitInt(l[c++].c_str());

		VLL vr;
		//SolveSmall(v[0], v[1], v[2], vr);
		SolveLarge(v[0], v[1], v[2], vr);
		long long res = 0;
		//long long res = SolveSmall(vs, vi);
		//long long res1 = SolveTest(l[c - 1], false);
		//if(res != res1)
		//{
		//    printf("Error: small %I64u != large %I64u\n", res, res1);
		//	SolveTest(l[c - 1], true);
		//}

        //double r = SolveLarge(v[2], l[c++], l[c++]);
        //double r = SolveSmall(v[2], l[c++], l[c++]);

        //if(((long long)ix[1])*ix[2] <= 20 && ix[0] <= 4)
        //{
            //long long ress = SolveSmall(n);
            //if(r != ress)
            //{
            //    printf("Error: small != large\n");
            //}
        //}
        
		if (vr.size() > 0)
		{
			fprintf(fout, "Case #%d:", t);
			for (int i = 0; i < vr.size(); ++i)
			{
			    fprintf(fout, " %I64u", vr[i]);
			}
			fprintf(fout, "\n");
		}
		else
		{
			fprintf(fout, "Case #%d: IMPOSSIBLE\n", t);
		}

		//fprintf(fout, "Case #%d: %I64d\n", t, res);
    }

    fclose(fout);

    __int64 end = GetTickCount64();

    printf("Time = %.3f sec\n", ((double)(end - start))/1000);

    return 0;
}

