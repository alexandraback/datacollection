#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <list>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iterator>
#include <complex>
#include <stack>
#include <queue>
#include <ctime>
#include <cassert>
//#include <NTL/ZZ.h>
using namespace std;
//using namespace NTL;
static const double EPS = 1e-8;
typedef long long ll;
typedef unsigned long long ull;
typedef complex <double> pt;
typedef complex <ll> pti;

vector <pair <ll, int> > factorp(ll n) {
	vector <pair <ll, int> > f;

	for(ll i=2; i*i<=n; i++) {
		int cnt=0;
		while(n%i==0) { n/=i; cnt++; }
		if(cnt) f.push_back(make_pair(i, cnt));
	}
	if(n>1) f.push_back(make_pair(n, 1));

	return f;
}

vector <int> solve2(int N, int M, int K, vector <ll> &v) {
	vector <int> res;
	srand(time(NULL));

	vector <int> cnt[10];
	for(int i=0; i<K; i++) {
		vector <pair <ll, int> > vp2=factorp(v[i]);
		for(int i=0; i<(int)vp2.size(); i++) {
			pair <ll, int> &p=vp2[i];
			cnt[p.first].push_back(p.second);
		}
	}

	for(int i=2; i<=M; i++) {
		if(!cnt[i].empty() && (i==5 || i==7)) {
			for(int j=0; j<*max_element(cnt[i].begin(), cnt[i].end()); j++) res.push_back(i);
		}
	}
	int rem=N-(int)res.size();
	assert(rem>=0);
	int rem3=rem;
	for(int i=0; i<(int)cnt[2].size(); i++) {
		int val=cnt[2][i];
		int c=val/3;
		val%=3;
		c+=val/2;
		rem3=max(rem3, rem-c);
	}
	int num3=0, num9=0;
	for(int i=0; i<(int)cnt[3].size(); i++) {
		int val=cnt[3][i];
		if(val>rem3) num9=max(num9, val-rem3);
		if(val%2) num3=1;
	}
	int rem2=rem;
	for(int i=0; i<(int)cnt[3].size(); i++) {
		int val=cnt[3][i];
		int c=val/2;
		rem2=max(rem2, rem-c);
	}
	int num2=0, num4=0, num8=0;
	for(int i=0; i<(int)cnt[2].size(); i++) {
		int val=cnt[2][i];
		if(val>rem2*2) num8=max(num8, val-rem2*2);
		if(val>rem2) num4=max(num4, val-rem2);
		if(val%2) num2=1;
	}
	for(int i=0; i<num9; i++) res.push_back(9);
	for(int i=0; i<num8; i++) res.push_back(8);
	for(int i=0; i<num4; i++) res.push_back(4);
	rem=N-(int)res.size();
	assert(rem>=0);
	if(rem==1) {
		if(num2 && num3) res.push_back(6);
		else if(num2) res.push_back(2);
		else if(num3) res.push_back(3);
	} else if(rem>1) {
		if(num2 && num3) {
			int rt=rand()%3;
			if(rt==0) res.push_back(2);
			if(rt==1) res.push_back(3);
			if(rt==2) res.push_back(6);
		} else if(num2) res.push_back(2);
		else if(num3) res.push_back(3);
	}
	rem=N-(int)res.size();
	assert(rem>=0);
	for(int i=0; i<rem; i++) {
		res.push_back(rand()%(M-1)+2);
	}

	return res;
}

vector <vector <int> > solve(int R, int N, int M, int K, vector <vector <ll> > &v) {
	vector <vector <int> > res;

	for(int i=0; i<R; i++) res.push_back(solve2(N, M, K, v[i]));
	
	return res;
}

int main() {
	int practice=0;
	string prb[12];
	const string difficulty[2][2]={{"-small-attempt.in", "-large.in"}, {"-small-practice.in", "-large-practice.in"}};
	const string extension="";
	//const string extension=".txt";

	char key;
	while(1) {
		for(int i=0; i<12; i++) {
			prb[i].assign(1, 'A'+i/2);
			prb[i]+=difficulty[practice][i%2];
			prb[i]+=extension;
			cout << (char)(i%2?('A'+i/2):('a'+i/2)) << ". " << prb[i] << endl;
		}
		cout << "p. " << (practice?"change to practice mode.":"change to match mode.") << endl;

		do {
			cout << "Choose the input file." << endl;
			cin >> key;
		} while(!('a'<=key && key<'a'+6) && !('A'<=key && key<'A'+6) && key!='p');
		if(key!='p') break;
		practice^=1;
		system("cls");
	}

	int index, cap;
	if(key>='a') { index=(key-'a')*2; cap=0; }
	else { index=(key-'A')*2+1; cap=1; }
	string filename=prb[index];

	if(!cap && !practice) {
		do {
			cout << "Choose number of attempt times." << endl;
			cin >> key;
		} while(key<'0' || '9'<key);
		filename.insert(15, 1, key);
	}

	cout << "Filename is " << filename << endl;
	ifstream ifs(filename.c_str());

	ofstream ofs("output.txt");

	int testcase;
	ifs >> testcase; ifs.ignore();
	for(int testnum=1; testnum<=testcase; testnum++) {
		int R, N, M, K;
		ifs >> R >> N >> M >> K;
		vector <vector <ll> > v(R, vector <ll>(K));
		for(int i=0; i<R; i++) {
			for(int j=0; j<K; j++) ifs >> v[i][j];
		}
		vector <vector <int> > res=solve(R, N, M, K, v);
		ofs << "Case #" << testnum << ":" << endl;
		for(int i=0; i<R; i++) {
			for(int j=0; j<N; j++) ofs << res[i][j];
			ofs << endl;
		}
	}
}

//Powered by NTL-5.5.2 (http://www.shoup.net/ntl/)