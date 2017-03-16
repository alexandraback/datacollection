#include <bits/stdc++.h>
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
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890123456789LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	for(int t =0; t < T; t++) {
		cout << "Case #" << t+1 << ": ";
		string C,J;
		cin >> C >> J;
		int fd =0;
		int N =C.length();
		while(fd < N && (C[fd] == J[fd] || C[fd] == '?' || J[fd] == '?')) fd++;
		if(fd == N) {
			for(int i =0; i < N; i++) {
				if(C[i] == '?' && J[i] == '?') C[i] =J[i] ='0';
				else if(C[i] == '?') C[i] =J[i];
				else if(J[i] == '?') J[i] =C[i];}
			cout << C << " " << J << "\n";
			continue;}
		bool swp =false;
		if(C[fd] < J[fd]) {
			swap(C,J);
			swp =true;}
		string c,j;
		long long dif_opt =OVER9000;
		
		for(int i =0; i <= fd; i++) {
			string cn =C, jn =J;
			for(int j =0; j < i; j++) {
				if(cn[j] == '?' && jn[j] == '?') cn[j] =jn[j] ='0';
				else if(cn[j] == '?') cn[j] =jn[j];
				else if(jn[j] == '?') jn[j] =cn[j];}
			for(int j =i+1; j < N; j++) {
				if(cn[j] == '?') cn[j] ='0';
				if(jn[j] == '?') jn[j] ='9';}
			bool ok =true;
			if(cn[i] == '?' && jn[i] == '?') cn[i] ='1', jn[i] ='0';
			else if(cn[i] == '?') {
				cn[i] =jn[i]+1;
				if(jn[i] == '9') ok =false;}
			else if(jn[i] == '?') {
				jn[i] =cn[i]-1;
				if(cn[i] == '0') ok =false;}
			if(!ok) continue;
			long long dif =0;
			for(int i =0; i < N; i++) dif =dif*10+(cn[i]-jn[i]);
			if(dif < dif_opt) {
				dif_opt =dif;
				c =cn, j =jn;}
			if(dif == dif_opt && make_pair(c,j) > make_pair(cn,jn)) c =cn, j =jn;
			}

		for(int i =0; i < fd; i++) {
			string cn =C, jn =J;
			for(int j =0; j < i; j++) {
				if(cn[j] == '?' && jn[j] == '?') cn[j] =jn[j] ='0';
				else if(cn[j] == '?') cn[j] =jn[j];
				else if(jn[j] == '?') jn[j] =cn[j];}
			for(int j =i+1; j < N; j++) {
				if(cn[j] == '?') cn[j] ='9';
				if(jn[j] == '?') jn[j] ='0';}
			bool ok =true;
			if(cn[i] == '?' && jn[i] == '?') cn[i] ='0', jn[i] ='1';
			else if(cn[i] == '?') {
				cn[i] =jn[i]-1;
				if(jn[i] == '0') ok =false;}
			else if(jn[i] == '?') {
				jn[i] =cn[i]+1;
				if(cn[i] == '9') ok =false;}
			if(!ok) continue;
			long long dif =0;
			for(int i =0; i < N; i++) dif =dif*10+(jn[i]-cn[i]);
			if(dif < dif_opt) {
				dif_opt =dif;
				c =cn, j =jn;}
			if(dif == dif_opt && make_pair(c,j) > make_pair(cn,jn)) c =cn, j =jn;
			}
		
		if(swp) swap(c,j);
		cout << c << " " << j << "\n";}
	return 0;}

// look at my code
// my code is amazing
