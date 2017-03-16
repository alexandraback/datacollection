/*
*Rainto96
*Beijing University of Posts and Telecommunications School of Software Engineering
*http://blog.csdn.net/u011775691
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <climits>
using namespace std;
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define VINT vector<int>
#define PII pair<int,int>
#define MP(x,y) make_pair((x),(y))
#define ll long long
#define ull unsigned long long
#define MEM0(x)  memset(x,0,sizeof(x))
#define MEM(x,val) memset((x),val,sizeof(x))
#define scan(x) scanf("%d",&(x))
#define scan2(x,y) scanf("%d%d",&(x),&(y))
#define scan3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z))
#define scan4(x,y,z,k) scanf("%d%d%d%d",&(x),&(y),&(z),&(k))
#define Max(a,b) a=max(a,b)
#define Min(a,b) a=min(a,b)
#define fuck(x) cout<<#x<<" - "<<x<<endl
string c[10];

int dfs(int idx, int st, int res, int num[], int ans[])
{
    if(res == 0){
        return idx;
    }
    if(st > 0 && num['Z'] != 0) return -1;
    if(st > 8 && num['T'] != 0) return -1;
    if(st > 8 && num['G'] != 0) return -1;
    if(st > 8 && num['H'] != 0) return -1;
    if(st > 7 && num['V'] != 0) return -1;
    if(st > 7 && num['S'] != 0) return -1;
    if(st > 6 && num['X'] != 0) return -1;
    if(st > 5 && num['F'] != 0) return -1;
    if(st > 4 && num['O'] != 0) return -1;
    if(st > 4 && num['U'] != 0) return -1;
    if(st > 4 && num['R'] != 0) return -1;
    if(st > 2 && num['W'] != 0) return -1;
    for(int i = st; i < 10; i++)
    {
        int len = c[i].length();
        if(res < len) continue;
        bool flag = true;
        for(int j = 0; j < len && flag; j++)
            if(num[c[i][j]] == 0) {
                flag = false;
                break;
            }
        if(!flag) continue;
        for(int j = 0; j < len; j++) num[c[i][j]]--;
        ans[idx] = i;
        int rr = dfs(idx+1, i, res - len,num,ans);
        if(rr != -1) return rr;
        else{
            for(int j = 0; j < len; j++) num[c[i][j]]++;
        }
    }
    return -1;
}
char str[2222];
int main()
{
    //freopen("A-large.in","r",stdin);
    //freopen("A-large.out","w",stdout);
    c[0] = string("ZERO");
    c[1] = string("ONE");
    c[2] = string("TWO");
    c[3] = string("THREE");
    c[4] = string("FOUR");
    c[5] = string("FIVE");
    c[6] = string("SIX");
    c[7] = string("SEVEN");
    c[8] = string("EIGHT");
    c[9] = string("NINE");
    int T;
    scanf("%d", &T);
    for(int cas=1;cas<=T;cas++)
    {
        int num[222];
        int ans[2222];
        memset(num, 0, sizeof(num));
        scanf("%s", str);
        int len = strlen(str);
        for(int i = 0; i < len; i++)
        {
            num[str[i]]++;
        }
        int idx = dfs(0, 0, len, num, ans);
        printf("Case #%d: ", cas);
        for(int i = 0; i < idx; i++){
            printf("%d", ans[i]);
        }
        putchar('\n');
    }
    return 0;
}
