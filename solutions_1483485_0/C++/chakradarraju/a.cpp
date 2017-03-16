#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#define sz size()
#define pb push_back
#define _(x,a) memset(x,a,sizeof(x))
#define LET(x,a) typeof(a) x(a)
#define GFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define EACH(i,v) GFOR(i,(v).begin(),(v).end())
#define LL long long
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({LL t;scanf("%lld",&t);t;})
#define GD ({double t;scanf("%lf",&t);t;})
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;} 
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;} 
using namespace std;

int main (int argc, char const* argv[]) {
    
    string conv = "yhesocvxduiglbkrztnwjpfmaq", str;
    int kase = 1;
    int t = GI; getline(cin,str);
    while(t--) {
        getline(cin,str);
        int l = str.sz;
        printf("Case #%d: ",kase++);
        REP(i,l) printf("%c",str[i]==' '?' ':conv[str[i]-'a']);
        printf("\n");
    }
    
    return 0;
}

