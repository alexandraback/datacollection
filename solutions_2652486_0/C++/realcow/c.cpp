#include <iostream>   
#include <vector>   
#include <algorithm>   
#include <queue>   
#include <string>  
#include <xfunctional>
#include <set>
//#include <boost/multiprecision/cpp_int.hpp>  
//using namespace boost;
//using namespace boost::multiprecision;
using namespace std;   
#define rep(x,n) for(x=0;x<n;x++)   

typedef vector<int> vi;   
typedef long long ll;   
typedef unsigned long long ull;   
typedef pair<int, ull> pil;

unsigned int p[40], pcnt, e[40];   
void factorization(unsigned int m) {   
    pcnt = 0;   
    if (m == 0) return;   
    for (unsigned int i = 2; m > 1 && i * i <= m; i++) {   
        if (m % i == 0) {   
            p[pcnt] = i, e[pcnt] = 0;   
            while (m % i == 0) e[pcnt]++, m /= i;   
            pcnt++;   
        }   
    }   
    if (m != 1) e[pcnt] = 1, p[pcnt++] = m;   
}  

int main() {
    int i, j, k;
    scanf("%*d");
    int R, N, M, K;
    scanf("%d%d%d%d", &R, &N, &M, &K);
    printf("Case #1:\n");
    for (i = 0; i < R; i++)
    {
        int cnt[10];
        memset(cnt, 0, sizeof(cnt));
        for (j = 0; j < K; j++)
        {
            int t;
            scanf("%d", &t);
            factorization(t);
            for (k = 0; k < pcnt; k++) cnt[p[k]] += e[k];
        }
        for (j = 0; j < N; j++)
        {
            int best = max_element(cnt, cnt + 10) - cnt;
            
            if (j == 0 && best == 2) best = 4;
            
            printf("%d", (best == 0 ? 2 : best));
            
            cnt[best] = 0;
        }
        puts("");
    }
}