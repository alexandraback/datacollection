#include<bits/stdc++.h>

using namespace std;

inline long long int gi(){
	long long int ret = 0;
	char ch = ' ';
	while(ch < '0' || ch > '9'){
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		ret *= 10;
		ret += ch - '0';
		ch = getchar();
	}
	return ret;
}

#define N 1000
#define LL long long int 
#define MOD 1000000007LL

int n;
string s[N];
LL adj[N][N];
LL fac[N];

inline void pre(){
	fac[0] = 1;
	for(int i = 1; i < N; i++){
		fac[i] = fac[i - 1] * i;
		fac[i] %= MOD;
	}
}

inline void process(int p){
	if(s[p].length() == 1){
		return;
	}
	int i, j, k, l = s[p].length();
	int a, b;
	if(s[p][0] == s[p][l - 1]){
		for(j = 0; j < l; j++){
			if(s[p][j] != s[p][0]){
				s[p] = " ";
				return;
			}
		}
	}
	for(a = 1; a < l; a++){
		if(s[p][a] != s[p][0]){
			break;
		}
	}
	a--;
	for(b = l - 2; b >= 0; b--){
		if(s[p][b] != s[p][l - 1]){
			break;
		}
	}
	b++;
	if(a >= b - 1){
		return;
	}
	for(i = a + 1; i < b; i++){
		for(j = i + 1; j < b; j++){
			if(s[p][j] != s[p][i]){
				break;
			}
		}
		i = j - 1;
		while(j < b){
			if(s[p][j] == s[p][i]){
				s[p] = " ";
				return;
			}
			j++;
		}
		for(j = 0; j < n; j++){
			if(j != p){
				for(k = s[j].length() - 1; k >= 0; k--){
					if(s[j][k] == s[p][i]){
						s[p] = " ";
						return;
					}
				}
			}
		}
	}
	return;
}

inline void gof(int a, int b){
	for(int i = 0; i < 26; i++){
		if(adj[b][i] > 0){
			adj[b][i] = 0;
			n--;
			gof(b, i);
			return;
		}
	}
}

inline void gob(LL a, LL b){
	for(LL i = 0; i < 26; i++){
		if(adj[i][a] > 0){
			adj[i][a] = 0;
			n--;
			gob(i, a);
			return;
		}
	}
}

inline void solve(){
	cin>>n;
	LL i, j, a, b, c;
	for(i = 0; i < n; i++){
		cin>>s[i];
	}
	for(i = 0; i < 26; i++){
		for(j = 0; j < 26; j++){
			adj[i][j] = 0;
		}
	}
	for(i = 0; i < n; i++){
		process(i);
		if(s[i] == " "){
			cout<<"0"<<endl;
			return;
		}
		adj[s[i][0] - 'a'][s[i][s[i].length() - 1] - 'a']++;
	}
	//cout<<"here"<<endl;
	LL ans = 1;
	LL comp = 0;
	for(i = 0; i < 26; i++){
		if(adj[i][i] == 0){
			continue;
		}
		ans *= fac[adj[i][i]];
		ans %= MOD;
		n -= adj[i][i];
		adj[i][i] = 0;
		for(j = 0; j < 26; j++){
			if(adj[j][i] > 0 || adj[i][j] > 0){
				break;
			}
		}
		if(j == 26){
			comp++;
		}
	}
//	cout<<n<<endl;
	for(i = 0; i < 26; i++){
		c = 0;
		for(j = 0; j < 26; j++){
			if(adj[j][i] > 0){
				c++;
			}
			if(adj[j][i] > 1 || c > 1){
				cout<<"0"<<endl;
				return;
			}
		}
		c = 0;
		for(j = 0; j < 26; j++){
			if(adj[i][j] > 0){
				c++;
			}
			if(adj[i][j] > 1 || c > 1){
				cout<<"0"<<endl;
				return;
			}
		}
	}
	//cout<<comp<<endl;
	while(n > 0){
		a = -1;
		b = -1;
		for(i = 0; i < 26; i++){
			for(j = 0; j < 26; j++){
				if(adj[i][j] != 0){
					a = i;
					b = j;
				}
			}
		}
		n--;
		adj[a][b] = 0;
		gof(a, b);
		gob(a, b);
		comp++;
	//	cout<<a<<" "<<b<<endl;
	}
	//cout<<comp<<" "<<ans<<endl;
	ans *= fac[comp];
	ans %= MOD;
	cout<<ans<<endl;
}

int main(){
	pre();
	LL t, i = 0;
	cin>>t;
	while(t--){
		i++;
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
