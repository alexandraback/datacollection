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

int N;
int one[2000];
int two[2000];
int lookup[2000];
pii vec1[2000], vec2[2000];

void solve(int tcase)
{
    memset(one, 0, sizeof one);
    memset(two, 0, sizeof two);
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        int a, b; scanf("%d%d", &a, &b);
        vec1[i]=pii(a, i);
        vec2[i]=pii(b, i);
    }
    sort(vec1, vec1+N);
    sort(vec2, vec2+N);

    for(int i=0; i<N; ++i) lookup[vec2[i].second] = i;

    int p1, p2, curr, ans;
    p1=p2=0; curr=ans=0;

    while(p2<N) {
        if (curr >= vec2[p2].first) { // play two
            int x = vec2[p2].second;
            if (one[x]) curr++;
            else curr+=2;
            one[x]=two[x]=1;
            p2++; ans++;
        }
        else { // play one
            int id=-1;
            for(p1=0; p1<N; ++p1) 
            if (!one[vec1[p1].second] && curr>=vec1[p1].first) {
                int now=vec1[p1].second;
                if (id<0 || lookup[now] > lookup[vec1[id].second])
                    id=p1;
            }
            if (id<0) break;
            // play vec1[id]
            curr++; one[vec1[id].second]=1; ans++;
        }
    }
    //printf("outloop %d %d %d %d\n", ans, curr, p2, N);
    if (p2 >= N) printf("Case #%d: %d\n", tcase, ans);
    else printf("Case #%d: Too Bad\n", tcase);
}

int main()
{
    int T; scanf("%d", &T);
    for(int t=1; t<=T; ++t) solve(t);
}
