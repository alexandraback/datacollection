#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double du;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

int main()
{
    #ifdef __FIO
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int T, i0;
    scanf("%d", &T);
    for(i0 = 1; i0 <= T; i0++){
        cout<<"Case #"<<i0<<": "<<endl;
        int R, N, M, K;
        cin>>R>>N>>M>>K;
        while(R--){
            int i;
            du c2, c3, c5;
            int m2, m3, m5;
            c2 = c3 = c5 = m2 = m3 = m5 = 0;
            for(i = 0; i < K; i++){
                int t;
                int j;
                cin>>t;
                for(j = 0; t%2 == 0; j++)
                    t /= 2;
                c2 += j;
                m2 = max(m2, j);
                for(j = 0; t%3 == 0; j++)
                    t /= 3;
                c3 += j;
                m3 = max(m3, j);
                for(j = 0; t%5 == 0; j++)
                    t /= 5;
                c5 += j;
                m5 = max(m5, j);
            }
            c2 /= 3.5;
            c3 /= 3.5;
            c5 /= 3.5;
            c2 = max(c2, (du)m2);
            c3 = max(c3, (du)m3);
            c5 = max(c5, (du)m5);
            m3 = (int)(c3+0.5);
            m5 = (int)(c5+0.5);
            m2 = N-m3-m5;
            for(i = 0; i < m3; i++)
                printf("3");
            for(i = 0; i < m5; i++)
                printf("5");
            if(m2*2 < c2)
                c2 = m2*2;
            if(c2 < m2)
                c2 = m2;
            for(i = 0; i < (int)(c2+0.5)-m2; i++)
                printf("4");
            for(i = 0; i < m2-((int)(c2+0.5)-m2); i++)
                printf("2");
            printf("\n");
        }
    }
    return 0;
}
