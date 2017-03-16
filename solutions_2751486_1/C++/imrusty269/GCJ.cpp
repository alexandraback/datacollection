//============================================================================
// Name        : GCJ.cpp
// Author      : Dung
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cassert>

#define rep(i,j,n) for (int i=j ; i < (int)n; ++i)
#define add push_back
#define ms(mat,val) memset(mat,val,sizeof(mat))


using namespace std;

typedef long long LL;
typedef unsigned long long ULL;


bool isVowel(char a) {
	return (a == 'a' || a=='e' || a == 'i' || a == 'o' || a== 'u');
}

int main() {
	ifstream in("input");
	ofstream out("output");
	int T;
	in >> T;
	for(int t = 0; t < T;++t) {
		int n,L;
		string str;
		in >> str >> n;
		L = str.size();
		L = str.size();
		int cnt[1000001];
		rep(i,0,L) {
			if (!isVowel(str[i]))
				cnt[i] = (i ? cnt[i-1] + 1 : 1);
			else
				cnt[i] = 0;
		}

		LL cur =  (cnt[n-1] == n);
		LL res = cur;
		rep(k,n,L) {
			if (cnt[k] >= n)
				cur=k+2-n;
			res += cur;
		}
		out << "Case #" << t+1 <<": " << res << endl;
	}
}
