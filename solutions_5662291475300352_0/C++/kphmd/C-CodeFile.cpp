#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <set>
#include <utility>
#include <stack>

#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;

void solve();
void runCase();

void runCase()
{
	int N,D,H,M;
	vector<pair<int,int> > hi;
	cin >> N;
	rep(i,N) {
		cin >> D >> H >> M;
		rep(j,H) {
			hi.push_back(make_pair(-(M+j),D));
		}
	}
	
	sort(hi.begin(),hi.end());
	
	int rv = 0;
	if(hi.size()==1) rv = 0;
	else {
		long long fast,slow;
		slow = (360LL-hi[0].second)*(-hi[0].first);
		fast = (720LL-hi[1].second)*(-hi[1].first);
		if(slow>=fast) rv = 1;
		else rv = 0;
		// if(hi[0].first==hi[1].first) {
			// long long fast = (720.0-hi[0].first)/(360.0/hi[0].second);
			// double slow = (360.0-hi[1].first)/(360.0/hi[1].second);
			// if(slow >= fast) rv = 1;
			// else rv = 0;
		// } else {
			// double slow = (360.0-hi[0].first)/(360.0/hi[0].second);
			// double fast = (720.0-hi[1].first)/(360.0/hi[1].second);
			// if(slow >= fast) rv = 1;
			// else rv = 0;
		// }
	}
	printf("%d\n",rv);
}

void runSample()
{
	string input;

	char buf[501] = {0};
	cin.getline(buf,501);

	input = buf;


	printf("%s\n",input.c_str());
}

void solve()
{
	int n;
	scanf("%d",&n);
	getchar();

	for(int i = 0; i < n; i++) {
		printf("Case #%d: ",i+1);
		runCase();
		//runSample();
	}
}

int main()
{
	solve();
	return 0;
}
