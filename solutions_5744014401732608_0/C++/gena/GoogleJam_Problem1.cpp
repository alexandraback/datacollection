// GoogleJam_Problem1.cpp : Defines the entry point for the console application.
//

//#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

#include "stdafx.h"
#include "StringHelpers.h"
#include "windows.h"
#include <queue>
#include <xmmintrin.h>
 

//vector<long long> ix;

__declspec(thread) char * g_hash = NULL; 
size_t g_hashSize = 500 * 1024 * 1024;
vector<string> g_l;
volatile unsigned int g_lc = 0;
volatile unsigned int g_curOut = 1;
HANDLE g_ParametersParsedEvent = NULL;
FILE * g_fout = NULL;

//std::hash_map<unsigned long long, long long> g_h;

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
		return ((*(g_hash + t / 8)) & (1 << (t&0x7))) != 0;
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

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void SolveLarge(int J, int P, int S, int K, VI &vr)
{
	int vjp[1000];
	int vjs[1000];
	int vps[1000];

	memset(vjp, 0, sizeof(vjp));
	memset(vjs, 0, sizeof(vjs));
	memset(vps, 0, sizeof(vps));

	FOR(j, 0, J)
	{
		FOR(p, 0, P)
		{
			int jp = j * 100 + p * 10;

			FOR(s, 0, S)
			{
				int js = j * 100 + s;
				if (vjp[jp] == K)
					break;
				if (vjs[js] == K)
					continue;
				int ps = p * 10 + s;
				if (vps[ps] == K)
					continue;

				vr.push_back(jp + s);

				vjp[jp]++;
				vjs[js]++;
				vps[ps]++;
			}
		}
	}
}


void SolveSmall(const VS& vs, long long * pa, long long * pb)
{
}


void Test()
{
}

void Init()
{

}

/////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

VOID CALLBACK MyWorkCallback(PTP_CALLBACK_INSTANCE Instance, PVOID Parameter, PTP_WORK Work)
{
	if(g_hash == NULL)
		g_hash = (char *)VirtualAlloc((LPVOID)NULL, g_hashSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

	unsigned t = static_cast<unsigned>((unsigned long long)Parameter);

	//printf("Solving %d\n", (int)Parameter);

	// Parsing params
	//

	//string s = g_l[g_lc++];
	VLL v = splitLongInt(g_l[g_lc++]);
	long b = (long)v[0];
	LL m = v[1];

	SetEvent(g_ParametersParsedEvent);

	// Solving
	//

	//VI vr;
	//SolveLarge(v[0], v[1], v[2], v[3], vr);
	long long maxm = 1LL << (b - 2);
	long long r = 0;
	if (maxm >= m)
	{
		r = m;
	}

	while (g_curOut != t)
	{
		Sleep(100);
	}

	// Output results
	//

	//char buf[200];
	//sprintf(buf, "Case #%%d: %%0%dI64d %%0%dI64d\n", nn, nn);

	if (r == 0)
	{
		fprintf(g_fout, "Case #%d: IMPOSSIBLE\n", t);
	}
	else
	{
		fprintf(g_fout, "Case #%d: POSSIBLE\n", t);

		FOR(i, 0, b)
		{
			FOR(j, 0, b)
			{
				int w = 0;
				if (j > i)
				{
					if (j < b - 1 || i == 0)
					{
						w = 1;
					}
					else
					{
						if ((1LL << (i - 1)) & (r - 1))
						{
							w = 1;
						}
					}
				}
				fprintf(g_fout, "%d", w);
			}
			fprintf(g_fout, "\n");
		}
	}

	//printf("Solved %d\n", (int)Parameter);
	InterlockedIncrement(&g_curOut);
}

TP_CALLBACK_ENVIRON g_CallBackEnviron;
PTP_POOL g_pool = NULL;

DWORD CreateCustomThreadpool(unsigned int numThreads = 8)
{
	BOOL bRet = FALSE;
	PTP_WORK work = NULL;
	PTP_CLEANUP_GROUP cleanupgroup = NULL;

	InitializeThreadpoolEnvironment(&g_CallBackEnviron);

	// Create a custom, dedicated thread pool.
	g_pool = CreateThreadpool(NULL);

	if (NULL == g_pool) {
		_tprintf(_T("CreateThreadpool failed. LastError: %u\n"), GetLastError());
		return -1;
	}

	// The thread pool is made persistent simply by setting
	// both the minimum and maximum threads to 1.
	SetThreadpoolThreadMaximum(g_pool, numThreads);

	bRet = SetThreadpoolThreadMinimum(g_pool, numThreads);
	if (FALSE == bRet) {
		_tprintf(_T("SetThreadpoolThreadMinimum failed. LastError: %u\n"), GetLastError());
		return -1;
	}

	// Create a cleanup group for this thread pool.
	cleanupgroup = CreateThreadpoolCleanupGroup();
	if (NULL == cleanupgroup) {
		_tprintf(_T("CreateThreadpoolCleanupGroup failed. LastError: %u\n"),  GetLastError());
		return -1;
	}

	// Associate the callback environment with our thread pool.
	SetThreadpoolCallbackPool(&g_CallBackEnviron, g_pool);

	// Associate the cleanup group with our thread pool.
	// Objects created with the same callback environment
	// as the cleanup group become members of the cleanup group.
	SetThreadpoolCallbackCleanupGroup(&g_CallBackEnviron, cleanupgroup, NULL);

	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
    __int64 start = GetTickCount64();
	bool useMultipleThreads = false;

	g_ParametersParsedEvent = CreateEvent(NULL, FALSE, FALSE, NULL);

    char * outPath = "D:\\progs\\GoogleJam_Problem1\\out.txt";

    if(argc < 2)
    {
        printf("Error. Need in and out files\n");
        return -1;
    }

    if (argc >= 3)
    {
        outPath = argv[2];
    }

	if (argc >= 4)
	{
		if (_stricmp(argv[3], "multi") == 0)
		{
			useMultipleThreads = true;
		}
		else
		{
			useMultipleThreads = false;
		}
	}

    FILE * fin = NULL;

    g_fout = _fsopen(outPath, "w", _SH_DENYNO);
    if(g_fout == NULL)
    {
        printf("Can't open %s\n", outPath);
        return -1;
    }

    g_l = fileToLines(argv[1]);
    if (g_l.size() == 0)
    {
        printf("Can't open %s\n", argv[1]);
        return -1;
    }
    int numTests = atoi(g_l[g_lc++].c_str());

    Init();

	if(useMultipleThreads)
		CreateCustomThreadpool(8);
	// getPrimes((1ll << 19) - 1, g_primes, g_hash);

	Test();

	for(int t = 1; t <= numTests; ++t)
    {
		if (!useMultipleThreads)
		{
			MyWorkCallback(NULL, (void *)(unsigned long long)t, NULL);
		}
		else
		{
			// Create work with the callback environment.
			PTP_WORK work = CreateThreadpoolWork(MyWorkCallback, (PVOID)(unsigned long long)t, &g_CallBackEnviron);
			if (work == NULL) printf("ERROR: failed to create work item, 0x%x\n", GetLastError());
			SubmitThreadpoolWork(work);
			while(WaitForSingleObject(g_ParametersParsedEvent, INFINITE) != WAIT_OBJECT_0);
		}
    }

	while (g_curOut != numTests + 1)
	{
		Sleep(100);
	}

    fclose(g_fout);

    __int64 end = GetTickCount64();

    printf("Time = %.3f sec\n", ((double)(end - start))/1000);

    return 0;
}

