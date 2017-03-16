#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define PROB "A"

//string inPath = PROB "-large.in";
//string outPath = PROB "-large.out";

string inPath = PROB "-small-attempt0.in";
string outPath = PROB "-small-attempt0.out";

//string inPath = "input.txt";
//string outPath = "output.txt";

long long gcd(long long a, long long b) {
    if(a < b)
        swap(a, b);
    
    while(b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main(int argc, char** argv) {
    FILE * fin = fopen(inPath.c_str(), "r");
    FILE * fout = fopen(outPath.c_str(), "w");
    
    int tcases;
    fscanf(fin, "%d", &tcases);
    
    for(int tcase = 0; tcase < tcases; ++tcase) {
        printf("test %d...\n", tcase + 1);
        
        char s[30];
        fscanf(fin, "%s", s);
        
        int sp = 0;
        for(; s[sp] && s[sp] != '/'; ++sp);
        
        s[sp] = 0;
        long long p = atoll(s);
        long long q = atoll(s + sp + 1);

        long long g = gcd(p, q);
        p /= g;
        q /= g;
        
        printf("%lld %lld\n", p, q);
        
        bool f = 0;
        int k = 0;
        for(long long m = 1; ; m *= 2, ++k) {
            if(m == q)
                break;
            if(q % m) {
                f = 1;
                break;
            }
        }
        
        if(f) {
            fprintf(fout, "Case #%d: impossible\n", tcase+1);
            continue;
        }
        
        while(p % 2 == 0 && q % 2 == 0) {
            p /= 2;
            q /= 2;
            k--;
        }
        
        int l = 0;
        for(long long m = 1; m <= p; m *= 2, ++l);
        l--;
        
        printf("%d %d\n", l, k);
        
        int ans = k - l;
        if(ans == 0)
            ans = 1;
        
        fprintf(fout, "Case #%d: %d\n", tcase+1, ans);
        

        printf("OK\n");
    }
    
    return 0;
}

