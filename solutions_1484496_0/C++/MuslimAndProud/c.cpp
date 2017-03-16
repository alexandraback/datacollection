#include <iostream>
#include <fstream>

#include <vector>
#include <algorithm>
#include <map>

#define REP(i,a,b)		for(i=(int)a ; i<=(int)b ; i++)
#define FOR(i,N)		REP(i,0,N-1)

#define VI				vector<int>
#define VVI				vector<VI>

using namespace std;

VI N;

int main(){
	ifstream cin("input.txt");
	ofstream cout("c1.out");
	int T;
	cin >> T;
	int cnt;
	REP(cnt,1,T){
		int i,j,k;
		int n;
		cin >> n;
		N.resize(n);
		FOR(i,n)
			cin >> N[i];

		map<int,VI> nums;
		VI sum;

		nums[0] = VI();
		sum.push_back(0);

		VI ans1;
		VI ans2;

		bool flg = false;
		FOR(i,n){
			int m = sum.size();
			FOR(j,m){
				k = sum[j] + N[i];
				if(nums.find(k) != nums.end()){
					flg = true;
					ans1 = nums[k];
					ans2 = nums[sum[j]];
					ans2.push_back(N[i]);
					break;
				}
				sum.push_back(k);
				nums[k] = nums[sum[j]];
				nums[k].push_back(N[i]);
			}
			if(flg)
				break;
		}

		cout <<"Case #"<<cnt<<":"<<endl;
		if(flg){
			FOR(i,ans1.size()){
				if(i) cout <<" ";
				cout << ans1[i];
			}
			cout << endl;
			FOR(i,ans2.size()){
				if(i) cout <<" ";
				cout << ans2[i];
			}
			cout << endl;
		}
		else
			cout << "Impossible" << endl;
	}
}