#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>

#define N 1000005
using namespace std;

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }

int f[N];
char s[N];

int vowel(char c){
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int main(){
    int tt; scanf("%d",&tt);
    for (int ti=1;ti<=tt;ti++){
        int K;
        scanf("%s%d", s, &K);

        int n = strlen(s);
        int m = n - K + 1;
        int last = 0;
        for (int i=0;i<m;i++) f[i] = 1;
        for (int i=0;i<n;i++){
            if (vowel(s[i])){
                for (int j=max(last, i-K+1);j<=i;j++){
                    f[j] = 0;
                }
                last = i;
            }
        }

        //for (int i=0;i<m;i++)printf("%d", f[i]); puts("");

        int p = 0, q=-1;
        int ans = 0;
        while (q<m && f[q]==0) q++;
        if (q<m){
            for (int p=0;p<m;p++){
                if (f[p]){
                    q = p;
                }
                if (q<p){
                    q++;
                    while (q<m && f[q]==0) q++;
                }
                if (q<m){
                    ans += m-q;
                    //printf("p:%d %d\n", p, m-q);
                }
            }
        }

        printf("Case #%d: %d\n",ti,ans);
    }
    return 0;
}

