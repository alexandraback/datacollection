#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

int mmax(int a, int b) { return a>b?a:b; }

int power(int a, int b) {
	if(b==0) return 1;
	else return a*power(a,b-1);
}

void find_allseq(vector<string> &dict, string &keys, string str, int i, int S) {
	if(i==S) {
		dict.push_back(str);
		return;
	}

	for(int k=0 ; k<keys.size() ; k++) {
		string str2 = str+keys[k];
		find_allseq(dict, keys, str2, i+1, S);
	}
}

int find_patterns(string &dicti, string &target) {

	int n=dicti.size(), w=target.size(), ret=0;

	for(int i=0 ; i+w-1<n ; i++) {
		bool chk=true;
		for(int j=0 ; j<w ; j++) {
			if(dicti[i+j]!=target[j]) {
				chk=false;
				break;
			}
		}

		if(chk) ret++;
	}

	return ret;
}

int main() {

	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int T;
	cin>>T;

	for(int t=1 ; t<=T ; t++) {
		int K,L,S;
		string keys, target, tmp;
		vector<string> dict;
		vector<int> banana_memo;

		cin>>K>>L>>S;
		cin>>keys;
		cin>>target;

		find_allseq(dict,keys,tmp,0,S);

		int bananas = 0;
		for(int i=0 ; i<dict.size() ; i++) {
			banana_memo.push_back(find_patterns(dict[i], target));
			bananas = mmax(bananas, banana_memo[i]);
		}

		double p = 1/(double)(power(K,S));

		double ans=0.0;
		for(int i=0 ; i<dict.size() ; i++) {
			ans = ans + p*(double)(bananas-banana_memo[i]);
		}

		cout<<"Case #"<<t<<": ";
		printf("%.9lf\n", ans);
	}

	return 0;
}