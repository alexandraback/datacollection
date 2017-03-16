#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<iostream>
#include<cstring>

#define maxn 105
#define mod 1000000007

using namespace std;

int n;
int fr[maxn][3],apare[26],F[maxn],pre[26],suc[26];
string s[maxn];

inline int solve () {
	
	for ( int i = 1 ; i <= n ; ++i ){
		for ( int ch = 0 ; ch < 26 ; ++ch ){
			
			for ( int k = 0 ; k < (int)(int)s[i].size() ; ++k ){
				if ( s[i][k]-'a' == ch ){
					++apare[ch];
					break ;
				}
			}
		}
	}
	
	for ( int i = 1 ; i <= n ; ++i ){
		
		if ( s[i][0] == s[i][(int)s[i].size()-1] ){
			for ( int j = 1 ;  j < (int)s[i].size() ; ++j ){
				if ( s[i][j] != s[i][j-1] )	return 0;
			}
			++fr[s[i][0]-'a'][0];
		}
		else{
			
			int este[26];
			memset(este,0,sizeof(este));
			for ( int j = 0 ; j < (int)s[i].size() ; ++j ){
				if ( j == 0 || s[i][j] != s[i][j-1] ){
					++este[s[i][j]-'a'];
					if ( este[s[i][j]-'a'] > 1 )	return 0;
				}
			}
			
			++fr[s[i][0]-'a'][1];
			if ( fr[s[i][0]-'a'][1] > 1 )	return 0;
			suc[s[i][0]-'a'] = s[i][(int)s[i].size()-1]-'a';
			++fr[s[i][(int)s[i].size()-1]-'a'][2];
			if ( fr[s[i][(int)s[i].size()-1]-'a'][2] > 1 )	return 0;
			pre[s[i][(int)s[i].size()-1]-'a'] = s[i][0]-'a';
			
			int p = 1,u = (int)s[i].size()-2;
			while ( s[i][p] == s[i][p-1] )	++p;
			while ( s[i][u] == s[i][u+1] )	--u;
			for ( int j = p ; j <= u ; ++j ){
				if ( apare[s[i][j]-'a'] > 1 )	return 0;
				apare[s[i][j]-'a'] = 0;
			}
		}
	}
	
	for ( int i = 0 ; i < 26 ; ++i ){
		if ( fr[i][1] && fr[i][2] && suc[i] == pre[i] )	return 0;
	}
	
	int lanturi = 0,sol = 1;
	for ( int i = 0 ; i < 26 ; ++i ){
		if ( !apare[i] )	continue ;
		if ( !fr[i][2] )	++lanturi;
		sol = (1LL*sol*F[fr[i][0]])%mod;
	}
	
	sol = (1LL*sol*F[lanturi])%mod;
	return sol;
}

int main () {
	
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	
	F[0] = 1;
	for ( int i = 1 ; i < maxn ; ++i ){
		F[i] = (1LL*F[i-1]*i)%mod;
	}
	
	int tests;
	scanf("%d",&tests);
	
	for ( int t = 1 ; t <= tests ; ++t) {
		
		cin >> n;
		for ( int i = 1 ; i <= n ; ++i ){
			cin >> s[i];
		}
		
		printf("Case #%d: %d\n",t,solve());
		
		memset(fr,0,sizeof(fr));
		memset(apare,0,sizeof(apare));
		memset(pre,0,sizeof(pre));
		memset(suc,0,sizeof(suc));
	}
	
	return 0;
}