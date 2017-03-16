#define DINGER_GISBAR
#include <bits/stdc++.h>
using namespace std;
const long long MOD = static_cast<int>(1e9) + 7;
//{{{TEMPLATE_BEGIN
#include <unistd.h>
using namespace std::rel_ops;
#ifdef ZEROKUGI
#include <dumper.hpp>
#define dump(x) dumper::dumper(cerr, __LINE__, (#x), (x), 50, 1, 1)
#define tick(...) dumper::tick(__VA_ARGS__)
#pragma message "Compiling " __FILE__
#else
#define dump(x)
#define tick(...)
#endif
typedef long long lint;
typedef unsigned long long ulint;
typedef long double ldouble;
typedef vector<int> vint;
#define rep(i,n) for(int i=0,i##_len=static_cast<int>(n);i<i##_len;i++)
#define all(c) begin(c),end(c)
#define perm(c) sort(all(c));for(bool c##p=1;c##p;c##p=next_permutation(all(c)))
#define uniquenize(v) (v).erase(unique(all(v)), end(v))
#define size(c) (int)((c).size())
#define cauto const auto&
#define memset(x,y) memset(x,y,sizeof(x))
#define popcount __builtin_popcount
#define gcd __gcd
inline lint bit(int x){return 1LL<<x;}
template<class T>inline bool chmin(T&a,const T&b){return a>b?a=b,1:0;}
template<class T>inline bool chmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline pair<vector<T>,char>operator*(const vector<T>&v,const char&c)
{return make_pair(v, c);}
template<class T>inline istream&operator>>(istream&is,vector<T>&v){
#ifdef ZEROKUGI
if(v.empty()){cerr<<"Error L"<<__LINE__<<": vector size is zero."<<endl;
exit(EXIT_FAILURE);}
#endif
for(auto&x:v)is>>x;return is;}
template<class T>inline ostream&operator<<(ostream&os,const pair<vector<T>,char>&v)
{bool t=0;for(const T&x:v.first){if(t)os<<v.second;os<<x;t=1;}return os;}
template<class T>inline ostream&operator<<(ostream&os,vector<T>&v){return os<<v*' ';}
struct before_main{before_main()
{cin.tie(0);ios::sync_with_stdio(0);cout<<fixed<<setprecision(20);tick(0,0);};}__before_main;
//}}}TEMPLATE_END

lint interpret_as(lint x, int base){
    lint res = 0;
    return res;
}

//1xxxxxxx1
//11 100 -> 1100
//11 1000000000000001 (l15)

const int N = 32;
const int SIZE = 500;
set<string> S;

void generate(){
    vector<string> res;
    string str(N-1, '0');
    str[0] = str.back() = '1';
    while(size(S) < SIZE){
        string s = str;
        for(int i = 2; i < N-3; i++){
            if(rand()%2){
                s[i]++;
                i++;
            }
        }
        S.insert(s);
    }
}

int main(){
    //small
    vector<int> a = {3, 4, 5, 6, 7, 8, 9, 10, 11};
    generate();
    cout << "Case #1:" << endl;
    for(auto s: S){
        string ans(N, '0');
        for(int i = 0; i < N-1; i++){
            if(s[i] == '1'){
                ans[i] = ans[i+1] = '1';
            }
        }
        cout << ans;
        for(auto x:a) cout << " " << x;
        cout << endl;
    }
}

