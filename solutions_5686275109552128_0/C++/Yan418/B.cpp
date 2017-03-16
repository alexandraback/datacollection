#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

inline int calcK(int x,int left){
	//int k = 0;
	/*while (k<=left){
		int maxT;
		if (x % (k + 1) == 0){
			maxT = x / (k + 1);
		}
		else
			maxT = x / (k + 1) + 1;
		if (maxT > left) k++;
		else
			break;
	}*/
	return x / left - (x % left == 0 ? 1 : 0);
	//return k;
}

bool isPosi(int t,const vector<int>& P){
	if (P[0] <= t)
		return true;
	for (int spe = 0; spe < t; spe++){
		int speLeft = spe;
		for (int i = 0; i < P.size(); i++){
			if (P[i] <= t - spe)
				return true;
			int k = calcK(P[i],t - spe);
			speLeft -= k;
			if (speLeft < 0) break;
		}
		if (speLeft >= 0)
			return true;
	}
	return false;
}
int main(){
	int n;
	ifstream inf("B-small-attempt0.in");
	ofstream outf("B-small-attempt0.out");
	inf >> n;
	int D, x;
	for (int i = 1; i <= n; i++){
		vector<int> P;
		inf >> D;
		for (int j = 0; j < D; j++) {
			inf >> x;
			P.push_back(x);
		}
		sort(P.begin(), P.end(), [](int x, int y){ return x > y; });
		int slow = P[0],fast = 0;
		while (fast!=slow){
			if (isPosi((fast + slow) / 2,P))
				slow = (fast + slow) / 2;
			else
				fast = (fast + slow) / 2 + 1;
		}

		outf << "Case #" << i << ": " << slow << "\n";
	}


	return 0;
}