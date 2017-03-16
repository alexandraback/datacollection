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
        cnt += (S[x] - c)*round(pow(10.0, (S.size()-1-x)));
        S[x] = c;
    }
}

int doall(){
	int a = 0;
	int c = 0;
	if(S[S.size()-1-a] > '1'){
		set1(S.size()-1-a, '1');
	}
//	if(S[S.size()-1-a] < S[a]){
//		swap(S[S.size()-1-a], S[a]);
//		cnt++;
//	}
//	if(S[S.size()-1-a] >= '1'){
//		set1(S.size()-1-a, '1');
//	}
    for(a=1;a<S.size()/2;a++){
		if(S[S.size()-1-a] > '0'){
            set1(S.size()-1-a, '0');
//            printf("%d: %lld\n", a, cnt);
		}
    }
//    dump(cnt);


    for(a=0;a<S.size()/2;a++){
        if(S[a] != S[S.size()-a-1]) c = 1;
		swap(S[S.size()-1-a], S[a]);
    }
    if(c) cnt++;

//	dump(c);

    if(S[S.size()-1-0] > '1'){
		set1(S.size()-1-0, '1');
	}

    for(a=1;a<S.size()/2;a++){
		if(S[S.size()-1-a] > '0'){
            set1(S.size()-1-a, '0');
		}
    }
//    dump(S);
//    dump(cnt);

}

void dec(){
    int a;
    R.clear();
    for(a=0;a<S.size()-1;a++){
        R.pb('9');
    }
    char *p, *q;
    ll T1 = strtoll(S.c_str(), &p, 10);
    ll T2 = strtoll(R.c_str(), &q, 10);
    cnt += T1-T2;
//    dump(T1);
//    dump(T2);
    S = R;
}

int main(){
int a, b, c, d;
freopen("C:\\Users\\Jui\\Downloads\\A-large (2).in", "r", stdin);
freopen("A-ssss.txt", "w", stdout);
int test, TT;
cin >> test;
REPI(TT, test){
	cnt = 0;
	cin >> N;
	if(N%10 == 0){
		N--;
		cnt++;
	}
	sprintf(cc, "%lld", N);
	S = cc;
    while(S.size() != 1){
        doall();
        dec();
    }
    cnt += S[0] - '0';
    printf("Case #%d: %lld\n", TT, cnt);
}


return 0;
}
