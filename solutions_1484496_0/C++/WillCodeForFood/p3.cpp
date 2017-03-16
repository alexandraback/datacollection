#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define vs vector<string>
#define vi vector<int>
#define pii pair<int,int>
#define vvi vector< vector<int> >
#define vpi vector< pair<int,int> >
#define LL long long


int main() {
        int T; cin >> T;
        for(int iter=0;iter<T;iter++) {
			multimap<int,int> sums;
			int N; cin >> N;
			vi nos(N);
			int ans1, ans2;
			ans1 = ans2 = -1;
			for(int i=0;i<N;++i) cin>>nos[i];
			for(int i = 1; i < (1<<N); ++i) {
				int s = 0;
				for(int j=0;j<N;++j) {
					if (((i>>j)&1)) s+=nos[j];
				}
				if (sums.count(s) == 0) 
					sums.insert(pair<int,int>(s,i));
				else {
					pair<multimap<int, int>::iterator, multimap<int, int>::iterator> ppp = sums.equal_range(s);
					for(multimap<int,int>::iterator it = ppp.first; it != ppp.second; ++it) {
						int set = (*it).second;
						bool d = true;
						for(int j=0;j<N && d;++j) {
							if(((i>>j)&1) && ((set>>j)&1))
								d = false;
						}
						if (d) {
							ans1 = i;
							ans2 = set;
							goto exit;
						}
					}
					sums.insert(pair<int,int>(s,i));
				} 
			}
			exit:
			printf("Case #%d:\n",(iter+1));
			if (ans1 != -1) {
				for(int i=0;i<N;++i) 
				if(((ans1>>i)&1)) cout << nos[i] << " ";
				cout << "\n";
				for(int i=0;i<N;++i) 
				if(((ans2>>i)&1)) cout << nos[i] << " ";
				cout << "\n";
			} else
				cout <<"Impossible\n";
	}
}

