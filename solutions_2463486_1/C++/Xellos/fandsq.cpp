// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	int T;
	long long A,B;
	cin >> T;
	map<long long,int> fsq;
	for(long long i =1; i <= 10000000LL; i++) {
		string s;
		long long b =i;
		bool Bb =true;
		while(b > 0) {
			s +=(char)(b%10+'0');
			b /=10;}
		for(uint j =0; j < s.length(); j++) if(s[j] != s[s.length()-1-j]) {
			Bb =false;
			break;}
		if(!Bb) continue;
		b =i*i;
		s.clear();
		while(b > 0) {
			s +=(char)(b%10+'0');
			b /=10;}
		for(uint j =0; j < s.length(); j++) if(s[j] != s[s.length()-1-j]) {
			Bb =false;
			break;}
		if(Bb) fsq[i*i] =0;}
	fsq[0] =0;
	int x =0;
	ALL_THE(fsq,it) {
		it->second =x;
		x++;}
	
	for(int t =0; t < T; t++) {
		cin >> A >> B;
		auto it =fsq.lower_bound(A), jt =fsq.upper_bound(B);
		--it, --jt;
		cout << "Case #" << t+1 << ": " << (jt->second)-(it->second) << endl;}
	return 0;}
        
// look at my code
// my code is amazing
