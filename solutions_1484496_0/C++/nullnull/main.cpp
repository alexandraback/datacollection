#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <math.h>
#include <cstring>
#include <complex>
using namespace std;

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<vector<string> > VVS;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VPII;
#define rep(i,start,m) for(int i=(int)(start);i<(int)(m);i++)
#define showarray(array,m) for(int sa_i=0;sa_i<(int)(m);sa_i++) cout << array[sa_i] <<" "; cout << endl;
#define showvector(array) for(int sa_i=0;sa_i<(int)(array.size());sa_i++) cout << array[sa_i] << " "; cout << endl;
stringstream ss;
#define cast(a,b) ss.clear(); ss<<a; ss>>b; ss.clear();
#define rev(s) (string((s).rbegin(), (s).rend()))
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;
#define clr(a) memset((a), 0, sizeof(a))
const int INF = 999999;

int dx[] = {-1,0,1,0,1,1,-1,-1};
int dy[] = {0,-1,0,1,1,-1,1,-1};

template<class T>
int pyfind(const vector<T> &vect, const T &targ){
	for(int i=0;i<vect.size();i++){
		if(vect[i] == targ) return i;
	}
	return -1;
}

int T;



/*全ての組み合わせを列挙する next_combination
 do{
 
 }while( next_combination( data.begin(),data.begin()+r,data.end()) );
 という形で、dataの組み合わせを辞書順で列挙する
 （next_comb一回で、dataの次の組み合わせを探してdataにいれる
 組み合わせになってるのはdata+rまでの範囲で、以降の範囲には使われなかった要素が格納されてるので、表示させる際は注意する
 */
template < class BidirectionalIterator >
bool next_combination ( BidirectionalIterator first1 ,
					   BidirectionalIterator last1 ,
					   BidirectionalIterator first2 ,
					   BidirectionalIterator last2 )
{
	if (( first1 == last1 ) || ( first2 == last2 )) {
		return false ;
	}
	BidirectionalIterator m1 = last1 ;
	BidirectionalIterator m2 = last2 ; --m2;
	while (--m1 != first1 && !(* m1 < *m2 )){
	}
	bool result = (m1 == first1 ) && !(* first1 < *m2 );
	if (! result ) {
		// ①
		while ( first2 != m2 && !(* m1 < * first2 )) {
			++ first2 ;
		}
		first1 = m1;
		std :: iter_swap (first1 , first2 );
		++ first1 ;
		++ first2 ;
	}
	if (( first1 != last1 ) && ( first2 != last2 )) {
		// ②
		m1 = last1 ; m2 = first2 ;
		while (( m1 != first1 ) && (m2 != last2 )) {
			std :: iter_swap (--m1 , m2 );
			++ m2;
		}
		// ③
		std :: reverse (first1 , m1 );
		std :: reverse (first1 , last1 );
		std :: reverse (m2 , last2 );
		std :: reverse (first2 , last2 );
	}
	return ! result ;
}

template < class BidirectionalIterator >
bool next_combination ( BidirectionalIterator first ,
					   BidirectionalIterator middle ,
					   BidirectionalIterator last )
{
	return next_combination (first , middle , middle , last );
}
//////combination ここまで/////////


int n;
vector<long long> data;


void solve(){
	vector<ll> d;
	d.clear();
	long long sum,s;
	rep(i,1,4){
		rep(j,1,4){
			do{
				d.clear(); sum=0;
				rep(k,0,i+j){
					d.push_back(data[k]);
					sum+=data[k];
				}
				do{
					s=0;
					rep(k,0,i){
						s += d[k];
					}
					//cout << s << " " << sum << endl;
					if(s == (sum-s)){
						//cout << s << endl;
						rep(k,0,i){
							cout << d[k] << " ";
						}
						cout << endl;
						rep(k,i,i+j){
							cout << d[k] << " ";
						}
						cout << endl;
						return;
					}
				}while( next_combination( d.begin(),d.begin()+i,d.end()) );
				
			}while( next_combination( data.begin(),data.begin()+i+j,data.end()) );
		}
	}
	cout << "Impossible" << endl;
}

int main () {
	freopen("/Users/katsuma/c++/input.txt","rt",stdin);
	freopen("/Users/katsuma/c++/C-small-attempt0.in","rt",stdin);
	//freopen("/Users/katsuma/c++/C-small-attempt0out.txt","wt",stdout);
	//freopen("/Users/katsuma/c++/C-large.in","wt",stdout);
	//freopen("/Users/katsuma/c++/C-largeout.txt","wt",stdout);
	cin >> T;
	rep(t,0,T){
		cout << "Case #" << t+1 << ": " <<endl; 
		long long tmp; data.clear();
		cin >> n;
		rep(i,0,n){
			cin >> tmp;
			data.push_back(tmp);
		}
		solve();
	}
}








