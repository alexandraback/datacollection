#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <list>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <valarray>
#include <ctime>
#include <set>
#include <sstream>
#include <stdarg.h>
#include <fstream>

using namespace std;
map<string, map<string, string> > a;

void solve(int t) {
    int l;
    long long x;
    cin>>l>>x;
    string s;
    cin>>s;
    string cur="1";
    bool gotI=false, gotJ=false;
    for (int i=0;i<min(x,8ll);i++) {
        for (int j=0;j<s.size();j++) {
            string s1="";
            s1+=s[j];
            cur=a[cur][s1];
            if (!gotI && cur=="i") {
                gotI = true;
                cur="1";
            } else if (gotI && !gotJ && cur=="j") {
                gotJ=true;
                cur="1";
            }
        }
        if (gotI&&gotJ) {
            x-=(i+1);
            break;
        }
    }
    if (!gotI || !gotJ) {
        printf("Case #%d: NO\n",t);
        return;
    } else {
        string curTwo="1";
        for (int i=0;i<s.size();i++) {
            string s1="";
            s1+=s[i];
            curTwo=a[curTwo][s1];
        }
        string res=cur;
        bool sign=true;
        if (curTwo[0]=='-') {
            string curTwoNew="";
            curTwoNew+=curTwo[1];
            curTwo=curTwoNew;
            if (x%2 != 0) {
                sign=false;
            }
        }

        for (int i=0;i<(x%4);i++)
            res=a[res][curTwo];
        if (sign && res=="k") {
            printf("Case #%d: YES\n",t);
            return;
        } else if (!sign && res=="-k") {
            printf("Case #%d: YES\n",t);
            return;
        } else {
            printf("Case #%d: NO\n",t);
            return;
        }
    }
}

int main(int argc, char** argv) {
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int T;
    cin>>T;
    a["1"]["1"]="1";
    a["1"]["i"]="i";
    a["1"]["j"]="j";
    a["1"]["k"]="k";
    a["i"]["1"]="i";
    a["i"]["i"]="-1";
    a["i"]["j"]="k";
    a["i"]["k"]="-j";
    a["j"]["1"]="j";
    a["j"]["i"]="-k";
    a["j"]["j"]="-1";
    a["j"]["k"]="i";
    a["k"]["1"]="k";
    a["k"]["i"]="j";
    a["k"]["j"]="-i";
    a["k"]["k"]="-1";
    a["-1"]["1"]="-1";
    a["-1"]["i"]="-i";
    a["-1"]["j"]="-j";
    a["-1"]["k"]="-k";
    a["-i"]["1"]="-i";
    a["-i"]["i"]="1";
    a["-i"]["j"]="-k";
    a["-i"]["k"]="j";
    a["-j"]["1"]="-j";
    a["-j"]["i"]="k";
    a["-j"]["j"]="1";
    a["-j"]["k"]="-i";
    a["-k"]["1"]="-k";
    a["-k"]["i"]="-j";
    a["-k"]["j"]="i";
    a["-k"]["k"]="1";
    for (int i=0;i<T;i++)
        solve(i+1);
    return 0;
}