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

const double eps = 1e-6;

int logbin(int a){
    a--;
    int res=1;
    while(a) a>>=1, res<<=1;
    return res;
}
int binpow (int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1)
            res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
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
vector<pair<int,pair<int,int> > > res;
void dfs(treap *v){
    if(v->l!=NULL) dfs(v->l);
    cout<<v->x<<' ';
    if(v->r!=NULL) dfs(v->r);
}

int main(){
    freopen("A.in","r",stdin);
    freopen("output.txt","w",stdout);


    /*int t=in();

    for(int k=0;k<t;++k){
        int n=in();
        vector<pair<int,int> > d;
        for(int i=0;i<n;++i){
            int a=in(),b=in();
            d.push_back (make_pair(a,b));
        }
        int res=0;
        int s=0;
        for(int i=0;i<=2*n;++i){
            int r=-1;
            for(int j=0;j<d.size ();++j){
                if(d[j].second!=-1 && d[j].second<=s){
                                        if(r==-1)
                                                r=j;
                                        else if(d[r].first==-1 && d[j].first!=-1) r=j;
                }
            }
            if(r>=0){
                res++;
                s++;
                                if(d[r].first!=-1) ++s;
                d[r].second=-1;
                d[r].first=-1;
            }else{
                for(int j=0;j<d.size ();++j){
                    if(d[j].first!=-1 && d[j].first<=s){
                        if(r==-1)
                            r=j;
                        else if(d[j].second>d[r].second)
                            r=j;
                    }
                }
                if(r!=-1){
                    ++res;
                    ++s;
                                        d[r].first=-1;
                }
            }

        }
        if(s==2*n){
            printf("Case #%d: %d\n",k+1,res);
        }else{
            printf("Case #%d: Too Bad\n",k+1);
        }
    }
*/
    int t=in();
    for(int k=0;k<t;++k){
        int a=in(),b=in();
        vector<double> c;
        for(int i=0;i<a;++i){
            double d;
            cin>>d;
            c.push_back (d);
        }
        double res=b+2;
        double p=1;
        for(int i=1;i<a;++i){
            c[i]*=c[i-1];
        }
        for(int i=0;i<a;++i){
            double p=c[a-i-1];
            res=min(res,p*(i+i+b-a+1)+(1-p)*(b+1+i+i+b-a+1));
            //cout<<p<<' '<<res<<endl;
        }
        printf("Case #%d: %.6lf\n",k+1,res);
    }


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
