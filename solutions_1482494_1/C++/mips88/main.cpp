using namespace std;

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#define forNF(I,F,C) for(int32_t I=(F); I<int32_t(C); ++I)
#define forN(I,C) forNF(I,0,C)
#define vi vector<int>
#define pb push_back
#define sumMod(a,b) a=(a+b)%1000003
#define mulMod(a,b) a=(a*b)%1000003
#define toZero(a) forN(kk,sizeof(a)) ((char*)a)[kk]=0
//#define local

int aa[2000];
int bb[2000];
bool deza[2000];
bool dezb[2000];


double solve(int* a, int* b ,int n)
{
    int stars=0;
    int lvl=0;
    for(;;)
    {
        int taken=-1;
        forN(j,n)
        {
            if ((b[j]<=stars)&&(!dezb[j]))
            {
                dezb[j] = true;
                stars++;
                if (!deza[j])
                    stars++;
                deza[j] = true;
                taken = -2;
                lvl++;
                break;
            }
            else
            if ((a[j]<=stars)&&(!deza[j]))
            {
                if (taken!=-1)
                if (b[taken]>=b[j])
                continue;

                taken = j;

            }
        }
        if (taken == -2)
        continue;
        if (taken == -1)
        {
            if (stars==2*n)
                return lvl;
            else
                return -1;
        }
        else
        {
            deza[taken]=true;
            lvl++;
            stars++;
        }
    }
}
int main()
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    long long nrT;
    //string st;
    //cin >> st;
    cin >> nrT;

    forN(test,nrT)
    {
        memset(dezb,false,sizeof(dezb));
        memset(deza,false,sizeof(deza));
        cout << "Case #"<<test+1<<": ";

        int n,a,b;

        cin >> n;
        forN(i,n)
        {
            cin >> aa[i] >> bb[i];
        }

        int res = solve(aa,bb,n);

        if (res == -1)
            printf("Too Bad\n");
        else
            printf("%d\n",res);
    }
    return 0;
}
