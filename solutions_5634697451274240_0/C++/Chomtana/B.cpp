#include <bits/stdc++.h>

using namespace std;

void output(int t,int ans) {
    cout<<"Case #"<<t<<": "<<ans<<endl;
}

int last_(string &s) { //return index of last '-'
    int res = -1;
    for (int i = 0;i<s.size();i++) {
        if (s[i]=='-') res = i;
    }
    return res;
}

bool isOk (string &s) {
    bool ok = true;
    for (int i = 0;i<s.size();i++) {
        if (s[i]!='+') {ok = false; break;}
    }
    return ok;
}

void flip(string &s,int n) {
    for (int i = 0;i<=n;i++) {
        if (s[i]=='+') s[i]='-'; else s[i]='+';
    }
    reverse(s.begin(),s.begin()+(n+1));
}

int main() {
    ios::sync_with_stdio(false);
    cout<<fixed;
    int t; cin>>t;
    for(int _t=1;_t<=t;_t++) {
        string s; cin>>s;
        long long count = 0;
        while (!isOk(s)) {
            int n= last_(s); //n = end ^^
            if (s[0]=='+') {
                for (int i = 0;i<=n;i++) {
                    if (s[i]=='+') s[i]='-'; else break;
                }
                count++;
            }
            flip(s,n);
            count++;
        }
        output(_t,count);
    }
    return 0;
}
