#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
vector<int> A,B;
string a,b;
void dfs(int x,int ans,string &s,vector<int> &vec) {
    if(x == s.length()) {
        vec.push_back(ans);
        return;
    }
    if(s[x] != '?') {
        ans = ans * 10 + s[x] - '0';
        dfs(x + 1,ans,s,vec);
    } else {
        for(int i = 0; i < 10; ++i) {
            ans = ans * 10 + i;
            dfs(x + 1,ans,s,vec);
            ans /= 10;
        }
    }
}

string getStr(int na,int len) {
    string c = "";
    while(na || c.size() < len) {
        if(na) c = (char)(na % 10 + '0') + c;
        else c = '0' + c;
        na /= 10;
    }
    return c;
}

void solve() {
    int T,cnt = 0;
    cin>>T;
    while(T--) {
        A.clear();
        B.clear();
        cin>>a>>b;
        dfs(0,0,a,A);
        dfs(0,0,b,B);
        int diff = 1 << 30;
        int na,nb;
        for(int i = 0; i < A.size(); ++i) {
            for(int j = 0; j < B.size(); ++j) {
                int tmp = abs(A[i] - B[j]);
                if(tmp < diff) {
                    diff = tmp;
                    na = A[i];
                    nb = B[j];
                } else if(tmp == diff) {
                    if(A[i] < na || A[i] == na && B[j] < nb) {
                        na = A[i];
                        nb = B[j];
                    }
                }
            }
        }
        int len = a.length();
        printf("Case #%d: ",++cnt);
        string c = getStr(na,len);
        string d = getStr(nb,len);
        cout << c << " " << d << endl;
    }
}

int main() {
    freopen("in","r",stdin);
    freopen("A.out","w",stdout);
    solve();
    return 0;
}
