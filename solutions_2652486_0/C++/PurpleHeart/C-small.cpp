#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int cases, R, N, M, K;
vector<int> gs, ps;

int gao(int x, int y, int z){
	ps.push_back(x);
	ps.push_back(y);
	ps.push_back(z);
	ps.push_back(x*y);
	ps.push_back(x*z);
	ps.push_back(y*z);
	ps.push_back(x*y*z);
}

int main(){
	scanf("%d", &cases);
	puts("Case #1:");
	scanf("%d%d%d%d", &R, &N, &M, &K);
	for(int i = 0; i < R; ++i){
		gs.clear();
		for(int j = 0; j < K; ++j){
			int x;
			scanf("%d", &x);
			if(x != 1) gs.push_back(x);
		}
		if(gs.size() == 0) puts("222");
		else{
			string pp = "";
			for(int x1 = 2; x1 <= M; ++x1)
				for(int x2 = 2; x2 <= M; ++x2)
					for(int x3 = 2; x3 <= M; ++x3){
						ps.clear();
						gao(x1, x2, x3);
						sort(ps.begin(), ps.end());
						bool ok = true;
						for(int j = 0; j < gs.size(); ++j){
							vector<int>::iterator it = lower_bound(ps.begin(), ps.end(), gs[j]);
							if(it == ps.end() || (*it != gs[j])) ok = false;
						}
						if(ok) {
							//printf("OK: %d %d %d\n", x1, x2, x3);
							char t1 = x1 + '0';
							char t2 = x2 + '0';
							char t3 = x3 + '0';
							pp = t1;
							pp = pp + t2;
							pp = pp + t3;
						}
					}
			if(pp == "") puts("222");
			else cout << pp << endl;
		}
	}
}
