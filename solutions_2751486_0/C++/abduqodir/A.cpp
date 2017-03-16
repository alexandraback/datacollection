#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<map>
#include<algorithm>

#define pb push_back
#define mp make_pair
#define fr first
#define se second
#define sc scanf
#define pr printf

const double eps = 1e-12;
const double PI = 3.1415926535898;
const int alphabet = 256;
const int MN = 1000010;
const long long inf = (1LL<<60);

using namespace std;
struct pt{
    double x, y;
};
inline double sqr(double X){
    return (X*X);
}
inline double dist(pt a, pt b){
    return sqrt( sqr(a.x-b.x) + sqr(a.y-b.y) + eps);
}
inline double vector_m(pt a, pt b, pt c){
    return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}
inline double scalar_m(pt a, pt b, pt c){
    return (b.x-a.x)*(c.x-a.x) + (b.y-a.y)*(c.y-a.y);
}
pt IntersectionOfLines(double A1, double B1, double C1, double A2, double B2, double C2){
    double D = A2*B1 - A1*B2;
    pt ans;
    if(fabs(D)<eps){
        ans.x = -inf;
        ans.y = -inf;
    }
    else{
        ans.x = (C1*B2 - C2*B1)/D;
        ans.y = (A1*C2 - A2*C1)/D;
    }
    return ans;
}
inline bool intersect(double a, double b, double c, double d){
    if(a>b)swap(a, b);
    if(c>d)swap(c, d);
    return (max(a, c)-min(b, d))<eps;
}
inline bool cmp (pt a, pt b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

char s[MN];

bool vowel(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
int a[MN], r[MN], l[MN];

main(){
	freopen("input.txt", "r", stdin);	freopen("output.txt", "w", stdout);
	//freopen("paint.in", "r", stdin);	freopen("paint.out", "w", stdout);
    int T, n, len;
    sc("%d", &T);
    for(int k=1; k<=T; k++){
        pr("Case #%d: ", k);
        sc("%s%d", s, &n);
        len = strlen(s);
        //pr("%s %d\n", s, n);
        a[0] = !vowel(s[0]);
        for(int i=1; i<len; i++){
            if(!vowel(s[i])){
                a[i] = a[i-1]+1;
            }
            else {
                a[i] = 0;
            }
        }
        /*
        for(int i=0; i<len; i++){
            pr("%d ", a[i]);
        }
        pr("\n");
        */
        l[len] = 0;
        for(int i=len-1; i>=0; i--){
            if(a[i] == n){
                l[i] = i;
            }
            else {
                l[i] = l[i+1];
            }
        }
        /*
        for(int i=0; i<len; i++){
            pr("%d ", l[i]);
        }
        pr("\n");
        */
        if(!vowel(s[len-1])){
            r[ len-1 ] = len-1;
        }
        for(int i=len-2; i>=0; i--){
            if(!vowel(s[i])){
                if(!vowel(s[i+1])){
                    r[i] = r[i+1];
                }
                else {
                    r[i] = i;
                }
            }
        }
        /*
        for(int i=0; i<len; i++){
            pr("%d ", r[i]);
        }
        pr("\n");
        */
        long long ans = 0;
        for(int i=0; i<len; i++){
            if(!vowel(s[i])){
                if(r[i]-i+1>=n){
                    ans += len-(i+n-1);
                }
                else {
                    if(l[ r[i]+1 ] != 0){
                        ans += len-l[ r[i]+1 ];
                    }
                }
            }
            else {
                if(l[i] != 0){
                    ans += len-l[i];
                }
            }
        }
        pr("%lld\n", ans);
    }
	return 0;
}
