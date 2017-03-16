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


double SolveLarge(int s, const string &ks, const string &ts)
{
    LL res = 0;
    int st[100];
    int pa[100];
    int ns = 0;

    for (int i = 1; i < ts.size(); ++i)
    {
        bool e = true;
        for (int j = 0; j < ts.size() - i; ++j)
        {
            if (ts[i] != ts[j])
            {
                e = false;
                break;
            }
        }
        if (e)
        {
            st[ns++] = i;
        }
    }

    st[ns++] = ts.size();

    memset(pa, 0, AS(pa));
    FOR(i, 0, ks.size())
    {
        pa[ks[i]]++;
    }

    FOR(i, 0, ts.size())
    {
        if (pa[ts[i]] == 0)
            return 0.0;
    }

    int l = ts.size();

    FOR(i, 0, s + 1)
        FOR(j, 0, s + 1)
    {
        g_a[i][j] = -1;
        g_p[i][j] = -1;
    }

    double av = 0;

    FOR(i, 0, s + 1)
        FOR(j, 0, l)
    {
        double a = 0;
        double p = 0;
        if ((i + j) <= l)
        {
            if (i + j == l)
            {
                p = 1;
                FOR(x, j, l)
                {
                    p *= pa[ts[x]] / ks.size();
                }
                a = p;
            }
        }
        else
        {
            double br = 1;
            FOR(x, j, l)
                br *= pa[ts[x]] / ks.size();
            double a1 = br*(g_a[i - (l - j)][0] + g_p[i - (l - j)][0]);
        }

        g_p[i][j] = p;
        g_a[i][j] = a;
    }

    int maxb = (s - l)/st[0] + 1;

    av = g_a[s][0];

    return maxb - av;
}



/// ---------------
//  SMALL
///

void Flip(string &s, int end)
{
	FOR(i, 0, (end + 1) / 2)
	{
		swap(s[i], s[end - i]);
	}

	FOR(i, 0, end + 1)
	{
		s[i] = (s[i] == '+') ? '-' : '+';
	}
}

bool Check(const string &s)
{
	FOR(i, 0, s.size())
	{
		if (s[i] != '+')
			return false;
	}

	return true;
}

long long SolveTest(const std::string &s, bool printRes)
{
	int t = 0;
	int m = 1;

	if (Check(s))
	{
		return 0;
	}

	int l = (s.size() + 1) / 2 + 1;
	int b = s.size();

	int rt = 0;

	long long r = l;

	FOR(i, 0, l)
	{
		m *= b;
	}

	for (; t < m; ++t)
	{
		string s1 = s;
		int t1 = t;
		FOR(i, 0, r)
		{
			int e = t1 % b;
			Flip(s1, e);
			if (Check(s1))
			{
				r = i + 1;
				rt = t;
				break;
			}

			t1 = t1 / b;
		}
	}

	if(printRes)
	{
		printf("resTEst: %d\n", r);
		printf("0: %s\n", s.c_str());
		string s1 = s;
		int t1 = rt;
		FOR(i, 0, r)
		{
			int e = t1 % b;
			Flip(s1, e);
			printf("%d: %s\n", i + 1, s1.c_str());

			t1 = t1 / b;
		}
	}

	return r;
}

long long SolveSmall(const std::string &s)
{
	long long r = 0;
	int cur = s.size() - 1;
	char need = '+';

	while (cur >= 0)
	{
		if (s[cur] == need)
		{
			cur--;
			continue;
		}

		r++;
		need = (need == '+') ? '-' : '+';
		cur--;
	}

	return r;
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

    Test();

    for(int t = 1; t <= numTests; ++t)
    {
        //int n = atoi(l[c++].c_str());
        //VI v = splitInt(l[c++].c_str());
		long long res = SolveSmall(l[c++]);
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
        
        //fprintf(fout, "Case #%d:\n", t);
        //for (int i = 0; i < n; ++i)
        //{
        //    fprintf(fout, "%d\n", res[i]);
        //}
        //fprintf(fout, "Case #%d: %1.7f\n", t, r);
		fprintf(fout, "Case #%d: %I64d\n", t, res);
    }

    fclose(fout);

    __int64 end = GetTickCount64();

    printf("Time = %.3f sec\n", ((double)(end - start))/1000);

    return 0;
}

