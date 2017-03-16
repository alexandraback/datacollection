#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#define sz size()
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define fu(i,n) for(int i=0; i<(n); i++)
#define ALL(a) (a).begin(),(a).end()
#define cl(a,co) memset(a,co,sizeof a)
#define un(a) sort(ALL(a)),a.erase( unique(ALL(a)), a.end() )
typedef long long ll;
//istringstream is(s); is >> a;

using namespace std;

int ileTestow;

// 1 -> 1
// i -> 2
// j -> 3
// k -> 4

int sign(int x) {
	return (x > 0) - (x < 0);
}

int multiply(int a, int b){
	int znak = sign(a) * sign(b);
	if( abs(a) == 1 ) return znak * abs(b);
	if( abs(b) == 1 ) return znak * abs(a);
	if( abs(a) == abs(b) ) 	return - znak;
	if( abs(a) == 2 ){
		if( abs(b) == 3 ) return 4 * znak;
		return -3 * znak;
	}
	if( abs(a) == 3 ){
		if( abs(b) == 4 ) return 2 * znak;
		return -4 * znak;
	}
	if( abs(a) == 4 ){
		if( abs(b) == 2 ) return 3 * znak;
		return -2 * znak;
	}
}

int find(vi &v, int l, int val){
	int cur = v[0];
	for(int i=1; i<4*l; i++){
		if( cur == val ) return i-1;				
		
		int prev = cur;
		cur = multiply(cur, v[i%l]);
	}
	return -1;
}

int find_r(vi &v, int l, int val){
	int cur = v[0];
	for(int i=1; i<4*l; i++){
		if( cur == val ) return i-1;				
		
		int prev = cur;
		cur = multiply(v[i%l], cur);
	}
	return -1;
}

int char_to_i(char c){
	if( c == 'i' ) return 2;
	if( c == 'j' ) return 3;
	return 4;
}

int main(){

	scanf("%d",&ileTestow);

	for(int q=1; q<=ileTestow; q++){
		printf("Case #%d: ",q);
		
		ll l, x;
		string tmp;

		cin >> l >> x;
		cin >> tmp;
		
		vi v;
		for(int i=0; i<tmp.size(); i++){
			v.pb( char_to_i( tmp[i] ) );
		}

		int i_end = find(v, l, 2);
		reverse(v.begin(), v.end());
		int k_start = find_r(v, l, 4);
		reverse(v.begin(), v.end());

		x -= (int)(i_end + k_start + 2 + l - 1) / l;

		if( i_end == -1 || k_start == -1 || x < 0 ){
			cout << "NO" << endl;
			continue;
		}

		k_start = l - k_start%l - 1;

		int j_outcome = 1;
		for(int i=(i_end+1)%l; i%l != k_start%l; i++){
			j_outcome = multiply(j_outcome, v[i%l]);
		}

		int all = 1;
		for(int i=0; i<l; i++){
			all = multiply(all, v[(k_start+i)%l]);
		}

		if( x % 2 == 1 ){
			j_outcome = multiply(j_outcome, all);	
		}

		if( x % 4 >= 2 ){
			j_outcome = multiply(j_outcome, multiply(all,all));	
		}
		
		if( j_outcome == 3 ){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
