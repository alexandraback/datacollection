//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <time.h>
//    clock_t lim = clock() + 1.9*CLOCKS_PER_SEC;
//        if (clock() >= lim)break;
//#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
const int MAXN = 100010;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-6;
int v[50],ans[15];
string s;
int main()
{
//    freopen("in.in","r",stdin);
//    freopen("out.out","w",stdout);
    int t,n,cas=1;
    cin>>t;
    while(t--){
        cin>>s;
        int l=s.size();
        memset(v,0,sizeof v);
        memset(ans,0,sizeof ans);
        for(int i=0;i<l;i++)
            v[s[i]-'A']++;
        while(v['Z'-'A']--){
            v['E'-'A']--;
            v['R'-'A']--;
            v['O'-'A']--;
            ans[0]++;
        }
        while(v['G'-'A']--){
            v['E'-'A']--;
            v['I'-'A']--;
            v['H'-'A']--;
            v['T'-'A']--;
            ans[8]++;
        }
        while(v['X'-'A']--){
            v['S'-'A']--;
            v['I'-'A']--;
            ans[6]++;
        }
        while(v['H'-'A']--){
            v['T'-'A']--;
            v['R'-'A']--;
            v['E'-'A']-=2;
            ans[3]++;
        }
        while(v['T'-'A']--){
            v['W'-'A']--;
            v['O'-'A']--;
            ans[2]++;
        }
        while(v['R'-'A']--){
            v['F'-'A']--;
            v['O'-'A']--;
            v['U'-'A']--;
            ans[4]++;
        }
        while(v['F'-'A']--){
            v['I'-'A']--;
            v['V'-'A']--;
            v['E'-'A']--;
            ans[5]++;
        }
        while(v['V'-'A']--){
            v['S'-'A']--;
            v['N'-'A']--;
            v['E'-'A']-=2;
            ans[7]++;
        }
        while(v['I'-'A']--){
            v['E'-'A']--;
            v['N'-'A']-=2;
            ans[9]++;
        }
        while(v['O'-'A']--){
            v['E'-'A']--;
            v['N'-'A']--;
            ans[1]++;
        }
        printf("Case #%d: ",cas++);
        for(int i=0;i<=9;i++)
//            cout<<ans[i]<<endl;
            while(ans[i]--)
                printf("%d",i);
        puts("");
    }
    return 0;
}
