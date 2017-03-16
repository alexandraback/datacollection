#include <bits/stdc++.h>
using namespace std;

string str[12];
int n;
bool chin[12][27];
		
long long int func(char last, bool ch[27], bool used[11]){
	int k;
	for(k = 0; k < n; ++k){
		if(!used[k]) break;
	}
	if(k == n) return 1;
	long long int count = 0;
	if(last == '1'){
		for(int i = 0; i < n; ++i){
			int j;
			bool cnxt[27];
			for(j = 0; j < 27; ++j) cnxt[j] = chin[i][j];
			char lnxt = str[i][str[i].size() - 1];
			bool unxt[11];
			for(j = 0; j < 11; ++j) unxt[j] = used[j];
			unxt[i] = 1;
			//cout << i << " " << lnxt << " " ;
			count += func(lnxt, cnxt, unxt);
		}
	}
	else{
		for(int i = 0; i < n; ++i){
			if(!used[i]){
				int j;
				bool cnxt[27];
				for(j = 0; j < 26; ++j){
					cnxt[j] = ch[j] || chin[i][j];
					if(ch[j] && chin[i][j] && !((last - 'a' == j) && (str[i][0] - 'a' == j))) break;
				}
				if(j != 26) continue;
				char lnxt = str[i][str[i].size() - 1];
				bool unxt[11];
				for(j = 0; j < 11; ++j) unxt[j] = used[j];
				unxt[i] = 1;
				//cout << i << " " << lnxt << " " ;
				count += func(lnxt, cnxt, unxt);
			}
		}
	}
	return count;
}

int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		cin >> n;
		bool flag = 0;		
		for(int i = 0; i < n; ++i){
			cin >> str[i];
			for(int j = 0; j < 26; ++j) chin[i][j] = 0;
			for(int j = 0; j < str[i].size(); ++j){
				if(chin[i][str[i][j] - 'a'] && str[i][j] != str[i][j - 1]){flag = 1; break;}
				chin[i][str[i][j] - 'a'] = 1;
			}
		}
		printf("Case #%d: ", t);
		if(flag){ cout << "0\n"; continue;}
		bool used[11] = {0};
		bool ch[27] = {0};
		char last = '1';
		long long int count = func(last, ch, used);		
		cout << count << endl;;
	}
	return 0;
}
