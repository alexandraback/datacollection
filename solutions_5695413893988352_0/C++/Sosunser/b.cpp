#include <bits/stdc++.h>
using namespace std;

int t,sol;
char ch;
vector<int> a,b,c,d;
int s1,s2;

void calc(){
    string x,y;
    for(int i : a){
        x += (char)i+'0';
    }
    for(int i : b){
        y += (char)i+'0';
    }
    int a1 = stoi(x);
    int a2 = stoi(y);
    if(abs(a1-a2) < sol){
        sol = abs(a1-a2);
        s1 = a1;
        s2 = a2;
    }
    return;
}

void solve(bool w, int idx){
    if(!w){
        for(int i = idx; i < a.size(); i++){
            if(c[i] == -1){
                for(int j = 0; j <= 9; j++){
                    a[i] = j;
                    solve(0,i+1);
                }
                return;
            }
        }
        for(int i = 0; i < b.size(); i++){
            if(d[i] == -1){
                for(int j = 0; j <= 9; j++){
                    b[i] = j;
                    solve(1,i+1);
                }
                return;
            }
        }
        calc();
        return;
    }
    for(int i = idx; i < b.size(); i++){
        if(d[i] == -1){
            for(int j = 0; j <= 9; j++){
                b[i] = j;
                solve(1,i+1);
            }
            return;
        }
    }
    calc();
    return;
}

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
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
        sol = INT_MAX;
        solve(0,0);
        cout << "Case #" << k << ": ";
        for(int i = 0; i < c.size()-to_string(s1).size(); i++) cout << "0";
        cout << s1 << " ";
        for(int i = 0; i < d.size()-to_string(s2).size(); i++) cout << "0";
        cout << s2 << endl;
    }
}