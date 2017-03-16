#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef long double ld;

int main(){
	srand(5);
	cin.sync_with_stdio(false);
	int T;
	cin >> T;
	rep(t,1,T+1){
		cout << "Case #" << t << ":\n";
		int n,j;
		cin >> n >> j;
		set<int> used;
		rep(_,0,j){
			int x;
			do{
				x = rand();
				x &= (1<<(n-1)) - 1;
				x |= (1<<(n-2)) | 1;
				x &= ~(x<<1);
			} while(used.count(x) || !(x&(1<<(n-2))));
			used.insert(x);
			x *= 3;
			rrep(i,0,n)
				cout << bool(x&(1<<i));
			rep(i,2,11)
				cout << " " << i+1;
			cout << endl;
		}
	}
}