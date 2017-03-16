#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<queue>
#include <stdlib.h>
#include <unordered_set>
#include <memory.h>
#include <iomanip>
#include<stack>
#include<vector>
#include<string>
#include <deque>
#include <unordered_map>
//#include<unordered_set>
using namespace std;
typedef long long ll;
typedef long double ld;

set <pair<int, int> > st;
void print(int tst){
	cout << "Case #" << tst << ": ";
}


//int ans[100][100];
//int jp[100][100];
//int ps[100][100];
int d[100];

vector <int> ans1;
vector <int> ans2;
vector <int> ans3;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++){
		ans1.clear();
		ans2.clear();
		ans3.clear();
		int j, p, s;
		cin >> j >> p >> s;
		int k;
		cin >> k;
		for (int i2 = 1; i2 <= p; i2++){
			for (int i1 = 1; i1 <= s; i1++){
				d[i1] = 0;
			}
			int cur = 1;
			for (int i1 = 1; i1 <= j; i1++){
				for (int t = 1; t <= min(k, s); t++){
					if (d[cur] < k){
						d[cur]++;
						ans1.push_back(i1);
						ans2.push_back(i2);
						ans3.push_back(cur);
					}
					else{
						cur++;
						if (cur > s){
							cur = 1;
						}
						break;
					}
					cur++;
					if (cur > s){
						cur = 1;
					}
				}
			}
		}
		print(i);
		cout << ans1.size() << "\n";
		for (int i = 0; i < (int)ans1.size(); i++){
			cout << ans1[i] << " " << ans2[i] << " " << ans3[i] << "\n";
		}
	}

	return 0;
}