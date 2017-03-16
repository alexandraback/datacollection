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
#include<string>
#include<sstream>
#include<numeric>
#include<complex>
#include<cassert>
#include<queue>
using namespace std;

#define big long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int SIZE = 300;
int N, arr[SIZE], X;

bool ok(int idx, double V){

	double Vscore = arr[idx]+V*X;
	double rem = 1-V;
	for(int i = 0 ; i < N ; i++){
		if(idx == i)
			continue;
		if(fabs(arr[i]-Vscore) < EPS || arr[i] > Vscore)
			continue;
		double req = (Vscore-arr[i]*1.)/X;
		if(fabs(req-rem) > EPS && req > rem)
			return true;
		rem -= req;
	}
	return fabs(rem) <= EPS;
}

double solve(int idx){

	double low = 0, high = 1, mid;
	for(int it = 0 ; it <= 1000 ; it++){
		mid = (low+high)/2;
		if(ok(idx, mid))
			high = mid;
		else
			low = mid;
	}
	return mid;
}

int main(){

	//freopen("1.in", "rt", stdin);
	//freopen("1.out", "wt", stdout);
	//freopen("A-small-attempt0.in", "rt", stdin);
	//freopen("A-small-attempt0.out", "wt", stdout);
	freopen("A-large.in", "rt", stdin);
	freopen("A-large.out", "wt", stdout);

	int tt; scanf("%d ", &tt);
	for(int t = 0 ; t < tt ; t++){
		cerr << "Solving testcase " << t+1 << endl;
		cin >> N;
		X = 0;
		for(int i = 0 ; i < N ; i++){
			cin >> arr[i];
			X += arr[i];
		}

		printf("Case #%d:", t+1);
		for(int i = 0 ; i < N ; i++){
			printf(" %.9f", solve(i)*100);
		}
		printf("\n");
	}

	return 0;
}
