#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <algorithm>
#include <unordered_set>

using namespace std;


vector<string> w;
string key;
string target;
int k, l, s;
string st;

void gen(int n) {
    if (n==s) {
        w.push_back(st);
    }
    else {
        for (int i=0;i<k;i++) {
            st[n]=key[i];
            gen(n+1);
        }
    }
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    cout.precision(12);
    freopen("Bki.txt", "w", stdout);
    int t;
    cin >> t;
    for (int tt=1;tt<=t;tt++) {
        cin >> k>>l>>s;
        cin>> key;
        cin>> target;
        w.clear();
        st="";
        for (int i=0;i<s;i++) st+='.';
        gen(0);
        long double ma=0;
        for (int i=0;i<w.size();i++) {
            long double c=0;
            for (int j=0;j<s;j++) {
                bool b=true;
                for (int f=0;f<l;f++) {
                    if (j+f>=s) b=false;
                    else {
                        if (w[i][j+f]!=target[f]) b=false;
                    }
                }
                if (b) c++;
            }
            ma=max(c, ma);
        }

        long double sol=0;
        for (int i=0;i<w.size();i++) {
            long double c=0;
            for (int j=0;j<s;j++) {
                bool b=true;
                for (int f=0;f<l;f++) {
                    if (j+f>=s) b=false;
                    else {
                        if (w[i][j+f]!=target[f]) b=false;
                    }
                }
                if (b) c++;
            }
            sol+=c/(long double) w.size();
        }

        cout << "Case #" << tt<< ": "<<ma-sol<<endl;
    }
    return 0;
}
