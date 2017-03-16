//Catch me if you can!
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<cstring>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
using namespace std;

#define big unsigned long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int E, R, N, arr[100];
int table[100][100];

int get(int i, int rem){
	if(i >= N)return 0;
	if(table[i][rem] != -1)return table[i][rem];

	int best = 0;
	for(int j = 0 ; j <= rem ; j++){
		int current = j*arr[i]+get(i+1, min(E, rem-j+R));
		best = max(current, best);
	}

	return table[i][rem] = best;
}

int main(){

	//freopen("1.in", "rt", stdin);
	freopen("C-small-1-attempt1.in", "rt", stdin);
	freopen("C-small-1-attempt1.out", "wt", stdout);

	cout << "Case #1:" << endl;

	int temp, TT, N, M, K; cin >> temp >> TT >> N >> M >> K;
	for(int t = 1 ; t <= TT ; t++){

		map<int, int> m;
		for(int i = 0 ; i < K ; i++){
			int x; cin >> x;
			m[x]++;
		}

		int best = 0;
		vector<int> bestv;
		bestv.push_back(2);bestv.push_back(3);bestv.push_back(2);
		for(int a = 2 ; a <= M ; a++)
			for(int b = a ;b <= M ; b++)
				for(int c = b ; c <= M ; c++){
					set<int> s;
					vector<int> v;
					int cur =0;
					v.push_back(a);v.push_back(b);v.push_back(c);
					for(int i = 0 ; i < 8 ; i++){
						int p = 1;
						for(int j = 0 ; j < 3 ; j++)
							if((i>>j)&1)
								p *= v[j];
						s.insert(p);
					}
					for(set<int>::iterator itr = s.begin() ; itr != s.end() ; itr++)
						cur += m[*itr];

					if(cur > best){
						best = cur;
						bestv = v;
					}
//
//					for(int i = 0 ; i < 3 ; i++)
//						cout << v[i];
//					cout << " -> " << cur << endl;
				}
		for(int i = 0 ; i < 3 ; i++)
			cout << bestv[i];
		cout << endl;
	}

	return 0;
}
