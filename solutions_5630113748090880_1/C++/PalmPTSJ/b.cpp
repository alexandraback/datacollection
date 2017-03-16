// Version 3.12
#define TESTCASE true
#define DEBUG false
#define GCJ_TESTCASE true

#include <bits/stdc++.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#define forn(s,t) for(int s = 0;s < t;s++)
#define forr(i,s,e) for(int i = s;i < e;i++)
#define forn1(s,t) for(int s = 1;s <= t;s++)

#define forIn(a,v) for(int a = 0;a < v.size();a++)
#define forIt(t,a,v) for(t::iterator a = v.begin();a != v.end();++a) // forIt(type,var,container) -> forIt(vector<int>,a,V)

#define EL printf("\n");

#define gcd(a,b) __gcd(a,b) // GNU GCC only !

#define MIN_HEAP true
#define MAX_HEAP false

#define pii pair<int,int>
#define plli pair<lli,lli>
#define vi vector<int>
#define vlli vector<lli>
#define vs vector<string>
#define vec vector
#define all(v) v.begin(),v.end()
#define gint(a) int a = getInt();

typedef long long int lli;
typedef unsigned long long int ulli;
using namespace std;

class scanner { public :
    scanner& operator >>(int& t) { scanf("%d",&t); return *this; };
    scanner& operator >>(double& t) { scanf("%lf",&t); return *this; };
    scanner& operator >>(string& t) { scanf("%s",buf); t=buf; return *this; };
    scanner& operator >>(lli& t) { scanf("%lld",&t); return *this; };
    scanner& operator >>(char& t) { scanf("%s",buf); t=buf[0]; return *this; };
    template<class t> scanner& operator >>(vec<t> &V) { forn(i,V.size()) *this >> V[i];}
    template<class t,class t2> scanner& operator >>(pair<t,t2> &p) { *this >> p.first >> p.second; }
    string scanln() { string t = ""; while(t.size()==0) getline(cin,t); return t; };
    char buf[100010];
} scan;
class outputter { public :
    outputter& operator <<(int t) { printf("%d",t); return *this; };
    outputter& operator <<(unsigned int t) { printf("%u",t); return *this; };
    outputter& operator <<(double t) { printf("%lf",t); return *this; };
    outputter& operator <<(string t) { printf("%s",t.c_str()); return *this; };
    outputter& operator <<(lli t) { printf("%lld",t); return *this; };
    outputter& operator <<(char t) { putchar(t); return *this; };
    template<class t> outputter& operator <<(vec<t> V) { forn(i,V.size()) *this << V[i] << " "; return *this; }
} print;

int getInt() { int a; scanf("%d",&a); return a; }
void getInt(int& a) { scanf("%d",&a); }
lli getLLI() { lli a; scanf("%lld",&a); return a; }
double getDouble() { double a; scanf("%lf",&a);return a; }
void getDouble(double& a) { scanf("%lf",&a); }

template<class t> void getArray(t *arr,int size) { forn(i,size) scan >> arr[i]; }
template<class t> void getArray(t **arr,int N,int M) { forn(i,N) forn(j,M) scan >> arr[i][j]; }
template<class t> void getArray(t ***arr,int N,int M,int L) { forn(i,N) forn(j,M) forn(k,L) scan >> arr[i][j][k]; }
template<class t> vec<t> getVector(int N) { vec<t> V; V.resize(N); forn(i,N) scan >> V[i]; return V;}
template<class t> void getVector(vec<t> &V,int N) { V.resize(N); forn(i,N) scan >> V[i];}
template<class t> void getVectorUntil(vec<t> &V,t x) { V.erase(); while(true) {t e; scan >> e; if(e==x) break; V.push_back(e);} }
template<class t> vec<t> getVectorUntil(t x) { vec<t> V; while(true) {t e; scan >> e; if(e==x) break; V.push_back(e);} return V; }

template<class t> void printArray(t* arr,int size) { forn(i,size) print << arr[i] << " "; }
template<class t> void printArray(t **arr,int N,int M) { forn(i,N) { forn(j,M) print << arr[i][j] << " "; printf("\n");}}
template<class t> void printVector(vec<t> &V) { forn(i,V.size()) print << V[i] << " "; } /// == print << V

template<class t> void setArray(t* arr,int size,t v) { forn(i,size) arr[i] = v;}
template<class t> void setArray(t** arr,int N,int M,t v) { forn(i,N) forn(j,M) arr[i] = v;}
template<class t> void setArray(t*** arr,int N,int M,int L,t v) { forn(i,N) forn(j,M) forn(k,L) arr[i] = v;}
template<class t> t* carray(int N) { return (t*)calloc(sizeof(t),N); }
template<class t> t** carray(int N,int M) { t** toRet = (t**)calloc(sizeof(t*),N); forn(i,N) toRet[i] = carray<t>(M); return toRet; }
template<class t> t*** carray(int N,int M,int L) { t*** toRet = (t***)calloc(sizeof(t**),N); forn(i,N) toRet[i] = carray<t>(M,L); return toRet; }
template<class t> void freeMatr(t** matr,int N,int M) { forn(i,N) free(matr[i]); free(matr); }
template<class t> void freeMatr(t*** matr,int N,int M,int L) { forn(i,N) freeMatr(matr[i],M,L); free(matr); }
#define freeArray freeMatr

template<class t> void sortUp(t* arr,int n) { sort(arr,&arr[n]); }
template<class t> void sortUp(vector<t> &V) { sort(all(V)); }
template<class t> void sortDown(t* arr,int n) { sort(arr,&arr[n],greater<t>()); }
template<class t> void sortDown(vector<t> &V) { sort(all(V),greater<t>()); }

template<class t> vector<t> subvector(vector<t> &V,int st,int len) { return vector<t>(V.begin()+st,V.begin()+st+len); }
template<class t> void append(vector<t> &V,vector<t> &S) { V.insert(V.end(),S.begin(),S.end()); }
template<class t> void operator+=(vector<t>& V,t i) { V.push_back(i); }
template<class t> void operator+=(vector<t>& V,vector<t>& a) { append(V,a); }
template<class t1,class t2> void operator+=(map<t1,t2> &MP,pair<t1,t2> &el) { MP.insert(el); }
template<class t> void operator+=(set<t> &S,t x) { S.insert(x); }
template<class t> void operator-=(vector<t>& V,int ind) { V.erase(V.begin()+ind); }

vs split(const string &s, char delim) { vs elems; stringstream ss(s); string item; while(getline(ss,item,delim)) elems+=(item); return elems; }

template<class t> string operator+(string str,t x) {ostringstream ss; ss << str << x; return ss.str();} /// [py] "ab"+50 = "ab50"
string operator*(string str,int c) { string toRet = str;for(int i = 1;i < c;i++) toRet += str;return toRet;} /// [py] "ab"*3 = "ababab"
string operator/(string str,string cmd) { /// [py] "abc"/"::-1" = "cba"
    vs args = split(cmd,':'); if(cmd[cmd.size()-1] == ':') args += string("");
    string toRet = ""; bool om[3] = {true,true,true};int num[3] = {0,0,0};
    if(args.size() == 1) {if(args[0].size() > 0) {om[0] = false; num[0] = strtol(args[0].c_str(),NULL,10);}if(!om[0]) toRet += str[num[0]];}
    else if(args.size() == 2){ if(args[0].size() > 0) {om[0] = false; num[0] = strtol(args[0].c_str(),NULL,10);}
        if(args[1].size() > 0) {om[1] = false; num[1] = strtol(args[1].c_str(),NULL,10);}
        int S = 0,E = str.size(); if(!om[0]) S = num[0]; if(!om[1]) E = num[1]>=0?num[1]-S:str.size()+num[1]-S; toRet += str.substr(S,E);
    }
    else { if(args[0].size() > 0) {om[0] = false; num[0] = strtol(args[0].c_str(),NULL,10);}
        if(args[1].size() > 0) {om[1] = false; num[1] = strtol(args[1].c_str(),NULL,10);}
        if(args[2].size() > 0) {om[2] = false; num[2] = strtol(args[2].c_str(),NULL,10);}
        int S = 0,E = str.size(),ST = 1; if(!om[0]) S = num[0]; if(!om[1]) E = num[1]>=0?num[1]-S:str.size()+num[1]-S;
        if(!om[2]) { ST = num[2]; if(ST < 0) { if(om[0]) S = str.size()-1; if(om[1]) E = -1; for(int i = S;i > E;i += ST) toRet += str[i];}
            else if(ST == 0) return ""; else for(int i = S;i < E;i += ST) toRet += str[i]; }
        else for(int i = S;i < E;i += ST) toRet += str[i];}
    return toRet;
}

inline bool validPos(int x,int y,int w,int h) { return !(x<0||y<0||x>=w||y>=h); }
ulli fac(int n) { ulli toRet = 1; forr(i,2,n+1) toRet *= i; return toRet; }
lli gcdSlow(lli a,lli b) { if(a>=b) { if(a%b) return gcdSlow(b,a%b); return b; } else { if(b%a) return gcdSlow(a,b%a); return a; }} /// [SLOW] use __gcd (gcc only)
inline lli lcmSlow(lli a,lli b) { return a*b/gcdSlow(a,b); } /// [SLOW] use lcm (gcc only)
inline lli lcm(lli a,lli b) { return a*b/gcd(a,b); }
ulli C(int n,int r) {  ulli t = 1; for(int i = r+1;i <= n;i++) t *= i; for(int i = 2;i <= n-r;i++) t/= i; return t; } /// n!/r!(n-r)!
ulli P(int n,int r) { ulli t = 1; for(int i = n-r+1;i <= n;i++) t *= i; return t; } /// n!/(n-r)!
lli pow10(int n) { lli toRet = 1; forn(i,n) toRet*=10; return toRet; }
lli pow(int b,int e) { lli toRet = 1; forn(i,e) toRet*=b; return toRet; }
int getDig(lli num,int d) { return (num/pow10(d))%10; }
bool deq(double a,double b) { return fabs(a-b)<=0.00000001; } /// 1*10^-8
vi primeList(int n) { vi T; bool* A = carray<bool>(n+1); forr(i,2,n+1) {if(!A[i]) {T.push_back(i); for(int j = i*2;j<=n;j+=i) A[j] = true;}} free(A); return T;}
lli bitshiftRight(lli x,int n) {assert(n<64); return x>>n;}
lli bitshiftLeft(lli x,int n){assert(n<64); return x<<n;}
lli pow2(int n){assert(n<64); return lli(1)<<n;}
vi factor(int x){vi T; forn1(i,x) {if(x/i<i) break; if(x%i==0) {T+=i; if(x/i>i) T+=x/i;}} return T;} /// not sorted !
template<class t> t max(vec<t> V) { assert(V.size()>0); t T = V[0]; forn(i,V.size()) if(T<V[i]) T=V[i]; return T;}
template<class t> t min(vec<t> V) { assert(V.size()>0); t T = V[0]; forn(i,V.size()) if(T>V[i]) T=V[i]; return T;}
template<class t> t sum(vec<t> V) { assert(V.size()>0); t T = V[0]; forr(i,1,V.size()) T+=V[i]; return T;}

template<class t> bool has(t x,vector<t> c) { return find(c.begin(),c.end(),x)!=c.end(); }
template<class t,class mp> bool has(t x,mp m) { return m.count(x)>0; }

vi powerSet(lli bits) { vi toRet; for(int i = 0;i < 60;i++) if(bits & (lli(1)<<i)) toRet += i; return toRet; }

template<class t> class heap { public :
    heap(bool a = true) { minHeap = !a; } /// true = minHeap , false = maxHeap
    void push(t data) { V.push_back(data); if(minHeap) push_heap(all(V)); else push_heap(all(V),greater<t>()); }
    void operator+=(t data) { push(data); }
    void operator+=(heap& oth) { forn(i,oth.V.size()) push(oth.V[i]);}
    t operator[](int ind) { return V[ind];}
    bool empty() { return V.size()==0;}
    t pop() { assert(!empty()); t toRet = V[0]; if(minHeap) pop_heap(all(V)); else pop_heap(all(V),greater<t>()); V.pop_back(); return toRet; }
    bool minHeap;
    vec<t> V;
};
template<class t> class customHeap { public :
    customHeap(bool (*f)(const t& a,const t& b)) { cmpFunc = f; }
    void push(t data) { (heap<t>::V).push_back(data); push_heap(all(V),cmpFunc); }
    void operator+=(t data) { push(data); }
    void operator+=(customHeap& oth) { forn(i,oth.V.size()) push(oth.V[i]);}
    t operator[](int ind) { return V[ind];}
    bool empty() { return V.size()==0;}
    t pop() {assert(!empty()); t toRet = V[0]; pop_heap(all(V),cmpFunc); V.pop_back(); return toRet;}
    bool (*cmpFunc)(const t& a,const t& b);
    vec<t> V;
};
class fenwickTree { public : // 1-index
    fenwickTree(int N) {n=N; arr = carray<lli>(n+1);}
    ~fenwickTree() {free(arr);}
    void update(int ind,lli val) {while(ind <= n) {arr[ind] += val;ind += ind & -ind;}}
    lli query(int ind) {lli toRet = 0; while(ind > 0) { toRet += arr[ind]; ind -= ind&-ind; } return toRet;}
    lli queryRange(int ind1,int ind2) { return query(ind2)-query(ind1-1);}
    lli* arr;
    int n;
};

class graph { public :
    graph(int N) {n=N; m=0; V = carray<vector<plli> >(n); visited = carray<bool>(n);}
    ~graph() { free(V); }
    void addEdge(int from,int to,int weight) { V[from] += plli(to,weight); m++; }
    void scanEdge(int m) {forn(i,m) {lli a,b,w; scan >> a >> b >> w; a--; b--; addEdge(a,b,w);} }
    void scanEdge0(int m) { forn(i,m) {lli a,b,w; scan >> a >> b >> w; addEdge(a,b,w);} }
    lli shortestPath(int source,int targ) {
        heap<plli> hp(MIN_HEAP);
        hp.push(plli(0,source));
        setArray(visited,n,false);
        while(!hp.empty()) {
            plli data = hp.pop();
            lli id = data.second;
            lli score = data.first;
            if(visited[id]) continue;
            visited[id] = true;
            if(id == targ) return score;
            forIn(i,V[id]) {
                if(!visited[V[id][i].first]) hp.push(plli(score+V[id][i].second,V[id][i].first));
            }
        }
        return -1;
    }
    vector<plli> *V;
    bool *visited;
    int n,m;
};
class graphUnd : public graph { public :
    graphUnd(int N):graph(N) { }
    ~graphUnd() { }
    void addEdge(int from,int to,int weight) { graph::addEdge(from,to,weight); graph::addEdge(to,from,weight); }
    void scanEdge(int m) {forn(i,m) {lli a,b,w; scan >> a >> b >> w; a--; b--; addEdge(a,b,w); } }
    void scanEdge0(int m) { forn(i,m) {lli a,b,w; scan >> a >> b >> w; addEdge(a,b,w);} }
};
class graphUnw : public graph { public :
    graphUnw(int N):graph(N) { }
    ~graphUnw() { }
    void addEdge(int from,int to) { graph::addEdge(from,to,1);}
    void scanEdge(int m) {forn(i,m) {lli a,b; scan >> a >> b; a--; b--; addEdge(a,b); } }
    void scanEdge0(int m) { forn(i,m) {lli a,b; scan >> a >> b; addEdge(a,b);} }
    lli shortestPath(int source,int targ) {
        queue<plli> Q;
        Q.push(plli(0,source));
        setArray(visited,n,false);
        while(!Q.empty()) {
            plli data = Q.front();
            Q.pop();
            lli id = data.second;
            lli score = data.first;
            if(visited[id]) continue;
            visited[id] = true;
            if(id == targ) return score;
            forIn(i,V[id]) {
                if(!visited[V[id][i].first]) Q.push(plli(score+1,V[id][i].first));
            }
        }
        return -1;
    }
};
class graphUnwUnd : public graphUnw { public :
    graphUnwUnd(int N) : graphUnw(N) {}
    ~graphUnwUnd() {}
    void addEdge(int from,int to) { graph::addEdge(from,to,1); graph::addEdge(to,from,1);}
    void scanEdge(int m) {forn(i,m) {lli a,b; scan >> a >> b; a--; b--; addEdge(a,b); } }
    void scanEdge0(int m) { forn(i,m) {lli a,b; scan >> a >> b; addEdge(a,b);} }
};
typedef graphUnwUnd graphUndUnw; // name swap l0l

int bucket[3000];

void solve()
{
    int n;
    scan >> n;
    forn(i,3000) bucket[i] = 0;
    for(int i = 0;i < 2*n-1;i++) {
        for(int j = 0;j < n;j++) {
            int x = getInt();
            bucket[x]++;
        }
    }
    for(int i = 0;i < 3000;i++) {
        if(bucket[i] != 0 && bucket[i] % 2 == 1) {
            printf("%d ",i);
        }
    }
    printf("\n");
}

int main()
{
    if(TESTCASE) {
        int t,tt;
        scanf("%d",&tt);
        for(t=0;t < tt;t++)
        {
            if(GCJ_TESTCASE) printf("Case #%d: ",t+1);
            solve();
        }
    } else {
        solve();
    }
}
