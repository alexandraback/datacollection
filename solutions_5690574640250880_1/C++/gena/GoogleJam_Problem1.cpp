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


//
// LARGE 1 --------------
//
bool SolveLarge1(long r, long c, long m, char (*res)[c_MaxD])
{
    bool found = false;
    long total = r * c;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;

    if(m == 0 || r == 1 || c == 1 || m == r*c - 1 || (r <= 3 && c <= 3))
    {
        return Solve(r, c, m, res);
    }

    if(r == 2)
    {
        if(m&1 || m == total - 2)
        {
            return false;
        }
        else 
        {
            memset(res[0], '*', m/2);
            memset(res[0] + m/2, '.', c - m/2);
            memset(res[1], '*', m/2);
            memset(res[1] + m/2, '.', c - m/2);

            res[0][c-1] = 'c';
            return true;
        }
    }

    if(c == 2)
    {
        if(m&1 || m == total - 2)
        {
            return false;
        }
        else 
        {
            for(int i = 0; i < r - m/2; ++i)
            {
                res[i][0] = '.';
                res[i][1] = '.';
            }

            for(int i = r - m/2; i < r; ++i)
            {
                res[i][0] = '*';
                res[i][1] = '*';
            }

            res[0][c-1] = 'c';
            return true;
        }
    }

    int easym = (r-2)*(c-2);

    if(easym >= m)
    {
        ldiv_t ldivresult;
        ldivresult = ldiv (m, c - 2);

        int nr = ldivresult.quot;
        int left = ldivresult.rem;

        for(int i = r - 1; i >= r - nr; --i)
        {
            memset(res[i], '*', c - 2);
            memset(res[i] + c - 2, '.', 2);
        }

        if(left)
        {
            memset(res[r - nr - 1], '*', left);
            memset(res[r - nr - 1] + left, '.', c - left);
        }

        for(int i = 0; i < r - nr - (left ? 1 : 0); ++i)
        {
            memset(res[i], '.', c);
        }

        res[0][c-1] = 'c';
        return true;
    }

    long left = m - easym;
    if(left <= (c-3)*2 + (r-3)*2)
    {
        x1 = (std::min)(c-3, (left + 1)/2);
        y1 = 2;
        
        if(left&1)
        {
            x2 = c - 3;
            y2 = 3;
        }
        else
        {
            x2 = c -2;
            y2 = 2;
        }

        x3 = c - 2;
        y3 = r - (((left + 1)/2) - x1);
        found = true;
    }
    else
    {
        if(m == total - 4)
        {
            x1 = x2 = x3 = c -2;
            y1 = y2 = y3 = 2;
            found = true;
        }
        else if(m == total - 6)
        {
            x1 = x2 = x3 = c -2;
            y1 = y2 = y3 = 3;
            found = true;
        }
    }

    if(found)
    {
        for(int i = 0; i < y1; ++i)
        {
            memset(res[i], '*', x1);
            memset(res[i] + x1, '.', c - x1);
        }

        for(int i = y1; i < y2; ++i)
        {
            memset(res[i], '*', x2);
            memset(res[i] + x2, '.', c - x2);
        }

        for(int i = y2; i < y3; ++i)
        {
            memset(res[i], '*', x3);
            memset(res[i] + x3, '.', c - x3);
        }

        for(int i = y3; i < r; ++i)
        {
            memset(res[i], '*', c);
        }

        res[0][c - 1] = 'c';
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

bool Verify(long r, long c, long m, char (*res)[c_MaxD])
{
    // Find 'c' and count amount of m
    long mines = 0;
    int xc = -1;
    int yc = -1;

    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            if(res[i][j] == 'c')
            {
                yc = i;
                xc = j;
            }
            else if(res[i][j] == '*')
            {
                ++mines;
            }
        }
    }

    if(mines != m || xc < 0 || yc < 0)
    {
        return false;
    }

    vector<std::pair<int, int>> q;

    char p[c_MaxD][c_MaxD];
    memset(p, 'u', sizeof(p));

    q.push_back(make_pair(xc, yc));

    int d[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}};

    while(!q.empty())
    {
        pair<int, int> cur = q.back();
        q.pop_back();
        p[cur.second][cur.first] = 'o';
        
        bool isMineNear = false;
        for(int i = 0; i < 8; ++i)
        {
            int newx = cur.first + d[i][0];
            int newy = cur.second + d[i][1];
            if(newx < c && newx >= 0 && newy < r && newy >= 0)
            {
                if(res[newy][newx] == '*')
                {
                    isMineNear = true;
                    break;
                }
            }
        }

        if(!isMineNear)
        {
            for(int i = 0; i < 8; ++i)
            {
                int newx = cur.first + d[i][0];
                int newy = cur.second + d[i][1];
                if(newx < c && newx >= 0 && newy < r && newy >= 0)
                {
                    if(p[newy][newx] == 'u')
                    {
                        q.push_back(make_pair(newx, newy));
                    }
                }
            }
        }
    }

    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            if(res[i][j] == 'c')
            {
                if(p[i][j] != 'o')
                {
                    return false;
                }
            }
            else if(res[i][j] == '.')
            {
                if(p[i][j] != 'o')
                {
                    return false;
                }
            }
            else if(res[i][j] == '*')
            {
                if(p[i][j] != 'u')
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

void Test(long r, long c, long m, FILE * fout, bool print = true)
{
    char resSmall[c_MaxD][c_MaxD];
    char resLarge[c_MaxD][c_MaxD];

    bool foundLarge = SolveLarge1(r, c, m, resLarge);
    // bool foundSmall = Solve(r, c, m, resSmall);
    bool foundSmall = foundLarge;

    bool verify = true;
    if(foundLarge)
    {
        verify = Verify(r, c, m, resLarge);
    }

    if(foundLarge != foundSmall || !verify)
    {
        fprintf(fout, "Error: Input %u x %u, %u mines. %s, Small %s, but Large %s\n", 
            r, c, m, 
            verify ? "Verified" : "Incorrect", 
            foundSmall ? "found" : "not_found", 
            foundLarge ? "found" : "not_found");

        //fprintf(fout, "Input %u x %u, %u mines\n", r, c, m);
        if(foundSmall)
        {
            Print(r, c, resSmall, fout);
        }
        else
        {
            Print(r, c, resLarge, fout);
            //fprintf(fout, "Impossible\n");
        }

        fprintf(fout, "\n");
        //fflush(fout);

        SolveLarge1(r, c, m, resLarge);
    }
    else if(print)
    {
        fprintf(fout, "Input %u x %u, %u mines. %s\n", 
            r, c, m, foundLarge ? "found" : "not_found");

        if(foundLarge)
        {
            Print(r, c, resLarge, fout);
        }

        fprintf(fout, "\n");
        //fflush(fout);
    }
}

void Test(FILE * fout)
{
    Test(50, 50, 249, fout);

    Test(3, 2, 1, fout);
    Test(3, 2, 2, fout);
    Test(3, 2, 3, fout);
    Test(3, 2, 4, fout);
    Test(4, 2, 3, fout);
    Test(4, 2, 4, fout);

    Test(2, 3, 1, fout);
    Test(2, 3, 2, fout);
    Test(2, 3, 3, fout);
    Test(2, 3, 4, fout);
    Test(2, 4, 3, fout);
    Test(2, 4, 4, fout);
    
    Test(4, 5, 5, fout);

    Test(4, 6, 1, fout);
    Test(4, 6, 2, fout);
    Test(4, 6, 6, fout);
    Test(4, 6, 7, fout);
    Test(4, 6, 8, fout);
    Test(4, 6, 9, fout);
    Test(4, 6, 10, fout);
    Test(4, 6, 11, fout);
    Test(4, 6, 12, fout);
    Test(4, 6, 13, fout);
    Test(4, 6, 14, fout);
    Test(4, 6, 15, fout);
    Test(4, 6, 16, fout);
    Test(4, 6, 17, fout);
    Test(4, 6, 18, fout);
    Test(4, 6, 19, fout);
    Test(4, 6, 20, fout);
    Test(4, 6, 21, fout);
    Test(4, 6, 22, fout);
    Test(4, 6, 23, fout);

    for(int tr = 2; tr <= 11; ++tr)
    {
        for(int tc = 2; tc <= 11; ++tc)
        {
            for(int i = 0; i < tc*tr; ++i)
            {
                Test(tr, tc, i, fout, false);
            }
        }
    }

    Test(50, 50, 2401, fout, false);
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

    //Testing
    //Test(fout);


    for(int t = 1; t <= numTests; ++t)
    {
        ps = fgets(buf, sizeof(buf), fin);

        char * ps1 = strtok(ps, " ");
        long r = atoi(ps1);

        ps1 = strtok(ps1 + strlen(ps1) + 1, " ");
        long c = atoi(ps1);

        ps1 = strtok(ps1 + strlen(ps1) + 1, " ");
        long m = atoi(ps1);

        bool found = SolveLarge1(r, c, m, res);
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

