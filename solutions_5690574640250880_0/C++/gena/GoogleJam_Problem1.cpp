// GoogleJam_Problem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"

const unsigned int c_MaxD = 52;

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

void Transform(long r, long c, unsigned int v, char (*res)[c_MaxD])
{
    int len = c + r;
    int x = 0;
    int y = 0;

    memset(res, '.', c_MaxD*c_MaxD);
    res[0][c - 1] = 'c';

    for(int j = 0; j < len; ++j)
    {
        if(v&(1<<j))
        {
            // go down
            ++y;
            memset(res[y - 1], '*', x);
        }
        else
        {
            // go right
            ++x;
        }
    }
}

bool Solve(long r, long c, long m, char (*res)[c_MaxD])
{
    bool found = false;

    if(m == 0)
    {
        for(int i = 0; i < r; ++i)
        {
            memset(res[i], '.', c);
        }

        res[0][c - 1] = 'c';

        return true;
    }

    if(m == r*c - 1)
    {
        for(int i = 0; i < r; ++i)
        {
            memset(res[i], '*', c);
        }

        res[0][c - 1] = 'c';

        return true;
    }

    if(r == 1)
    {
        memset(res[0], '*', m);
        memset(res[0] + m, '.', c - m);
        res[0][c - 1] = 'c'; 
        
        return true;
    }

    if(c == 1)
    {
        for(int i = 0; i < m; ++i)
        {
            res[i][0] = '*';
        }

        for(int i = m; i < r; ++i)
        {
            res[i][0] = '.';
        }

        res[r - 1][0] = 'c';

        return true;
    }

    int len = c + r;
    unsigned int t = 1ul << len;
    unsigned int v = 0;

    for(; v < t; ++v)
    {
        int x = 0;
        int y = 0;
        int j = 0;
        int curm = 0;
        for(; j < len; ++j)
        {
            if(v&(1<<j))
            {
                // go down
                if(y == r)
                {
                    break;
                }

                if(x == c - 1)
                {
                    break;
                }
                ++y;

                curm += x;
            }
            else
            {
                // go right
                if(x == c)
                {
                    break; 
                }

                if(y == 1)
                {
                    break;
                }
                ++x;
            }

            if(curm + x*(r - y) > m)
            {
                break;
            }

            if(curm + c*(r - y) < m)
            {
                break;
            }
        }

        if(j == len && curm == m)
        {
            found = true;
            break;
        }
    }

    if(found)
    {
        Transform(r, c, v, res);
    }

    return found;
}


void Print(long r, long c, char (*res)[c_MaxD], FILE * fout)
{
    for(int i = 0; i < r; ++i)
    {
        res[i][c] = '\n';
        res[i][c+1] = 0;
        fputs(res[i], fout);
    }
}

void Test(long r, long c, long m, FILE * fout)
{
    char res[c_MaxD][c_MaxD];

    bool found = Solve(r, c, m, res);
    fprintf(fout, "Input %u x %u, %u mines\n", r, c, m);
    if(found)
    {
        Print(r, c, res, fout);
    }
    else
    {
        fprintf(fout, "Impossible\n");
    }

    fprintf(fout, "\n");
    fflush(fout);
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

    fin = _fsopen(argv[1], "rt", _SH_DENYNO);
    if(fin == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        return -1;
    }

    fout = _fsopen(argv[2], "w", _SH_DENYNO);
    if(fout == NULL)
    {
        printf("Can't open %s\n", argv[2]);
        return -1;
    }

    char buf[1024];

    char * ps = fgets(buf, sizeof(buf), fin);
    int numTests = atoi(ps);
    
    char res[c_MaxD][c_MaxD];

    // Testing
    // Test(3, 3, 0, fout);

    for(int t = 1; t <= numTests; ++t)
    {
        ps = fgets(buf, sizeof(buf), fin);

        char * ps1 = strtok(ps, " ");
        long r = atoi(ps1);

        ps1 = strtok(ps1 + strlen(ps1) + 1, " ");
        long c = atoi(ps1);

        ps1 = strtok(ps1 + strlen(ps1) + 1, " ");
        long m = atoi(ps1);

        bool found = Solve(r, c, m, res);
        fprintf(fout, "Case #%d:\n", t);
        if(found)
        {
            Print(r, c, res, fout);
        }
        else
        {
            fprintf(fout, "Impossible\n");
        }
    }

    fclose(fin);
    fclose(fout);

    __int64 end = GetTickCount64();

    printf("Time = %d sec\n", (int)((end - start)/1000));

	return 0;
}

