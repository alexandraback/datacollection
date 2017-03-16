//includes
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

//typedefs
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

//defines-general
#define to(a) __typeof(a)
#define all(vec)  vec.begin(),vec.end()
#define fill(a,val)  memset(a,val,sizeof(a))

//defines-iteration
#define repi(i,a,b) for(__typeof(b) i = a;i<b;i++)
#define repii(i,a,b) for(__typeof(b) i = a;i<=b;i++)
#define repr(i,b,a) for(__typeof(b) i = b;i>a;i--)
#define repri(i,b,a) for(__typeof(b) i = b;i>=a;i--)
#define tr(vec,it)  for(__typeof(vec.begin())  it = vec.begin();it!=vec.end();++it)



//defines-pair
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

// my own
#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld%lld",&a,&b)
#define slll(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define sllll(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define fastio   std::ios_base::sync_with_stdio(false)



using namespace std;

int visit[10000000];

void init()
{
    memset(visit,0,sizeof(visit));
}

int reverse(int N)
{
	int rev = 0;
	while(N>0){
		rev = 10*rev+(N%10);
		N/=10;
	}
	return rev;
}

int getAns(int N)
{
    pii p,top,nbr;
    int x,y;
	if(N==1)
		return 1;
	queue<pii > Q;
	p.first=1;
	p.second=1;
	Q.push(p);
	visit[1]=1;
	while(!Q.empty()) {
		top = Q.front();
		Q.pop();
		x= reverse(top.first);
		y= top.first+1;
		if(x==N||y==N)
			return top.second+1;
		if((!visit[y])&&(y<10000000)){
            nbr.first=y;
            nbr.second=top.second+1;
			Q.push(nbr);
			visit[y]=1;
		}
		if(!visit[x]){
            nbr.first=x;
            nbr.second=top.second+1;
			Q.push(nbr);
			visit[x]=1;
		}
	}
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int N,T;
	cin>>T;
	for (int i = 1; i <= T; i++) {
		cin>>N;
		//cout<<N<<endl;
		init();
		int ans = getAns(N);
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}
