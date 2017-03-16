#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define FOR(i,n) for (int i = 0 ; i< n;i++)
#define FORI(i,s,e) for (int i = s ; i<= e;i++)
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define FZ(x) memset(x,0,sizeof(x))
using namespace std;
FILE* fin;
FILE* fout;
int nTESTS;

vector<double> Naomi;
vector<double> Ken;
int n;

/*
0.186 0.300 0.389 0.557 0.832 0.899 0.907 0.959 0.992
0.215 0.271 0.341 0.458 0.520 0.521 0.700 0.728 0.916

*/
void read()
{
    Naomi.clear();
    Ken.clear();
    fscanf(fin,"%d",&n);
    FOR(i,n)
    {
        double a;
        fscanf(fin,"%lf",&a);
        //cout << a << endl;
        Naomi.PB(a);
    }

    FOR(i,n)
    {
        double a;
        fscanf(fin,"%lf",&a);
        Ken.PB(a);
    }
}

int NaomiWAR;
int NaomiDWAR;
void solve()
{
    NaomiWAR=0;
    NaomiDWAR=0;
    sort(ALL(Naomi));
    sort(ALL(Ken));
    bool used[SZ(Naomi)];


    // WAR
    FZ(used);

    FOR(i,SZ(Naomi))
    {

        FOR(j,SZ(Ken))
        {
        if (!used[j])
            if (Naomi[i] < Ken[j])
                {
                    used[j] = true;
                    NaomiWAR--;
                    break;
                }
        }
        NaomiWAR++;
    }

    // DWAR
    FZ(used);

    FOR(i,SZ(Naomi))
    {
        double minim = 0;
        for (int j = SZ(Ken)-1;j>=0;j--)
            if (!used[j])
                minim = Ken[j];

        if (minim > Naomi[i])
        for (int j = SZ(Ken)-1;j>=0;j--)
        {
        if (!used[j])
            if (Naomi[i] < Ken[j])
                {
                    used[j] = true;
                    NaomiDWAR--;
                    break;
                }

        }
        else
        {
            for (int j = 0;j<SZ(Ken);j++)
            if (!used[j])
            {
                used[j] = true;
                break;
            }

        }
        NaomiDWAR++;
    }

}
void write()
{
    fprintf(fout,"%d %d",NaomiDWAR,NaomiWAR);
}



int main()
{
    fin = fopen("input.txt","r");
    fout = fopen("output.txt","w");

    fscanf(fin,"%d",&nTESTS);

    FOR(crtTest,nTESTS)
    {
        read();
        solve();
        fprintf(fout,"Case #%d: ",crtTest+1);
        write();
        fprintf(fout,"\n");
    }
    fclose(fout);

    return 0;
}
