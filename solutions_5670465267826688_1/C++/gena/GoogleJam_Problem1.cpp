// GoogleJam_Problem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StringHelpers.h"
#include "windows.h"

string i_l;
vector<long long> i_lx;

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

char g_s[9][5] = {
    { 1, -4, -1,  4,  1 },
    { 1, -3, -1,  3,  1 },
    { 1, -2, -1,  2,  1 },
    { 1, -1,  1, -1,  1 },
    { 0,  0,  0,  0,  0 },
    { 1,  1,  1,  1,  1 },
    { 1,  2, -1, -2,  1 },
    { 1,  3, -1, -3,  1 },
    { 1,  4, -1, -4,  1 },
};

int g_Min[9][9][9];

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
    long long nb = i_lx[1];
    //long long n = i_lx[0] * (long long)nb;

    // Calculate all pairs for chunk
    for (int i = 0; i < l; ++i)
    {
        char cur = 1;
        for (int k = i; k < l; ++k)
        {
            cur = Combine(cur, v[k%l]);
            g_hash[i*l + k] = cur;
        }
    }


    char rep = g_hash[l - 1];

    // Find suitable split
    //
    //   finding best for i end
    for (int i = 0; i < l; ++i)
    {
        char ipart2 = g_hash[0*l + i];
        int ireq = g_Min[4][rep + 4][ipart2 + 4];
        if (ireq == -10)
            continue;
        for (int j = 0; j < l; ++j)
        {
            char jpart1 = 1;
            if(i < l - 1)
                jpart1 = g_hash[(i + 1) * l + l - 1];
            char jpart2 = g_hash[0 * l + j];
            int jreq = g_Min[jpart1 + 4][rep + 4][jpart2 + 4];

            char kpart1 = 1;
            if(j < l - 1)
                kpart1 = g_hash[(j + 1)*l + l - 1];
            int kreq = g_Min[kpart1 + 4][rep + 4][4];
            if (kreq == -10)
                continue;

            int numused = 2;

            int retr = 0;
            while (true)
            {
                //
                if (jreq != -10)
                {
                    // now we have requirement of blocks
                    int minAddBlocks = ireq + jreq + kreq;
                    if (rep == 1)
                    {
                        res = 1;
                        return res;
                    }
                    else
                    {
                        int d = (rep == -1) ? 2 : 4;
                        if (numused + minAddBlocks <= nb)
                        {
                            if ((nb - numused - minAddBlocks) % d == 0)
                            {
                                res = 1;
                                return res;
                            }
                        }
                    }
                }

                if (retr == 0)
                {
                    // try one block for i and j
                    if (i >= j || g_hash[(i + 1)*l + j] != 3)
                        break;
                    jreq = 0;
                    numused = 1;
                    ++retr;
                }
                else
                    break;
            }
        }
    }


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

void Init()
{
    // Calculate min additional blocks
    for (int x = -4; x < 5; ++x)
    {
        for (char r = -4; r < 5; ++r)
        {
            if (r == 0)
                continue;
            for (char y = -4; y < 5; ++y)
            {
                int e = 3;
                int cx = x;
                int cy = y;
                if (x == 0)
                {
                    e = 2;
                    cx = 1;
                }
                if (y == 0)
                {
                    e = 4;
                    cy = 1;
                }

                int b = -10;
                // Debug
                //if (x == 1 && r == -4 && y == 0)
                //    x = x;
                for (int k = 0; k <= 3; ++k)
                {
                    int c1 = Combine(cx, g_s[r + 4][k]);
                    int c2 = Combine(c1, cy);

                    if (c2 == e)
                    {
                        b = k;
                        break;
                    }
                }
                g_Min[x + 4][r + 4][y + 4] = b;
            }
        }
    }

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
        i_lx = splitLongInt(l[c++]);
        const string& line = l[c++];

        i_l = line;

        int res = SolveLarge();
        //int res = SolveSmall();

        //if(((long long)i_lx[0])*i_lx[1] <= 10000ll)
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

