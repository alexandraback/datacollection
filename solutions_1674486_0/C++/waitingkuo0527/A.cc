#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;

int N;
int M[1001];
vector<int> par[1001];

void print()
{
	for (int i=0; i<N; i++) {
		cout << i <<": ";
		for (int j=0; j<par[i].size(); j++) {
			cout << par[i][j] << " ";
		}
		cout << endl;
	}

}
void solve()
{

	int conti = 1;
	while (conti) {
		conti = 0;
		for (int i=0; i<N && !conti; i++) {
			for (int j=0; j<par[i].size() && !conti; j++) {
				int p = par[i][j];
				if (par[p].size() >= 1) {
					par[i].erase(par[i].begin()+j);
					for (int k=0; k<par[p].size(); k++) {
						par[i].push_back(par[p][k]);
					}
					conti = 1;
					break;
				}
			}
		}
	}

	for (int i=0; i<N; i++) {
		if (par[i].size() >= 1)
			sort(par[i].begin(), par[i].end());
		
		for (int j=0; j<(int)par[i].size()-1; j++) {
			if (par[i][j] == par[i][j+1]) {
				cout << "Yes" << endl;
				return;
			}
		}
	}

	cout << "No" << endl;
}


int main()
{
	int case_num;
	cin >> case_num;

	for (int t=1; t<=case_num; t++) {
		// initialization, IO
		cin >> N;
		for (int i=0; i<N; i++) par[i].clear();
		for (int i=0; i<N; i++) {
			cin >> M[i];
			int tmp;
			for (int j=0; j<M[i]; j++) {
				cin >> tmp;
				par[i].push_back(tmp-1);
				}
		}


		cout << "Case #" << t << ": ";
		solve();

	}
}
