#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

struct quat
{
    int o,i,j,k;
};

quat ONE = {1,0,0,0}, NEG_ONE = {-1,0,0,0},
        I = {0,1,0,0}, J = {0,0,1,0}, K = {0,0,0,1};

quat mult(quat q1, quat q2)
{
    quat q;
    q.o = q1.o*q2.o - q1.i*q2.i - q1.j*q2.j - q1.k*q2.k;
    q.i = q1.o*q2.i + q1.i*q2.o + q1.j*q2.k - q1.k*q2.j;
    q.j = q1.o*q2.j + q1.j*q2.o + q1.k*q2.i - q1.i*q2.k;
    q.k = q1.o*q2.k + q1.k*q2.o + q1.i*q2.j - q1.j*q2.i;
    return q;
}

bool eq(quat q1, quat q2)
{
    return q1.o == q2.o && q1.i == q2.i && q1.j == q2.j && q1.k == q2.k;
}

quat toQuat(char c)
{
    switch (c)
    {
        case 'i':
            return I;
        case 'j':
            return J;
        case 'k':
            return K;
    }
}

int main()
{
    int T;
    cin >> T;
    for (int t=1; t<=T; t++)
    {
        ll l,x;
        cin >> l >> x;
        string s;
        cin >> s;
        
        quat prod = ONE;
        for (ll pos=0; pos<l; pos++)
        {
            prod = mult(prod, toQuat(s[pos]));
        }
        quat pprod = ONE;
        for (int i=0; i<x%4; i++)
        {
            pprod = mult(pprod, prod);
        }
        
        bool prodOk = eq(pprod, NEG_ONE), iOk = false, jOk = false;
        quat cur = ONE;
        if (prodOk)
        {
            for (ll pos=0; pos<min(8*l,x*l); pos++)
            {
                cur = mult(cur, toQuat(s[pos%l]));
                if (!iOk && eq(cur, I))
                {
                    iOk = true;
                    cur = ONE;
                }
                if (iOk && eq(cur, J))
                {
                    jOk = true;
                    break;
                }
            }
        }
        //cout << prodOk << iOk << jOk << endl;
        if (prodOk && iOk && jOk)
            printf("Case #%d: YES\n", t);
        else
            printf("Case #%d: NO\n", t);
    }
}
