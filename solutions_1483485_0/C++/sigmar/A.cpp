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

string g[3]={
	"ejp mysljylc kd kxveddknmc re jsicpdrysi", 
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", 
	"de kr kd eoya kw aej tysr re ujdr lkgc jv"
};
string o[3]={
	"our language is impossible to understand", 
	"there are twenty six factorial possibilities", 
	"so it is okay if you want to just give up"
};

map <char, char> gmap;

string solve(string s) {
	string res;

	for(int i=0; i<(int)s.size(); i++) {
		res.push_back(gmap[s[i]]);
	}
	
	return res;
}

int main() {
	int practice=0;
	string prb[12];
	const string difficulty[2][2]={{"-small-attempt.in", "-large.in"}, {"-small-practice.in", "-large-practice.in"}};
	const string extension="";
	//const string extension=".txt";

	int cnt[26]={0};
	gmap.clear();
	for(int i=0; i<3; i++) {
		for(int j=0; j<(int)g[i].size(); j++) {
			gmap[g[i][j]]=o[i][j];
			cnt[o[i][j]-'a']++;
		}
	}
	gmap['z']='q';
	cnt['q'-'a']++;
	int rem=-1;
	for(int i=0; i<26; i++) if(!cnt[i]) rem=i;

	for(char c='a'; c<='z'; c++) {
		if(!gmap.count(c)) {
			gmap[c]='a'+rem;
			break;
		}
	}

	memset(cnt, 0, sizeof(cnt));
	for(char c='a'; c<='z'; c++) {
		if(!gmap.count(c) || gmap[c]<'a' || cnt[gmap[c]-'a']) {
			cerr << "cannot resolve " << c << endl;
		}
		cnt[gmap[c]-'a']++;
	}

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
		string s;
		getline(ifs, s);
		string res=solve(s);
		ofs << "Case #" << testnum << ": ";
		ofs << res << endl;
	}
}

//Powered by NTL-5.5.2 (http://www.shoup.net/ntl/)