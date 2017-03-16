#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <cstring>
using namespace std;
typedef long long LL;
typedef pair <int, int> ii;
#define MAXN 2000000
vector <int> v;
LL reverse(LL num);

void gen_numbers(){
	v.assign(MAXN + 10, -1);

	queue <ii> q;
	q.push(ii(1, 1));

	while (!q.empty()){
		ii fr = q.front(); q.pop();
		int num = fr.first;
		int lvl = fr.second;

		if (v[num] != -1) continue;
		v[num] = lvl;
					
		int add = num + 1;
		int rev = reverse(num);

		if (add <= MAXN) {
			q.push(ii(add, lvl + 1));
		}
		if (rev <= MAXN && rev != add) {
			q.push(ii(rev, lvl + 1));
		}
	}
	
}

LL reverse(LL num){
	string tmp;
	stringstream ss;
	ss << num; ss >> tmp;
	stringstream ss2;
	ss2 << string(tmp.rbegin(), tmp.rend());
	LL res;
	ss2 >> res;
	return res;
}

LL solve(void){
	LL n;
	cin >> n;
	return v[n];
}

int main(){
	int t;
	cin >> t;
	gen_numbers();
	for (int cs = 1; cs <= t; cs++){
		cout << "Case #" << cs << ": ";
		cout << solve() << endl;
	}
	return 0;
}
