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
//#include <NTL/ZZ.h>
using namespace std;
//using namespace NTL;
static const double EPS = 1e-8;
typedef long long ll;
typedef unsigned long long ull;
typedef complex <double> pt;
typedef complex <ll> pti;

int solve(int N, vector <int> &a, vector <int> &b) {
	int res;
	
	int star=0;
	vector <int> done1(N), done2(N);
	for(int one=0; one<=N; one++) {
		bool cont=true;
		while(cont) {
			cont=false;
			for(int i=0; i<N; i++) {
				if(done2[i]) continue;
				if(star<b[i]) continue;
				done2[i]=1;
				if(done1[i]) star++;
				else star+=2;
				cont=true;
			}
		}
		int maxb=-1, maxbi=-1;
		for(int i=0; i<N; i++) {
			if(done1[i] || done2[i]) continue;
			if(a[i]<=star && b[i]>maxb) {
				maxbi=i;
				maxb=b[i];
			}
		}
		if(maxb==-1) break;
		done1[maxbi]=1;
		star++;
	}

	res=N;
	for(int i=0; i<N; i++) {
		if(!done2[i]) return N*2+1;
		res+=done1[i];
	}

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
		int N;
		ifs >> N;
		vector <int> a(N), b(N);
		for(int i=0; i<N; i++) ifs >> a[i] >> b[i];
		int res=solve(N, a, b);
		ofs << "Case #" << testnum << ": ";
		if(res>N*2) ofs << "Too Bad" << endl;
		else ofs << res << endl;
	}
}

//Powered by NTL-5.5.2 (http://www.shoup.net/ntl/)