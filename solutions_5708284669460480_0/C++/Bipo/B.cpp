#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<bitset>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<functional> //highest
#include<algorithm>	//sort, heap etc.
#include<utility>	//pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef stack<int> si;
typedef queue<int> qi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> elst;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(a,b) ((a) < (b) ? (b)-(a) : (a)-(b))

#define FORN(i,j,n) for(int i=j;i<(int)n;i++)
#define forn(i,n) FORN(i,0,n)
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define sz size()
#define ff first
#define ss second
#define pq priority_queue
#define all(x) (x).begin(),(x).end()
#define mlc(t,n) ((t*)malloc(n*sizeof(t)))
#define mset(m,v) memset(m,v,sizeof(m))

#define INF 1000000000
#define M 1000000007

//---------------------------------------------//

void solve(){
	int K,L,S;
	cin >> K >> L >> S;
	string k,l;
	cin >> k >> l;

	int c[26];
	forn(i,26) c[i]=0;
	forn(i,K) c[k[i]-'A']++;

	forn(i,L){
		if(c[l[i]-'A']==0){
			cout << "0.0" << endl;
			return;
		}
	}
	double b = 1;
	int t = S-L,p=L;

	FORN(i,1,L){
		if(l.substr(0,L-i) == l.substr(i,L-i)){
			p = i;
			break;
		}
	}

	b += t/p;

	double eb=1;

	forn(i,L){
		eb *= (ld)c[l[i]-'A']/(ld)K;
	}

	b = b - b*eb;
	printf("%0.8lf\n",b);
	//cout << b << endl;
}

int main(){
	//freopen("1C/in.txt","r",stdin);
	freopen("1C/B-small-attempt1.in","r",stdin);
	//freopen("1C/B-large.in","r",stdin);
	freopen("1C/out.txt","w",stdout);

	int T;
	cin >> T;
	forn(t,T){
		cout << "Case #" << t + 1 << ": ";
		solve();
		//cout << endl;
	}
}
