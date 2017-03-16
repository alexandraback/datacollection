#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int t, x, w;
string s;
bool first;

int main() {
    int i, j;
    scanf("%d", &t);
    for (i=0; i<t; ++i) {
        cin>>s;
        first = 0;
        x=1;
        if (s[0] == '+') {
            first = 1;
            x=0;
        }
        for (j=1; j<s.length(); ++j) {
            if (s[j] == '-' && s[j-1] == '+') {
                x++;
            }
        }
        w=2*x;
        if (!first) {
            w--;
        }
        printf("Case #%d: %d\n", i+1, w);
    }
    return 0;
}
