#pragma comment(linker, "/STACK:1024000000,1024000000")  
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
template<class T> T gcd(T x,T y){while(T t=x%y)x=y,y=t;return y;}
const double eps = 1e-9;
const double PI = acos(-1.);
const int INF = 1000000000;
const int MOD = 1000000007;
const double E = 2.7182818284590452353602874713527;

#define pmul(x1,y1,x2,y2) ((x1)*(x2)+(y1)*(y2))
#define xmul(x1,y1,x2,y2) ((x1)*(y2)-(x2)*(y1))
#define sqr(x) ((x)*(x))

#define FR(i,N) for(int i=0;i<N;i++)
#define FRS(i,S,E) for(int i=S;i<=E;i++)
#define FRD(i,S,E) for(int i=S;i>=E;i--)
#define SZ(x) ((int)(x).size())
#define fill(a,b) memset(a,b,sizeof(a))
#define PII pair<int,int>
#define MP(a,b) make_pair(a,b)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define PB push_back
#define lowbit(x) ((x)&(-(x)))

bool isdig(char x){return x>='0'&&x<='9';}
bool isup(char x){return x>='A'&&x<='Z';}
bool isdown(char x){return x>='a'&&x<='z';}
bool islet(char x){return isup(x)||isdown(x);}

//--------CODE----------
int N;
double A[1000], B[1000];
void get_data(){
	scanf("%d", &N);
	FR(i, N)scanf("%lf", &A[i]);
	FR(i, N)scanf("%lf", &B[i]);
}

void run(){
	sort(A, A + N);
	sort(B, B + N);
	
	int s0 = 0, s1 = 0;
	int nowB;
	
	nowB = 0;
	FR(i, N){
		if(A[i] < B[nowB])continue;
		nowB++;
		s0++;
	}
	
	int nowA;
	nowA = 0;
	FR(i, N){
		if(B[i] < A[nowA])continue;
		nowA++;
		s1++;
	}
	printf("%d %d\n", s0, N - s1);
}
int main(){
//	get_prime();
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	int t;
	scanf("%d", &t);
	FR(i, t)
	{
	get_data();
	printf("Case #%d: ", i + 1);
	run();
	}
	return 0;
}
