#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
#include <iterator>
#include <list>
#include <set>
#include <map>
#include <bitset>

using namespace std;

#define MEMSET(x,v) memset(x,v,sizeof(x))
template<class A, class B> inline bool mina(A &x, B y) {return (x > y)?(x=y,1):0;}
template<class A, class B> inline bool maxa(A &x, B y) {return (x < y)?(x=y,1):0;}
typedef long long int LL;

char C[20], J[20];
int main()
{
    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++)
    {
        scanf("%s %s", C, J);

        int greater = 0;
        for(int i = 0; i < strlen(C); i++)
        {
            if(greater == 0)
            {
                if(C[i] == '?' && J[i] == '?')
                {
                    C[i] = J[i] = '0';
                }
                else if(C[i] == '?')
                {
                    C[i] = J[i];
                }
                else if(J[i] == '?')
                {
                    J[i] = C[i];
                }
                else
                {
                    greater = J[i]-C[i];
                }
            }
            else if(greater > 0)
            {
                if(C[i] == '?')
                    C[i] = '9';
                if(J[i] == '?')
                    J[i] = '0';
            }
            else
            {
                if(C[i] == '?')
                    C[i] = '0';
                if(J[i] == '?')
                    J[i] = '9';
            }
        }

        printf("Case #%d: %s %s\n", t, C, J);
    }
}
