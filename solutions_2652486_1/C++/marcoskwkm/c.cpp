#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define foreach(_it,_v) for(typeof(_v.begin()) _it = _v.begin(); _it != _v.end(); ++_it)

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXK = 10, MAXN = 10;

int r,n=12,m=8,k=12;
lint v[MAXK];
int p[] = {2,3,4,5,6,7,8};
int qntd[7];
lint fact[15];

map< lint,set<string> > cj;
map< lint,map<string,lint> > cnt;
map< lint,lint > tot;

void go(int i,int q) {
    if(i == 6) {
        qntd[6] = q;
        string s = "";
        vector<int> vet;
        for(int a=0;a<qntd[0];++a) {
            s += '0'+p[0];
            vet.push_back(p[0]);
        }
        for(int a=0;a<qntd[1];++a) {
            s += '0'+p[1];
            vet.push_back(p[1]);
        }
        for(int a=0;a<qntd[2];++a) {
            s += '0'+p[2];
            vet.push_back(p[2]);
        }
        for(int a=0;a<qntd[3];++a) {
            s += '0'+p[3];
            vet.push_back(p[3]);
        }
        for(int a=0;a<qntd[4];++a) {
            s += '0'+p[4];
            vet.push_back(p[4]);
        }
        for(int a=0;a<qntd[5];++a) {
            s += '0'+p[5];
            vet.push_back(p[5]);
        }
        for(int a=0;a<qntd[6];++a) {
            s += '0'+p[6];
            vet.push_back(p[6]);
        }
        lint add = fact[12]/(fact[qntd[0]]*fact[qntd[1]]*fact[qntd[2]]*fact[qntd[3]]*fact[qntd[4]]*fact[qntd[5]]*fact[qntd[6]]);        
        for(int mask=0;mask<(1<<n);++mask) {
            lint prod = 1;
            for(int a=0;a<n;++a) if(mask&(1<<a)) prod *= vet[a];
            cj[prod].insert(s);
            cnt[prod][s] += add;
            tot[prod] += add;
        }
        return;
    }
    for(int a=0;a<=q;++a) {
        qntd[i] = a;
        go(i+1,q-a);
    }
}
        

void generate_sets() { go(0,n); }

int main() {
    fact[0] = 1;
    for(int a=1;a<=12;++a) fact[a] = a*fact[a-1];
    generate_sets();
    scanf("%*d");
    printf("Case #1:\n");
    scanf("%d%*d%*d%*d",&r);
    for(int a=0;a<r;++a) {
        lint high = LINF;
        int ind = 0;
        for(int b=0;b<k;++b) {
            scanf("%lld",&v[b]);
            if(cj[v[b]].size() < high) {
                high = cj[v[b]].size();
                ind = b;
            }
        }
        swap(v[0],v[ind]);
        double best = 0;
        string ans;
        for(string s: cj[v[0]]) {
            double prob = double(cnt[v[0]][s])/tot[v[0]];
            bool ok = 1;
            for(int b=1;b<k;++b) {
                if(cj[v[b]].find(s) == cj[v[b]].end()) {
                    ok = 0;
                    break;
                }
                else prob *= double(cnt[v[b]][s])/tot[v[b]];
            }
            if(ok && prob > best) {
                best = prob;
                ans = s;
            }
        }
        printf("%s\n",ans.c_str());
    }    
    return 0;
}
