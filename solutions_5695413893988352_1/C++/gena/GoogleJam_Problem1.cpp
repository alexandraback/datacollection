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
void SolveLarge(const VS& vs, long long * pa, long long * pb, int k)
{
	long long a = *pa, b = *pb;
	int nn = vs[0].size();
	FOR(i, k, nn)
	{
		char ac = vs[0][i];
		char bc = vs[1][i];
		if (ac != '?')
		{
			if (bc != '?')
			{
				b = b * 10 + (bc - '0');
			}
			else
			{
				if (a > b)
				{
					b = b * 10 + 9;
				}
				else if (a == b)
				{
					int aci = (ac - '0');
					long long a1 = a*10 + aci;
					long long b1 = b*10 + aci;
					long long d1 = 1ll << 60;

					if (aci > 0)
					{
						long long a2 = a * 10 + aci;
						long long b2 = b * 10 + aci - 1;
						SolveLarge(vs, &a2, &b2, i + 1);
						long long d2 = _abs64(a2 - b2);
						if (d2 < d1)
						{
							a1 = a2;
							b1 = b2;
							d1 = d2;
						}
					}

					{
						long long a2 = a * 10 + aci;
						long long b2 = b * 10 + aci;
						SolveLarge(vs, &a2, &b2, i + 1);
						long long d2 = _abs64(a2 - b2);
						if (d2 < d1)
						{
							a1 = a2;
							b1 = b2;
							d1 = d2;
						}
					}
					
					if (aci < 9)
					{
						long long a2 = a * 10 + aci;
						long long b2 = b * 10 + aci + 1;
						SolveLarge(vs, &a2, &b2, i + 1);
						long long d2 = _abs64(a2 - b2);
						if (d2 < d1)
						{
							a1 = a2;
							b1 = b2;
							d1 = d2;
						}
					}

					*pa = a1;
					*pb = b1;
					return;
				}
				else
				{
					b = b * 10;
				}
			}
			a = a * 10 + (ac - '0');
		}
		else
		{
			if (bc != '?')
			{
				if (a > b)
				{
					a = a * 10;
				}
				else if (a == b)
				{
					//a = a * 10 + (bc - '0');
					int aci = (bc - '0');
					long long a1 = a * 10 + aci;
					long long b1 = b * 10 + aci;
					long long d1 = 1ll << 60;

					if (aci > 0)
					{
						long long a2 = a * 10 + aci - 1;
						long long b2 = b * 10 + aci;
						SolveLarge(vs, &a2, &b2, i + 1);
						long long d2 = _abs64(a2 - b2);
						if (d2 < d1)
						{
							a1 = a2;
							b1 = b2;
							d1 = d2;
						}
					}

					{
						long long a2 = a * 10 + aci;
						long long b2 = b * 10 + aci;
						SolveLarge(vs, &a2, &b2, i + 1);
						long long d2 = _abs64(a2 - b2);
						if (d2 < d1)
						{
							a1 = a2;
							b1 = b2;
							d1 = d2;
						}
					}

					if (aci < 9)
					{
						long long a2 = a * 10 + aci + 1;
						long long b2 = b * 10 + aci;
						SolveLarge(vs, &a2, &b2, i + 1);
						long long d2 = _abs64(a2 - b2);
						if (d2 < d1)
						{
							a1 = a2;
							b1 = b2;
							d1 = d2;
						}
					}

					*pa = a1;
					*pb = b1;
					return;
				}
				else
				{
					a = a * 10 + 9;
				}

				b = b * 10 + (bc - '0');
			}
			else
			{
				if (a > b)
				{
					a = a * 10;
					b = b * 10 + 9;
				}
				else if (a == b)
				{
					long long a1 = a * 10;
					long long b1 = b * 10;
					long long d1 = 1ll << 60;

					{
						long long a2 = a * 10;
						long long b2 = b * 10;
						SolveLarge(vs, &a2, &b2, i + 1);
						long long d2 = _abs64(a2 - b2);
						if (d2 < d1)
						{
							a1 = a2;
							b1 = b2;
							d1 = d2;
						}
					}

					{
						long long a2 = a * 10;
						long long b2 = b * 10 + 1;
						SolveLarge(vs, &a2, &b2, i + 1);
						long long d2 = _abs64(a2 - b2);
						if (d2 < d1)
						{
							a1 = a2;
							b1 = b2;
							d1 = d2;
						}
					}

					{
						long long a2 = a * 10 + 1;
						long long b2 = b * 10;
						SolveLarge(vs, &a2, &b2, i + 1);
						long long d2 = _abs64(a2 - b2);
						if (d2 < d1)
						{
							a1 = a2;
							b1 = b2;
							d1 = d2;
						}
					}

					*pa = a1;
					*pb = b1;
					return;
				}
				else
				{
					a = a * 10 + 9;
					b = b * 10;
				}
			}
		}
	}

	*pa = a;
	*pb = b;
}


bool MyMatch(long long v, const std::string & s)
{
	long long c = v;
	for(int i = s.size() - 1; i >= 0; --i)
	{
		long long t = c % 10;
		c = c / 10;
		if (s[i] == '?')
			continue;
		if (t != s[i] - '0')
			return false;
	}

	return true;
}

void SolveSmall(const VS& vs, long long * pa, long long * pb)
{
	int nn = (int)vs[0].size();
	long long p = 1;
	FOR(i, 0, nn)
	{
		p *= 10;
	}

	long long d = 1ll << 60;
	long long a = 0, b = 0;

	for (long long i = 0; i < p; ++i)
	{
		if (!MyMatch(i, vs[0]))
			continue;
		for (long long j = 0; j < p; ++j)
		{
			if (!MyMatch(j, vs[1]))
				continue;
			long long d1 = _abs64(i - j);
			if (d1 < d)
			{
				a = i;
				b = j;
				d = d1;
			}
		}

	}

	*pa = a;
	*pb = b;
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

	VS vs = split(g_l[g_lc++]);
	int nn = vs[0].size();
	long long a = 0, b = 0;
	long long d = b - a;
	int k = 0;
	for(; k<nn; ++k)
	{
		char ac = vs[0][k];
		char bc = vs[1][k];

		if (ac != '?' || bc != '?')
			break;
	}

	if (k == 0)
	{
		SolveLarge(vs, &a, &b, 0);
	}
	else
	{
		long long at1 = 0, bt1 = 0;
		SolveLarge(vs, &at1, &bt1, k);
		long long d = _abs64(at1 - bt1);
		a = at1;
		b = bt1;

		long long at2 = 0, bt2 = 1;
		SolveLarge(vs, &at2, &bt2, k);
		long long d2 = _abs64(at2 - bt2);
		if (d2 < d)
		{
			a = at2;
			b = bt2;
			d = d2;
		}

		long long at3 = 1, bt3 = 0;
		SolveLarge(vs, &at3, &bt3, k);
		long long d3 = _abs64(at3 - bt3);
		if (d3 < d)
		{
			a = at3;
			b = bt3;
		}


	}

	unsigned t = static_cast<unsigned>((unsigned long long)Parameter);

	//long long as, bs;
	//SolveSmall(vs, &as, &bs);
	//if (as != a || bs != b)
	//{
	//	printf("ERROR %d\n", t);
	//}

	SetEvent(g_ParametersParsedEvent);
	//double rr = SolveLarge(nn, m);

	while (g_curOut != t)
	{
		Sleep(100);
	}

	char buf[200];
	sprintf(buf, "Case #%%d: %%0%dI64d %%0%dI64d\n", nn, nn);

	fprintf(g_fout, buf, t, a, b);

	//std::sort(vr, vr + nn);
	//FOR(j, 0, nn)
	//{
	//	fprintf(fout, " %d", vr[j]);
	//}
	//fprintf(fout, "\n");
	
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

