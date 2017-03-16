#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

char m[] = "yhesocvxduiglbkrztnwjpfmaq";
char s[1000];

int main()
{
    freopen("A-small-attempt0.in", "rt", stdin);
    freopen("A-small-attempt0.out", "wt", stdout);
    int T;
    cin>>T;
    getchar();
    for (int cas=1; cas<=T; ++cas)
    {
        cin.getline(s,999,'\n');
        for (int i=0; s[i]; ++i) if (isalpha(s[i])) s[i] = m[s[i]-'a'];
        printf("Case #%d: %s\n", cas, s);
    }
    return 0;
}
