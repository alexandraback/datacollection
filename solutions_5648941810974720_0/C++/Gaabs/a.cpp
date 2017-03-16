#include <bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for(int i = a; i < b; i++)
#define fre(i,a,b) for(int i = a; i <= b; i++)
#define frd(i,a,b) for(int i = a; i > b; i--)
#define fred(i,a,b) for(int i = a; i >= b; i--)
#define pb push_back
#define SET(a,v) memset(a,v,sizeof a)

#define INF 1e8
#define N 2010

typedef long long ll;
typedef pair<int,int> ii;

int t,len;
int cnt[500];
int dig[10];
char str[N];

/*
(S)EVEN
FI(V)E
T(H)REE
T(W)O
(T)EN
FOU(R)
(O)NE
(N)INE
*/

void solve(){
	SET(cnt,0);
	SET(dig,0);
	
	fr(i,0,len) cnt[str[i]]++;
	int temp;
	
	//(Z)ERO
	if (cnt['Z']){
		temp = cnt['Z'];
		dig[0] += temp;
		cnt['Z'] -= temp;
		cnt['E'] -= temp;
		cnt['R'] -= temp;
		cnt['O'] -= temp;
	}
	
	//SI(X)
	if (cnt['X']){
		temp = cnt['X'];
		dig[6] += temp;
		cnt['S'] -= temp;
		cnt['I'] -= temp;
		cnt['X'] -= temp;
	}
	
	//EI(G)HT
	if (cnt['G']){
		temp = cnt['G'];
		dig[8] += temp;
		cnt['E'] -= temp;
		cnt['I'] -= temp;
		cnt['G'] -= temp;
		cnt['H'] -= temp;
		cnt['T'] -= temp;
	}
	

	//(S)EVEN
	if (cnt['S']){
		temp = cnt['S'];
		dig[7] += temp;
		cnt['S'] -= temp;
		cnt['E'] -= temp;
		cnt['V'] -= temp;
		cnt['E'] -= temp;
		cnt['N'] -= temp;
	}
	
	//FI(V)E
	if (cnt['V']){
		temp = cnt['V'];
		dig[5] += temp;
		cnt['F'] -= temp;
		cnt['I'] -= temp;
		cnt['V'] -= temp;
		cnt['E'] -= temp;
	}
	
	//T(H)REE
	if (cnt['H']){
		temp = cnt['H'];
		dig[3] += temp;
		cnt['T'] -= temp;
		cnt['H'] -= temp;
		cnt['R'] -= temp;
		cnt['E'] -= temp;
		cnt['E'] -= temp;
	}
	
	//T(W)O
	if (cnt['W']){
		temp = cnt['W'];
		dig[2] += temp;
		cnt['T'] -= temp;
		cnt['W'] -= temp;
		cnt['O'] -= temp;
	}
	
	//FOU(R)
	if (cnt['R']){
		temp = cnt['R'];
		dig[4] += temp;
		cnt['F'] -= temp;
		cnt['O'] -= temp;
		cnt['U'] -= temp;
		cnt['R'] -= temp;
	}
	
	//(O)NE
	if (cnt['O']){
		temp = cnt['O'];
		dig[1] += temp;
		cnt['O'] -= temp;
		cnt['N'] -= temp;
		cnt['E'] -= temp;
	}
	
	//N(I)NE
	if (cnt['I']){
		temp = cnt['I'];
		dig[9] += temp;
		cnt['N'] -= temp;
		cnt['I'] -= temp;
		cnt['N'] -= temp;
		cnt['E'] -= temp;
	}
	
}

int main(){
	scanf("%d",&t);
	fr(t2,0,t){
		printf("Case #%d: ",t2+1);
		scanf("%s",str);
		len = strlen(str);
		solve();
		fr(i,0,10){
			fr(j,0,dig[i]) printf("%d",i);
		}
		puts("");
	}

	return 0;
}