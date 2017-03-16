/*

jsrkrmciB

*/

#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define clear(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define Fora(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define fora(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define output(x) cout << (x)
#define ST first
#define ND second
#define br printf("\n")
#define getnum(x) scanf("%d", &x);
#define GCJ(x,y)  printf("Case #%d: %d\n", x+1, y);
#define getline(x) 	scanf("\n%[^\n]",x);

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
template <class _T> inline istream& operator << (istream& is, const _T& a) { is.putback(a); return is; }

typedef long double ld;
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const ld PI  = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

#define DEBUG

#ifdef DEBUG
#define debug(x) cout << #x << ":" << x << "\n";
#define dprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#else
#define debug //
#define dprintf(fmt,...)
#endif

// Global Variable
int qq,N,seq[200];
bool flag;

void swap(int &a, int &b){
	int buf;
	buf=a;
	a=b;
	b=buf;
}

bool tryOpen(int Chest[201], int &K, int Key[]){
	if(Key[Chest[0]]>0){
		Key[Chest[0]]--;
		K--;
		for(int i=1;i<40;i++){
			Key[i]+=Chest[1+i];
			K+=Chest[1+i];
		}
		return true;
	}
	return false;
}
void tryClose(int Chest[201], int &K, int Key[]){
	Key[Chest[0]]++;
	K++;
	for(int i=1;i<40;i++){
		Key[i]-=Chest[1+i];
		K-=Chest[1+i];
	}
}

bool isNotOpened(int x,int O){
	fora(i,O)
		if(seq[i]==x)
			return false;
	return true;
}

void permutate(int K, int Key[], int Chest[][201], int O){
	for(int i=0; i<N; i++){
		if (K==0)
			return;
		if(isNotOpened(i,O)){
			if(tryOpen(Chest[i],K,Key)){
				seq[O]=i;
				O++;
				if(O==N){
					flag=true;
					return;
				}
				if(Key[Chest[i][0]]==0){
					bool unique=true,need=false;
					fora(j,N){
						if(!isNotOpened(j,O))
							continue;
						if(Chest[j][0]==Chest[i][0])
							need=true;
						else if(Chest[j][1+Chest[i][0]]>0)
							unique=false;
					}
					if((need&!unique)||!need)
						permutate(K,Key,Chest,O);
				}else
					permutate(K,Key,Chest,O);
				if(flag){return;}
				tryClose(Chest[i],K,Key);
				seq[O]=0;
				O--;
			}
		}
	}
}

int main() {
	freopen("D-small-attempt12.in", "rt", stdin); 
	freopen("output.out", "wt", stdout); 
	getnum(qq);
	fora(T,qq){
		flag=false;
		int buf,K,Key[40],K1[40],K2[40];
		fora(i,40){
			Key[i]=0;
			K1[i]=0;
			K2[i]=0;
		}
		getnum(K);
		getnum(N);
		int Chest[200][201];
		fora(i,N)
			fora(j,201)
				Chest[i][j]=0;
		fora(i,K){
			getnum(buf);
			Key[buf]++;
			K1[buf]++;
		}
		fora(i,N){
			getnum(Chest[i][0]); // Type of key
			K2[Chest[i][0]]++;
			getnum(Chest[i][1]); // Number of key inside
			fora(j,Chest[i][1]){ 
				getnum(buf); //Contain key
				Chest[i][1+buf]++;
				K1[buf]++;
			}
		}
		bool flag2=true;
		fora(i,40){
			if(K1[i]<K2[i]){
				flag2=false;
			}
		}
		if(flag2){
			permutate(K,Key,Chest,0);
		}
		if(flag){
			printf("Case #%d:",T+1);
			fora(i,N){
				cout <<" "<< seq[i]+1 ;
			}
		}else{
			printf("Case #%d: IMPOSSIBLE",T+1);
		}

		cout << endl;
	}
	return 0;
}