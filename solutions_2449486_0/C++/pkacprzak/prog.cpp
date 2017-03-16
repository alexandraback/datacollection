#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
#include <cstring>
#include <ctime>
using namespace std;
#define pb push_back
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
inline void pisz(int n) { printf("%d\n",n); }
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari<< " = "<< (vari) <<endl;

const int MAX_N = 100;
const int MAX_M = 100;

int used_row[MAX_N];
int used_col[MAX_M];

typedef struct box
{
    int h, i, j;
} box;

box lawn[MAX_N * MAX_M + 10];
int current_test;

bool cmp(const box& b1, const box& b2)
{
    return b1.h > b2.h;
}
void output(int answer)
{
    printf("Case #%d: ", current_test);
    if(answer) printf("YES");
    else printf("NO");
    printf("\n");
}
int main()
{
    int t;
    scanf("%d", &t);
    for(current_test = 1; current_test <= t; current_test++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        FOR(i, n)
        {
            FOR(j, m)
            {
                scanf("%d", &lawn[i * m + j].h);
                lawn[i * m + j].i = i;
                lawn[i * m + j].j = j;
            }
        }
        sort(lawn, lawn + n * m, cmp);
        memset(used_row, 0, n * sizeof(int));
        memset(used_col, 0, m * sizeof(int));
        int i = 0;
        while(1)
        {            
            if(used_row[lawn[i].i] <= lawn[i].h || used_col[lawn[i].j] <= lawn[i].h)
            {
                REMAX(used_row[lawn[i].i], lawn[i].h);
                REMAX(used_col[lawn[i].j], lawn[i].h);
                i++;
                if(i == n * m) break;
            }
            else break;
        }
        if(i == n * m) output(1);
        else output(0);
    }
    return 0;
}
