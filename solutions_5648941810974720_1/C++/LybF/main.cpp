#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <cassert>
#include <set>
using namespace std;


const int N=500;
string d[N]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[N];
int ans[N];
void go(int x) {
    int now=ans[x];
    for (int i=0;i<d[x].size();i++) {
        cnt[d[x][i]]-=now;
    }
}
int main () {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        string s;
        cin>>s;
        memset(cnt,0,sizeof cnt);
        for (int i=0;i<s.size();i++) {
            cnt[s[i]]++;
        }
        memset(ans,0,sizeof ans);
        ans[0]=cnt['Z'];
        go(0);

        ans[2]=cnt['W'];
        go(2);

        ans[6]=cnt['X'];
        go(6);

        ans[4]=cnt['U'];
        go(4);

        ans[5]=cnt['F'];
        go(5);

        ans[7]=cnt['V'];
        go(7);

        ans[8]=cnt['G'];
        go(8);

        ans[3]=cnt['T'];
        go(3);

        ans[1]=cnt['O'];
        go(1);

        ans[9]=cnt['E'];
        go(9);
        for (int i='A';i<='Z';i++) {
            assert(cnt[i]==0);
        }
        static int cas=1;
        cout<<"Case #"<<cas++<<": ";
        for (int i=0;i<=9;i++) {
            for (int j=1;j<=ans[i];j++) {
                cout<<i;
            }
        }
        cout<<endl;
    }
    return 0;
}
