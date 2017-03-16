#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define IT(a,it) for(auto it=a.begin(); it != a.end(); it++)
#define REV_IT(a,it) for(auto it=a.rbegin(); it != a.rend(); it++)
#define LL long long
#define LD long double
#define MP make_pair
#define FF first
#define SS second
#define PB push_back
#define INF (int)(1e9)
#define EPS (double)(1e-9)

#ifndef ONLINE_JUDGE
#  define LOG(x) cerr << #x << " = " << (x) << endl
#else
#  define LOG(x) 0
#endif

#define MAXX 500005

using namespace std;

typedef pair <int, int> pi_i;
typedef pair<int, pi_i> pi_ii;

bool cmp(int a, int b){ return a>b; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

int n, mr[MAXX], ans = 0;
string s1[MAXX], s2[MAXX];
string RS1[MAXX], RS2[MAXX];
string FS1[MAXX], FS2[MAXX];

void solve(int idx){
	if(idx == n){
		int ct1 = 0, ct2 = 0;
		for(int i = 0;i < n;i++){
			if(mr[i] == 1){		//real
				RS1[ct1] = s1[i];
				RS2[ct1++] = s2[i];
			}else{
				FS1[ct2] = s1[i];
				FS2[ct2++] = s2[i];
			}
		}
		for(int i = 0;i < ct2;i++){
			string fff = FS1[i], sss = FS2[i];
			int tot1 = 0, tot2 = 0;
			for(int j = 0;j < ct1;j++){
				if(fff == RS1[j]) tot1++;
				else if(sss == RS2[j]) tot2++;
			}
			if(tot1 > 0 && tot2 > 0){
				//cout << tot1 << " " << tot2 << endl;
				//cout << ct1 << " " << ct2 << endl;
				/*if(ct2 == 13){
					cout << ct2 << endl;
					for(int _i = 0;_i < ct2;_i++){
						cout << FS1[_i] << " " << FS2[_i] << endl;
					}
					cout << "REAL" << endl;
					for(int _i = 0;_i < ct1;_i++){
						cout << RS1[_i] << " " << RS2[_i] << endl;
					}
				}*/
			}else{
				return;
			}
		}
		ans = max(ans, ct2);
		return;
	}
	solve(idx+1);
	mr[idx] = 1;
	solve(idx+1);
	mr[idx] = 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int T, casee = 1;
	cin >> T;
	for(casee=1;casee<=T;casee++){
		cout << "Case #" << casee << ": " ;
		cin >> n;
		for(int i = 0;i < n;i++){
			cin >>s1[i] >> s2[i];
		}
		ans = 0;
		solve(0);
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
return 0;	
}

