#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin(), unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define dump(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

int i, n, k, M, K;

char cc[20];

ll N;
ll rev;
string S, R;
ll cnt;

void set1(int x, char c){
    if(S[x] > c){
        cnt += (S[x] - c)*pow(10.0, (S.size()-1-x));
        S[x] = c;
    }
}

int doall(){
	int a = 0;

	if(S[S.size()-1-a] > '1'){
		set1(S.size()-1-a, '1');
	}
	if(S[S.size()-1-a] < S[a]){
		swap(S[S.size()-1-a], S[a]);
		cnt++;
	}
	if(S[S.size()-1-a] >= '1'){
		set1(S.size()-1-a, '1');
	}

    for(a=1;a<S.size()/2;a++){
		if(S[S.size()-1-a] > '0'){
            set1(S.size()-1-a, '0');
		}
        if(S[S.size()-1-a] < S[a]){
			swap(S[S.size()-1-a], S[a]);
			cnt++;
        }
		if(S[S.size()-1-a] > '0'){
            set1(S.size()-1-a, '0');
		}
    }
//    cout << S << "\n";
//    dump(cnt);
}

void dec(){
    int a;
    R.clear();
    for(a=0;a<S.size()-1;a++){
        R.pb('9');
    }
    char *p, *q;
    cnt += strtoll(S.c_str(), &p, 10)  - strtoll(R.c_str(), &q, 10);
    S = R;
}

int s[1000100];

int main(){
int a, b, c, d;
freopen("C:\\Users\\Jui\\Downloads\\A-small-attempt3.in", "r", stdin);
freopen("A-sssx.txt", "w", stdout);
int test, TT;
cin >> test;
char *p;
REP(a, 1000001) s[a] = 2e9;
s[1] = 1;
for(a=1;a<=1000000;a++){
	mina(s[a+1], s[a]+1);
	sprintf(cc, "%d", a);
	reverse(cc, cc+strlen(cc));
	rev = strtoll(cc, &p, 10);
	if(rev < 1000001){
		mina(s[rev], s[a]+1);
	}
}
REPI(TT, test){
	cnt = 0;
	cin >> N;
    printf("Case #%d: %d\n", TT, s[N]);
}


return 0;
}
