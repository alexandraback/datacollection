#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <map>
#include <cassert>
#include <queue>
using namespace std;
#define ll long long
#define maxn 105000



string d[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
// Z -- ZERO
// G -- EIGHT
// W -- TWO
// T -- THREE
// X -- SIX
// S -- SEVEN
// V -- FIVE
// F -- FOUR
// O -- ONE
// E -- NINE
int cnt[10];


int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T;cin>>T;int ca=0;
    while(T--) {
        string x;
        cin>>x;
        map<char,int> mm;
        for(int i=0;i<x.length();++i) {
            mm[x[i]]++;
        }
        memset(cnt,0, sizeof(cnt));
        if(mm['Z']) {
            cnt[0] = mm['Z'];
            for (int i = 0; i < d[0].length(); ++i) mm[d[0][i]] -= cnt[0];
        }
        if(mm['G']) {
            cnt[8] = mm['G'];
            for (int i = 0; i < d[8].length(); ++i) mm[d[8][i]] -= cnt[8];
        }
        if(mm['W']) {
            cnt[2] = mm['W'];
            for (int i = 0; i < d[2].length(); ++i) mm[d[2][i]] -= cnt[2];
        }
        if(mm['T']) {
            cnt[3] = mm['T'];
            for (int i = 0; i < d[3].length(); ++i) mm[d[3][i]] -= cnt[3];
        }
        if(mm['X']) {
            cnt[6] = mm['X'];
            for (int i = 0; i < d[6].length(); ++i) mm[d[6][i]] -= cnt[6];
        }
        if(mm['S']) {
            cnt[7] = mm['S'];
            for (int i = 0; i < d[7].length(); ++i) mm[d[7][i]] -= cnt[7];
        }
        if(mm['V']) {
            cnt[5] = mm['V'];
            for (int i = 0; i < d[5].length(); ++i) mm[d[5][i]] -= cnt[5];
        }
        if(mm['F']) {
            cnt[4] = mm['F'];
            for (int i = 0; i < d[4].length(); ++i) mm[d[4][i]] -= cnt[4];
        }
        if(mm['O']) {
            cnt[1] = mm['O'];
            for (int i = 0; i < d[1].length(); ++i) mm[d[1][i]] -= cnt[1];
        }
        if(mm['E']) {
            cnt[9] = mm['E'];
            for (int i = 0; i < d[9].length(); ++i) mm[d[9][i]] -= cnt[9];
        }
        printf("Case #%d: ",++ca);
        for(int i=0;i<10;++i){
            if(cnt[i]){
                for(int k=0;k<cnt[i];++k) printf("%c",'0'+i);
            }
        }
        puts("");
    }
    return 0;
}



