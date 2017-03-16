#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<set>
using namespace std;
typedef vector<int> VI;
typedef long long LL;
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); --x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) __typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) (int)x.size()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second

const int MAXN=1010;

VI v[MAXN];
int n;
bool czy[MAXN];

void edgeIn(int a, int b){
    v[a-1].PB(b-1);
}

void readData(){
    REP(i,MAXN){
        v[i].clear();
    }
    scanf("%d",&n);
    int tmp;
    int a;
    REP(i,n){
        scanf("%d",&tmp);
        REP(j,tmp){
            scanf("%d",&a);
            edgeIn(i+1,a);
        }
    }
}

void czysc(){
    REP(i,MAXN){
        czy[i]=false;
    }
}

bool sprawdz(int s){
    czy[s]=true;
    bool jest=false;
    VI::iterator it;
    for (it=v[s].begin();it!=v[s].end();it++){
        if (!czy[*it]){
            if (sprawdz(*it)) jest=true;
        }
        else return true;
    }
    return jest;
}

int t;

int main(){
    scanf("%d",&t);
    REP(x,t){
        bool jest=false;
        readData();
            REP(i,n){
                if (sprawdz(i)){
                    jest=true;
                }
                czysc();
            }
            if (jest){
                printf("Case #%d: Yes\n",x+1);
            }
            else printf("Case #%d: No\n",x+1);
    }
}
