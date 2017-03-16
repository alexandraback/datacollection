//
//  b.cpp
//  Round 1B 2016
//
//  Created by Bayan on 30.04.16.
//  Copyright © 2016 Bayan. All rights reserved.
//
#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
#define y1 lalka
#define right napravo
#define left nalevo
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

using ll = long long;
using pll = pair<string, string>;

const int INF = (int)1e9+7, N = (int)1e5+123, M = (int)1e6+123;
const double eps = 1e-9;
const long long inf = 1e18 + 17;

int tests;
char f(char a, char b){
    if(a < b) return '<';
    if(a > b) return '>';
    return '=';
}
string s, t;
pll calc(string s, string t, int id, char c){
    char last = '=';
    for(int i=0; i<s.size(); i++){
        bool c1 = s[i] != '?', c2 = t[i] != '?';
        if(c1 && c2){
            if(last == '=')
                last = f(s[i], t[i]);
        }
        if(!c1 && !c2){
            switch (last) {
                case '>':
                    s[i] = '0';
                    t[i] = '9';
                    break;
                case '<':
                    s[i] = '9';
                    t[i] = '0';
                    break;
                case '=':
                    if(id == i){
                        if(c == '<'){
                            s[i] = '0';
                            t[i] = '1';
                        }
                        else{
                            s[i] = '1';
                            t[i] = '0';
                        }
                        last = c;
                    }
                    else
                    s[i] = t[i] = '0';
                    break;
                default:
                    break;
            }
        }
        if(c1 && !c2){
            switch (last) {
                case '>':
                    t[i] = '9';
                    break;
                case '<':
                    t[i] = '0';
                    break;
                case '=':
                    if(id == i){
                        if(c == '<'){
                            t[i] = min(char(s[i] + 1), '9');
                        }
                        else{
                            t[i] = max(char(s[i]-1), '0');
                        }
                        last = c;
                    }
                    else
                    t[i] = s[i];
                    break;
                default:
                    break;
            }
        }
        if(!c1 && c2){
            switch (last) {
                case '>':
                    s[i] = '0';
                    break;
                case '<':
                    s[i] = '9';
                    break;
                case '=':
                    if(id == i){
                        if(c == '<'){
                            s[i] = max(char(t[i] - 1), '0');
                        }
                        else{
                            s[i] = min(char(t[i] + 1), '9');
                        }
                        last = c;
                    }
                    else
                    s[i] = t[i];
                    break;
                default:
                    break;
            }
        }
    }
    return mp(s, t);
}
ll operator -(string s, string t){
    ll res1 = 0, res2 = 0;
    for(auto i : s)res1 = res1 * 10 + (i - '0');
    for(auto i : t)res2 = res2 * 10 + (i - '0');
    return res1 - res2;
}
int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    freopen("B-large.in.txt","r",stdin);
    freopen("ans.txt","w",stdout);
    cin>>tests;
    for(int test=1; test <= tests; test++){
        cout<<"Case #"<<test<<": ";
        cin>>s>>t;
        vector<pll> ans;
        ans.pb(calc(s, t, s.size()+5, '<'));
        for(int i=0; i<s.size(); i++){
            ans.pb(calc(s, t, i, '<'));
            ans.pb(calc(s, t, i, '>'));
        }
        pll res = ans[0];
        for(auto i : ans){
            if(abs(i.f - i.s) < abs(res.f - res.s)){
                res = i;
            }
            if(abs(i.f - i.s) == abs(res.f - res.s) &&
               i.f < res.f
               ){
                res = i;
            }
            if(abs(i.f - i.s) == abs(res.f - res.s) &&
               i.f == res.f && i.s < res.s
               ){
                res = i;
            }
        }
        cout<<res.f<<" "<<res.s<<"\n";
        cerr<<test<<"\n";
    }

    
    return 0;
}
