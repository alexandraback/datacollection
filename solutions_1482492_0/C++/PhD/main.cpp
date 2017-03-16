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
/*
#include <unordered_map>
#include <unordered_set>
#include <regex>
*/
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define ifo(n,v) for(int i=v;i<n;++i)
#define Fi for(int i=0;i<n;++i)
#define Vi vector <int>
#define pb push_back
#define sz size()
using namespace std;



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
    //return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

const double eps = 1e-6;
const double pi = 3.14159265358979323;
const int INF = 999999999;

int qq(int a,int b){
    int c=a+b;
    int res=0;
    while(c%10==0){
        ++res;
        c/=10;
    }
    return res;
}
bool isa(char a){
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u') return true;
    else return false;
}
bool isprime(int a){
    for(int i=2;i*i<=a;++i){
        if(a%i==0) return false;
    }
    return true;
}
struct Node{
    Node *l, *r,*p;
    int x,y;

    vector <Node*> a;
    vector <char> u;
    Node* use(){
        if(u.empty()) u.assign(a.size(),0);
        for(int i=0;i<u.size();++i){
            if(!u[i]){
                u[i]=1;
                return a[i];
            }
        }
        return NULL;
    }
    Node(){

    }

    Node(int xx,int yy){
        x=xx;
        y=yy;
        l=NULL;
        r=NULL;
        p=NULL;
    }
    Node(int xx,int yy,Node *pp){
        x=xx;
        y=yy;
        p=pp;
        l=NULL;
        r=NULL;
    }
    void setp(Node *pp){
        p=pp;
    }
};

class Treap{
private:
    Node *root,*l;
    void insert(Node *&r,Node *a){
        if(r==NULL){
            r=a;
            return;
        }
        // cout<<r->y<<' '<<a->y<<endl;
        if(a->y < r->y){
            split(r,a->x,a->l,a->r);
            r=a;
        }else{
            if(a->x < r->x) insert(r->l,a);
            else insert(r->r,a);
        }
    }
    void split(Node *a,int X,Node *&l,Node *&r){
        if(a==NULL){
            l=r=NULL;
            return;
        }
        if(a->x > X){
            split(a->l,X,l,a->l);
            r=a;
        }else{
            split(a->r,X,a->r,r);
            l=a;
        }

    }
    void built(Node *r,Node *t){
        while(r->y > t->y && r->p!=NULL){
            r=r->p;
        }
        if(r->p==NULL && t->y < r->y){
            r->p=t;
            t->l=r;
            root=t;
            root->p=NULL;
            l=t;
            return;
        }
        t->l=r->r;
        r->r=t;
        t->p=r;
        t->l->p=t;
        l=t;
    }

public:
    Treap(){
        root=NULL;
        l=NULL;
    }
    void built(pair<int,int> a){
        Node *n=new Node(a.first,a.second);
        if(root==NULL){
            root=n;
            l=n;
            return;
        }
        //cout<<root->y<<endl;
        if(l->y < n->y){
            l->r=n;
            n->p=l;
            l=n;
            return;
        }
        built(l,n);
    }

    void insert(pair<int,int> a){
        Node *node=new Node(a.first,a.second);
        insert(root,node);
    }
    Node* getRoot(){
        return root;
    }
};
/*int n=in();
vector<int>a,res,p;
for(;a.size()<n;a.push_back(in()));
vector<int>dp(a.size()+1,INF);
dp[0]=-INF;
for(int i=0;i<n;++i){
    int j=distance(dp.begin(),upper_bound(all(dp),a[i]));
    if(dp[j-1]<a[i] && a[i]<dp[j])
        dp[j]=a[i];
}
for(int i=1;i<=n;++i) cout<<dp[i]<<' ';*/
struct nod{
    nod *l,*r;
    long long sum;
};
int min(int x,int y){
    return y ^ ((x ^ y) & -(x < y));
}
int max(int x,int y){
    return x ^ ((x ^ y) & -(x < y));
}
int aa(int a){
    return log10(a);
}

string tos(int a){
    string r="";
    while(a>0){
        r+=a%10+'0';
        a/=10;
        // cout<<a;
    }
    reverse(all(r));
    return r;
}

string ma(string a){
    string r="";
    for(int i=0;i<a.size();++i){
        if(a[i]=='4' ||a[i]=='7') r+=a[i];
    }
    return r;
}
struct state {
    int len, link;
    map<char,int> next;
};

bool com(pair<double,int> a,pair<double,int> b){
    if (fabs(a.first-b.first)<=eps) return a.second<b.second;
    else return a.first>b.first;
}
long double nextApproximation(long double x){
    return x-(3*x+cos(x)+1)/(3-sin(x));
}
bool exit(){
    exit(0);
}
double dist(int x1,int y1,int x2,int y2){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

bool bfs(int t,int s,int n,vector<vector<long long> > g,vector<vector<long long> > f,vector<long long> &d){
    d.assign(n,0);
    queue<long long> q;
    q.push(s);
    d[s]=1;
    while(!q.empty()){
        long long v=q.front();
        q.pop();
        for(long long i=0;i<n;++i){
            if(d[i]==0 &&  g[v][i]-f[v][i]!=0 ){
                q.push(i);
                d[i]=d[v]+1;
            }
        }
    }
    return d[t]!=0;
}
long long dfs(int v,long long flow,int t,int n,vector<vector<long long> > g,vector<vector<long long> > &f,vector<long long> d,vector <long long> &ptr){
    cout<<v<<' ';
    if(v==t || flow<=0) return flow;
    for(long long &i=ptr[v];i<n;++i){
        if(d[i]==d[v]+1 && g[v][i]>f[v][i]){
            long long push=dfs(i,min(flow,g[v][i]-f[v][i]),t,n,g,f,d,ptr);
            if(push>0){
                f[v][i]+=push;
                f[i][v]-=push;
                return push;
            }

        }
    }
    return 0;
}

int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
    // vector <state> st;
    int n=in(),m=in();
    vector<vector<long long> > g(n,vector<long long>(n,0));
    vector<vector<long long> > f(n,vector<long long>(n,0));
    for(int i=0;i<m;++i){
        int a=in()-1,b=in()-1,c=in();
        g[a][b]=c;
       // g[b][a]+=c;
    }
    int s=0,t=n-1;
    vector<long long> d,ptr;
    long long inf=(long long)100000000000;
    long long flow=0;
    while(bfs(t,s,n,g,f,d)){
       // for(int i=0;i<n;++i) cout<<d[i]<<' ';
      //  cout<<endl;
        ptr.assign(n,0);
        while(long long push=dfs(s,inf,t,n,g,f,d,ptr)) flow+=push, cout<<endl;
        cout<<endl;
    }
    cout<<flow<<endl;



   return 0;
}
