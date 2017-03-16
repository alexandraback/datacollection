#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll MOD = 1000000007;
int G[26][2];
int O[26],C;
bool used[26];

bool dfs(int v, int d){
	//printf("dfs %d\n", v);
	if(used[v]) return false;
	used[v] = true;
	if(G[v][d] == -1) return true;
	return dfs(G[v][d], d);
}
int countC(){
	//puts("countC");
	int ret = 0;
	fill(used,used+26,false);
	for(int i = 0; i < 26; i++){
		if(O[i]>0 && G[i][1]==-1 && G[i][0] == -1){
			ret++;
		}else if(!used[i]){
			int f = 0;
			if(G[i][0] >= 0){
				f=1;
				//printf("i=%d DFS0\n",i);
				if(!dfs(i,0)){
					//printf("failed i=%d 0\n",i);
					return -1;
				}
			}
			if(G[i][1] >= 0){
				f=1;
				used[i] = false;
				//printf("i=%d DFS1\n",i);
				if(!dfs(i,1)){
					//printf("failed i=%d 1\n",i);
					return -1;
				}
			}
			ret += f;
		}
	}
	return ret;
}
ll ff[110];
int solve(){
	//puts("solve");
	ll ret = 1;
	for(int i = 0; i < 26; i++){
		//printf("i=%d ret=%lld\n", i, ret);
		if(O[i]>0){
			ret = (ret * ff[O[i]]) % MOD;
		}
	}
	//printf("C=%d\n",C);
	ret = (ret * ff[C]) % MOD;
	return (int)ret;
}
int N;
string S[100];
bool isok(int t){
	vector<P> v;
	string s = S[t];
	int l = s.size();
	for(int i = 0; i < l; i++){
		v.push_back(P(s[i], i));
		if(s[i] != s[0] && s[i] != s[l-1]){
			for(int j=0;j<N;j++){
				if(j==t) continue;
				for(int k=0;k<S[j].size();k++){
					if(S[j][k] == s[i]){
						//puts("NOT");
						return false;
					}
				}
			}
		}
	}
	sort(v.begin(), v.end());	
	for(int i=1; i<v.size(); i++){
		if(v[i].first == v[i-1].first){
			if(!(v[i].second == v[i-1].second + 1))
				return false;
		}
	}
	return true;
}
int main(){
	int T;
	scanf("%d", &T);
	ff[0] = 1;
	for(int i = 1; i < 110; i++){
		ff[i] = (ff[i-1] * i) % MOD;
	}
	for(int cnt = 1; cnt <= T; cnt++){
		for(int i=0;i<26;i++){
			G[i][0] = -1;
			G[i][1] = -1;
		}
		fill(O,O+26,0);
		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			char s[1000], c;
			scanf("%c%s",&c,s);
			//printf("[%s]\n", s);
			string str = string(s);
			S[i] = str;
		}
		for(int i = 0; i < N; i++){
			//printf("i=%d\n",i);
			string s = S[i];
			int l = s.size();
			if(s[0] == s[l-1]){
				for(int j = 0; j < l; j++){
					if(s[j] != s[0]) goto zero;
				}
				O[s[0]-'a']++;
			}else{
				if(!isok(i)) goto zero;
				if(G[s[0]-'a'][0] >= 0) goto zero;
				if(G[s[l-1]-'a'][1] >= 0) goto zero;
				G[s[0]-'a'][0] = s[l-1]-'a';
				G[s[l-1]-'a'][1] = s[0]-'a';
			}
		}
		//puts("processing");
		/* for(int i = 0; i < 26; i++){
			printf("%c:%d ", (char)i+'a',O[i]);
		}puts(""); */
		C = countC();
		//printf("C=%d\n",C);
		if(C == -1) goto zero;
		printf("Case #%d: %d\n",cnt, solve());
		continue;

		zero:
		printf("Case #%d: 0\n",cnt);
	}
}

