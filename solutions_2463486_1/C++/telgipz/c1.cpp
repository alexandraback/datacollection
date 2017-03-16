#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

vector<long long> fair;
vector<long long> sqf;
vector<long long> res;
vector<long long> fres;
long long from=0, to=20;

void gen_sqf(long long x) {
    for (long long i=1; i<=x; i++) {
        sqf.push_back(i*i);
    }
}

void gen3(long long x, int is_odd) {
    char buff[40];
    sprintf(buff, "%lld", x);
    char *a=buff+strlen(buff), *b;
    b=a-is_odd;
    while (b!=buff) {
        *a++=*--b;
    }
    *a='\0';
    fair.push_back(atoll(buff));
}

void gen2(long long lo, long long hi) {
    for (long long i=lo; i<=hi; i++) 
        gen3(i, 1);
    for (long long i=lo; i<=hi; i++)
        gen3(i, 0);
}

void gen_fair() {
    gen2(1, 9);
    gen2(10, 99);
    gen2(100, 999);
    gen2(1000, 9999);
    gen2(10000, 99999);
    gen2(100000, 999999);
    gen2(1000000, 9999999);
    //gen2(10000000, 99999999);
}

bool is_pal(long long i) {
    char buf[40];
    sprintf(buf, "%lld", i);
    char* a=buf, *b=buf+strlen(buf)-1;
    while (a<b) {
        if(*a++!=*b--) return false;
    }
    return true;
}

void merge(vector<long long>::iterator first1, vector<long long>::iterator last1,vector<long long>::iterator first2,vector<long long>::iterator last2) {
    while (first1!=last1 && first2!=last2) {
        if (*first1<*first2) ++first1;
        else if (*first2<*first1) ++first2;
        else {
            if (is_pal(sqrt(*first1))) {
                res.push_back(*first1);
            }
            ++first1; ++first2;
        }
    }
}



int main() {
    
    freopen("c1.in", "r", stdin);
    freopen("c1.out", "w", stdout);
    
    gen_sqf(sqrt((long long)1E14)+1);
    gen_fair();
    
    merge(sqf.begin(), sqf.end(), fair.begin(), fair.end());
    
    int t;
    scanf("%d", &t);
    for (int test=1; test<=t; test++) {
        long long  a,b;
        scanf("%lld %lld", &a, &b);
        int out=0;
        for (int i=0; i<res.size(); i++) {
            if (res[i]>=a && res[i]<=b) {
                out++;
            }
        }
        printf("Case #%d: %d\n", test, out);
    }
    
    /*
    // DEBUG (print all)
    for (int i=0; i<res.size(); i++) {
        printf("%lld\n", res[i]);
        if(res[i]>1E14) break;
    }
    
    printf("%d", res.size());
    */

    return 0;
}