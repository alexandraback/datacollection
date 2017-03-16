// GoogleJam_Problem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StringHelpers.h"
#include "windows.h"

string i_l;
VI i_lx;

char * g_hash = NULL; 
size_t g_hashSize = 200 * 1024 * 1024;

std::hash_map<unsigned int, short> g_h;

class Cmp
{
public:
    bool operator()(short l, short r)
    {
        return r < l;
    }
};

// 1 => 1
// 2 => i
// 3 => j
// 4 => k
char g_tr[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4},
    {0, 2, -1, 4, -3},
    {0, 3, -4, -1, 2},
    {0, 4, 3, -2, -1}
};

char Combine(char l, char n)
{
    char r = g_tr[abs(l)][abs(n)];
    if ((l^n) & 0x80)
        r *= -1;
    return r;
}

// ----------
// LARGE
//


int SolveLarge()
{
    int res = 0;


    return res;
}



/// ---------------
//  SMALL
///
int SolveSmall()
{
    memset(g_hash, 0, g_hashSize);
    int res = 0;
    char v[10000];
    for (int i = 0; i < i_l.size(); ++i)
    {
        char c = i_l[i];
        if (c == 'i')
            v[i] = 2;
        else if (c == 'j')
            v[i] = 3;
        else
            v[i] = 4;
    }

    int l = i_lx[0];
    int x = i_lx[1];
    int n = i_lx[0] * x;

    // Calculate all pairs
    for (int i = 0; i < n; ++i)
    {
        char cur = 1;
        for (int k = i; k < n; ++k)
        {
            cur = Combine(cur, v[k%l]);
            g_hash[i*n + k] = cur;
        }
    }

    // try to find good split
    for (int i = 0; i < n - 2; ++i)
    {
        if (g_hash[i] != 2)
            continue;
        for (int j = i + 1; j < n - 1; ++j)
        {
            if (g_hash[(i + 1)*n + j] == 3)
            {
                if (g_hash[(j + 1)*n + n - 1] == 4)
                {
                    //printf("%d %d\n", i, j);
                    res = 1;
                    break;
                }
            }
        }
    }

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

    g_hash = (char *)VirtualAlloc((LPVOID)NULL, g_hashSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    Test();

    for(int t = 1; t <= numTests; ++t)
    {
        i_lx = splitInt(l[c++]);
        const string& line = l[c++];

        i_l = line;

        //int res = SolveLarge();
        int res = SolveSmall();

        //if(i_lx[0]*i_lx[1] <= 10000)
        //{
        //    int ress = SolveSmall();
        //    if(res != ress)
        //    {
        //        printf("Error: small != large\n");
        //    }
        //}
        
        //fprintf(fout, "Case #%d: %d\n", t, res);
        fprintf(fout, "Case #%d: %s\n", t, res ? "YES" : "NO");
    }

    //fclose(fin);
    fclose(fout);

    __int64 end = GetTickCount64();

    printf("Time = %.3f sec\n", ((double)(end - start))/1000);

	return 0;
}

