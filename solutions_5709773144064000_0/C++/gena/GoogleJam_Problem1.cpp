// GoogleJam_Problem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"


vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != (int)s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != (int)tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}


long double Solve(long double c, long double f, long double x)
{
    const long double prec = 0.0000005;
    
    long double curf = 2;
    long double best = x/curf; 
    long double curt = 0;

    while(true)
    {
        curt = curt + c/(curf);
        curf += f;
        long double t = curt + x/(curf);

        long double diff = best - t;
        if(diff < prec)
        {
            return best;
        }

        best = t;
    }

    return 0.0;
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

    fopen_s(&fin, argv[1], "rt");
    if(fin == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        return -1;
    }

    fopen_s(&fout, argv[2], "w");
    if(fout == NULL)
    {
        printf("Can't open %s\n", argv[2]);
        return -1;
    }

    //Solve(500, 4, 2000);

    char buf[1024];

    char * ps = fgets(buf, sizeof(buf), fin);
    int numTests = atoi(ps);

    for(int t = 1; t <= numTests; ++t)
    {
        ps = fgets(buf, sizeof(buf), fin);

        char * ps1 = strtok(ps, " ");
        long double c = strtod(ps1, NULL);

        ps1 = strtok(ps1 + strlen(ps1) + 1, " ");
        long double f = strtod(ps1, NULL);

        ps1 = strtok(ps1 + strlen(ps1) + 1, " ");
        long double x = strtod(ps1, NULL);

        long double res = Solve(c,f,x);
        fprintf(fout, "Case #%d: %.9f\n", t, (double)res);
    }

    fclose(fin);
    fclose(fout);

	return 0;
}

