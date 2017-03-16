#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int tc, mat[10][10];
	bool status, xwin, owin, ada;
	string dumstr;
	char temp, dummy;
	scanf("%d", &tc);
	scanf("%d", &dummy);
	for (int a=1; a<=tc; a++){
		xwin=owin=ada=false;
		for (int b=1; b<=4; b++){
			for (int c=1; c<=4; c++){
				scanf("%c", &temp);
				if (temp=='X'){
					mat[c][b]=1;
				}
				else if (temp=='O'){
					mat[c][b]=2;
				}
				else if (temp=='T'){
					mat[c][b]=-1;
				}
				else {
					ada=true;
					mat[c][b]=0;
				}
			}
			scanf("%c", &dummy);
		}
		getline(cin, dumstr);
		for (int b=1; b<=4; b++){
			for (int c=1; c<=4; c++){
				if ((mat[c][b]==1 && xwin==false) || (mat[c][b]==-1 && xwin==false)){
					status=true;
					for (int d=0; d<=3; d++){
						if (mat[c+d][b]!=1 && mat[c+d][b]!=-1){
							status=false;
							break;
						}
					}
					if (status) xwin=true;
					status=true;
					for (int d=0; d<=3; d++){
						if (mat[c][b+d]!=1 && mat[c][b+d]!=-1){
							status=false;
							break;
						}
					}
					if (status) xwin=true;
					status=true;
					for (int d=0; d<=3; d++){
						if (mat[c+d][b+d]!=1 && mat[c+d][b+d]!=-1){
							status=false;
							break;
						}
					}
					if (status) xwin=true;
					status=true;
					for (int d=0; d<=3; d++){
						if (mat[c-d][b+d]!=1 && mat[c-d][b+d]!=-1){
							status=false;
							break;
						}
					}
					if (status) xwin=true;
				}
				if ((mat[c][b]==2 && owin==false) || (mat[c][b]==-1 && owin==false)){
					status=true;
					for (int d=0; d<=3; d++){
						if (mat[c+d][b]!=2 && mat[c+d][b]!=-1){
							status=false;
							break;
						}
					}
					if (status) owin=true;
					status=true;
					for (int d=0; d<=3; d++){
						if (mat[c][b+d]!=2 && mat[c][b+d]!=-1){
							status=false;
							break;
						}
					}
					if (status) owin=true;
					status=true;
					for (int d=0; d<=3; d++){
						if (mat[c+d][b+d]!=2 && mat[c+d][b+d]!=-1){
							status=false;
							break;
						}
					}
					if (status) owin=true;
					status=true;
					for (int d=0; d<=3; d++){
						if (mat[c-d][b+d]!=2 && mat[c-d][b+d]!=-1){
							status=false;
							break;
						}
					}
					if (status) owin=true;
				}
			}
		}
		if (xwin==true){
			printf("Case #%d: X won\n", a);
		}
		else if (owin==true){
			printf("Case #%d: O won\n", a);
		}
		else if (xwin==false && owin==false && ada==true){
			printf("Case #%d: Game has not completed\n", a);
		}
		else if (xwin==false && owin==false && ada==false){
			printf("Case #%d: Draw\n", a);
		}
	}
}
