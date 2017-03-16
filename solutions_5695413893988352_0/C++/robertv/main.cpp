#include <bits\stdc++.h>
using namespace std;
typedef long long ll;
template <class T> T sqr(T x) { return x*x; }

int T;
char C[20], J[20];
int nrd(ll x){
    int res = 1;
    while(x>9){
        res++;
        x/=10;
    }
    return res;
}
bool check(ll x, char* s){
    if (nrd(x)>strlen(s)) return false;
    for(int i=strlen(s)-1; i>=0; i--){
        int d = x%10;
        if (s[i]!='?' && d!=s[i]-'0')
            return false;
        x /= 10;
    }
    return true;
}
struct trip{
    ll c, j, diff;
    bool operator < (const trip& o) const{
        if (diff == o.diff)
            if (c==o.c)
                return j < o.j;
            else
                return c < o.c;
        else
            return diff < o.diff;
    }
};
void solve(int testi){
    scanf("%s%s",C, J);
    vector<trip> sols;
    for(int cc = 0; cc<1000; cc++){
        if (!check(cc,C)) continue;
        for(int jj = 0; jj<1000; jj++){
            if (!check(jj,J)) continue;

            ll diff = abs(cc-jj);
            sols.push_back({cc, jj, diff});
        }
    }
    sort(sols.begin(), sols.end());
    printf("Case #%d: %*0I64d %*0I64d\n",testi, strlen(C), sols[0].c, strlen(J), sols[0].j);
}
int main(){
	#ifdef LOCAL_PROJECT
		freopen("d:\\src\\CppProjects\\stdin","r",stdin);
		freopen("d:\\src\\CppProjects\\stdout","w",stdout);
	#endif
	scanf("%d\n",&T);
    for(int i=1; i<=T; i++){
        cerr << i << endl;
        solve(i);
    }
	return 0;
}
