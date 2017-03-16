/*
 * Author: lbs4570
 * Created Time:  2012/4/14 10:11:43
 * File Name: b.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <list>
#include <stack>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

const int maxn = 100 + 100;
int CS,n,p,s,total[maxn],a[maxn],ans;

void dfs(int k,int left){
    if (k == n){
        if (left == 0){
            int count = 0;
            //for (int i = 0; i < n; i++) out(a[i]);
            for (int i = 0; i < n; i++)
                if (a[i] >= p) count++;
            //out(count);
            if (ans < count) ans = count;
        }
        return;
    }
    if (left > 0){
        if (total[k] % 3 == 2) a[k] = total[k] / 3 + 2;
        else a[k] = total[k] / 3 + 1;
        if (a[k] >= 2) dfs(k + 1,left - 1);
    }
    if (total[k] % 3 == 0) a[k] = total[k] / 3;
    else a[k] = total[k] / 3 + 1;
    dfs(k + 1,left);
}

int main() {
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    scanf("%d",&CS);
    int cs = 0;
    while (CS--){
        scanf("%d%d%d",&n,&s,&p);
        for (int i = 0; i < n; i++) scanf("%d",&total[i]);
        memset(a,-1,sizeof(a));
        ans = 0;
        dfs(0,s);
        printf("Case #%d: %d\n",++cs,ans);
    }
    fclose(stdout);
    return 0;
}

