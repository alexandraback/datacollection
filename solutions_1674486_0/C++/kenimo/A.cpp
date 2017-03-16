#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#define FOR(i, b, e) for (typeof(b) i = (b); i != (e); ++i)
#define VAR(a,b) typeof(b) a=b
#define dout cout
using namespace std;
typedef long long LL;

struct SCOPE
{
	vector<int> child[1000];
	vector<int> des[1000];

	bool update(int i){
		if (des[i].size()){
			return false;
		}

		des[i].push_back(i);

		vector<bool> cont(1000,false);
		FOR(q,0,child[i].size()){
			int j=child[i][q];
			if (update(j)){
				return true;
			}
			FOR(k,0,des[j].size()){
				int v=des[j][k];
				if(cont[v]){
					return true;
				}
				cont[v]=true;
				des[i].push_back(v);
			}
		}
		return false;
	}
	void run(int Case)
	{
		int N;
		cin >> N;
		FOR(i,0,N){
			int M;
			cin >> M;
			FOR(j,0,M){
				int k;
				cin >> k;
				child[i].push_back(k-1);
			}
		}

		cout << "Case #" << Case << ": ";
		FOR(i,0,N)
		{
			if(update(i)){
				cout << "Yes" << endl;
				return;
			}
		}

		cout << "No" << endl;
	}
};

int main() {
	int T;
	cin >> T;
	for (int t=1;t<=T;t++) {
		SCOPE* pSCOPE = new SCOPE();
		pSCOPE->run(t);
		delete pSCOPE;
	}
}

