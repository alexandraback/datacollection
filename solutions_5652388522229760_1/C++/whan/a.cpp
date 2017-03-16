/*
 *    google code jam 2016 qual
 */
#include<fstream>
#include<iostream>
#include<cstdlib>
#include<cmath> 
#include<algorithm>
#include<vector>
#include<list>
#include<cstring>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<queue>
#include<deque>
#include<ctime>
#include<complex>
#include<bitset>
#include<time.h>

using namespace std;
#define PB push_back
#define LL long long
#define MP make_pair
typedef unsigned long long ULL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define DBG 0

#define fori(i,a,b) for(int i = (a); i < (b); i++)
#define forie(i,a,b) for(int i = (a); i <= (b); i++)
#define ford(i,a,b) for(int i = (a); i > (b); i--)
#define forde(i,a,b) for(int i = (a); i >= (b); i--)
#define forls(i,a,b,n) for(int i = (a); i != (b); i = n[i])
#define mset(a,v) memset(a, v, sizeof(a))
#define mcpy(a,b) memcpy(a, b, sizeof(a))

#define dout  DBG && cerr << __LINE__ << " >>| "
#define checkv(x) dout << #x"=" << (x) << " | "<<endl
#define checka(array,a,b) if(DBG) { \
dout << #array"[] | " << endl; \
forie(i, a, b) cerr << "[" << i << "]=" << array[i] << " |" << ((i - (a)+1) % 5 ? " " : "\n"); \
if (((b)-(a)+1) % 5) cerr << endl; \
}

#define redata(T, x) T x; cin >> x
#define MIN_LD -2147483648
#define MAX_LD  2147483647
#define MIN_LLD -9223372036854775808
#define MAX_LLD  9223372036854775807
#define MAX_INF 18446744073709551615
const int INF = 0x7fffffff;//use double for addition
inline int  reint() { int d; scanf("%d", &d); return d; }
inline long relong() { long l; scanf("%ld", &l); return l; }
inline char rechar() { scanf(" "); return getchar(); }
inline double redouble() { double d; scanf("%lf", &d); return d; }
inline string restring() { string s; cin >> s; return s; }

typedef set<int> Set;
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
//set_union(ALL(x1),ALL(x2),INS(x)),set_intersection


int N,T;
map<int,int> m;
int ok(LL a){
	while(a>0){
		int b = a%10;
		a/=10;
		m[b] = 1;
	}
	if(m.size()==10){return 1;}
	else{return 0;}
}
int main(void){
    freopen("A-large.in", "r", stdin);
    freopen("A_large.out", "w", stdout);
    cin.sync_with_stdio(false);
    cin >> T;
    forie(cnt,1,T){
    	m.clear();
    	cin >> N;
    	printf("Case #%d: ",cnt);
    	if(N==0){
    		printf("INSOMNIA\n");
    		continue;
    	}
    	int i = 1; LL cur;
    	while(i<=(int)1e6){
    		cur = (LL) i*N;i++;
    		if(ok(cur)){
    			printf("%lld\n",cur);
    			break;
    		}
    	}
    	if(m.size()<10){printf("INSOMNIA\n");}
    }
    return 0;
}