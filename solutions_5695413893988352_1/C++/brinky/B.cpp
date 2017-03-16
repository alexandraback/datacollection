#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <cstring>

using namespace std;

string c, j;
long long bestc;
long long bestj;

void rek(long long cc, long long cj, int p){
	if(p == c.size()){
		if(abs(cj - cc) < abs(bestj - bestc)){
			bestc = cc;
			bestj = cj;
		}else if(abs(cj - cc) == abs(bestj - bestc)){
			if((cc < bestc) || (cc == bestc && cj < bestj)){
				bestc = cc;
				bestj = cj;
			}
		}
		return;
	}
	cc *= 10;
	cj *= 10;
	long long sc = c[p] - '0', sj = j[p] - '0';
	if(cc == cj){
		if(c[p] == '?' && j[p] == '?'){
			rek(cc, cj, p+1);
			rek(cc+1, cj, p+1);
			rek(cc, cj+1, p+1);
			return;
		}
		if(c[p] == '?'){
			sc = sj;
			rek(cc + sc, cj + sj, p+1);
			sc = (sj + 1) % 10;
			rek(cc + sc, cj + sj, p+1);
			sc = (sj + 9) % 10;
			rek(cc + sc, cj + sj, p+1);
			return;
		}
		if(j[p] == '?'){
			sj = sc;
			rek(cc + sc, cj + sj, p+1);
			sj = (sc + 1) % 10;
			rek(cc + sc, cj + sj, p+1);
			sj = (sc + 9) % 10;
			rek(cc + sc, cj + sj, p+1);
			return;
		}
	}else if(cc > cj){
		if(c[p] == '?'){
			sc = 0;
		}
		if(j[p] == '?'){
			sj = 9;
		}
	}else{
		if(c[p] == '?'){
			sc = 9;
		}
		if(j[p] == '?'){
			sj = 0;
		}
	}
	rek(cc + sc, cj + sj, p+1);
}

char b[255];

void p(long long d, int s){
	sprintf(b, "%lld", d);
	for(int i=0; i<s - strlen(b); ++i){
		printf("0");
	}
	printf("%s", b);
}

int main(){
	int tcn, tc;
	cin >> tcn;
	for(tc = 1; tc <= tcn; ++tc){
		bestc = 1000000000000000000ll;
		bestj = 0ll;
		cin >> c >> j;
		rek(0ll, 0ll, 0);
		printf("Case #%d: ", tc);
		p(bestc, c.size());
		printf(" ");
		p(bestj, c.size());
		printf("\n");
	}
}
