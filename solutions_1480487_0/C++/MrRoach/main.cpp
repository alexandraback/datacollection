#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;
int t;
int n;
int score[300];
int main(){
	cin>>t;
	for (int times = 0; times < t; ++times){
		cin>>n;
		int A = 0;
		for (int i = 0;i < n; ++i){
			cin >> score[i];
			A += score[i];
		}
		printf("Case #%d:", times + 1);
		for (int i = 0; i < n; ++i){
			double remain = 2*A;
			int num = n;
			bool visit[300];
			memset(visit, false, sizeof(visit));
			visit[i] = true;
			while (num > 1) {
				int maxs = -1;
				int maxi = 0;
				for (int j = 0; j < n; ++j){
					if (visit[j]) continue;
					if (score[j] > maxs){
						maxs = score[j];
						maxi = j;
					}
				}
				visit[maxi] = true;
				if (maxs > remain/num) {
					remain -= maxs;
				}else {
					remain -= remain/num;
				}
				num --;
			}
			double d = (remain - score[i]) / double(A);
			if (d < 0) d = 0;
			cout<<setprecision(10) << " " << 100*d;
		}
		printf("\n");
	}
	return 0;
}