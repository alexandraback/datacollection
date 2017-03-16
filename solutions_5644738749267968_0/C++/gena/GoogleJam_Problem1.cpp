// GoogleJam_Problem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"

const unsigned int c_MaxD = 1000;

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

struct Item
{
    int p;
    double w;
    bool used;

    void Reset()
    {
        p = 0;
        w = 0;
        used = false;
    }

    bool operator <(const Item& rhs)
    {
        return w > rhs.w;
    }

};

void Print(Item * v, long nb)
{
    for(int i = 0; i < nb; ++i)
    {
        printf("%d ", v[i].p);
    }
    printf("\n");
}

void Solve(Item *v, long nb, long * pDwar, long * pWar)
{
    int len = 2*nb;
    Item * vn = v;
    Item * vk = v + nb;
    // TODO: use global ordering instead of weight comparison

    std::sort(vn, vn + nb);
    std::sort(vk, vk + nb);

    // Get DWar score
    //

    int dwar = 0;

    {
        for(int s = 0; s < nb; ++s)
        {
            // find largest unused naoumi
            int curn = 0;
            for(; curn < nb; ++curn)
            {
                if(!vn[curn].used)
                {
                    break;
                }
            }

            // find largest unused ken
            int curk = 0;
            for(; curk < nb; ++curk)
            {
                if(!vk[curk].used)
                {
                    break;
                }
            }

            if(vn[curn].w > vk[curk].w)
            {
                // Find smallest unused ken
                int jk = nb - 1;
                while (true)
                {
                    if(!vk[jk].used)
                    {
                        break;
                    }
                    --jk;
                }

                double valk = vk[jk].w;
                // Find smallest unused naomi that is larger then smallest unused ken
                // TODO: do binary search
                int jn = nb - 1;
                while(true)
                {
                    if(!vn[jn].used && vn[jn].w > valk)
                    {
                        break;
                    }

                    --jn;
                }

                vn[jn].used = true;
                vk[jk].used = true;

                ++dwar;
            }
            else
            {
                // Find smallest unused naomi
                // TODO: do binary search
                int jn = nb - 1;
                while(true)
                {
                    if(!vn[jn].used)
                    {
                        break;
                    }

                    --jn;
                }

                vn[jn].used = true;
                vk[curk].used = true;
            }
        }
    }

    *pDwar = dwar;

    int war = 0;

    // Get War score
    //
    {
        // Show blocks starting from smallest
        // First go untill ken has something larger

        int curn = nb - 1;
        int curk = nb - 1;

        int lost = 0;

        for(int s = 0; s < nb; ++s)
        {
            double valn = vn[curn].w;
            int jk = curk;
            for(; jk >= 0; --jk)
            {
                if(vk[jk].w > valn)
                {
                    break;
                }
            }

            if(jk < 0)
            {
                break;
            }

            --curn;
            curk = jk - 1;
            ++lost;
        }

        war = nb - lost;
    }

    *pWar = war;
}

bool Test(Item *v, long nb)
{
    long dwar = -1;
    long war = -1;

    Solve(v, nb, &dwar, &war);
    printf("Input: \n");
    std::sort(v, v + nb*2);
    Print(v, nb*2);

    printf("Result: %d %d\n\n", dwar, war);

    return true;
}

void Test()
{
    {
        Item v1[10] = { {0, 0.01, 0}, {0, 0.02, 0}, {0, 0.03, 0}, {0, 0.04, 0}, {0, 0.05, 0},
                        {1, 0.11, 0}, {1, 0.12, 0}, {1, 0.13, 0}, {1, 0.14, 0}, {1, 0.15, 0} };

        Test(v1, sizeof(v1)/sizeof(v1[0])/2);
    }

    {
        Item v1[10] = { {0, 0.11, 0}, {0, 0.12, 0}, {0, 0.13, 0}, {0, 0.14, 0}, {0, 0.15, 0},
                        {1, 0.01, 0}, {1, 0.02, 0}, {1, 0.03, 0}, {1, 0.04, 0}, {1, 0.05, 0} };

        Test(v1, sizeof(v1)/sizeof(v1[0])/2);
    }

    {
        Item v1[10] = { {0, 0.01, 0}, {0, 0.02, 0}, {0, 0.03, 0}, {0, 0.04, 0}, {0, 0.05, 0},
                        {1, 0.015, 0}, {1, 0.025, 0}, {1, 0.035, 0}, {1, 0.045, 0}, {1, 0.055, 0} };

        Test(v1, sizeof(v1)/sizeof(v1[0])/2);
    }

    {
        Item v1[10] = { {0, 0.016, 0}, {0, 0.026, 0}, {0, 0.036, 0}, {0, 0.046, 0}, {0, 0.056, 0},
                        {1, 0.015, 0}, {1, 0.025, 0}, {1, 0.035, 0}, {1, 0.045, 0}, {1, 0.055, 0} };

        Test(v1, sizeof(v1)/sizeof(v1[0])/2);
    }
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

    char buf[10240];

    char * ps = fgets(buf, sizeof(buf), fin);
    int numTests = atoi(ps);
    
    //Testing
    //Test();

    Item v[2*c_MaxD];

    for(int t = 1; t <= numTests; ++t)
    {
        ps = fgets(buf, sizeof(buf), fin);
        long nb = atoi(ps);

        for(int p = 0; p < 2; ++p)
        {
            ps = fgets(buf, sizeof(buf), fin);
            char * ps1 = ps;
    
            for(int b = 0; b < nb; ++b)
            {
                ps1 = strtok(ps1, " ");
                double w = strtod(ps1, NULL);
                ps1 += strlen(ps1) + 1;

                v[p*nb + b].Reset();
                v[p*nb + b].p = p;
                v[p*nb + b].w = w;
            }
        }

        long dwar = 0;
        long war = 0;
        Solve(v, nb, &dwar, &war);
        fprintf(fout, "Case #%d: %d %d\n", t, dwar, war);
    }

    fclose(fin);
    fclose(fout);

    __int64 end = GetTickCount64();

    printf("Time = %d sec\n", (int)((end - start)/1000));

	return 0;
}

