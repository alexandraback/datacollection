/*
 Petar 'PetarV' Velickovic
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <time.h>
#define LIMIT 1000000
using namespace std;
typedef long long lld;
char buffer[LIMIT], * pos = buffer + LIMIT;

const int corr = 250;

int H[10001];
int memoOverlap[10001];

int t, n;
int di, ni, wi, ei, si, ddi, dpi, dsi;
//di - day of first attack
//ni - amount of attacks
//wi, ei - initial interval
//si - initial strength
//delta_di - days between attax
//delta_pi - shift of intervalZ
//delta_si - change in strength

struct Attack
{
    int L, R, str, t;
    Attack() {}
    Attack(int L, int R, int str, int t)
    {
        this -> L = L;
        this -> R = R;
        this -> str = str;
        this -> t = t;
    }
    bool operator <(const Attack &a) const
    {
        return (t < a.t);
    }
};

int main()
{
    freopen("/Users/PetarV/CodeJam/C-small-attempt1.in.txt","r",stdin);
    freopen("/Users/PetarV/CodeJam/C-e2.txt","w",stdout);
    scanf("%d",&t);
    for (int f=1;f<=t;f++)
    {
        for (int i=0;i<10000;i++)
        {
            memoOverlap[i] = H[i] = 0;
        }
        
        scanf("%d",&n);
        vector<Attack> attaX;
        for (int i=0;i<n;i++)
        {
            scanf("%d%d%d%d%d%d%d%d",&di,&ni,&wi,&ei,&si,&ddi,&dpi,&dsi);
            for (int j=0;j<ni;j++)
            {
                attaX.push_back(Attack(wi, ei, si, di));
                di += ddi;
                wi += dpi;
                ei += dpi;
                si += dsi;
            }
        }
        sort(attaX.begin(), attaX.end());
        int currT = 0;
        int sol = 0;
        for (int i=0;i<attaX.size();i++)
        {
            int L = attaX[i].L;
            int R = attaX[i].R;
            int S = attaX[i].str;
            
            //cout << "ATTACK!\n";
            //printf("L = %d, R = %d, S = %d, T = %d\n",L, R, S, attaX[i].t);
            
            L += corr;
            R += corr;
            
            if (attaX[i].t == currT)
            {
                bool breach = false;
                for (int j=L;j<R;j++)
                {
                    memoOverlap[j] = max(memoOverlap[j], S);
                    if (!breach && (S > H[j]))
                    {
                        sol++;
                        breach = true;
                    }
                }
                //if (breach) printf(" SUCCESS ! \n");
            }
            
            else
            {
                for (int j=0;j<10000;j++)
                {
                    H[j] = max(H[j], memoOverlap[j]);
                }
                bool breach = false;
                for (int j=L;j<R;j++)
                {
                    memoOverlap[j] = max(memoOverlap[j], S);
                    if (!breach && (S > H[j]))
                    {
                        sol++;
                        breach = true;
                    }
                }
                currT = attaX[i].t;
                //if (breach) printf(" SUCCESS ! \n");
            }
        }
        printf("Case #%d: %d\n",f, sol);
    }
    return 0;
}