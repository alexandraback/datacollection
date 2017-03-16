#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

// Solves the system of equations av=b.
// Returns one of the strings "inconsistent", "ok" or "multiple", depending
// on whether the system has 0, 1 or infinitely many solutions.
// If it has exactly one solution, that solution is returned as well
pair<string, vector<double> > solveEquation(vector<vector<double> > a, vector<double> b){
    const double EPS = 1e-8;
    int n=b.size();
    bool multiple = false;
    rep(j,0,n){
        int best = -1;
        rep(i,0,n){
            bool ok = (abs(a[i][j]) > EPS);
            rep(k,0,j)
                if(abs(a[i][k]) > EPS){
                    ok=false;
                    break;
                }
            if(!ok)
                continue;
            if(best == -1 || abs(a[i][j]) > abs(a[best][j]))
                best=i;
        }
        if(best == -1){
            multiple = true;
            continue;
        }
        b[best] /= a[best][j];
        rrep(k,n,0){
            a[best][k] /= a[best][j];
        }
        rep(i,0,n){
            if(i == best)
                continue;
            double mul = a[i][j];
            rep(k,0,n){
                a[i][k] -= a[best][k]*mul;
            }
            b[i] -= b[best]*mul;
        }
        swap(a[j], a[best]);
        swap(b[j], b[best]);
    }
    rep(i,0,n){
        bool ok = abs(b[i]) < EPS;
        rep(j,0,n)
            if(abs(a[i][j]) > EPS)
                ok = true;
        if(!ok)
            return make_pair("inconsistent", vector<double>());
    }
    if(multiple)return make_pair("multiple", vector<double>());
    return make_pair("ok", b);
}

char s[2005];
string digits[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
vector<int> b;
vector<int> ans;

void subtract(int num){
	ans.push_back(num);
	rep(i,0,digits[num].size()){
		//printf("%c ", digits[num][i]);
		--b[digits[num][i]-'A'];
	}
	/*rep(i,0,26)
		printf("%c%d ", i+'A', b[i]);
	printf("\n");*/
}

void solve(){
	scanf("%s", s);
	int len=strlen(s);
	sort(s, s+len);
	b.clear();
	ans.clear();
	rep(i,0,26)
		b.push_back(0);
	rep(i,0,len)
		b[s[i]-'A']++;
	while(b['Z'-'A'])subtract(0);
	while(b['W'-'A'])subtract(2);
	while(b['U'-'A'])subtract(4);
	while(b['X'-'A'])subtract(6);
	while(b['G'-'A'])subtract(8);
	while(b['F'-'A'])subtract(5);
	while(b['V'-'A'])subtract(7);
	while(b['O'-'A'])subtract(1);
	while(b['N'-'A'])subtract(9);
	while(b['T'-'A'])subtract(3);
	sort(all(ans));
	rep(i,0,ans.size())
		printf("%d", ans[i]);
	
	/*vector<double> b(26, 0);
	vector<vector<double> > a(26, vector<double>(10, 0));
	rep(i,0,len)
		b[s[i]-'A']++;
	rep(i,0,10){
		rep(j,0,digits[i].size()){
			a[digits[i][j]-'A'][i]++;
		}
	}
	vector<double> res=solveEquation(a, b).second;
	rep(i,0,10){
		for(int j=0; j < res[i]+0.5; ++j)
			printf("%d", i);
	}*/
	printf("\n");
}

int main(){
	int T;
	scanf("%d", &T);
	for(int i=1; i <= T; ++i){
		printf("Case #%d: ", i);
		solve();
	}
}
