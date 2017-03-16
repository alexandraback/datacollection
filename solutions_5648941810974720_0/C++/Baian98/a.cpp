/*
 Created by Saidolda Bayan.
 Copyright (c) 2015 Bayan. All rights reserved.
 LANG: C++
 */
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
using pii = pair<int, int>;
using ll = long long;

const int INF = (int)1e9+7, mod = (int)1e9+9, pw = 31, N = (int)1e5+123, M = (int)1e6+123;
const double eps = 1e-11;
const long long inf = 1e18;


int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    freopen("A-small-attempt1.in.txt","r",stdin);
    freopen("ans.txt","w",stdout);
    int test;
    cin>>test;
    for(int g = 1; g <= test; g++){
        cout<<"Case #"<<g<<": ";
        string s;
        int ans[10];
        unordered_map<char, int> cnt;
        cnt.clear();
        memset(ans, 0, sizeof ans);
        cin>>s;
        for(auto i : s){
            cnt[i]++;
        }
        // 0
        while(cnt['Z']){
            ans[0]++;
            cnt['Z']--;
            cnt['E']--;
            cnt['R']--;
            cnt['O']--;
        }
        // 2
        while(cnt['W']){
            ans[2]++;
            cnt['T']--;
            cnt['W']--;
            cnt['O']--;
        }
        // 4
        while(cnt['U']){
            ans[4]++;
            cnt['F']--;
            cnt['O']--;
            cnt['U']--;
            cnt['R']--;
        }
        // 5
        while(cnt['F']){
            ans[5]++;
            cnt['F']--;
            cnt['I']--;
            cnt['V']--;
            cnt['E']--;
        }
        // 6
        while(cnt['X']){
            ans[6]++;
            cnt['S']--;
            cnt['I']--;
            cnt['X']--;
        }
        // 7
        while(cnt['S']){
            ans[7]++;
            cnt['S']--;
            cnt['E']--;
            cnt['V']--;
            cnt['E']--;
            cnt['N']--;
        }
        // 8
        while(cnt['G']){
            ans[8]++;
            cnt['E']--;
            cnt['I']--;
            cnt['G']--;
            cnt['H']--;
            cnt['T']--;
        }
        // 9
        while(cnt['I']){
            ans[9]++;
            cnt['N']--;
            cnt['I']--;
            cnt['N']--;
            cnt['E']--;
        }
        // 1
        while(cnt['O']){
            ans[1]++;
            cnt['O']--;
            cnt['N']--;
            cnt['E']--;
        }
        // 3
        while(cnt['T']){
            ans[3]++;
            cnt['T']--;
        }
        for(int i=0; i<=9; i++){
            while(ans[i]--)cout<<i;
        }
        cout<<"\n";
    }
    
    
    
    
    return 0;
}
