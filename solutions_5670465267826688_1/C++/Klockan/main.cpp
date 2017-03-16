#include <bits/stdc++.h>
#define M_PI    3.14159265358979323846  /* pi */
#define ff(i,s,n) for(int i=(s);i<(n);i++)
#define fr(i,s,n) for(int i=(n-1);i>=(s);i--)
#define FF(i,s,n) for(int i=(s);i<=(n);i++)
#define Fr(i,s,n) for(int i=(n);i>=(s);i--)
#define FR(i,s,n) for(int i=(n);i>=(s);i--)
#define all(a) a.begin(),a.end()
#define endl '\n'
#define tnm typename
#define invd inline void
#define templ1 template<tnm T>
#define btempl templ1 invd
#define ln prln()
#define sp prsp()
using namespace std;typedef int64_t ll;typedef unsigned int uint;
invd scan(int&i){scanf("%d",&i);}invd scan(double&i){scanf("%lf",&i);}invd scan(ll&i){scanf("%" PRId64 ,&i);}invd pr(string&s){cout<<s;}
template<typename T, typename V> invd scan(pair<T,V>&a){scan(a.first),scan(a.second);}
invd pr(char c){putchar(c);};invd pr(const char*c){while(*c!=0)putchar(*c++);}
invd pr(int i){printf("%d",i);}invd pr(bool b){pr((int)b);}invd pr(double d){printf("%.12lf",d);}invd prln(){putchar('\n');}invd prsp(){putchar(' ');}invd pr(ll i){printf("%" PRId64 ,i);}
invd pr(size_t i){pr((ll)i);}btempl scan(vector<T>&v){for(T&t:v)scan(t);}btempl scan(T*a,int n){while(n--)scan(*a++);}
template<class A, class B> invd pr(pair<A,B> a){pr(a.first),sp,pr(a.second);}
btempl prsp(vector<T>&v){for(T&t:v)pr(t),sp;}btempl prsp(T*a,int n){while(n--)pr(*a++),sp;}btempl prln(vector<T>&v){for(T&t:v)pr(t),ln;}
btempl prln(T*a,int n){while(n--)pr(*a++),ln;}btempl prln(vector<vector<T> >&v){for(vector<T>&t:v)prsp(t),ln;}
invd scan(string&s){int c;while((c=getchar())=='\n'||c==' '||c=='\r');do{switch(c){case'\n':case'\r':case' ':return;default:s+=c;}}while((c=getchar())!=EOF);};
btempl scan(char*s){int c;while((c=getchar())){switch(c){case'\n':case'\r':case' ':break;default:*s++=c;}}*s=0;};
template<typename T, typename... Args>invd scan(T&first, Args (&... args)) {scan(first),scan(args...);}
template<typename T, typename... Args>invd pr(T first, Args... args) {pr(first),sp,pr(args...);}
templ1 vector<T>& operator+=(vector<T>& v,T x) {v.push_back(x);return v;}
templ1 vector<T>& operator--(vector<T>& v) {v.pop_back();return v;}templ1 vector<T>& operator--(vector<T>& v,int) {v.pop_back();return v;}
templ1 bool operator!(stack<T>&q) {return !q.empty();}templ1 stack<T>& operator+=(stack<T>& v,T x) {v.push(x);return v;}
templ1 T operator--(stack<T>& v) {v.pop();return v.top();}templ1 T operator--(stack<T>& v,int) {T t=v.top();v.pop();return t;}
templ1 bool operator!(queue<T>&q) {return !q.empty();}templ1 queue<T>& operator+=(queue<T>& v,T x) {v.push(x);return v;}
templ1 T operator--(queue<T>& v) {v.pop();return v.front();}templ1 T operator--(queue<T>& v,int) {T t=v.front();v.pop();return t;}
template<tnm T,tnm U>invd smax(T&a,U b){if(b>a)a=b;}template<tnm T,tnm U>invd smin(T&a,U b){if(b<a)a=b;}
template<tnm T,tnm U>inline T gcd(T a, U b){return __gcd(a,b);}typedef vector<int> vi;typedef vector<vi > vvi;typedef pair<int, int> pii;typedef pair<ll,ll> pll;
typedef vector<pii > vpii;invd init();



struct quart{
  char val;
  bool sign;
  quart(int c, bool sign):val(c),sign(sign){}
  quart(char c='1'):sign(0){
    if(c=='1')val = 0;
    else if(c=='i')val = 1;
    else if(c=='j')val = 2;
    else if(c=='k')val = 3;
  }
  
  quart operator *(quart c){
    c.sign^=sign;
    if(!val)return c;
    if(!c.val)return {val,c.sign};
      
    int k = (c.val-val+3)%3;
    if(k==0)return {0,!c.sign};
    if(k==1)return {val^c.val,c.sign};
    if(k==2)return {val^c.val,!c.sign};
  }
  bool operator ==(quart c){
    return val==c.val&&sign==c.sign;
  }
  bool operator !=(quart c){
    return val!=c.val||sign!=c.sign;
  }
  
};

void pr(quart a){
  if(a.sign)putchar('-');
  else putchar(' ');
  switch(a.val){
    case 0:putchar('1');break;
    case 1:putchar('i');break;
    case 2:putchar('j');break;
    case 3:putchar('k');break;
  }
}



int mult(int a, int b){
  if(a==0)return b;
  if(a==b)return a;
}

int solve(){
  int L, X;
  quart a='i',b='j',c='k';
  scan(L,X);
  X--;
  string s;
  scan(s);
  vector<quart> v(L);
  ff(i,0,L)v[i]=s[i];
  int p = 0, ac=0;
  quart cur;
  while(cur!=a){
    cur=cur*v[p++];
    if(p==L)p=0,X--,ac++;
    if(X<0||ac>=4) return puts("NO"),0;
  }
  ac=0;
  cur='1';
  while(cur!=b){
    cur=cur*v[p++];
    if(p==L)p=0,X--,ac++;
    if(X<0||ac>=4) return puts("NO"),0;
  }
  cur='1';
  while(p<L){
    cur=cur*v[p++];
  }
  quart tot;
  ff(i,0,L){
    tot=tot*v[i];
  }
  X%=4;
  ff(i,0,X){
    cur=cur*tot;
  }
  if(X>=0&&cur==c)puts("YES");
  else puts("NO");
}
int main(){
  init();
  int T;
  scan(T);
  FF(i,1,T){
    printf("Case #%d: ",i);
    solve();
  }
}

invd init(){
#ifndef ONLINE_JUDGE
    freopen("C-large.in","r",stdin);
    freopen("C-large-solution.out","w",stdout);
#endif
    
}