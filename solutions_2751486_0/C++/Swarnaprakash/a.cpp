// Author: Swarnaprakash
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>

using namespace std;

const int M = 105;
const int INF = 0x3f3f3f3f;
const bool debug=true;

#define SET(x,v)	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define SZ(x)		((int)((x).size()))
#define DB(x) 		if(debug) cout << #x << " : " << x <<endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

char name[M];
int n;

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int t=1;t<=tc;++t) {
        scanf("%s %d", name, &n);

        int len=strlen(name);
        int ans=0;
        for (int i=0;i<len;++i)
            for(int j=i;j<len;++j) {
                int cons = 0;
                int max_cons = 0;
                for(int k=i;k<=j;++k) {
                    if(is_vowel(name[k])) {
                        cons = 0;
                    } else {
                        ++cons;
                        max_cons = max(max_cons, cons);
                    }
                }
                if(max_cons >=n) ++ans;
            }

        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}

