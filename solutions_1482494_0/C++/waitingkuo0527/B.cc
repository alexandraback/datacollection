#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;

int N;
int star1[1001];
int star2[1001];

bool mycomp(pair<int,int> p1, pair<int,int> p2)
{
	return p1.second < p2.second;
}


void solve()
{
	vector<pair<int,int> > v;
	for (int i=0; i<N; i++) {
		pair<int,int> p(star1[i],star2[i]);
		v.push_back(p);
	}

	sort(v.begin(), v.end(), mycomp);

	//for (int i=0; i<N; i++) {
	//	cout << v[i].first << " " << v[i].second << " ";
	//}
	//	cout << endl;

	int ans = 0;
	int count = 0;
	long long stars = 0;
	while (count < N) {
		int test = 0;
		for (int i=v.size()-1; i>=0; i--) {
			if (stars >= v[i].second) {
				test = 1;
				if (v[i].first == -1) stars += 1;
				else stars += 2;
				v.erase(v.begin() + i);
				count ++;
				ans++;
				//break;
			}
		}
		if (test == 1) continue;

		for (int i=v.size()-1; i>=0; i--) {
			if (v[i].first != -1 && v[i].first <= stars) {
				v[i].first = -1;
				stars += 1;
				test = 1;
				ans++;
				break;
			}
		}
		if (test == 0) {
			cout << "Too Bad" << endl;
			return;
		}
	}

	cout << ans << endl;
/*
	sort(star1, star1+N);	
	sort(star2, star2+N);	
	//for (int i=0; i<N; i++) cout << star1[i] << " ";
	//cout << endl;
	//for (int i=0; i<N; i++) cout << star2[i] << " ";
	//cout << endl;

	bool have_played_1[1001];
	bool have_played_2[1001];
	for (int i=0; i<1001; i++) {
		have_played_1[i] = false;
		have_played_2[i] = false;
	}

	int ans = 0;
	long long stars = 0;
	int count1 = 0;
	int count2 = 0;
	
	while (count2 < N) {
		if (stars>=star2[count2]) {
			have_played_2[count2] == true;
			if (have_played_1[count2] == false) {
				stars += 2;
				have_played_1[count2] == true;
			}
			else {
				stars += 1;
			}
			count2++;
			ans++;
		}
		else if (stars>=star1[count1]) {
			if (have_played_1[count1] == true) {
				continue;
			}
			stars += 1;	
			count1++;
			ans++;
		}
		else {
			cout << "Too Bad" << endl;
			return;
		}
			
	}

	cout << ans << endl;
	//cout << N + count1 << endl; 
*/
}


int main()
{
	int case_num;
	cin >> case_num;

	for (int t=1; t<=case_num; t++) {
		// initialization, IO
		cin >> N;
		for (int i=0; i<N; i++) cin >> star1[i] >> star2[i];

		cout << "Case #" << t << ": ";
		solve();

	}
}
