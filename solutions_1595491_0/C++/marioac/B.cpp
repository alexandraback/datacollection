//#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

ifstream cin("B-small-attempt0.in");
ofstream cout("B-small.out");

int main() {
int T;

cin >> T;
for (int tt=1; tt<=T; tt++) {
vector<int> total;
int N,S,p;
cin >> N >> S >> p;

for (int i=0; i<N; i++) {
	int ll;
	cin >> ll;
	total.push_back(ll);
}

sort(total.begin(), total.end());
reverse(total.begin(), total.end());

int totali = 0;

for (int i=0; i<total.size(); i++) {
	if (3*p <= total[i]) { totali++; continue; }
	if (p+2*(p-1) <= total[i] && (p-1)>=0) totali++;
	else {
		if (S==0) break;
		if (p+2*(p-2) <= total[i] && (p-2)>=0) { S--; totali++; } else break;
	}
}

cout << "Case #"<<tt<<": " << totali << endl;
}


return 0;
}
