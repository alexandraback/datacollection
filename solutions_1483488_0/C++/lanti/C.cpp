// C.cpp
//
// Problem C. Recycled Numbers
//
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

typedef long long int64;

set<int> vset;

void solve(int tcase)
{
    int64 ans=0;
    int A, B; scanf("%d%d", &A, &B);
    for(int n=A; n<=B; ++n) {
        char s[10]; sprintf(s, "%d", n);
        int len=strlen(s);
        vset.clear();
        for(int i=0; i<len; ++i) {
            char ch = s[0];
            for(int p=1; p<len; ++p) s[p-1]=s[p];
            s[len-1]=ch;
            int m=0;
            for(int p=0; p<len; ++p) {
                m=m*10 + s[p]-'0';
            }
            if (n<m && m<=B) vset.insert(m);
        }
        ans+=(int64)vset.size();
    }
    printf("Case #%d: %lld\n", tcase, ans);
}

int main()
{
    int T; scanf("%d", &T);
    for(int t=1; t<=T; ++t) solve(t);
}
