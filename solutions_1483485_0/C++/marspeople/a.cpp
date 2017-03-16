#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<(n); i++)
        // abcdefghijklmnopqrstuvwxyz
char mp[]="yhesocvxduiglbkrztnwjpfmaq";

int main() {
    int nt;
    char s[1000];

    scanf("%d",&nt);
    gets(s);
    for (int ct=1;ct<=nt;ct++) {
        gets(s);

        for (int i=0;s[i];i++)
            if (s[i]>='a')
                s[i]=mp[s[i]-'a'];

        printf("Case #%d: %s\n",ct,s);
    }
    return 0;
}

