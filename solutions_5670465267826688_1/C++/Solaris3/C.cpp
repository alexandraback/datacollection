#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int MAXN = 1000006,N=4*8;//10^6

char s[MAXN];
int need[]={2,4,6,-1};
int Trans[8][8]={
	{0,1,2,3,4,5,6,7},
	{1,0,3,2,5,4,7,6},
	{2,3,1,0,6,7,5,4},
	{3,2,0,1,7,6,4,5},
	{4,5,7,6,1,0,2,3},
	{5,4,6,7,0,1,3,2},
	{6,7,4,5,3,2,1,0},
	{7,6,5,4,2,3,0,1}
};
map<char,int> M;
void solve() {
	int n;
	ll m;
	scanf("%d%lld%s",&n,&m,s);
	vector<vi> G(N,vi(N,0));
	M['i']=2;
	M['j']=4;
	M['k']=6;
	//create graph
	fru(i,N)
	{
		set<int>S,SS;
		S.insert(i);
		fru(j,n)
		{
			tr(it,S)
			{
				int stat=*it/8,last=*it%8;
				last=Trans[last][M[s[j]]];
				SS.insert(stat*8+last);
				if(last==need[stat])SS.insert((stat+1)*8);
			}
			swap(S,SS);
			SS.clear();
		}
		tr(it,S)
		{
			//printf("zazn %d %d\n",i,*it);
			G[i][*it]=1;
		}
	}
	vector<vi> ANS(N,vi(N,0));
	fru(i,N)ANS[i][i]=1;
	while(m)
	{
		if(m%2)
		{
			vector<vi> T(N,vi(N,0));
			fru(i,N)fru(j,N)fru(k,N)T[i][j]|=ANS[i][k] &&G[k][j];
			swap(ANS,T);
		}
		m/=2;
		vector<vi> T(N,vi(N,0));
		fru(i,N)fru(j,N)fru(k,N)T[i][j]|=G[i][k] &&G[k][j];
		swap(G,T);	
	}
	puts(ANS[0][24]?"YES":"NO");
}

int main(){
	int t=1;scanf("%d",&t);
	fru(i,t)
	{
		printf("Case #%d: ",i+1);
		solve();
	}
	return 0;
}

