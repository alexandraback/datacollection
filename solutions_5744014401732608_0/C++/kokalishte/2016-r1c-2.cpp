//
//  main.cpp
//  codejam
//
//  Created by Todor Lyubomirov Bonchev on 1/1/16.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <limits>

using namespace std;

typedef unsigned long long ull;
//const ull BIG = 18446744073709551614ULL;

int b,m;
bool graph[6][6];

int countWaysCur(int curNode, int curLen, int totalLen) {
    if (curLen==totalLen && curNode == b-1) {
        return 1;
    } else if (curLen==totalLen) return 0;
    int res=0;
    for (int i=0;i<6;++i) {
        if (graph[curNode][i]) {
            res+=countWaysCur(i, curLen+1, totalLen);
        }
    }
    return res;
}

int countWaysLen(int len) {
    return countWaysCur(0, 0, len);
}

int countWays() {
    int res = 0;
    for (int i=1;i<b;++i) {
        res+= countWaysLen(i);
    }
    return res;
}

bool check(int i, int j) {
    if (i==b) {
        int ways = countWays();
        return ways==m;
    }
    if (j==b) {
        return check(i+1,i+2);
    }
    graph[i][j]=1;
    if (check(i,j+1)) return true;
    graph[i][j]=0;
    return check(i,j+1);
}

void solve() {
    cin>>b>>m;
    memset(graph,0,sizeof(graph));
    if (check(0,1)) {
        puts("POSSIBLE");
        for (int i=0;i<b;++i) {
            for (int j=0;j<b;++j) {
                if (i==j||j==0||i==b-1) putchar('0');
                else putchar(graph[i][j]+'0');
            }
            putchar('\n');
        }
    } else {
        puts("IMPOSSIBLE");
    }


    //putchar('\n');
}

int main(int argc, const char * argv[]) {
    freopen("/XCodeProjects/codejam/codejam/in.txt", "r", stdin);
    freopen("/XCodeProjects/codejam/codejam/out.txt", "w", stdout);

    int tests;
    scanf("%d", &tests);
    for (int test=1;test<=tests;++test) {
        printf("Case #%d: ", test);
        solve();
    }

    return 0;
}
