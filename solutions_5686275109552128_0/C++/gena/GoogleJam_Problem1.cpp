// GoogleJam_Problem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StringHelpers.h"
#include "windows.h"

string i_l;

short * g_hash = NULL; 

std::hash_map<unsigned int, short> g_h;

class Cmp
{
public:
    bool operator()(short l, short r)
    {
        return r < l;
    }
};

int SolveR(short * v, int d)
{
    if (d == 0)
        return 0;

    unsigned id = 0;
    for (int i = 0; i < d; ++i)
    {
        id = id * 10 + v[i];
    }

    auto it = g_h.find(id);
    if (it != g_h.end())
        return it->second;
    
    short vcur[2000];
    memcpy(vcur, v, sizeof(v[0])*d);
    int best = INT_MAX;

    // Try no move step 
    int d1 = d;
    for (int i = 0; i < d1;)
    {
        if (vcur[i] > 1)
        {
            vcur[i]--;
            i++;
        }
        else
        {
            if (d1 > 0)
            {
                vcur[i] = vcur[d1 - 1];
                --d1;
            }
        }
    }

    if (d1 == 0)
    {
        g_h[id] = 1;
        return 1;
    }
    else
    {
        std::sort(vcur, vcur + d1, Cmp());
        best = SolveR(vcur, d1) + 1;
    }

    // Try to reduce larest one
    short m = v[0];
    for (short i = 1; i < m; ++i)
    {
        memcpy(vcur, v, sizeof(v[0])*d);
        vcur[0] = i;
        vcur[d] = m - i;
        std::sort(vcur, vcur + d + 1, Cmp());
        int r = SolveR(vcur, d + 1) + 1;
        if (r < best)
            best = r;
    }

    g_h[id] = best;

    return best;
}

// ----------
// LARGE
//

int SolveO(short * v, int d, int m)
{
    int res = 0;
    for (int i = 0; i < d; ++i)
    {
        int l = v[i];
        if (l > m)
        {
            int k = (l - 1) / m;
            res += k;
        }
    }

    return res;
}

int SolveLarge()
{
    int res = 0;

    VI vi = splitInt(i_l);
    int d = (int)vi.size();

    short v[2000];

    int vmax = 0;

    for (int i = 0; i < d; ++i)
    {
        v[i] = vi[i];
        if (vi[i] > vmax)
            vmax = vi[i];
    }

    res = vmax;
    for (int i = 1; i < vmax; ++i)
    {
        int r = SolveO(v, d, i);
        if (r + i < res)
            res = r + i;
    }

    return res;
}



/// ---------------
//  SMALL
///
int SolveSmall()
{
    //g_hash = (short *)VirtualAlloc((LPVOID)NULL, 2ull * 1024 * 1024 * 1024, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    //memset(g_hash, 0, 2000000000ull);

    VI d = splitInt(i_l);
    int n = (int)d.size();
    int res = 0;

    short v[2000];

    for (int i = 0; i < n; ++i)
    {
        v[i] = d[i];
    }

    std::sort(v, v + n, Cmp());
    res = SolveR(v, n);

    return res;
}


void Test()
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
    
    Test();


    for(int t = 1; t <= numTests; ++t)
    {
        int nd = atoi(l[c++].c_str());
        const string& line = l[c++];

        i_l = line;

        int res = SolveLarge();
        //int res = SolveSmall();

        if(nd <= 6)
        {
            int ress = SolveSmall();
            if(res != ress)
            {
                printf("Error: small != large\n");
            }
        }
        
        fprintf(fout, "Case #%d: %d\n", t, res);
    }

    //fclose(fin);
    fclose(fout);

    __int64 end = GetTickCount64();

    printf("Time = %.3f sec\n", ((double)(end - start))/1000);

	return 0;
}

