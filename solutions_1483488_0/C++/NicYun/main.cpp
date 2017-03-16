#include <iostream>
#include <vector>
#include <set>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); ++i)

const int N = 128;

bool check(int a, int b){
    char s1[N], s2[N];
    sprintf(s1, "%d", a);
    sprintf(s2, "%d", b);
    int len = strlen(s1);
    for(int i = 0; i < len; i++){
        bool match = true;
        for(int j = 0; j < len; j++){
            if(s2[j] != s1[(i+j)%len]){
                match = false;
                break;
            }
        }
        if(match) return true;
    }
    return false;
}

set<pair<int, int> > st;

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int T, a, b;
    scanf("%d", &T);
    REP(t, T){
        st.clear();
        scanf("%d %d", &a, &b);
        int res = 0, tot = 1;
        while(a >= tot) tot *= 10;
        for(int i = a; i <= b; i++){
            for(int base = 10; base < tot; base *= 10){
                int remin = i % base;
                int tmp = remin * (tot / base) + i / base;
                if(tmp <= b && tmp > i) {
                    if(!check(i, tmp)){
                        cerr << i << " " << tmp << endl;
                    }
                    st.insert(make_pair(i, tmp));
                    res ++;
                }
            }
        }
        printf("Case #%d: %d\n", t + 1, st.size());
    }
    return 0;
}
