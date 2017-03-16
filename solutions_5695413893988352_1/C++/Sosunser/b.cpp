#include <bits/stdc++.h>
using namespace std;

int t;
long long sol;
char ch;
vector<int> a,b,c,d;
long long s1,s2;

void calc(){
    string x,y;
    for(int i : a){
        x += (char)i+'0';
    }
    for(int i : b){
        y += (char)i+'0';
    }
    long long a1 = stoll(x);
    long long a2 = stoll(y);
    if(abs(a1-a2) <= sol){
        if(sol == abs(a1-a2)){
            if(s1 < a1) return;
            if(s1 == a1 && s2 < a2) return;
        }
        sol = abs(a1-a2);
        s1 = a1;
        s2 = a2;
    }
    return;
}

void solve(int idx, int dir){
    if(idx == a.size()){
        calc();
        return;
    }
    if(dir != 0){
        for(int i = idx; i < a.size(); i++){
            if(c[i] == -1){
                if(dir == 1) a[i] = 0;
                else a[i] = 9;
            }
            if(d[i] == -1){
                if(dir == 1) b[i] = 9;
                else b[i] = 0;
            }
        }
        calc();
        return;
    }
    if(c[idx] == -1 && d[idx] == -1){
        a[idx] = 0;
        b[idx] = 0;
        solve(idx+1,0);
        a[idx] = 1;
        b[idx] = 0;
        solve(idx+1,1);
        a[idx] = 0;
        b[idx] = 1;
        solve(idx+1,-1);
    }else if(d[idx] == -1){
        b[idx] = a[idx];
        solve(idx+1,0);
        if(c[idx] != 0){
            b[idx] = a[idx]-1;
            solve(idx+1,1);
        }
        if(c[idx] != 9){
            b[idx] = a[idx]+1;
            solve(idx+1,-1);
        }
    }else if(c[idx] == -1){
        a[idx] = b[idx];
        solve(idx+1,0);
        if(d[idx] != 0){
            a[idx] = b[idx]-1;
            solve(idx+1,-1);
        }
        if(d[idx] != 9){
            a[idx] = b[idx]+1;
            solve(idx+1,1);
        }
    }else{
        if(a[idx] == b[idx]) solve(idx+1,0);
        if(a[idx] > b[idx]) solve(idx+1,1);
        if(a[idx] < b[idx]) solve(idx+1,-1);
    }
    return;
}

int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d\n",&t);
    for(int k = 1; k <= t; k++){
        a.clear();
        b.clear();
        while(1){
            scanf("%c",&ch);
            if(ch == ' ') break;
            if(ch == '?') a.push_back(-1);
            else a.push_back(ch-'0');
        }
        while(1){
            scanf("%c",&ch);
            if(ch == '\n') break;
            if(ch == '?') b.push_back(-1);
            else b.push_back(ch-'0');
        }
        c = a;
        d = b;
        sol = LONG_LONG_MAX;
        solve(0,0);
        cout << "Case #" << k << ": ";
        for(int i = 0; i < c.size()-to_string(s1).size(); i++) cout << "0";
        cout << s1 << " ";
        for(int i = 0; i < d.size()-to_string(s2).size(); i++) cout << "0";
        cout << s2 << endl;

    }
}