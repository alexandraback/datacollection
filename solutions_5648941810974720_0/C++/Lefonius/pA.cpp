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


const int L = 128;
char str[5000];

int main() {
    int T;
    R(T);

    for (int t=1; t<=T; t++) {
        R(str);
        int cnt[L]={};
        for (int i=0; str[i]; i++)
            cnt[str[i]]++;

        printf("Case #%d: ", t);

        while (cnt['Z'] && cnt['E'] && cnt['R'] && cnt['O']) { // Z
            cnt[0]++;
            cnt['Z']--; cnt['E']--; cnt['R']--; cnt['O']--;
        }
        while (cnt['T'] && cnt['W'] && cnt['O']) { // W
            cnt[2]++;
            cnt['T']--; cnt['W']--; cnt['O']--;
        }
        while (cnt['S'] && cnt['I'] && cnt['X']) { // X
            cnt[6]++;
            cnt['S']--; cnt['I']--; cnt['X']--;
        }
        while (cnt['E'] && cnt['I'] && cnt['G'] && cnt['H'] && cnt['T']) { // G
            cnt[8]++;
            cnt['E']--; cnt['I']--; cnt['G']--; cnt['H']--; cnt['T']--;
        }
        while (cnt['S'] && cnt['E']>=2 && cnt['V'] && cnt['N']) { // S
            cnt[7]++;
            cnt['S']--; cnt['E']-=2; cnt['V']--; cnt['N']--;
        }
        while (cnt['F'] && cnt['I'] && cnt['V'] && cnt['E']) { // V
            cnt[5]++;
            cnt['F']--; cnt['I']--; cnt['V']--; cnt['E']--;
        }
        while (cnt['F'] && cnt['O'] && cnt['U'] && cnt['R']) { // F
            cnt[4]++;
            cnt['F']--; cnt['O']--; cnt['U']--; cnt['R']--;
        }
        while (cnt['N']>=2 && cnt['I'] && cnt['E']) { // I
            cnt[9]++;
            cnt['N']-=2; cnt['I']--; cnt['E']--;
        }
        while (cnt['T'] && cnt['H'] && cnt['R'] && cnt['E']>=2) { // T
            cnt[3]++;
            cnt['T']--; cnt['H']--; cnt['R']--; cnt['E']-=2;
        }
        while (cnt['O'] && cnt['N'] && cnt['E']) { // O
            cnt[1]++;
            cnt['O']--; cnt['N']--; cnt['E']--;
        }

        for (int i=0; i<10; i++)
            while (cnt[i]) {
                putchar('0'+i);
                cnt[i]--;
            }

        puts("");

    }

    return 0;
}
