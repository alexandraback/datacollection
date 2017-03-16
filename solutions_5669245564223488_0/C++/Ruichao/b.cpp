#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int t;
int n;
string str[200];
bool v[200];
int ans;
bool u[26];
bool tu[100][26];
bool ok;

bool check(int cen,string st,int cur){
	memcpy(tu[cen],tu[cen-1],sizeof(tu[cen]));
	for ( int sj = 0; sj < st.size(); ++ sj){
		if (st[sj] - 'a' != cur && tu[cen][st[sj] - 'a']) return false;
		cur = st[sj] - 'a';
		tu[cen][st[sj] - 'a'] = true;
	}
	return true;
}

void search(int cen,int cur){
	if (cen > n){
		++ ans;
		return;
	}
	for ( int si = 1; si <= n; ++ si){
		if (v[si]) continue;
		if (!check(cen,str[si],cur)) continue;
		v[si] = true;
		//cout << "search " << cen << " " << si << endl;
		search(cen+1,str[si][str[si].size()-1]-'a');
		v[si] = false;
	}
}

int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin >> t;
	for ( int i = 1; i <= t; ++ i){
		printf("Case #%d: ",i);
		cin >> n;
		ok = true;
		for ( int j = 1; j <= n; ++ j){
			cin >> str[j];
			memset(u,false,sizeof(u));
			for ( int k = 0; k < str[j].size(); ++ k){
				if (u[str[j][k]-'a'] && str[j][k] != str[j][k-1]){
					ok = false;
				}
					
				if (!u[str[j][k]-'a']) u[str[j][k]-'a'] = true;
			}
		}
		if (!ok) printf("0");
		else{
			memset(v,false,sizeof(v));
			ans = 0;
			memset(tu,false,sizeof(tu));
			search(1,-1);
			printf("%d",ans);
			
		}
		printf("\n");
	}

	return 0;
}
