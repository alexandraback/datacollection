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
ll a, b;
void get_data(){
	scanf("%lld/%lld", &a, &b);
}

void run(){
	ll g = gcd(a, b);
	a /= g;
	b /= g;
	ll tb = b;
	while(tb % 2 == 0)tb /= 2;
	if(tb != 1){
		cout<<"impossible"<<endl;
		return;
	}
	ll gg = 1;
	while(gg * 2 <= b)gg *= 2;
	while(gg > a)gg /= 2;
	b /= gg;
	ll t = 0;
	while(b > 1){
		t++;
		b /= 2;
	}cout<<t<<endl;
}
int main(){
//	get_prime();
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int t;
	cin>>t;
	FR(i, t)
	{
	get_data();
	printf("Case #%d: ", i + 1);
	run();
	}
	return 0;
}
