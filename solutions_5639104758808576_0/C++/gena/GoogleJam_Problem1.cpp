// GoogleJam_Problem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StringHelpers.h"
#include "windows.h"

string i_l;

// ----------
// LARGE
//
int SolveLarge()
{
    VS d = split(i_l);
    int smax = atoi(d[0].c_str());

    string v = d[1];

    int sum = v[0] - 0x30;
    int res = 0;
    for (int i = 1; i <= smax; ++i)
    {
        int k = v[i] - 0x30;
        if (k > 0 && i > sum)
        {
            int delta = i - sum;
            res += delta;
            sum += delta;
        }

        sum += k;
    }

    return res;
}



/// ---------------
//  SMALL
///
int SolveSmall()
{
    return 0;
}


void Test()
{
}

int _tmain(int argc, _TCHAR* argv[])
{
    __int64 start = GetTickCount64();
    if(argc < 3)
    {
        printf("Error. Need in and out files\n");
        return -1;
    }

    FILE * fin = NULL;
    FILE * fout = NULL;

    fout = _fsopen(argv[2], "w", _SH_DENYNO);
    if(fout == NULL)
    {
        printf("Can't open %s\n", argv[2]);
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
        const string& line = l[c++];

        i_l = line;

        int res = SolveLarge();

        //if(n < 22)
        //{
        //    int ress = SolveSmall();
        //    if(res != ress)
        //    {
        //        printf("Error: small != large\n");
        //    }
        //}
        
        fprintf(fout, "Case #%d: %d\n", t, res);
    }

    //fclose(fin);
    fclose(fout);

    __int64 end = GetTickCount64();

    printf("Time = %.3f sec\n", ((double)(end - start))/1000);

	return 0;
}

