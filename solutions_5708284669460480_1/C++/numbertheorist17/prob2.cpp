#include <bits/stdc++.h>
using namespace std;

int t, k, l, s;
string alpha, target;
map<char,double> m;

int main(void) {
    if (fopen("b.in","r")) {
        freopen("b.in","r",stdin);
        freopen("b.out","w",stdout);
    }
    cin >> t;
    for (int ii=1; ii<=t; ii++) {
        cin >> k >> l >> s;
        cin >> alpha >> target;
        m=map<char,double>();
        for (int i=0; i<26; i++) {
            m['A'+i]=0.0;
        }
        for (int i=0; i<alpha.length(); i++) {
            m[alpha[i]]++;
        }
        int t=100;
        for (int i=0; i<26; i++) {
            m['A'+i]=m['A'+i]/alpha.length();
        }
        double prob=s-l+1;
        bool occurs=true, done=false;
        for (int i=0; i<target.length() && occurs && !done; i++) {
            prob*=m[target[i]];
            if (m[target[i]]==0) occurs=false;
            if (prob<=1e-15) done=true;
        }
        int ind=-1;
        for (int i=1; i<target.length() && ind==-1; i++) {
            if (target.substr(i,target.length()-i)==target.substr(0,target.length()-i)) {
                ind=i;
            }
        }
        if (ind==-1) ind=target.length();
        int tot=0;
        if (occurs) tot=(s-target.length())/ind+1;
        else tot=0;
        cout << "Case #" << ii << ": ";
        printf("%.11f\n",tot-prob);
    }
    return 0;
}
