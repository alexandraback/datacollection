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
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	rep(ix,1,t+1){
		cout << "Case #" << ix << ": ";
		int n;
		cin >> n;
		if(n == 0){
			cout << "INSOMNIA\n";
		} else {
			bool seen[10] = {};
			int cnt = 0;
			for(int i = n; true; i += n){
				int j = i;
				while(j){
					cnt += seen[j%10] == 0;
					seen[j%10] = 1;
					j /= 10;
				}
				if(cnt == 10){
					cout << i << endl;
					break;
				}
			}
		}
	}
}