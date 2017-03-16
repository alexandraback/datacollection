// {{{
#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define ALL(x) begin(x),end(x)
#define SZ(x) ((int)x.size())
#define REP(i,n) for(int i=0;i<n;i++)
#define REP2(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

#ifdef FEI
template<typename T>
void _dump(const char* s, T&& head) { cerr<<s<<"="<<head<<endl; }
template<typename T, typename... Args>
void _dump(const char* s, T&& head, Args&&... tail) {
    int c=0;
    while (*s!=',' || c!=0) {
        if (*s=='(' || *s=='[' || *s=='{') c++;
        if (*s==')' || *s==']' || *s=='}') c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _dump(s+1, tail...);
}

#define dump(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _dump(#__VA_ARGS__, ##__VA_ARGS__); \
} while(0);

template<typename Iter>
ostream& _out(ostream &s, Iter b, Iter e) {
    s<<'[';
    for (auto it=b; it!=e; it++) s<<(it==b?"":",")<<*it;
    s<<']';
    return s;
}

template<typename A, typename B>
ostream& operator <<(ostream &s, const pair<A,B> &p) { return s<<"("<<p.first<<","<<p.second<<")";}
template<typename T>
ostream& operator <<(ostream &s, const vector<T> &x) { return _out(s,ALL(x)); }
template<typename T, size_t N>
ostream& operator <<(ostream &s, const array<T,N> &x) { return _out(s,ALL(x)); }
template<typename T>
ostream& operator <<(ostream &s, const set<T> &x) { return _out(s,ALL(x)); }
template<typename A, typename B>
ostream& operator <<(ostream &s, const map<A,B> &x) { return _out(s,ALL(x)); }
#else
#define dump(...)
#endif

template<typename T>
void _R(T &x) { cin>>x; }
void _R(int &x) { scanf("%d",&x); }
void _R(LL &x) { scanf("%" PRId64,&x); }
void _R(double &x) { scanf("%lf",&x); }
void _R(char &x) { scanf(" %c",&x); }
void _R(char *x) { scanf("%s",x); }

void R(){}
template<typename T, typename... X>
void R(T& head, X&... tail) { _R(head); R(tail...); }
// }}}

const int N = 20;
char s1[N], s2[N];
int len;
int ans1, ans2, diff;

bool match(char* str, int v) {
    for (int i=len-1; i>=0; i--) {
        if (str[i] == '?');
        else if (str[i]-'0' != v%10) return 0;
        v /= 10;
    }
    return 1;
}

int main() {
    int T;
    R(T);

    for (int t=1; t<=T; t++) {
        R(s1, s2);
        int X = 1;
        len = strlen(s1);
        diff = 1<<20;

        for (int i=0; i<len; i++) X *= 10;
        dump(len, X);

        for (int i=0; i<X; i++)
            if (match(s1, i)) {
                for (int j=0; j<X; j++)
                    if (match(s2, j)) {
                        if (abs(i-j)<diff) {
                            diff = abs(i-j);
                            ans1 = i; ans2 = j;
                        }
                    }
            }
        char fmt[100];
        sprintf(fmt, "Case #%%d: %%0%dd %%0%dd\n", len, len);
        printf(fmt, t, ans1, ans2);

    }

    return 0;
}
