//T-shirt is honor for programmers!
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <sstream>
#define inf 1000000007
#define N 505
#define eps 1e-8
#define M 505
#define For(i,a,b) for(int i=(a);i<(b);i++)
#define Pi acos(-1.0)
using namespace std;
int n;
string s;

int calc(int a, int b) {
    int num = 0;
    int tmp = 0;
    for (int i = a; i < b; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            tmp = 0;
        } else
            tmp++;
        num = max(tmp, num);
    }
    return num;
}

int main(int argc, char** argv) {
    int T;
    freopen("123.txt","r",stdin);
    freopen("222.txt","w",stdout);
    scanf("%d", &T);
    int cs = 0;

    while (T--) {
        cs++;
        cin >> s >> n;
        int m = s.size();
        int ans = 0;

        For(i, 0, m) {

            For(j, i + n, m+1) {
//                cout<<i<<" "<<j<<" "<<calc(i,j)<<endl;
                if (calc(i, j) >= n)
                    ans++;
            }
        }
        printf("Case #%d: %d\n", cs, ans);
    }

    return 0;
}

