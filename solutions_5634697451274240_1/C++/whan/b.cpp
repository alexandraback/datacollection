/*
 *    google code jam qual 2016 b
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
string s;
int main(void){
    freopen("B-large.in", "r", stdin);
    freopen("B_large.out", "w", stdout);

    cin.sync_with_stdio(false);
    int beginneg,num_neg_block;
    cin >> T;
    forie(cnt,1,T){
    	num_neg_block = 0;
    	cin >> s;
    	int n = s.length();
    	printf("Case #%d: ",cnt);
    	beginneg = (s[0]=='-');
    	if(beginneg && n==1){
    		printf("1\n");
    		continue;
    	}
    	fori(i,0,n){
    		if(i==0){
    			if(s[i]=='-'){
    				num_neg_block++;
    			}
    			continue;
    		}
    		if(s[i]=='-' && s[i-1]=='+'){
    			num_neg_block++;
    		}
    	}
    	if(beginneg){
    		printf("%d\n",2*(num_neg_block)-1);
    	}
    	else{
    		printf("%d\n",2*num_neg_block);    		
    	}
    }
    return 0;
}