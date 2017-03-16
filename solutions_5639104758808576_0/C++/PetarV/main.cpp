/*
 Petar 'PetarV' Velickovic
 Task: Standing Ovation
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

#define MAX_N 1001

#define DPRINTC(C) printf(#C " = %c\n", (C))
#define DPRINTS(S) printf(#S " = %s\n", (S))
#define DPRINTD(D) printf(#D " = %d\n", (D))
#define DPRINTLLD(LLD) printf(#LLD " = %lld\n", (LLD))
#define DPRINTLF(LF) printf(#LF " = %.5lf\n", (LF))

using namespace std;
typedef long long lld;
typedef unsigned long long llu;

int t;
int n;
string s;
int arr[MAX_N];

int main()
{
    freopen("/Users/PetarV/HackerCup/A-small.in.txt","r",stdin);
    freopen("/Users/PetarV/HackerCup/A-small-out.txt","w",stdout);
    
    scanf("%d", &t);
    
    for (int f=1;f<=t;f++)
    {
        scanf("%d", &n);
        
        cin >> s;
        for (int i=0;i<=n;i++) arr[i] = s[i] - '0';
        
        int ret = 0;
        
        while (true)
        {
            bool ok = true;
            int cur = ret;
            for (int i=0;i<=n;i++)
            {
                if (cur < i)
                {
                    ok = false;
                    break;
                }
                cur += arr[i];
            }
            if (!ok) ret++;
            else break;
        }
        
        printf("Case #%d: %d\n", f, ret);
    }
    
    return 0;
}