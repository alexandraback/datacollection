#include <bits/stdc++.h>

using namespace std;

void output(int t,int ans) {
    cout<<"Case #"<<t<<": "<<ans<<endl;
}

void output(int t,string ans) {
    cout<<"Case #"<<t<<": "<<ans<<endl;
}

string toStr(int i) {
    ostringstream oss;
    oss<<i;
    return oss.str();
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin>>t;
    for (int _t=1;_t<=t;_t++) {
        long long n; cin>>n;
        long long nold = n;
        if (n==0) {output(_t,"INSOMNIA"); continue;}
        bool found[10];
        for (int i =0;i<10;i++) found[i]=false;
        while (true) {
            string str = toStr(n);
            for (int i = 0;i<str.size();i++) {
                found[str[i]-'0'] = true;
            }

            bool allfound = true;
            for (int i = 0;i<10;i++) {
                if(!found[i]) {allfound=false; break;}
            }

            if (allfound) {
                output(_t,n);
                break;
            } else {
                n+=nold;
            }
        }
    }
    return 0;
}
