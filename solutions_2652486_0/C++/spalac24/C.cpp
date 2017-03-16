using namespace std;
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
#include <iterator>
#include <bitset>
#include <cstdlib>
#include <set>

template <class T> string toStr (T x){stringstream ss;ss << x;return ss.str();}
template <class T> long long toInt (T x){stringstream ss; ss << x; long long r; ss >> r; return r;}


#define FOR(i,a,b) for(int i = (a); i <(b); ++i)
#define foreach(x,v) for(typeof (v).begin() x = v.begin(); x != v.end(); ++x)
#define sz(x) (int)(x).size()
#define DEBUG
#ifdef DEBUG
#define REACH  cout<<" reached line "<<__LINE__<<endl
#define D(x) cout<<#x " is "<<(x)<<endl
#else
#define REACH
#define D(x)
#endif	
#define D2(x) cout<<#x " is "<<(x)<<endl
typedef unsigned long long ull; 

int cases = 0;


int r,n,m,k;
int main (){
	ios::sync_with_stdio(false);
	cin>>cases;
	for (int run = 1; run <= cases; ++run) {
		cout<<"Case #"<<run<<":\n";
		cin>>r>>n>>m>>k;
		int all [70][3];
		int count = 0;
		for (int i = 2; i <= m; ++i) {
			for (int j = 2; j <= m; ++j) {
				for (int k = 2; k <= m; ++k) {
					all[count][0] = i;
					all[count][1] = j;
					all[count][2] = k;
					++count;
				}
			}
		}
		for (int i = 0; i < r; ++i) {
			int prod;
			bool valid [70];
			memset(valid,1,sizeof valid);
			for (int j = 0; j < k; ++j) {
				cin>>prod;
				for (int i = 0; i < count; ++i) {
					if (!valid[i]) continue;
					valid[i] = false;
					for (int k = 0; k < (1<<3); ++k) {
						int tprod = 1;
						for (int l = 0; l < 3; ++l) {
							if ((1<<l)&k) {
								tprod *= all[i][l];
							}
						}
						if (tprod == prod) {
							valid[i] = true;
							break;
						}
					}
				}
				
			}
			for (int i = 0; i < count; ++i) {
				if (valid[i]) {
					cout<<all[i][0]<<all[i][1]<<all[i][2]<<endl;
					break;
				}
			}
		}
	}

}
