#define _CRT_SECURE_NO_DEPRECATE
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <map>
#include <list>
#include <sstream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <iomanip>
#include <queue>
#include <set>	
#include <cstring>
using namespace std;
typedef long long		ll;
typedef pair<int, int>	ii;
typedef pair<ii, int>	iii;
typedef vector<ii>		vii;
typedef vector<iii>		viii;
typedef vector<int>		vi;
typedef vector<char>	vc;
typedef vector<vc>		vvc;
typedef vector<string>	vs;
typedef unsigned long long	ull;
typedef vector<ull>		vul;
typedef vector<bool>	vb;
typedef vector<vi>		vvi;
typedef vector<vii>		vvii;
typedef vector<double>	vd;
#define INF 1000000000
#define PI 3.14159265



int getMaxSize(int A, vi motes) {
	int maxA = A;
	vb used(motes.size(),false);
	for (int i=0; i<motes.size(); i++) {
		if (!used[i] && motes[i] < maxA) {
			used[i] = true;
			maxA += motes[i];
			i = -1;
			//cout << "\nmaxA " << maxA;
		}
	}
	return maxA;
}


int main(int argc, char *argv[]){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		cout << "Case #" << t << ": "; 
		int A, N;
		cin >> A >> N;
		vi motes(N);
		for (int i=0; i<N; i++) cin >> motes[i];

		int maxA = getMaxSize(A,motes);
		int removeMotes = 0;
		// count number of larger motes
		for (int i=0; i<N; i++) {
			//cout << "\nmotes[i]: "<<motes[i]<<", maxA: " << maxA << "ds ds " << removeMotes;
			if (motes[i] >= maxA) removeMotes ++;
		}
		int bestOp = removeMotes;
		if (maxA==1) removeMotes = 0;
		
		//cout << "\nExtra: 0, Remove: " << removeMotes;
		for (int addExtra=1; removeMotes>0; addExtra++) {
			//cout << "tmp";
			motes.push_back(maxA-1); // doubles size -1
			//cout << "\n Adding: -  "<< maxA-1 << " -";
			maxA = getMaxSize(A, motes);
			removeMotes = 0;
			//cout << "motes: ";
			for (int i=0; i<motes.size(); i++) {
				//cout << motes[i] << " ";
				if (motes[i] >= maxA) removeMotes ++;
			}
			//cout << endl;
			bestOp = min(bestOp,addExtra + removeMotes);
			//cout << "\nExtra: "<< addExtra <<", Remove: " << removeMotes;
		}

		cout << bestOp << endl;
	}

	return EXIT_SUCCESS;
}