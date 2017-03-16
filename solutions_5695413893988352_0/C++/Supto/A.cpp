#include <bits/stdc++.h>
using namespace std;
#define D(x) cerr<<#x " = "<<(x)<<endl
#define pb push_back
#define ff first
#define ss second
#define mem(a) memset(a,0,sizeof(a))
#define _set(a) memset(a,-1,sizeof(a))
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define eps 1e-9
#define MAX 100000
#define MAXL 20
#define MAXE 100000
//ll mod = 1000000000+7;
//int dx[] = {0,0,1,-1};
//int dy[] = {1,-1,0,0};
//int dx[] = {-1,-1,-1,0,0,1,1,1};
//int dy[] = {-1,0,1,-1,1,-1,0,1};
char aa[10], bb[10];
vector <int> A, B;
int n;
void gen(int pos, int num)
{
    if(pos == n)
    {
        A.pb(num);
        return;
    }
    if(aa[pos] != '?')
    {
        gen(pos+1, num*10+aa[pos]-48);
        return;
    }
    for(int i = 0; i < 10; i++)
    {
        gen(pos+1, num*10+i);
    }
}
void gen1(int pos, int num)
{
    if(pos == n)
    {
        B.pb(num);
        return;
    }
    if(bb[pos] != '?')
    {
        gen1(pos+1, num*10+bb[pos]-48);
        return;
    }
    for(int i = 0; i < 10; i++)
    {
        gen1(pos+1, num*10+i);
    }
}
int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int ncase, tcase = 1, i, j;
    scanf("%d", &ncase);
    while(ncase--)
    {
        scanf("%s %s", aa, bb);
        n = strlen(aa);
        A.clear();
        B.clear();
        gen(0, 0);
        gen1(0, 0);
        int sz = A.size();
        int sz1 = B.size();
        int mn = 1000000;
        int ansa = 1000000, ansb = 1000000;
        for(i = 0; i < sz; i++)
        {
            for(j = 0; j < sz1; j++)
            {
                if(mn > abs(A[i]-B[j]))
                {
                    mn = abs(A[i]-B[j]);
                    ansa = A[i];
                    ansb = B[j];
                }
                else if(mn == abs(A[i]-B[j]) && A[i] < ansa)
                {
                    ansa = A[i];
                    ansb = B[j];
                }
                else if(mn == abs(A[i]-B[j]) && A[i] == ansa && B[j] < ansb)
                {
                    ansb = B[j];
                }
            }
        }
        printf("Case #%d: ", tcase++);
        int d = 0;
        int tmp = ansa;
        while(tmp)
        {
            d++;
            tmp /= 10;
        }
        if(ansa == 0) d++;
        for(i = 0; i < n-d; i++) printf("0");
        printf("%d ", ansa);
        d  = 0;
        tmp = ansb;
        while(tmp)
        {
            d++;
            tmp /= 10;
        }
        if(ansb == 0) d++;
        for(i = 0; i < n-d; i++) printf("0");
        printf("%d\n", ansb);
    }
    return 0;
}
