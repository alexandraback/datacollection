//
//  main.cpp
//  codejam
//
//  Created by Todor Lyubomirov Bonchev on 1/1/16.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int check(string a, string b) {
    int A = 0,B=0;
    for (int i=0;i<a.length();i++) {
        A*=10;
        A+=a[i]-'0';
        B*=10;
        B+=b[i]-'0';
    }
    return abs(A-B);
}

void solve() {
    string a,b;
    cin >> a >> b;
    string aa=a,bb=b;
    string amin, bmin;
    int minDiff = 10000;
    for (int i=0;i<10;++i) {
        if (a[0]=='?') aa[0]=i+'0';
        for (int j=0;j<10;++j) {
            if (a.length()>=2&&a[1]=='?')aa[1]=j+'0';
            for (int k=0;k<10;++k) {
                if (a.length()>=3&&a[2]=='?')aa[2]=k+'0';
                for (int ii=0;ii<10;++ii) {
                    if (b[0]=='?')bb[0]=ii+'0';
                    for (int jj=0;jj<10;++jj) {
                        if (b.length()>=2 &&b[1]=='?')bb[1]=jj+'0';
                        for (int kk=0;kk<10;++kk) {
                            if (b.length()>=3&&b[2]=='?')bb[2]=kk+'0';
                            int diff = check(aa,bb);
                            if (diff<minDiff) {
                                minDiff=diff;
                                amin=aa;
                                bmin=bb;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << amin << ' ' << bmin << endl;
}

int main(int argc, const char * argv[]) {
    freopen("a.txt", "r", stdin);
    freopen("b.txt", "w", stdout);

    int tests;
    scanf("%d", &tests);
    for (int test=1;test<=tests;++test) {
        printf("Case #%d: ", test);
        solve();
    }

    return 0;
}
