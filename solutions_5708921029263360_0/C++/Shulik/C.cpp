#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)

#define mt make_tuple

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef tuple<int, int, int> outfit;


int j, p, s, k;
int cnt;
vector<outfit> pos;

map<tuple<int, int, int, int>, vector<outfit> > solutions;

bool valid(int bm){
	map<outfit, int> cnts;
	int a,b,c;
	REP(i, cnt)if((1<<i) & bm){
		tie(a,b,c) = pos[i];
		cnts[mt(a,b,-1)]++;
		cnts[mt(a,-1,c)]++;
		cnts[mt(-1,b,c)]++;
	}
	for(auto x : cnts)if(x.second > k)return false;
	return true;
}

void testcase(int T){
	scanf("%d%d%d%d", &j, &p, &s, &k);
	k = min(k, 3);

	vector<outfit> res;
	if(solutions.find(mt(j, p, s, k)) == solutions.end()){

		cnt = j*p*s;

		pos.clear();

		REP(a, j)REP(b, p)REP(c, s)pos.push_back(mt(a, b, c));

		int bstc = -1;
		int bst = -1;
		REP(i, (1<<cnt)){
			if(__builtin_popcount(i) <= 18 && valid(i)){
				if(__builtin_popcount(i) > bstc){
					bstc=__builtin_popcount(i);
					bst = i;
				}
			}
		}
		REP(i, cnt)if((1<<i) & bst){
			res.push_back(pos[i]);
		}

		solutions[mt(j, p, s, k)] = res;
	}

	res = solutions[mt(j, p, s, k)];
	int a, b,c;

	printf("Case #%d: %d\n", T, (int)res.size());
	for(auto x : res){
		tie(a,b,c) = x;
		printf("%d %d %d\n", a+1,b+1,c+1);
	}

}

int main(){

	vector<outfit> res1 = {
		mt(0, 0, 0),
		mt(0, 0, 1),
		mt(0, 0, 2),
		mt(0, 1, 0),
		mt(0, 1, 1),
		mt(0, 1, 2),
		mt(0, 2, 0),
		mt(0, 2, 1),
		mt(0, 2, 2),
		mt(1, 0, 0),
		mt(1, 0, 1),
		mt(1, 0, 2),
		mt(1, 1, 0),
		mt(1, 1, 1),
		mt(1, 1, 2),
		mt(1, 2, 0),
		mt(1, 2, 1),
		mt(1, 2, 2),
		mt(2, 0, 0),
		mt(2, 0, 1),
		mt(2, 0, 2),
		mt(2, 1, 0),
		mt(2, 1, 1),
		mt(2, 1, 2),
		mt(2, 2, 0),
		mt(2, 2, 1),
		mt(2, 2, 2)
	};

	vector<outfit> res2 = {
		mt(0, 0, 0),
		mt(0, 0, 2),
		mt(0, 1, 0),
		mt(0, 1, 1),
		mt(0, 2, 1),
		mt(0, 2, 2),
		mt(1, 0, 0),
		mt(1, 0, 1),
		mt(1, 1, 1),
		mt(1, 1, 2),
		mt(1, 2, 0),
		mt(1, 2, 2),
		mt(2, 0, 1),
		mt(2, 0, 2),
		mt(2, 1, 0),
		mt(2, 1, 2),
		mt(2, 2, 0),
		mt(2, 2, 1)
	};

	vector<outfit> res3 = {
		mt(0, 0, 0),
		mt(1, 1, 1),
		mt(2, 2, 2), 
		mt(0, 1, 2),
		mt(0, 2, 1),
		mt(1, 0, 2),
		mt(1, 2, 0),
		mt(2, 1, 0),
		mt(2, 0, 1)
	};

	solutions[mt(3, 3, 3, 3)] = res1;
	solutions[mt(3, 3, 3, 1)] = res3;
	solutions[mt(3, 3, 3, 2)] = res2;

	int T;
	cin >> T;
	REP(i, T)testcase(i+1);


	return 0;
}
