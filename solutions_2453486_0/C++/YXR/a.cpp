#include <iostream>
#include <cstdio>
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n,cx,co,ct,ok;
char a[5][5];
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d\n",&n);
	fo(ii,1,n){
		ok=0;
		printf("Case #%d: ",ii);
		fo(i,1,4) {
			fo(j,0,3) scanf("%c",&a[i][j]);
			scanf("\n");
		}
		scanf("\n");
		fo(i,1,4){
			cx=co=ct=0;
			fo(j,0,3) {
                if (a[i][j]=='X') cx++;
			 else if(a[i][j]=='O') co++;
			 else if (a[i][j]=='T') ct++;
            }
			if (cx==4 || cx+ct==4) printf("X won\n"),ok=1;
			if (co==4 || co+ct==4) printf("O won\n"),ok=1;
		}
			if (ok) continue;
		fo(j,0,3){
			cx=co=ct=0;
			fo(i,1,4) if (a[i][j]=='X') cx++;
			else if(a[i][j]=='O') co++;
			else if (a[i][j]=='T') ct++;
			if (cx==4 || cx+ct==4) printf("X won\n"),ok=1;
			if (co==4 || co+ct==4) printf("O won\n"),ok=1;
		}
			if (ok) continue;
		cx=co=ct=0;
		fo(i,1,4) if (a[i][i-1]=='X') cx++;
			else if(a[i][i-1]=='O') co++;
			else if (a[i][i-1]=='T') ct++;
		if (cx==4 || cx+ct==4) printf("X won\n"),ok=1;
		if (co==4 || co+ct==4) printf("O won\n"),ok=1;
			if (ok) continue;
		cx=co=ct=0;
		fo(i,1,4) if (a[i][4-i]=='X') cx++;
			else if(a[i][4-i]=='O') co++;
			else if (a[i][4-i]=='T') ct++;
		if (cx==4 || cx+ct==4) printf("X won\n"),ok=1;
		if (co==4 || co+ct==4) printf("O won\n"),ok=1;
		if (ok) continue;
		fo(i,1,4) {
			fo(j,0,3) 
			if (a[i][j]=='.') {
					printf("Game has not completed\n"),ok=1;
					break;
			}
			if (ok) break;
		}
		if (ok) continue;
		else printf("Draw\n");
	}
}
