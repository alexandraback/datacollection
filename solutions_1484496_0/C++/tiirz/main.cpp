#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <map>
#include <deque>
#include <set>
using namespace std;

#define sz size()
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define fe(i,a) for (int (i) = 0; (i) < int((a).size()); ++(i))
#define C(a) memset((a),0,sizeof(a))
#define inf 1000000000
#define pb push_back
#define ppb pop_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define pi 2*acos(0.0)
#define sqr(a) (a)*(a)
#define mp(a,b) make_pair((a), (b))
#define X first
#define Y second

typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=2000000000;
const double eps=1e-7,EPS=1e-6;
int gcd(int a,int b){
        while(a){
                b%=a;
                swap(a,b);
        }
        return b;
}
ll md=1e9+7;
int n;
vector<int> a,val;
vector<set<int> > sm;
//vector<
int main() {
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    //freopen("input.txt","r",stdin);
    int T,m,c,g=0,h=1488,len,k=-1,a1,a2;
        cin>>T;
        rep(t,T){
                cin>>n;
                a.resize(n);
                sm.assign(1<<n,set<int>());
                val.assign(1<<n,0);
                rep(i,n)cin>>a[i];
                sort(all(a));
                FOR(i,1,(1<<n)-1){
                        sm[i].insert(all(sm[(i-1)&i]));
                        g=((i-1)&i)^i;
                        sm[i].insert(all(sm[g]));
                        g=0;
                        rep(j,n)if(i&(1<<j))g+=a[j];
                        sm[i].insert(g);
                        val[i]=g;
                //      if(i%1000==0)cout<<(100.0*i)/(1<<n)<<'%'<<endl;
                }
                rep(i,(1<<n))if(sm[i].size() && sm[i^((1<<n)-1)].size()){
                        h=i;
                        g=i^((1<<n)-1);
                        set<int>::iterator it1=sm[h].begin(),it2=sm[g].begin();
                        while(it1!=sm[h].end() && it2!=sm[g].end()){
                                if(*it1==*it2)break;
                                if(*it1<*it2)it1++; else it2++;
                        }
                        if(it1!=sm[h].end() && it2!=sm[g].end()){
                                k=*it1;
                                break;
                        }
                }
                printf("Case #%d:\n",t+1);

                int b=0;
                if(k==-1)puts("Impossible"); else{
                        rep(i,(1<<n))if(val[i]==k){
                                h=i^((1<<n)-1);
                                for(g=h;g;g=(g-1)&h)if(val[g]==k){
                                        a1=i; a2=g;
                                        b=1; break;
                                }
                                if(b)break;
                        }
                        rep(i,n)if((1<<i)&a1)cout<<a[i]<<' ';
                        cout<<endl;

                        rep(i,n)if((1<<i)&a2)cout<<a[i]<<' ';
                        cout<<endl;
                }

        }
    return 0;
}
