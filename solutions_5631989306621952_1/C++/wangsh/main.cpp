#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

//global constants
const int INF = 1<<29;
const double EPS = 1e-8;
typedef __int64 LL;

//local constants
const int N = 1010;
char s[N];

int main()
{
    freopen("A-large.in","r",stdin);
//    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t, cas = 0;
    scanf(" %d ", &t);
    while (t--) {
        scanf(" %s ", s);
//        printf("%s\n", s);
        string ret = "";
        ret += s[0];
        for (int i = 1; s[i] != '\0'; ++i) {
//            printf("%s\n", ret.c_str());
            if (s[i] < ret[0]) ret += s[i];
            else ret = s[i] + ret;
        }
        printf("Case #%d: %s\n", ++cas, ret.c_str());
    }
    return 0;
}
