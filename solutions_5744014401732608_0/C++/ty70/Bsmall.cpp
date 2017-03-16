#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>	// require sort next_permutation count __gcd reverse etc.
#include <cstdlib>	// require abs exit atof atoi 
#include <cstdio>		// require scanf printf
#include <functional>
#include <numeric>	// require accumulate
#include <cmath>		// require fabs
#include <climits>
#include <limits>
#include <cfloat>
#include <iomanip>	// require setw
#include <sstream>	// require stringstream 
#include <cstring>	// require memset
#include <cctype>		// require tolower, toupper
#include <fstream>	// require freopen
#include <ctime>		// require srand
#define rep(i,n) for(int i=0;i<(n);i++)
#define ALL(A) A.begin(), A.end()
#define each(i,c) for(auto i=(c).begin();i!=(c).end();++i)
#define exist(s,e) ((s).find(e)!=(s).end())
#define clr(a) memset((a),0,sizeof(a))
#define nclr(a) memset((a),-1,sizoef(a))
#define sz(s) (int)((s).size())
#define INRANGE(x,s,e) ((s)<=(x) && (x)<(e))
#define pb push_back
#define MP(x,y) make_pair((x),(y))

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

bool mat[55][55];
ll B, M;
bool is_ok(ll dia, ll M){
	ll res = 1LL;
	ll curr_dia = 1LL;		// 現在の対角線の数
	while(curr_dia <= dia && res <= M){
		if (curr_dia == 1LL){
//			res += 1LL; // 1 -> B;
			mat[0][B-1] |= true;
		}else{
			ll curr = 1LL;
			rep (i, curr_dia){
				if (i == 0){
					for (int j = 2-1; j < (int)B-1; ++j){
						mat[1-1][j] |= true;
					} // end for
				}else if (i == curr_dia - 1){
					for (int j = 2-1; j < (int)B-1; ++j){
						mat[j][(int)B-1] |= true;
					} // end for
				}else{
					for (int j = i + 1; j < curr_dia - 1; ++j){
						for (int k = j + 1; k < curr_dia - 1; ++k){
							mat[j][k] |= true;
						} // end for
					} // end for
				} // end if
				curr *= (dia-(ll)i-1LL);
			} // end rep
			res += curr;
		} // end if
		++curr_dia;
	} // end while

	return (res >= M);
}

int main()
{
	ios_base::sync_with_stdio(0);
	int T; cin >> T;
	rep (i, T){
		cin >> B;
		cin >> M;
		memset(mat, false, sizeof(mat));
		bool res = true;
		ll dia = 0LL;
		if (B == 2LL){
			dia = 1LL;
		}else if(B == 3LL){
			dia = 3LL;
		}else{
			dia = B*(B-3LL)/2LL;
		} // end if
 
		if (dia < M){
			res = false;
		}else{
			res = is_ok(dia, M);
		} // end if
		
		cout << "Case #" << i+1 << ": ";
		if (!res){
			cout << "IMPOSSIBLE" << endl;
		}else{
			cout << "POSSIBLE" << endl;
			rep (j, B){
				rep (k, B){
					cout << (int)mat[j][k];
				} // end rep
				cout << endl;
			} // end rep
		} // end if
	} // end rep

	return 0;
}
