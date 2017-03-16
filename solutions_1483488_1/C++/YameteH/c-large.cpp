/*
 * Author: lbs4570
 * Created Time:  2012/4/14 13:30:17
 * File Name: c.cpp
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

int CS,A,B,ans,a[5],b[5];

void divide(int a[],int n){
    memset(a,0,sizeof(a));
    while (n > 0){
        a[0]++;
        a[a[0]] = n % 10;
        n = n / 10;
    }
}
bool check(int n, int m){
    bool va[5],vb[5];
    divide(a,n); divide(b,m);
    //for (int i = a[0]; i >= 1; i--) printf("%d",a[i]);
    //printf("\n");
    if (a[0] != b[0]) return false;
    memset(va,0,sizeof(va));
    memset(vb,0,sizeof(vb));
    int cnt = 0;
    for (int i = 1; i <= a[0]; i++)
        for (int j = 1; j <= b[0]; j++)
            if (!va[i] && !vb[j] && a[i] == b[j]){
                va[i] = true; vb[j] = true; cnt++;
            }
    if (cnt != a[0]) return false;
    int i = 1, j = 2;
    while (i <= a[0] && a[i] == b[j]){
        i++; j++;
        if (j > b[0]) j = 1;
    }
    if (i > a[0]) return true;
    if (b[0] == 3){
        i = 1; j = 3;
        while (i <= a[0] && a[i] == b[j]){
            i++; j++;
            if (j > b[0]) j = 1;
        }
        if (i > a[0]) return true;
    }
}
void calc(int n){
    int a[10],b[10],exist[10];
    divide(a,n);
    b[0] = a[0];
    int i,j;
    i = a[0];
    memset(exist,0,sizeof(exist));
    for (int k = 1; k < a[0]; k++){
        i = i - 1; j = b[0];
        while (j > 0){
            b[j] = a[i];
            i--; j--;
            if (i == 0) i = a[0];
        }
        if (b[b[0]] == 0) continue;
        int m = 0;
        for (int q = b[0]; q > 0; q--) m = m * 10 + b[q];
        if (m > n && m <= B) {
            bool flag = true;
            for (int i = 1; i <= exist[0]; i++)
                if (exist[i] == m) {
                    flag = false;
                    break;
                }
            if (flag){
                ans++;
                exist[++exist[0]] = m;
            }
            //if (n >= 1111) printf("%d %d\n",n,m);
        }
    }
}

int main() {
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    scanf("%d",&CS);
    int cs = 0;
    while (CS--){
        scanf("%d%d",&A,&B);
        ans = 0;
        for (int i = A; i < B; i++) calc(i);
        printf("Case #%d: %d\n",++cs,ans);
    }
    fclose(stdout);
    return 0;
}

