#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int c(char a) {
	return a-'a';
}

bool nochange(string &str) {
	for (int i=1;i<str.length();i++) {
		if (str[0]!=str[i]) return false;
	}
	return true;
}

int main() {
  int T, N;
	long long M = 1000000007;
  cin >> T;
  for (int t=1;t<=T;t++) {
		cin >> N;

		int inter[26] = {}, left[26] = {}, right[26] = {}, exter[26] = {};
		bool mark[26] = {};
		int edge[26];
		for (int i=0;i<26;i++) edge[i]=-1;

		bool fail = false;
		for (int i=0;i<N;i++) {
			string str;
			cin >> str;
			int strn = str.length()-1;

			if (str[0] == str[strn]) {
				if (!nochange(str)) fail = true;
				exter[c(str[0])]++;
			}
			else {
				left[c(str[0])]++;
				right[c(str[strn])]++;
				edge[c(str[0])] = c(str[strn]);
				//printf("(%d->%d)",c(str[0]),c(str[strn]));
				for (int j=1;j<strn;j++) {
					if (str[j]!=str[j-1] && str[j] != str[strn]) {
						if (str[j-1]==str[strn]) fail = true;
						inter[c(str[j])]++;
					}
				}
			}
		}


		printf("Case #%d: ", t);
		long long ways = 1;
		int num = 0;
		//printf("(%d)",exter[3]);
		for (int i=0;i<26;i++) {
			//printf("(%d)", i);
			if (inter[i]>1) fail = true;
			if (inter[i]==1 && left[i]+right[i]+exter[i]>0) fail = true;
			if (left[i]>1) fail = true;
			if (right[i]>1) fail = true;

			for (int j=2;j<=exter[i];j++) {
				//printf("(*=%d,%d)",j,i);
				ways = (ways*j)%M;
			}

			if (right[i] + left[i] > 0) {
				if (!mark[i]) {

					mark[i] = true;
					int k = edge[i];
					while (k != i && edge[k] != -1 && !mark[k]) {
						mark[k] = true;
						k = edge[k];
					}
					//printf("(%d,%d,%d)",i,k);
					if (k==i) fail = true;
				}
			}
			if (right[i] == 0) {
				if (left[i] == 1) {
					num++;
				}
				else if (exter[i]>0) {
					num++;
				}
			}
		}
		while (num>1) {
			ways = (ways * num)%M;
			num--;
		}
		if (fail) cout << 0;
		else {
			cout << ways;
		}
		cout << endl;
	}

  return 0;
}
