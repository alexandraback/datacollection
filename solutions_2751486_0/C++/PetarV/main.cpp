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

int t, n;
char ch[1000001];
int currCons;

bool cons(char x)
{
    if (x == 'a') return false;
    if (x == 'e') return false;
    if (x == 'i') return false;
    if (x == 'o') return false;
    if (x == 'u') return false;
    return true;
}

int main()
{
    freopen("/Users/PetarV/CodeJam/A-small-attempt0.in copy.txt","r",stdin);
    freopen("/Users/PetarV/CodeJam/A-outt.txt","w",stdout);
    scanf("%d",&t);
    for (int f=1;f<=t;f++)
    {
        scanf("%s",&ch);
        int len = strlen(ch);
        scanf("%d",&n);
        currCons = 0;
        int sol = 0;
        bool been = false;
        int firstpoz = 0, lastpoz = len-1;
        for (int i=0;i<len;i++)
        {
            if (cons(ch[i])) currCons++;
            else currCons = 0;
            if (currCons >= n)
            {
                int curpoz = (i-(n-1));
                int left = curpoz - firstpoz + 1;
                int right = lastpoz - (curpoz + n - 1) + 1;
                sol += left * right;
                firstpoz = curpoz+1;
                //cout << "left = " << left << endl;
                //cout << "right = " << right << endl;
                //cout << "sol = " << sol << endl;
            }
        }
        printf("Case #%d: %d\n",f,sol);
    }
    return 0;
}
