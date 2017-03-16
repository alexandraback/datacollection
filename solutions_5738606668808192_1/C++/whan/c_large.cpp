/*
 *    
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


int T;
int N,J;


void print_binary(int a){
	//get the binary representation of a
	vector<int> v;
	while(a>0){
		if(a&1){
			v.PB(1);
		}
		else{
			v.PB(0);
		}
		a>>=1;
	}

	//construct the jamcoin 
	while(v.size()<N-2){
		v.PB(0);
	}
	v.PB(1);
	reverse(v.begin(),v.end());
	//print binary rep twice
	fori(ttt,0,2){
		fori(i,0,v.size()){
			printf("%d",v[i]);
		}
		printf("1");
	}
	printf(" ");

}
int solve(int a){
	LL cur = 0;
	int ans = 1;
	vector<LL> v;
	forie(k,2,10){
		//cur is 1000...binary(i)1 in base(k)
		cur = pow(k,N-1);
		cur++;
		int j = 0;
		while(a>>j){
			if((a>>j)&1){
				cur += pow(k,j+1);
			}
			j++;
		}
		//check if cur is prime 
		int isprime = 1;
		LL q = 2;
		while(q*q<=cur){
			if(cur%q==0){
				isprime = 0;break;
			}
			q++;
		}
		if(!isprime){
			v.PB(q);//divisor
		}
		else{
			ans = 0;break;
		}
	}
	if(ans){
		print_binary(a);
		fori(i,0,9){
			printf("%lld%c",v[i],i==8 ? '\n' : ' ');
		}
	}
	return ans;
}
int main(void){
	freopen("C-large.in", "r", stdin);
    freopen("C_large.out", "w", stdout);
   	
    cin.sync_with_stdio(false);
    cin >> T;
    forie(cnt,1,T){
    	cin >> N >> J;//input N was manually changed to 16
    	printf("Case #%d:\n",cnt);
    	int i = 0, m = 0;
    	while(m < J){
    		int ans = solve(i);
    		if (ans) m++;
    		i++;
    	}
    }
    return 0;
}