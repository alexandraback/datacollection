#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<class A, size_t N, class T> void Fill(A (&a)[N], const T &v){ fill( (T*)a, (T*)(a+N), v ); }

const int INF = 0x3fffffff;


int main(){
	int T;

	cin >> T;
	for(int caseNum=1; caseNum <= T; caseNum++){

		ll B, M;
		cin >> B >> M;
		printf("Case #%d: ", caseNum);

		if( M > (1<<(B-2)) ){
			cout << "IMPOSSIBLE" << endl;
			continue;
		}

		cout << "POSSIBLE" << endl;
		M = (1<<(B-2)) - M;
		rep(i,B){
			rep(j,B){
				if( j <= i )		cout << 0;
				else if( i == B-1 )	cout << 0;
				else if( j != B-1 )	cout << 1;
				else if( i > 0 && (M & ((ll)1<<(i-1))) ) cout << 0;
				else cout << 1;
			}
			printf("\n");
		}

	}

	return 0;
}
