/*
 * Author: lbs4570
 * Created Time:  2012/4/14 9:49:46
 * File Name: a.cpp
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
const char ch[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int CS;
char s[maxn],bk;
int main() {
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d%c",&CS,&bk);
    int cs = 0;
    while (CS--){
        gets(s);
        printf("Case #%d: ",++cs);
        int len = strlen(s);
        for (int i = 0; i < len; i++) 
            if (s[i] == ' ') printf(" ");
            else printf("%c",ch[s[i] - 'a']);
        printf("\n");
    }
    fclose(stdout);
    return 0;
}

