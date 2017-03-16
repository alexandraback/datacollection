// GoogleJam_Problem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StringHelpers.h"
#include "windows.h"
 

vector<long long> ix;

char * g_hash = NULL; 
size_t g_hashSize = 500 * 1024 * 1024;

std::hash_map<unsigned int, short> g_h;

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

struct G
{
    long st;
    long sp;
    long num;
    int id;
};

struct H
{
    long st;
    long sp;
    int id;
    long double ft;
};


// ----------
// LARGE
//


long SolveLarge(vector<G> &vg)
{
    vector<H> vh;
    vector<long double> vff;

    for (int i = 0; i < vg.size(); ++i)
    {
        G &g = vg[i];
        for (int j = 0; j < g.num; ++j)
        {
            H h;
            h.id = vh.size();
            h.sp = g.sp + j;
            h.st = g.st;

            long d = 360 - h.st;
            long double t = ((long double)h.sp)/360*d;
            vff.push_back(t);
            h.ft = t;

            vh.push_back(h);
        }
    }

    sort(vff.begin(), vff.end());

    int n = vh.size();
    int res = n;
    for (int i = 0; i < n; ++i)
    {
        H& h = vh[i];
        auto it = upper_bound(vff.begin(), vff.end(), h.ft);
        long numi = vff.end() - it;

        long double t = h.ft;

        for (int j = 0; j < n; ++j)
        {
            H& h1 = vh[j];
            if (j == i)
                continue;
            if (h1.ft >= t)
                continue;
            int k = (t - h1.ft) / h1.sp;
            numi += k;
        }

        if (numi < res)
            res = numi;
    }

    return res;
}


//char g_om[20][100][20][20];
//char g_os[20][100][3];
//
//int g_numo[20] = { 0, 1, 2, 6, 100 };

/// ---------------
//  SMALL
///
void SolveSmall()
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

    Test();

    for(int t = 1; t <= numTests; ++t)
    {
        int n = atoi(l[c++].c_str());
        vector<G> vg;
        for (int i = 0; i < n; ++i)
        {
            vector<long long> p = splitLongInt(l[c++]);
            G g;
            g.id = i;
            g.st = p[0];
            g.num = p[1];
            g.sp = p[2];
            vg.push_back(g);
        }

        //vector<long long> res;
        long r = SolveLarge(vg);
        //SolveSmall(vp, res);

        //if(((long long)ix[1])*ix[2] <= 20 && ix[0] <= 4)
        //{
        //    int ress = SolveSmall();
        //    if(res != ress)
        //    {
        //        printf("Error: small != large\n");
        //    }
        //}
        
        //fprintf(fout, "Case #%d:\n", t);
        //for (int i = 0; i < n; ++i)
        //{
        //    fprintf(fout, "%d\n", res[i]);
        //}
        fprintf(fout, "Case #%d: %d\n", t, r);
    }

    fclose(fout);

    __int64 end = GetTickCount64();

    printf("Time = %.3f sec\n", ((double)(end - start))/1000);

    return 0;
}

