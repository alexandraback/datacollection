/*
 Petar 'PetarV' Velickovic
 Task: Infinite House of Pancakes
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
#include <unordered_set>

#define MAX_N 100001

#define DPRINTC(C) printf(#C " = %c\n", (C))
#define DPRINTS(S) printf(#S " = %s\n", (S))
#define DPRINTD(D) printf(#D " = %d\n", (D))
#define DPRINTLLD(LLD) printf(#LLD " = %lld\n", (LLD))
#define DPRINTLF(LF) printf(#LF " = %.5lf\n", (LF))

using namespace std;
typedef long long lld;
typedef unsigned long long llu;

int t;
int d;
int p[MAX_N];
int sol[MAX_N];
int idd;

int bestSoln, currSoln;

int main()
{
    freopen("/Users/PetarV/HackerCup/B-small-attempt11.in.txt","r",stdin);
    freopen("/Users/PetarV/HackerCup/B-small-out11.txt","w",stdout);
    
    scanf("%d", &t);
    
    for (int f=1;f<=t;f++)
    {
        scanf("%d", &d);
        
        bestSoln = 0;
        
        for (int i=0;i<d;i++)
        {
            scanf("%d", &p[i]);
            if (p[i] > bestSoln) bestSoln = p[i];
        }
        
        for (int lim=1;lim<=bestSoln;lim++)
        {
            int currSoln = 0;
            for (int i=0;i<d;i++)
            {
                currSoln += (p[i] - 1) / lim;
            }
            if (currSoln + lim < bestSoln) bestSoln = currSoln + lim;
        }
        
        printf("Case #%d: %d\n", f, bestSoln);
    }
    
    return 0;
}
