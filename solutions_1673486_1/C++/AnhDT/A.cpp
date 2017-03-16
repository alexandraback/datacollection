#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
using namespace std;

#define Rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, b) for(int i = (a); i <= (b); i++)
#define Ford(i, a, b) for(int i = (a); i >= (b); i--)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

#define gcj(ans) {cout << "Case #" << (test) << ": " << (ans) << endl;}

const int maxn = 111111;
double p[maxn];

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    
    int TEST; scanf("%d", &TEST);
    for(int test = 1; test <= TEST; test++)
    {
        int A, B;
        cin >> A >> B;
        Rep(i, A) cin >> p[i];
        
        double p1 = 1., p2 = 0.;
        double best = min(B + 2, A + B + 1);
        
        //cout << (B + 2) << " " << (A + B + 1) << endl;
        
        for(int i = 0; i < A; i++)
        {
            p1 *= p[i];
            p2 = 1. - p1;
            
            double keys = 2 * (A - (i + 1)) + B - A + 1;
            double val = p1 * keys + p2 * (keys + B + 1);

            //cout << val << endl;
            
            best = min(best, val); 
        }
        
        printf("Case #%d: %.8lf\n", test, best);
    }
}
