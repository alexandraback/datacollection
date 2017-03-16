#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
//#include <unordered_map>
//#define lson x<<1
//#define rson x<<1|1
//#define mid ((lt[x].l+lt[x].r)/2)
//#define ID(x, y) ((x)*m+(y))
//#define CHECK(x, y) ((x)>=0 && (x)<n && (y)>=0 && (y)<m)
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
void Open()
{
    #ifndef ONLINE_JUDGE
        freopen("B-small-attempt0.in","r",stdin);
        freopen("B-small-attempt0.out","w",stdout);
    #endif // ONLINE_JUDGE
}

char C[222], J[222];
int main()
{
//    Open();
    int T;
    scanf("%d", &T);
    int cas = 1;
    while(T--)
    {
        scanf("%s%s", C, J);
        int len = strlen(C);
        int num = 0;
        int dif = INF, mic, mij, sol;
        for(int i = 0; i < len; i++) num += (C[i] == '?'), num += (J[i] == '?');

        int up = 1;
        while(num -- ) up*=10;
        for(int s = 0; s < up; s++)
        {
            int tmp = s;
            int cc = 0, jj = 0;
            for(int i = 0; i < len; i++)
            {
                if(C[i] == '?')
                {
                    cc = cc * 10 + tmp % 10;
                    tmp /= 10;
                }else {
                    cc = cc * 10 + C[i] - '0';
                }
            }
            for(int i = 0; i < len; i++)
            {
                if(J[i] == '?')
                {
                    jj = jj * 10 + tmp % 10;
                    tmp /= 10;
                }else {
                    jj = jj * 10 + J[i] - '0';
                }
            }
            if(dif > abs(cc-jj)) {
                dif = abs(cc-jj);
                mic = cc, mij = jj;
                sol = s;
            }else if(dif == abs(cc-jj) && cc < mic) {
                mic = cc;
                mij = jj;
                sol = s;
            }else if(dif == abs(cc-jj) && cc == mic && jj < mij) {
                mij = jj;
                sol = s;
            }
        }
        int tmp = sol;
        for(int i = 0; i < len; i++)
        {
            if(C[i] == '?')
            {
                C[i] = tmp % 10 + '0';
                tmp /= 10;
            }
        }
        for(int i = 0; i < len; i++)
        {
            if(J[i] == '?')
            {
                J[i] = tmp % 10 + '0';
                tmp /= 10;
            }
        }
//        cerr<<cas<<endl;
        printf("Case #%d: ", cas++);
//        printf("%d %d %d\n", dif, mic, mij);
        printf("%s %s\n", C, J);
    }
    return 0;
}
