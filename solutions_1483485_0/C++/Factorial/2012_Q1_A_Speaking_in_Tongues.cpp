#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
#include <utility>
#include <iterator>
#include <fstream>
#include <stdio.h>
#include <cstring>

using namespace std;

template<class T>
string tostring(T a){stringstream ss; ss<<a; return ss.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;
#define SZ(a) int((a).size()) 
#define PB push_back 
#define ALL(c) (c).begin(),(c).end() 
#define FOR(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define LOOP(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define MP(a,b) make_pair((a),(b))
#define LAST(t) (t[SZ(t)-1])

vector<char> mapping('z'+1);

void init(){
	string encr = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv zq",
	orig = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up qz";
	
	vector<bool> volt('z'+1);
	for(int i=0; i<SZ(encr); i++){
		mapping[encr[i]]=orig[i];
		volt[encr[i]]=true;
	}

	/*for(char i='a'; i<='z'; i++)
		if(!volt[i])
			i=i;*/
}

int main(){
	init();

	ifstream be("A-small-attempt1.in");
	ofstream ki("ki.txt");

	int tt; be>>tt;
	{string s;getline(be,s);} //////
	for(int i=0; i<tt; i++){

		string s; getline(be,s);
		ostringstream ss;
		for(int i=0; i<SZ(s); i++)
			ss<<mapping[s[i]];
		
		ki<<"Case #"<<i+1<<": "<<ss.str()<<endl;
	}

	return 0;
}