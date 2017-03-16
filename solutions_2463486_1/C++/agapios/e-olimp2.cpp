#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <map>
#include <queue>
#include <set>
#include <memory.h>
#include <string.h>
//#include <assert.h>
using namespace std;

#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define inf 1000000000
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define pi 2*acos(0.0)
#define mp(a,b) make_pair((a), (b))
#define X first
#define Y second

typedef vector<int> vint;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


ll n,m,k,t,x,cur;
int base = 10;
vector<int> mul(vector<int> a, vector<int> b){
	vector<int> temp;
	if(a.size() == 0 || b.size() == 0)
	{
		temp.resize(1);
		return temp;
	}
	temp.resize(a.size()*b.size() + 1);

	ll c = 0;
	int i,j;
	for(i = 0; i < a.size(); i++){
		c = 0;
		for(j = 0; j < b.size() || c; j++){
			if(j == b.size()) {
				temp[i+j] += c;
				c = 0;
				continue;
			}
			temp[i+j] += b[j]*a[i] + c;
			c = temp[i+j] / base;
			temp[i+j] %= base;
		}
	}
	temp.resize(i+j-1);
	return temp;
}

bool ispalin(vector<int> s){
	int n = s.size();
	for(int l = 0, r = n-1; l < r; l++, r--){
		if(s[l] != s[r])
			return 0;
	}
	return 1;
}
bool even = true;

vector<ll> ans;
vector<int> b;
void printfv(vector<int> a){
	ll res = 0;
	for(int i = 0; i < a.size(); i++){
		res = res*10+a[i];
	}
	ans.pb(res);
	/*
	for(int i = a.size()-1; i >= 0; i--){
		printf("%d", a[i]);
	}
	printf("\n");*/
}


//int evenF[1000], oddF[1000];
//int curEven, curOdd;

void solve(vector<int> a, int pos, int len){
	if(pos == len){
		// образец длиной len собран!
		// Четный
		if(even){
			for(int i= pos+1, j = len-1; j >= 0; j--, i++){
				a[i] = a[j];
			}
			FOR(i,0,3){
				a[pos] = i;
				b = mul(a,a);
				if(ispalin(a) && ispalin(b)){
					printfv(b);
					//evenF[curEven]++;
				}
			}
		}else{
			for(int i= pos, j = len-1; j >= 0; j--, i++){
				a[i] = a[j];
			}
			b = mul(a,a);
			if(ispalin(a) && ispalin(b)){
				printfv(b);
				//oddF[curOdd]++;
			}		
		}
		return;
	}
	FOR(i,0,2){
		if(pos == 0 && i == 0) continue;
		a[pos] = i;
		solve(a, pos+1, len);
	}
}

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ans.pb(1);
	ans.pb(4);
	ans.pb(9);

	vector<int> a;
	int len;// 2*len + 0/1
	FOR(len, 1, 4){
		even = 0;
		a.assign(2*len, 0);
		solve(a, 0, len);
		//curEven++;

		even = 1;
		a.assign(2*len+1, 0);
		solve(a, 0, len);
		//curOdd++;
	}

	/*FOR(i,0,ans.size()-1){
		cout << ans[i] << endl;
	}*/

	/*cout << "Even: "; 
	FOR(i,0, curEven){
		cout << evenF[i] << " ";
	}
	cout << "\nOdd: "; 
	FOR(i,0, curOdd){
		cout << oddF[i] << " ";
	}*/

	ll x,y;
	cin >> t;
	FOR(tt,1,t){
		//cin >> x >> y;
		scanf("%lld %lld", &x, &y);
		vector<ll>::iterator it = lower_bound(all(ans), y);
		if(it > ans.begin() && *it > y) it--;
		int r = it-ans.begin()+1; // чисел, меньших равных У.

		int l;
		if(x == 1){
			 l = 0;
		}else{
			it = lower_bound(all(ans), x-1);
			if(it > ans.begin() && *it > x-1) it--;
			l = it-ans.begin()+1;
		}
		//cout << "Case #" << tt << ": " << r-l << endl;
		printf("Case #%d: %d\n", tt, r-l);
	}



	return 0;
}