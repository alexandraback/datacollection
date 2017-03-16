/*
    jsrkrmciB
 */
    using namespace std;
#include <bits/stdc++.h> // precompiled headers
#define fora(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf (1<<30)
#define eps 1e-9
#define getnum(x) scanf("%d",&x);
#define dprintf(x...) fprintf(stderr,x);
#define lld I64d;
#define result(x,y)  printf("Case #%d: %I64d\n", x+1, (long long)y);
#if __cplusplus <= 199711L
  #error This library needs at least a C++11 compliant compiler
#endif
#define sd(x)  scanf("%d",&x)
#define sc(x) scanf("%c",&x)
#define sll(x) scanf("%I64d",&x)
#define sf(x) scanf("%Lf",&x)
#define ss(x) scanf("%s",x)
    typedef long double ld;
    typedef long long ll;
    typedef string str;

    int T;
    int main() {
    //ios::sync_with_stdio(false);//use with care
        freopen("C-small-attempt1.in","r",stdin);
        freopen("C-small-attempt1.out","w",stdout);
        getnum(T);
    // dprintf("%d %d\n",T,T);
        fora(t,T){
            int N,ans=0;
            char a[21],b[21];
            getnum(N);
            vector<pair<string,string> > v,w;
            fora(i,N){
                scanf("%s %s",a,b);
                v.pb(mp(string(a),string(b)));
                // w.pb(mp(b[i],a[i]));
            }
            sort(all(v));

            int maxans = 0;

            fora(i,100000){
                ans = 0;
                set<string> s,k;
                // sort(all(w));
                for(auto p:v){
                    if(s.count(p.first)==0 || k.count(p.second)==0){
                        s.insert(p.first);
                        k.insert(p.second);
                    }
                    else 
                        ans++;
                }
                maxans = max(maxans,ans);
                random_shuffle(all(v));
            }
            result(t,maxans);
            // for(auto p:w){
            //     printf("%s %s\n",p.first,p.second);
            // }
        }
        return 0;
    }