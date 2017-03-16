#pragma warning(disable:4996)
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

string code;
string jam;
string la,ra;
string ans;
int n;


string sabs(const string &a,const string &b)
{
    if(a<b) {return sabs(b,a);}
    string res;
    int sz=a.length();
    for(int i=0;i<sz;++i) res.push_back('0');
    bool borrow = false;
    int av,bv;
    for(int i=sz-1;i>=0;--i) {
        av = a[i];
        bv = b[i];
        if (borrow) {
            if (av >= 1) av -= 1, borrow = false;
            else {
                av = 9;
            }
        }
        if (av - bv >= 0) {
            res[i] = av - bv + '0';
        }
        else {
            borrow = true;
            res[i] = av + 10 - bv + '0';
        }
    }
    return res;
}


void dfs(int cur,string ls,string rs,int sta)
{
    if(cur==n) {
        string delta = sabs(ls,rs);
        if(delta <  ans) {
            ans = delta;
            la = ls;
            ra = rs;
        }
        else if(delta == ans){
            if(ls<la){
                ans = delta;
                la = ls;
                ra = rs;
            }
            else if(ls==la&&rs<ra){
                ans = delta;
                la = ls;
                ra = rs;
            }
        }
        return;
    }
    if(sta==0) {
        if(ls[cur] != '?' && rs[cur] != '?') {
            if (ls[cur] == rs[cur]) sta = 0;
            if (ls[cur] < rs[cur]) sta = -1;
            if (ls[cur] > rs[cur]) sta = 1;
            dfs(cur + 1, ls, rs, sta);
        }
        else if(ls[cur]=='?' && rs[cur] == '?') {
            ls[cur] = '0';
            rs[cur] = '0';
            dfs(cur + 1, ls, rs, sta);
            ls[cur] = '0';
            rs[cur] = '1';
            dfs(cur + 1, ls, rs, -1);
            ls[cur] = '1';
            rs[cur] = '0';
            dfs(cur + 1, ls, rs, 1);
        }
        else {
            if (ls[cur] == '?') {
                ls[cur] = rs[cur];
                dfs(cur + 1, ls, rs, sta);
                if (rs[cur] != '9') {
                    ls[cur] = rs[cur] + 1;
                    dfs(cur + 1, ls, rs, 1);
                }
                if (rs[cur] != '0') {
                    ls[cur] = rs[cur] - 1;
                    dfs(cur + 1, ls, rs, 1);
                }
            }
            else if (rs[cur] == '?') {
                rs[cur] = ls[cur];
                dfs(cur + 1, ls, rs, sta);
                if (ls[cur] != '9') {
                    rs[cur] = ls[cur] + 1;
                    dfs(cur + 1, ls, rs, 1);
                }
                if (ls[cur] != '0') {
                    rs[cur] = ls[cur] - 1;
                    dfs(cur + 1, ls, rs, 1);
                }
            }
        }
    }
    // 左小
    else if(sta<0) {
        if (ls[cur] == '?') ls[cur] = '9';
        if (rs[cur] == '?') rs[cur] = '0';
        dfs(cur+1,ls,rs,sta);
    }
    else if(sta>0) {
        if (ls[cur] == '?') ls[cur] = '0';
        if (rs[cur] == '?') rs[cur] = '9';
        dfs(cur + 1, ls, rs, sta);
    }

}



int main()
{
//    cout<<sabs("123","456")<<endl;
//    cout <<sabs("800","798") << endl;
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T; cin >> T; int ca = 0;
    while(T--) {
        cin >> code >> jam;
        n = code.length();
        ans = "";
        for (int i = 0; i < n; ++i) ans.push_back('9');
        dfs(0, code, jam, 0);
        printf("Case #%d: %s %s\n", ++ca,la.c_str(), ra.c_str());
    }
    return 0;
}



