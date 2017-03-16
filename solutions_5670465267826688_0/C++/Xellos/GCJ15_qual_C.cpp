// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int mult[4][4] ={
	{1,2,3,4},
	{2,-1,4,-3},
	{3,-4,-1,2},
	{4,3,-2,-1}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int t =0; t < T; t++) {
		cout << "Case #"  << t+1 << ": ";
		int L,X;
		string S;
		cin >> L >> X >> S;
		if(X > 20) X =20+X%4;
		string s;
		for(int i =0; i < X; i++) s +=S;
		L *=X;
		vector<int> pref(L+1,1),suf(L+1,1);
		for(int i =0; i < L; i++) {
			int c =s[i]-'i'+2;
			pref[i+1] =mult[abs(pref[i])-1][abs(c)-1]*pref[i]*c/abs(pref[i])/abs(c);}
		for(int i =L-1; i >= 0; i--) {
			int c =s[i]-'i'+2;
			suf[i] =mult[abs(c)-1][abs(suf[i+1])-1]*suf[i+1]*c/abs(suf[i+1])/abs(c);}
		if(pref[L] != -1) {cout << "NO\n"; continue;}
		int ii =-1, ik =L+1;
		for(int i =0; i <= L; i++) if(pref[i] == 2) {ii =i; break;}
		for(int i =0; i <= L; i++) if(suf[i] == 4) ik =i;
		if(ii >= 0 && ik <= L && ii < ik) cout << "YES\n";
		else cout << "NO\n";}
	return 0;}

// look at my code
// my code is amazing
