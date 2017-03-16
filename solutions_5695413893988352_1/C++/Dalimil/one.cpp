#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

string a, b; 
int n;

vector<vi> ans1, ans2, ans3, ans4;
// t = 1 maximise a ; t = -1 minimize a (max b) ; t = 0 equal
ll valA, valB;
ll bestA, bestB;
void solve(int pos, int t){
	//cout << pos <<" " << t << " - " << valA <<" " << valB << endl;
	if(pos == n){
		//cout << "ok "<<valA <<" " << valB << endl;
		// compare ans
		if(bestA == -1){
			bestA = valA;
			bestB = valB;
		}else{
			if(abs(valA - valB) < abs(bestA - bestB)){
				bestA = valA;
				bestB = valB;
			} else if(abs(valA - valB) == abs(bestA - bestB)){
				if(valA < bestA || (valA == bestA && valB < bestB) ){
					bestA = valA;
					bestB = valB;
				}
			}
		}
		//cout << "ok "<<valA <<" " << valB << " _ _ "<< bestA <<" " << bestB << endl;
		return;
	}

	// both fixed
	if(ans1[pos].size() == 1){
		valA = valA*10 + ans1[pos][0];
		valB = valB*10 + ans2[pos][0];
		if(t == 0){
			if(ans1[pos][0] < ans2[pos][0]) t = 1;
			else if(ans1[pos][0] > ans2[pos][0]) t = -1;
		}
		solve(pos+1, t);
		valA /= 10;
		valB /= 10;
		return;
	}

	if(t == 0){
		// 3 options
		// equal
		valA = valA*10 + ans1[pos][0];
		valB = valB*10 + ans2[pos][0];
		solve(pos+1, t); // still is equal
		valA /= 10;
		valB /= 10;

		// take max A
		// but only +1
		valA = valA*10 + ans3[pos][1];
		valB = valB*10 + ans4[pos][1];
		int tt = 0;
		if(ans3[pos][1] < ans4[pos][1]) tt = 1;
		else if(ans3[pos][1] > ans4[pos][1]) tt = -1;
		solve(pos+1, tt);
		valA /= 10;
		valB /= 10;

		// take max B
		// but only +1
		valA = valA*10 + ans3[pos][2];
		valB = valB*10 + ans4[pos][2];
		tt = 0;
		if(ans3[pos][2] < ans4[pos][2]) tt = 1;
		else if(ans3[pos][2] > ans4[pos][2]) tt = -1;
		solve(pos+1, tt);
		valA /= 10;
		valB /= 10;
	} else if(t == 1){
		// take max A
		valA = valA*10 + ans1[pos][1];
		valB = valB*10 + ans2[pos][1];
		solve(pos+1, t);
		valA /= 10;
		valB /= 10;
	} else { // t == -1
		// take max B
		valA = valA*10 + ans1[pos][2];
		valB = valB*10 + ans2[pos][2];
		solve(pos+1, t);
		valA /= 10;
		valB /= 10;
	}
}

int main(){
	int T; cin >> T;
	for(int t=1;t<=T;t++){
		cin >> a >> b;
		n = a.length();
		int sign = 0; // 1 means a > b
		ans1 = vvi(n);
		ans2 = vvi(n);
		ans3 = vvi(n);
		ans4 = vvi(n);
		valA = 0;
		valB = 0;
		bestA = -1;
		bestB = -1;
		for(int i=0;i<n;i++){
			if(a[i] != '?' && b[i] != '?'){
				ans1[i].push_back(a[i]-'0');
				ans2[i].push_back(b[i]-'0');
				continue;
			}

			
			if(a[i] == '?' && b[i] == '?'){
				// equal
				ans1[i].push_back(0);
				ans2[i].push_back(0);
				ans3[i].push_back(0);
				ans4[i].push_back(0);
				// max A
				ans1[i].push_back(9);
				ans2[i].push_back(0);
				ans3[i].push_back(1);
				ans4[i].push_back(0);
				// max B
				ans1[i].push_back(0);
				ans2[i].push_back(9);
				ans3[i].push_back(0);
				ans4[i].push_back(1);
			} else if(a[i] == '?'){
				// equal
				int d = b[i]-'0';
				ans1[i].push_back(d);
				ans2[i].push_back(d);
				ans3[i].push_back(d);
				ans4[i].push_back(d);
				// max A
				//if(d != 9){
					ans1[i].push_back(9);
					ans2[i].push_back(d);
					ans3[i].push_back(min(d+1, 9));
					ans4[i].push_back(d);
				//}
				// max B
				//if(d != 0){
					ans1[i].push_back(0);
					ans2[i].push_back(d);
					ans3[i].push_back(max(d-1, 0));
					ans4[i].push_back(d);
				//}
			} else if(b[i] == '?'){
				// equal
				int d = a[i]-'0';
				ans1[i].push_back(d);
				ans2[i].push_back(d);
				ans3[i].push_back(d);
				ans4[i].push_back(d);
				// max A
				//if(d != 0) {
					ans1[i].push_back(d);
					ans2[i].push_back(0);
					ans3[i].push_back(d);
					ans4[i].push_back(max(d-1, 0));
				//}
				// max B
				//if(d != 9){
					ans1[i].push_back(d);
					ans2[i].push_back(9);
					ans3[i].push_back(d);
					ans4[i].push_back(min(d+1, 9));
				//}
			}
		}
		solve(0, 0);
		stringstream ss1, ss2;
		ss1 << bestA;
		ss2 << bestB;
		string myA = ss1.str(), myB = ss2.str();
		while(myA.length() < n) myA = "0"+myA;
		while(myB.length() < n) myB = "0"+myB;
		cout << "Case #"<<t<<": "<<myA << " " << myB << endl;
	}

}
