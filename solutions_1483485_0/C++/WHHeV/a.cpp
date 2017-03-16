/*
 * Author: WHHeV
 * Created Time:  2012/4/14 16:12:16
 * File Name: a.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

char mat[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 
                'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    char c = getchar();
    for (int t = 1; t <= T; ++t) {
        char s[110];
        gets(s);
        printf("Case #%d: ", t);
        int len = strlen(s);
        //printf("%d", len);
        for (int i = 0; i < len; ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                printf("%c", mat[s[i] - 'a']);
            } else printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}

