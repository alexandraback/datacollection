#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;


void testcase(int T){
	int b;
	ll m;

	scanf("%d%lld", &b, &m);

	printf("Case #%d: ", T);

	if(m > (1ll<<(b-2))){
		printf("IMPOSSIBLE\n");
		return;
	}
	printf("POSSIBLE\n");

	bool add = false;
	if(m == (1ll<<(b-2))){
		add = true;
		m--;
	}
	vector<int> prnt;
	prnt.push_back(add ? 1 : 0);
	while(m > 0){
		prnt.push_back((m&1) ? 1 : 0);
		m/=2;
	}
	while(prnt.size() < b)prnt.push_back(0);
	for(int i = -1+(int)prnt.size(); i>= 0; i--)printf("%d", prnt[i]);
	printf("\n");
	for(int i = 1; i < b; i++){
		for(int j = 0; j < b; j++)printf("%d", j > i ? 1 : 0);
		printf("\n");
	}
}

int main(){
	int T;
	cin >> T;
	REP(i, T)testcase(i+1);


	return 0;
}
