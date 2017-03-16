#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <ctime>
#include <cstring>
#define FOR(x,y,z) for(int (x)=(y);(x)<(z);(x)++)
#define FORQ(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define FORD(x,y,z) for(int (x)=(y);(x)>(z);(x)--)
#define FORDQ(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define REP(x,z) for(int (x)=1;(x)<=(z);(x)++)
#define UNIQUE(x) sort(ALL((x))); (x).resize(unique(ALL((x)))-(x).begin());
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define PII pair<int,int>
#define PACKS(Z,IdzieSobieBladWielbladMaWrotkiNaKopytachJESTNIENORMALNY) int Z;scanf("%d",&Z);FORQ(IdzieSobieBladWielbladMaWrotkiNaKoptyachJESTNIENORMALNY,1,Z)
using namespace std;

char in[5][4];
int main(){
	int Z;
	scanf("%d",&Z);
	FORQ(cases,1,Z){
		FOR(i,0,4)
			scanf("%s",in[i]);
		int ok=0;
		FOR(i,0,4){
			int sum=0;
			FOR(j,0,4){
				if(in[i][j]!='.')sum+=in[i][j];
			}
			if(sum==4*'X'||sum==4*'O'||sum==(3*'X'+'T')||sum==(3*'O'+'T'))
				FOR(j,0,4)
					if(in[i][j]=='X')
						ok=1;
					else if(in[i][j]=='O')
						ok=2;				
		}
		if(ok!=0){
			printf("Case #%d: %c won\n",cases,ok==1?'X':'O');
			continue;
		}
		FOR(i,0,4){
			int sum=0;
			FOR(j,0,4){
				if(in[j][i]!='.')sum+=in[j][i];
			}
			if(sum==4*'X'||sum==4*'O'||sum==(3*'X'+'T')||sum==(3*'O'+'T'))
				FOR(j,0,4)
					if(in[j][i]=='X')
						ok=1;
					else if(in[j][i]=='O')
						ok=2;
		}
		if(ok!=0){
			printf("Case #%d: %c won\n",cases,ok==1?'X':'O');
			continue;
		}
		FOR(i,0,2){
			int sum=0;
			if (i==0){
				FOR(j,0,4)
					if(in[j][j]!='.')sum+=in[j][j];
			}
			else {
				int x=3;
				int y=0;
				FOR(j,0,4){
					if(in[x--][y++]!='.')sum+=in[x+1][y-1];
				}
			}
			if(sum==4*'X'||sum==4*'O'||sum==(3*'X'+'T')||sum==(3*'O'+'T')){
				if (i==0){
				FOR(j,0,4)
						if(in[j][j]=='X')ok=1;
						else if(in[j][j]=='O')ok=2;
				}
				else {
					int x=3;
					int y=0;
					FOR(j,0,4){
						if(in[x][y]=='X')
							ok=1;
						else if(in[x][y]=='O')
							ok=2;
						x--;y++;
					}
				}
			}
		}
		if(ok!=0){
			printf("Case #%d: %c won\n",cases,ok==1?'X':'O');
			continue;
		}
		FOR(i,0,4)FOR(j,0,4)if(in[i][j]=='.')ok=-1;
		if(ok!=-1)printf("Case #%d: Draw\n",cases);
		else printf("Case #%d: Game has not completed\n",cases);
	}
	return 0;
}

