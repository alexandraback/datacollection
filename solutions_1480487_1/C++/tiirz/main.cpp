//#pragma comment (linker, "/STACK:64000000")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <typeinfo>
#include <set>
#include <cctype>
#include <locale>
#include <utility>
#include <map>
#include <iterator>
#include <valarray>
#include <complex>
#include <sstream>
#include <bitset>
#include <ctime>
#include <list>
#include <numeric>
#include <cstring>
using namespace std;

/*
#include <unordered_map>
#include <unordered_set>
#include <regex>
*/
#define sz size()
#define pb push_back
#define ppb pop_back
#define all(c) (c).begin(), (c).end()
#define sqr(a) (a)*(a)
#define mp make_pair
#define rall(c) (c).rbegin(), (c).rend()



typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<vector<int> > vvint;
typedef vector<char> vchar;
typedef vector<vector<int> > graph;
typedef pair<pair<long long,long long>,pair<long long,long long> > matrix;
const int INF=1<<30;

int in() {
    int a;
    scanf("%d", &a);
    return a;
}

double din() {
    double a;
    scanf("%lf", &a);
    return a;
}

int gcd(int a, int b) {
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}


int logbin(int a){
    a--;
    int res=1;
    while(a) a>>=1, res<<=1;
    return res;
}

vector<int> getz (string s) {
    int n = s.size();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}
vector<int> getpf (string s) {
    int n = s.size();
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi;
}
struct treap{
    int x,y;
    treap *l,*r;
    int size;
};
void recalc(treap *&a){
    if(a==NULL) return ;
    int res=0;
    if(a->l!=NULL) res+=a->l->size;
    if(a->r!=NULL) res+=a->r->size;
    a->size=res+1;
}

treap* Merge(treap* a,treap* b){
    if(a==NULL) return b;
    if(b==NULL) return a;
    treap *ne=NULL;
    if(a->y < b->y){
        ne=a;
        a->r=Merge(a->r, b);
    }else{
        ne=b;
        b->l=Merge(a, b->l);
    }
    recalc (ne);
    return ne;
}
void split(treap* v,int x,treap* &l,treap* &r){
    if(v==NULL){
        l=r=NULL;
        return;
    }
    int n=l->size+1;
    if(n <= x){
        split(v->r, x - n, v->r ,r);
        l=v;
        recalc(l);
    }else{
        split(v->l, n - x, l, v->l);
        r=v;
        recalc(r);
    }
}
void dfs(treap *v){
    if(v->l!=NULL) dfs(v->l);
    cout<<v->x<<' ';
    if(v->r!=NULL) dfs(v->r);
}

long long LINF=1ll<<61;
ll mod=1000000007;
matrix mu(matrix a, matrix b){
    matrix c;
    c.first.first=(a.first.first*b.first.first%mod+a.first.second*b.second.first%mod)%mod;
    c.first.second=(a.first.first*b.first.second%mod+a.first.second*b.second.second%mod)%mod;
    c.second.first=(a.second.first*b.first.first%mod+a.second.second*b.second.first%mod)%mod;
    c.second.second=(a.second.first*b.first.second%mod+a.second.second*b.second.second%mod)%mod;
    return c;
}

matrix binpow (matrix a, long long n) {
    matrix res ;
    res.first.first=1;
    res.first.second=0;
    res.second.first=0;
    res.second.second=1;
    while (n) {
        if (n & 1)
            res=mu(res,a);
        a=mu(a,a);
        n >>= 1;
    }
    return res;
}
const double eps = 1e-8;

int main(){
    freopen("aa6.in","r",stdin);
     freopen("output.txt","w",stdout);
    int T=in();
    for(int t=1;t<=T;++t){
        int n=in();
        vector<int> a;
        vector<double> res;
        int sum=0;
        for(int i=0;i<n;++i) a.push_back (in()), sum+=a[i];
        printf("Case #%d: ",t);

        for(int i=0;i<n;++i){
            double l=0,r=1;
            while(fabsl (l-r)>=eps){
                double p=l+(r-l)/2;
                double m=1-p, score=a[i]+sum*p;
                double cons;
                bool o=1;
                double uru=0;
                for(int j=0;j<n;++j){
                    if(j==i) continue;
                    if(score<a[j]) continue;
                    cons=(score-a[j])/sum;
                    uru+=cons;
                }
                if(uru>m)o=0;
                if(o){
                    l=p;
                }else r=p;
            }
            printf("%.10lf ",r*100.);

        }
        cout<<endl;
    }


  /*  int T=in();
    for(int t=1;t<=T;++t){
        int n=in();
        vector<int> a;
        for(int i=0;i<n;++i) a.push_back (in());



   }*/


    return 0;
}






/* int n=in(),m=in();
treap *tr=NULL;
srand(time(NULL));
for(int i=0;i<n;++i){
    treap *b=new treap();
    b->y=rand();
    b->l=b->r=NULL;
    b->x=i+1;
    Merge (tr,b);
}
for(int i=0;i<m;++i){
    int a=in()-1,b=in()-1;
    treap *c,*d,*e,*h;
    split(tr,b,c,d);
    split(c,a,e,h);
    tr=Merge(h,e);
    tr=Merge(tr,d);
}
dfs(tr);*/
