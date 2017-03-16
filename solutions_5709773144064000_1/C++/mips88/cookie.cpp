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

double C,F,X;
void read()
{
    fscanf(fin,"%lf %lf %lf",&C,&F,&X);

}
double crtTime;
double bestTime;
void solve()
{
    double timeStep = 1.0/2;
    double freq = 2.0;

    crtTime=0;
    int cntCookie = 0;
    bestTime = timeStep*X;
    do
    {
        crtTime+=1.0/freq * C;

        freq+=F;
        bestTime = min(bestTime,crtTime+X*1.0/freq);
        if (bestTime<crtTime) break;
    } while(true);
    //bestTime = min(bestTime,crtTime);
}

void write()
{
    fprintf(fout,"%.8lf",bestTime);
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
