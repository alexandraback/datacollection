// =========================================================
// 
//       Filename:  B.cpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  04/27/2012 06:45:53 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  LI YAN (lyan), lyan@cs.ucr.edu
//        Company:  U of California Riverside
//      Copyright:  Copyright (c) 04/27/2012, LI YAN
// 
// =========================================================

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;

typedef pair<int,int> pii;

const int MAX=100000;
int N;
pii vec1[2000], vec2[2000];

int calc(int p2, int mask, int cum, int score)
{
    if (p2>=N) return cum;
    if (score >= vec2[p2].first) { // play p2
        int d=2;
        int x=vec2[p2].second;
        if (!(1<<x & mask)) d=1;
        return calc(p2+1, ~(1<<x) & mask, cum+1, score+d);
    }
    else { // play p1
        int ans=MAX;
        for(int i=0; i<N; ++i) if (1<<vec1[i].second & mask) {
            if (score < vec1[i].first) continue;
            int curr = calc(p2, (~(1<<vec1[i].second) & mask), cum+1, score+1);
            ans = min(ans, curr);
        }
        return ans;
    }
}

void solve(int tcase)
{
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        int a, b; scanf("%d%d", &a, &b);
        vec1[i]=pii(a, i);
        vec2[i]=pii(b, i);
    }
    sort(vec1, vec1+N);
    sort(vec2, vec2+N);

    int ans = calc(0, (1<<N)-1, 0, 0);

    //printf("outloop %d %d %d %d\n", ans, curr, p2, N);
    if (ans < MAX) printf("Case #%d: %d\n", tcase, ans);
    else printf("Case #%d: Too Bad\n", tcase);
}

int main()
{
    int T; scanf("%d", &T);
    for(int t=1; t<=T; ++t) solve(t);
}
