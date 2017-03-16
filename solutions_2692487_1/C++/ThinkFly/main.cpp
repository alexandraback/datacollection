#include <stdio.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
#include "assert.h"
#include <set>
#include <vector>
using namespace std;
#define MAX_SIZE 1000001
class mote
{
public:
    mote()
    {
        scanf("%d %d", &size, &n_mote);
        memset(m, 0, sizeof(m));
        for (int i=0; i<n_mote; i++)
        {
            int t;
            scanf("%d", &t);
            m[t] ++;
        }
    }
    int eat(int pos)
    {
        if (size <= 1)
        {
            return n_mote;
        }
        while (pos < MAX_SIZE && pos < size)
        {
            size += m[pos]*pos;
            n_mote -= m[pos];
            pos ++;
        }
        if (pos >= MAX_SIZE || n_mote <= 1)
        {
            return n_mote;
        }
        size += size - 1;
        int a = n_mote;
        return std::min(a, 1+eat(pos));
    }
    int n_mote;
    int size;
    static int m[MAX_SIZE];
};
int mote::m[MAX_SIZE];
int main(int argc, char**argv)
{
    freopen("D:\\1.in", "r+", stdin);
    freopen("D:\\1out.txt", "w+", stdout);
    int T;
    scanf("%d", &T);
    for (int i=1; i<=T; i++)
    {
        mote t;
        printf("Case #%d: %d\n", i, t.eat(0));
    }
    return 0;
}