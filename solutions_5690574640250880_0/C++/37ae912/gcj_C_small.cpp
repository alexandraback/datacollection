
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;


#define FOR(i,n) for(int i=0;i<n;++i)

int R,C,M;

const int sel[8][2] = { {0,1},{1,0},{0,-1},{-1,0}, {1,1},{1,-1},{-1,1},{-1,-1} };

int mp[10][10];

void build(int s)
{
	memset(mp,0,sizeof(mp))	;
	FOR(i,R)FOR(j,C){
		int k = i*C + j;
		if( (s>>k) & 1)	mp[i][j]=1;
		else mp[i][j] = 2;
	}
}

bool bad(int r, int c){
	if(r<0 || r>=R || c<0 || c>=C) return true;
	return false;
}

void click(int r, int c)
{
	if( bad(r,c) ) return;
	if( mp[r][c] == 1 ) return; // this is a mine
	if( mp[r][c] == 3) return; // visited	
	
	mp[r][c] = 3;
	int ct = 0;
	FOR(i,8){
		int tr = r + sel[i][0];
		int tc = c + sel[i][1];
		if(bad(tr,tc)) continue;
		if( mp[tr][tc] == 1 ) ++ct;
	}

	if(ct) return;

	FOR(i,8) click(r+sel[i][0], c+sel[i][1]);
}

int findclick(int s)
{	
	int res=-1;
	FOR(i,R)FOR(j,C){
		build(s);	
		click(i,j);
		bool ok=true;
		FOR(ii,R)FOR(jj,C) if(mp[ii][jj]==2){ok=false;break;}
		if(ok){
			res = i*1000 + j;
			return res;
		}
	}
	return res;
}

bool test(int s)
{
	return findclick(s) != -1;
}

void output(int s)
{
	int res = findclick(s);	
	if(res==-1){
		puts("illegal state");	
		return;
	}

	int r = res/1000;
	int c = res%1000;


	build(s);

	FOR(i,R){
		FOR(j,C){
			if(i==r && j==c) putchar('c');
			else if(mp[i][j]==1) putchar('*');
			else if(mp[i][j]==2) putchar('.');
			else puts("error"); 
				//putchar('E'); // error
		}
		puts("");
	}
}

int main()
{
	int T,cs=0;
	cin>>T;
	while(++cs <= T){
		cin>>R>>C>>M;
		
		int ans=-1;
		int sz = 1<<(R*C);
		for(int i=0;i < sz; ++i){
			int ct = 0;
			int j=i;
			while(j){
				if(j&1)++ct;
				j>>=1;	
			}	
			if(ct==M){
				if(test(i)){
					ans=i;
					break;
				}
			}
		}

		printf("Case #%d:\n",cs);
		if(ans==-1)puts("Impossible");
		else output(ans);
	}
	
	return 0;	
}
