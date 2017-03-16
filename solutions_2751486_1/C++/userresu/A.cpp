#include <cstdio>
#include <set>
#include <cstring>
using namespace std;

char s[1000001];
set<char> S;
int main () {
    S.insert('a');
    S.insert('e');
    S.insert('i');
    S.insert('o');
    S.insert('u');
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int z=1;z<=T;++z){
    int n,L;
    scanf("%s %d",s,&n);
    L = strlen(s);
    long long tot=0;
    int m=0,last=L;
    for (int i=L-1;i>=0;--i) {
        if (S.find(s[i])==S.end()) ++m;
        else m=0;
        if (m>=n) last=n+i-1;
        tot+=L-last;
    }
    printf("Case #%d: %lld\n",z,tot);
    }
    return 0;
}
