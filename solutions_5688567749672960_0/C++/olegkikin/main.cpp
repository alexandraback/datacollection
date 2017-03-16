//#include "InfInt/InfInt.cpp"
#include <bits/stdc++.h>
/*#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>*/
#define MAX 10000 // for strings

using namespace std;
std::map <long, long> cache;

int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

long sortNum(long n) {
  long ret=0, temp, digit;
  for (digit=9; digit>=0; digit--) {
    //cout << digit << " ";

    for (temp=n;temp>0;temp/=10)
      if (temp%10==digit)
            ret = ret*10 + digit;
  }
    return ret;

}

long rev(long n) {
    long ret = 0;
    while (n > 0){
        ret = ret*10 + n%10;
        n /= 10;
    }
    return ret;
}

long minm(long n) {
    if (n < 15) return n;
    if (cache.find(n) != cache.end()) {
        return cache[n];
    }
    return -1;
}

/*long precalc(long n, long steps) {
    if (n>1000000) return 0;
    if (cache.find(n) != cache.end()) {
        if (steps < cache[n])
            cache[n] = steps;
        return cache[n];
    }
    cout << n << " -> " << steps << endl;
    cache[n] = steps;



    long r = rev(n);

    if (cache.find(r) == cache.end())
        precalc(r, steps + 1);

    if (cache.find(n + 1) == cache.end())
        precalc(n+1, steps+1);

}*/

long precalc() {
    long *cur = new long[10000];
    long *next = new long[10000];
    long curcnt = 1, nextcnt = 0, flag = 0, r;
    cur[0] = 1;
    long i, j, steps = 1;
    while (true) {
        for (i=0; i<curcnt; i++)
            if (cache.find(cur[i]) != cache.end())
                cache[cur[i]] = min(steps, cache[cur[i]]); else
                cache[cur[i]] = steps;

        nextcnt = 0;
        for (i=0; i<curcnt; i++) {
            if (cur[i] <= 1000000 && cache.find(cur[i] + 1) == cache.end())
                next[nextcnt++] = cur[i] + 1;
        }

        for (i=0; i<curcnt; i++) {
            r = rev(cur[i]);
            if (r > 1000000) continue;
            flag = 0;
            for (j=0; j<nextcnt; j++)
                if (r == next[j]) {
                    flag = 1;
                    break;
                }
            if (flag == 0 && cache.find(r) == cache.end())
                next[nextcnt++] = r;
        }

        if (nextcnt == 0) break;

        for (i=0; i<nextcnt; i++) {
            //cout << next[i] << " ";
            cur[i] = next[i];
        }
        curcnt = nextcnt;
        //cout << endl;




        steps++;
    }
}




long solve() {
    long n, i, cnt = 0, tmp;
    cin >> n;
    //cout << n;
    return cache[n];

/*    for (i=1; i<=n; i++) {
        //cout << i << endl;
        cnt++;
        tmp = rev(i);

        if (tmp < n && tmp > i + 1) {
            i = tmp-1;
        }

    }

    return cnt;*/
}

int main()
{
    precalc();
    //cout << rev(99989);
    //return 0;
    freopen("A-small-attempt4.in", "r", stdin);
    //freopen("A.in", "r", stdin);
    //freopen("B-small-attempt4.in", "r", stdin);
   	freopen("out7.txt", "w", stdout);
    int cases = 123;
    //scanf("%d", &cases);
    cin >> cases;
    //cout << "CASES " << cases << endl;
    for (int c=0; c < cases; c++) {
         cout << "Case #" << (c + 1) << ": " << solve() << endl;
//         return 0;
    }

    return 0;
}
