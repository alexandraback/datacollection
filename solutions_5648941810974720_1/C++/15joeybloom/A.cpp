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

int freq['Z'+1];
int counts[10];
string words[10];
char c[10];
int m[10];
int main()
{
    m[0] = 0;
    m[1] = 6;
    m[2] = 8;
    m[3] = 2;
    m[4] = 3;
    m[5] = 4;
    m[6] = 5;
    m[7] = 7;
    m[8] = 9;
    m[9] = 1;
    words[0] = "ZERO";
    words[1] = "SIX";
    words[2] = "EIGHT";
    words[3] = "TWO";
    words[4] = "THREE";
    words[5] = "FOUR";
    words[6] = "FIVE";
    words[7] = "SEVEN";
    words[8] = "NINE";
    words[9] = "ONE";
    c[0] = 'Z';
    c[1] = 'X';
    c[2] = 'G';
    c[3] = 'W';
    c[4] = 'T';
    c[5] = 'U';
    c[6] = 'F';
    c[7] = 'V';
    c[8] = 'I';
    c[9] = 'O';
    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++)
    {
        MEMSET(freq,0);
        MEMSET(counts,0);

        char in[2020];
        scanf("%s", in);
        int n = strlen(in);
        for(int i = 0; i < n; i++)
        {
            freq[in[i]]++;
        }

        for(int i = 0; i < 10; i++)
        {
            int x = freq[c[i]];
            for(int j = 0; j < words[i].size(); j++)
                freq[words[i][j]] -= x;
            counts[m[i]] = x;
        }

        printf("Case #%d: ", t);
        for(int i =0; i < 10; i ++)
        {
            for(int j = 0; j < counts[i]; j++)
                printf("%d", i);
        }
        printf("\n");
    }
}
