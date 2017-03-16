#include<bits/stdc++.h>
using namespace std;
long long v[1010100];
long long s1[1010100],N,M;

int ok = 0;
set<int> S;
void make(int x) {
    while(x) {
        int d = x % 10;
        x=x/10;
        S.insert(d);
    }
}
int main() {
    freopen("test1.in","r",stdin);
    freopen("test1.out","w",stdout);
    int T;
    cin >> T;
    for (int tt=1;tt<=T;++tt) {
        string s;
        cin >> s;
        int grup = 1;
        for(int i=1;i<s.size();++i){
            if(s[i] != s[i-1])
                ++grup;
        }
        if(s[s.size()-1] == '+')
            grup--;
        printf("Case #%d: %d\n",tt,grup);
    }
}
