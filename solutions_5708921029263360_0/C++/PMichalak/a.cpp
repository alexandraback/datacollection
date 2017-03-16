#include<bits/stdc++.h>
#define ALL(X)        X.begin(),X.end()
#define FOR(I,A,B)    for(int (I) = (A); (I) <= (B); (I)++)
#define FORW(I,A,B)   for(int (I) = (A); (I) < (B);  (I)++)
#define FORD(I,A,B)   for(int (I) = (A); (I) >= (B); (I)--)
#define CLEAR(X)      memset(X,0,sizeof(X))
#define SIZE(X)       int(X.size())
#define CONTAINS(A,X) (A.find(X) != A.end())
#define PB            push_back
#define MP            make_pair
#define X             first
#define Y             second
using namespace std;
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U> &_p) { return os << "(" << _p.X << "," << _p.Y << ")"; }
template<typename T> ostream& operator << (ostream &os, const vector<T>& _V) { bool f = true; os << "["; for(auto v: _V) { os << (f ? "" : ",") << v; f = false; } return os << "]"; }
template<typename T> ostream& operator << (ostream &os, const set<T>& _S) { bool f = true; os << "("; for(auto s: _S) { os << (f ? "" : ",") << s; f = false; } return os << ")"; }
template<typename T, typename U> ostream& operator << (ostream &os, const map<T, U>& _M) { return os << set<pair<T, U>>(ALL(_M)); }
typedef signed long long slong;
typedef long double ldouble;
const slong INF = 1000000100;
const ldouble EPS = 1e-9;

int A, B, C, K;

void read_data() {
    scanf("%d %d %d %d", &A, &B, &C, &K);
}

vector<tuple<int, int, int>> Result;
vector<tuple<int, int, int>> Stack;
int AB[10][10], BC[10][10], AC[10][10];
int ABC[10][10][10];

void dfs(int ma = 0, int mb = 0, int mc = 0) {
    if(SIZE(Stack) > SIZE(Result)) {
        Result = Stack;
    }
    FOR(a,1,A) FOR(b,1,B) FOR(c,1,C) if(make_tuple(a, b, c) > make_tuple(ma, mb, mc)) {
        if(ABC[a][b][c] == 0 and AB[a][b] < K and BC[b][c] < K and AC[a][c] < K) {
            ++AB[a][b];
            ++AC[a][c];
            ++BC[b][c];
            ++ABC[a][b][c];
            Stack.emplace_back(a, b, c);
            
            dfs(a, b, c);

            Stack.pop_back();
            --AB[a][b];
            --AC[a][c];
            --BC[b][c];
            --ABC[a][b][c];
        }
    }
}

void solve() {
    Result.clear();
    Stack.clear();
    CLEAR(AB);
    CLEAR(BC);
    CLEAR(AC);
    CLEAR(ABC);
    dfs();
    printf("%d\n", SIZE(Result));
    for(auto &row: Result) {
        int a, b, c;
        tie(a, b, c) = row;
        printf("%d %d %d\n", a, b, c);
    }
}

int main() {
    int z;
    scanf("%d", &z);
    FOR(test_id,1,z) {
        printf("Case #%d: ", test_id);
        cerr << "Done: " << test_id << endl;
        read_data();
        solve();
        printf("\n");
    }
}
