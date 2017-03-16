#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<math.h>
#include<algorithm>
#include<set>

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case #%d: ", cas++);
#define EPS 1e-9
#define MAX 1000010
#define INF (1<<25)
#define MP make_pair
#define pii pair<int, int>
#define ll long long

int xx[] = {1,1,0,-1,-1,-1,0,1}, yy[] = {0,1,1,1,0,-1,-1,-1}; //eight direction

using namespace std;

string inp;
char str[MAX];

ll chk(string now, int n)
{
    int i, j, k;
    int con=0;
    for(i=0;i<SZ(now);i++)
    {
        if(now[i]=='a' || now[i]=='e' || now[i]=='i'
           || now[i]=='o' || now[i]=='u')
        {
            con=0;
        }
        else con++;
        if(con>=n) break;
    }
    if(con>=n) return 1;
    return 0;
}

int main()
{
    freopen("A-small.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    int t, cas=1;
    scanf("%d", &t);
    while(t--)
    {
        scanf(" %s", &str);
        int n;
        scanf("%d", &n);
        inp = str;
        int i, j, k;
        string now, prev="";
        ll val=0;
        for(i=0;i<SZ(inp);i++)
        {
            for(j=0;j<(SZ(inp)-i+1);j++)
            {
                now = inp.substr(i, j);
                val+=chk(now, n);
            }
        }
        csprnt;
        cout<<val<<endl;
    }
    return 0;
}

