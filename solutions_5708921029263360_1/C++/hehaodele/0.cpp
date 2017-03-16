#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"
#include "algorithm"
#include "set"
#include "map"
#include "queue"
#include "vector"
using namespace std;
#define rep(i,n) for(int i=0; i<n; ++i)
#define repp(i,a,b) for(int i=a; i<a+b; ++i)
#define sz size()
#define X first
#define Y second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
#define maxn 1005
int a[maxn], b[maxn], c[maxn];
int p[maxn];
void run(){
	int A,B,C,K,n;
	cin >> A >> B >> C >> K;
	n = 0;
	K = min(C,K);
	rep(i,A)rep(j,B)rep(k,K){
		a[n] = i, b[n] = j;
		++n;
	}
	n = A*B*K;
	rep(i,C) p[i] = i;
	rep(i,A){
		int bk = B*K;
		rep(j,bk){
			c[i*bk+j] = p[j%C];
		}
		int tmp = p[0];
		rep(j,C) p[j] = p[j+1];
		p[C-1] = tmp;
	}
	printf("%d\n", n);
	rep(i,n){
		printf("%d %d %d\n", a[i]+1, b[i]+1, c[i]+1);
	}
}

int main(int argc, char const *argv[])
{
	int cas;
	cin >> cas;
	rep(ca,cas){
		printf("Case #%d: ", ca+1);
		run();
	}
	return 0;
}