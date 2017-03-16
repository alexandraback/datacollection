#include <iostream>
#include <queue>
#include <string>
#include <iomanip> 
#include <vector>
#include <list>
#include <utility> 
#include <iterator> 
#include <algorithm> 
#include <map>
#include <time.h>
#include <set> 
using namespace std;
#define REP(i,T) for(int i=0;i<T;++i)
#define MP make_pair
#define PII pair<int,int>
#define BG begin
#define ND end
#define VI vector<int>
#define VB vector<bool>
#define ALL(i) i.BG(),i.ND()
#define FORI(i,a,b) for(int i=a;i!=b;++i)
#define OUT(i) while(!i.empty())
#define GP(a,b) a[b.first][b.second]
#define EX(a,b) (a.find(b)!=a.end())



int judge(){
	char st[4][4];
	getchar();
	REP(i,4){
		REP(j,4){
			st[i][j]=getchar();
		}
		getchar();
	}
	int cx,co,ct;
	bool over=true;
	REP(i,4){
		cx=co=ct=0;
		REP(j,4){
			if(st[i][j]=='.')over=false;
			else if(st[i][j]=='O')co++;
			else if(st[i][j]=='X')cx++;
			else if(st[i][j]=='T')ct++;
		}
		if(co==4||(co==3&&ct==1))return 1;
		if(cx==4||(cx==3&&ct==1))return 0;
		cx=co=ct=0;
		REP(j,4){
			if(st[j][i]=='.')over=false;
			else if(st[j][i]=='O')co++;
			else if(st[j][i]=='X')cx++;
			else if(st[j][i]=='T')ct++;
		}
		if(co==4||(co==3&&ct==1))return 1;
		if(cx==4||(cx==3&&ct==1))return 0;
	}
	cx=co=ct=0;
	REP(j,4){
		if(st[j][3-j]=='.')over=false;
		else if(st[j][3-j]=='O')co++;
		else if(st[j][3-j]=='X')cx++;
		else if(st[j][3-j]=='T')ct++;
	}
	if(co==4||(co==3&&ct==1))return 1;
	if(cx==4||(cx==3&&ct==1))return 0;
	
	cx=co=ct=0;
	REP(j,4){
		if(st[j][j]=='.')over=false;
		else if(st[j][j]=='O')co++;
		else if(st[j][j]=='X')cx++;
		else if(st[j][j]=='T')ct++;
	}
	if(co==4||(co==3&&ct==1))return 1;
	if(cx==4||(cx==3&&ct==1))return 0;

	if(over)return 2;
	return 3;
}
int main(){
	int t;
	cin>>t;
	REP(tt,t){
		int res=judge();
		printf("Case #%d: ",tt+1);
		switch(res){
		case 0:
			printf("X won\n");
			break;
		case 1:
			printf("O won\n");
			break;
		case 2:
			printf("Draw\n");
			break;
		case 3:
			printf("Game has not completed\n");
			break;
		}
	}



	return 1;
	

	
}