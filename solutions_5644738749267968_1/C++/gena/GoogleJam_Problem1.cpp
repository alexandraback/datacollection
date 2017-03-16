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

    bool operator <(const Item& rhs) const
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

struct ItemR
{
    short int w;

    bool IsUsed() const
    {
        return w < 0;
    }

    void SetUsed()
    {
        w = -w;
    }

    void UnsetUsed()
    {
        w = -w;
    }

    bool operator <(const ItemR& rhs) const
    {
        return w > rhs.w;
    }

};


// ----------
// LARGE
//
void SolveLarge(Item *v, long nb, long * pDwar, long * pWar)
{
    int len = 2*nb;
    // Use global ordering instead of weight comparison

    ItemR vr[2 * c_MaxD];
    ItemR * vn = vr;
    ItemR * vk = vr + nb;
    
    std::sort(v, v + len);

    int dn = 0;
    int dk = 0; 
    for(int i = 0; i < len; ++i)
    {
        if(!v[i].p)
        {
            vn[dn++].w = len - (short)i;
        }
        else
        {
            vk[dk++].w = len - (short)i;
        }
    }

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
                if(!vn[curn].IsUsed())
                {
                    break;
                }
            }

            // find largest unused ken
            int curk = 0;
            for(; curk < nb; ++curk)
            {
                if(!vk[curk].IsUsed())
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
                    if(!vk[jk].IsUsed())
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
                    if(!vn[jn].IsUsed() && vn[jn].w > valk)
                    {
                        break;
                    }

                    --jn;
                }

                vn[jn].SetUsed();
                vk[jk].SetUsed();

                ++dwar;
            }
            else
            {
                // Find smallest unused naomi
                // TODO: do binary search
                int jn = nb - 1;
                while(true)
                {
                    if(!vn[jn].IsUsed())
                    {
                        break;
                    }

                    --jn;
                }

                vn[jn].SetUsed();
                vk[curk].SetUsed();
            }
        }
    }

    *pDwar = dwar;

    int war = 0;

    // Recover weights
    for(int i = 0; i < nb; ++i)
    {
        if(vn[i].IsUsed())
        {
            vn[i].UnsetUsed();
        }
        if(vk[i].IsUsed())
        {
            vk[i].UnsetUsed();
        }
    }

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
    long dwarSmall = -1;
    long warSmall = -1;
    long dwarLarge = -1;
    long warLarge = -1;

    Solve(v, nb, &dwarSmall, &warSmall);

    SolveLarge(v, nb, &dwarLarge, &warLarge);

    if(dwarSmall != dwarLarge || warSmall != warLarge)
    {
        printf("Error: Input: \n");
        std::sort(v, v + nb*2);
        Print(v, nb*2);

        printf("Result: %d (!= %d) %d (!= %d)\n\n", dwarLarge, dwarSmall, warLarge, warSmall);
        SolveLarge(v, nb, &dwarLarge, &warLarge);
    }

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

    // Case 1
    {
        Item v1[2] = { {0, 0.5, 0},
                       {1, 0.6, 0} };

        Test(v1, sizeof(v1)/sizeof(v1[0])/2);
    }

    // Case 2
    {
        Item v1[4] = { {0, 0.7, 0}, {0, 0.2, 0},
                       {1, 0.8, 0}, {1, 0.3, 0} };

        Test(v1, sizeof(v1)/sizeof(v1[0])/2);
    }

    // Case 3
    {
        Item v1[6] = { {0, 0.5, 0}, {0, 0.1, 0}, {0, 0.9, 0}, 
                       {1, 0.6, 0}, {1, 0.4, 0}, {1, 0.3, 0} };

        Test(v1, sizeof(v1)/sizeof(v1[0])/2);
    }

    // Case 3
    {
        unsigned int sr = GetTickCount();
        printf("Srand(%u)\n", sr);
        srand(sr);
        const int nb = 1000;
        Item v1[2 * nb];

        for(int p = 0; p < 2; ++p)
        {
            for(int i = 0; i < nb; ++i)
            {
                v1[p*nb + i].Reset();
                v1[p*nb + i].p = p;
                // not very good randomization
                v1[p*nb + i].w = ((double)rand()) * ((double)rand()) * ((double)rand()/17);
            }
        }

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
        SolveLarge(v, nb, &dwar, &war);
        fprintf(fout, "Case #%d: %d %d\n", t, dwar, war);
    }

    fclose(fin);
    fclose(fout);

    __int64 end = GetTickCount64();

    printf("Time = %d sec\n", (int)((end - start)/1000));

	return 0;
}

