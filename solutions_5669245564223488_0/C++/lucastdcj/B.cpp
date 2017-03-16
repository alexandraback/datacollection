#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define MAXN 1010
#define MOD 1000000007LL;

int n;
string s[MAXN];
vector<int> adj[MAXN];

bool vis[MAXN],has[MAXN];
int din[MAXN],dout[MAXN];
ll cnt[MAXN];
ll fat[MAXN];
ll ans;

void reduce(int x){
    string ans;
    for(int i = 0 ; i < s[x].size() ;){
	ans += s[x][i];
	int pi = i + 1;
	while(pi < s[x].size() && s[x][pi] == s[x][i]) pi++;
	i = pi;
    }
    s[x] = ans;    
}

bool ciclo(int v){
    if(vis[v]) return true;
    vis[v] = true;
    for(int j = 0 ; j < adj[v].size() ; j++){
	int pv = adj[v][j];
	if(ciclo(pv)) return true;
    }
    return false;
}

void dfs(int v){
    ans = (ans*fat[cnt[v]])%MOD;
    for(int j = 0 ; j < adj[v].size() ; j++){
	int pv = adj[v][j];
	dfs(pv);
    }
}

ll solve(){
    for(int i = 0 ; i < 26 ; i++){
	has[i] = false;
	din[i] = dout[i] = cnt[i] = 0;
	adj[i].clear();
    }
    
    for(int i = 0 ; i < n ; i++){
	has[s[i][0] -'a'] = true;
	has[s[i][s[i].size() - 1] - 'a'] = true;	
    }   
    
    for(int i = 0 ; i < n ; i++){
	reduce(i);
	//~ cout << s[i] << endl;
	for(int j = 1 ; j < s[i].size() - 1 ; j++){
	    //~ printf("%c\n",s[i][j]);
	    if(has[s[i][j] - 'a']){		
		return 0;
	    }
	    has[s[i][j] - 'a'] = true;
	}
	if(s[i].size() > 1){
	    if(s[i][s[i].size() - 1] == s[i][0]) return 0;
	}
		
	string ans;
	ans += s[i][0];
	if(s[i][s[i].size() - 1] != s[i][0]){
	    ans += s[i][s[i].size() - 1];
	}
	s[i] = ans;	
    }
    //~ cout << "chegou" << endl;
    for(int i = 0 ; i < n ; i++){
	int fst = s[i][0] - 'a';
	int snd;
	if(s[i].size() == 2){
	    snd = s[i][1] - 'a';
	    adj[fst].push_back(snd);
	    dout[fst]++;
	    din[snd]++;
	}
	else if(s[i].size() == 1){
	    cnt[fst]++;
	}
    }
    for(int i = 0 ; i < 26 ; i++){
	if(din[i] > 1 || dout[i] > 1)
	    return 0;
    }
    
    for(int i = 0 ; i < 26 ; i++){
	for(int j = 0 ; j < 26 ; j++) vis[j] = 0;
	if(ciclo(i)) return 0;	
    }
       
    ans = 1LL;
    int seq = 0;
    
    for(int i = 0 ; i < 26 ; i++){	
	if(!din[i] && !dout[i]){
	    if(cnt[i]){
		seq++;
		ans = (ans*fat[cnt[i]])%MOD;
	    }
	}else{
	    if(din[i] == 0){
		seq++;	
		dfs(i);
	    }	    
	}
    }
    
    ans = (ans*fat[seq])%MOD;
    return ans;    
}

int main(){
    fat[0] = 1LL;
    for(ll i = 1 ; i < MAXN ; i++){
	fat[i] = (fat[i-1]*i)%MOD;
    }
    
    int nt;
    scanf(" %d",&nt);
    int t = 1;
    while(nt--){
	scanf(" %d",&n);
	for(int i = 0 ; i < n ; i++){
	    cin >> s[i];
	    //~ cout << s[i] << endl;
	}
	printf("Case #%d: %lld\n",t++,solve());
    }
    
    return 0;
}
