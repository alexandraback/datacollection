/*
 Petar 'PetarV' Velickovic
 Task: Dijkstra
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
#include <unordered_map>

#define MAX_N 10001

#define DPRINTC(C) printf(#C " = %c\n", (C))
#define DPRINTS(S) printf(#S " = %s\n", (S))
#define DPRINTD(D) printf(#D " = %d\n", (D))
#define DPRINTLLD(LLD) printf(#LLD " = %lld\n", (LLD))
#define DPRINTLF(LF) printf(#LF " = %.5lf\n", (LF))

using namespace std;
typedef long long lld;
typedef unsigned long long llu;

int t;
int l;
lld x;
string s;
int arr[MAX_N];

map<pair<int, int>, int> mul_table;

inline int abs1(int x)
{
    if (x < 0) return -x;
    return x;
}

inline int sgn(int a, int b)
{
    if (a < 0 && b < 0) return 1;
    if (a < 0 && b >= 0) return -1;
    if (a >= 0 && b < 0) return -1;
    return 1;
}

inline int mul(int a, int b)
{
    return sgn(a, b) * mul_table[make_pair(abs1(a), abs1(b))];
}

inline lld min1(lld a, lld b)
{
    if (a < b) return a;
    return b;
}

// 1 - 1, i - 2, j - 3, k - 4
// searching for: 2, 4, -1

int targets[3] = {2, 4, -1};
bool ok[3];

int main()
{
    freopen("/Users/PetarV/HackerCup/C-large.in.txt","r",stdin);
    freopen("/Users/PetarV/HackerCup/C-large-out.txt","w",stdout);
    
    mul_table[make_pair(1, 1)] = 1;
    mul_table[make_pair(1, 2)] = 2;
    mul_table[make_pair(1, 3)] = 3;
    mul_table[make_pair(1, 4)] = 4;
    
    mul_table[make_pair(2, 1)] = 2;
    mul_table[make_pair(2, 2)] = -1;
    mul_table[make_pair(2, 3)] = 4;
    mul_table[make_pair(2, 4)] = -3;
    
    mul_table[make_pair(3, 1)] = 3;
    mul_table[make_pair(3, 2)] = -4;
    mul_table[make_pair(3, 3)] = -1;
    mul_table[make_pair(3, 4)] = 2;
    
    mul_table[make_pair(4, 1)] = 4;
    mul_table[make_pair(4, 2)] = 3;
    mul_table[make_pair(4, 3)] = -2;
    mul_table[make_pair(4, 4)] = -1;
    
    scanf("%d", &t);
    
    for (int f=1;f<=t;f++)
    {
        scanf("%d%lld", &l, &x);
        
        cin >> s;
        
        for (int i=0;i<l;i++)
        {
            arr[i] = s[i] - 'i' + 2;
        }
            
        int curr = 1;
        int tar = 0;
        
        ok[0] = ok[1] = ok[2] = false;
        bool reps[4];
        
        for (int rpt=1;rpt<=8;rpt++)
        {
            if (rpt > x && tar != 2) break;
            for (int i=0;i<l;i++)
            {
                curr = mul(curr, arr[i]);
                //cout << curr << endl;
                if (curr == targets[tar] && tar != 2)
                {
                    ok[tar++] = true;
                }
            }
            if (tar == 2) reps[(rpt % 4)] = (curr == targets[2]);
        }
        
        printf("Case #%d: %s\n", f, (ok[0] && ok[1] && reps[(x % 4)]) ? "YES" : "NO");
    }
    
    return 0;
}
