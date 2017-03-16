#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <numeric>
#include <functional>
#include <utility>
#include <bitset>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

map <long long, int> a[53];
int answer[100], n, m, s[10000];

void print(int now, long long value, int res)
{
    int dir = a[now][value];
    long long v0 = value - dir * s[now - 1];
    answer[now - 1] = res * dir;
    if (v0 != 0)
        print(now-1, v0, res);
}

void PRINT()
{
    bool flag;
    flag = 1;
    for (int i=0;i<m+1;++i)
        if (answer[i] == 1)
        {
            if (flag)
                flag = 0;
            else
                printf(" ");
            printf("%d", s[i]);
        }
    printf("\n");
    
    flag = 1;
    for (int i=0;i<m+1;++i)
        if (answer[i] == -1)
        {
            if (flag)
                flag = 0;
            else
                printf(" ");
            printf("%d", s[i]);
        }
    printf("\n");
}

int main()
{
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    
int TT;
scanf("%d", &TT);
for (int T=1;T<=TT;++T)
{
    printf("Case #%d:\n", T);

    memset(answer, 0, sizeof(answer));
    scanf("%d", &n);
    for (int i=0;i<n;++i)
        scanf("%I64d",s+i);
    sort(s,s+n);
    long long sum = 0, now = 1;
    for (m=0;m<n;++m)
    {
        sum += s[m];
        now *= 2;
        if (sum < now - 1)
        {
            ++ m;
            break;
        }
    }
    
    s[m]=s[m/2];
    int l1=0, r1=m/2, l2=m/2+1, r2=m+1;
    
    bool flag = 0;
    a[0].clear();
    a[0][0] = 0;
    for (int i=0;i<m/2 && !flag;++i)
    {
        a[i+1].clear();
        for (map <long long, int>::iterator p = a[i].begin(); p != a[i].end(); ++ p)
        {
            long long x = p -> first;
            a[i+1][x+s[i]] = 1;
            a[i+1][x-s[i]] = -1;
            a[i+1][x] = 0;
            if (x + s[i] == 0 || x - s[i] == 0)
            {
                print(i+1,0,1);
                flag = 1;
                break;
            }
        }
    }
    
    a[m/2 + 1].clear();
    a[m/2 + 1][0] = 0;
    for (int i=m/2+1;i<m+1 && !flag;++i)
    {
        a[i+1].clear();
        for (map <long long, int>::iterator p = a[i].begin(); p != a[i].end(); ++ p)
        {
            long long x = p -> first;
            a[i+1][x+s[i]] = 1;
            a[i+1][x-s[i]] = -1;
            a[i+1][x] = 0;
            if (x + s[i] == 0 || x - s[i] == 0)
            {
                print(i+1,0,1);
                flag = 1;
                break;
            }
        }
    }
    
    if (!flag)
        for (map <long long, int>::iterator p = a[m/2].begin(); p != a[m/2].end(); ++ p)
        {
            long long x = p -> first;
            if (a[m+1].find(x) != a[m+1].end() && x!=0)
            {
                print(m+1,x,1);
                print(m/2,x,-1);
                flag = 1;
                break;
            }
        }
    if (flag)
        PRINT();
    else
        printf("Impossible!\n");
}
    
}
