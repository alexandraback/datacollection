#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }
string result[50]; //set of edges
string middleManList = "";
bool hasResult = false;
int i, j, k, b, m, n, l;


void evaluateMap(){
	
}

void bfs(){
	//NO LOOP

	//add middle man
	int current = 1;
	for (int i = 1; i< b-1; i++){
		if (current>=m){
			hasResult = true;
			return;
		}
		result[0].at(i) = '1';
		result[i].at(b-1) = '1';
		current++;
	}
	
	//add second middle man
	for (int i = 1; i< b-1; i++){
		for (int j = i+1; j< b-1; j++){
			if (current>=m){
				hasResult = true;
				return;
			}
			result[i].at(j) = '1';
			current++;
		}
	}
	if (current>=m){
		hasResult = true;
		return;
	}
}

int main() {
    //freopen("x.in", "r", stdin);

	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);

	//freopen("B-large.in", "r", stdin);
	//freopen("B-large.out", "w", stdout);

	int tt, tn; cin >> tn;

	F1(tt,tn) {
		//cerr << tt << endl;
		cin >> b >> m;
		middleManList = "";
		for (int j = 0; j < b; j++){
			result[j] = "";
			middleManList += '0';
			for (int p = 0; p < b; p++){
				result[j]+='0';
			}
		}
		middleManList.at(0) = '1';
		middleManList.at(b-1) = '1';
		hasResult = false;
		result[0].at(b-1) = '1';
		if (m > 1){
			//BFS the map
			bfs();
		}
		else{
			hasResult = true;
		}
  		printf("Case #%d: ", tt);
		if (!hasResult){
			cout<< "IMPOSSIBLE"<<endl;
		}
		else{
			cout<< "POSSIBLE"<<endl;
			for (int p = 0; p < b; p++){
				cout << result[p]<<endl;
			}
		}
	}
	return 0;
}
