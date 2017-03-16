#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-out.txt","w",stdout);
	int T;
	cin>>T;
	for(int at=0;at<T;at++){
		printf("Case #%d: ",at+1);
		vector<string> s(4);
		for(int i=0;i<4;i++)
			cin>>s[i];
		int px=0,po=0,emp=0;
		for(int i=0;i<4;i++){
			int x=0,o=0,t=0;
			for(int j=0;j<4;j++){
				if(s[i][j]=='.') emp++;
				if(s[i][j]=='X') x++;
				if(s[i][j]=='O') o++;
				if(s[i][j]=='T') t++;
			}
			if(x+t==4) px=1;
			if(o+t==4) po=1;
		}

		for(int j=0;j<4;j++){
			int x=0,o=0,t=0;
			for(int i=0;i<4;i++){
				if(s[i][j]=='X') x++;
				if(s[i][j]=='O') o++;
				if(s[i][j]=='T') t++;
			}
			if(x+t==4) px=1;
			if(o+t==4) po=1;
		}

		int x=0,o=0,t=0;
		for(int i=0;i<4;i++){
			if(s[i][i]=='X') x++;
			if(s[i][i]=='O') o++;
			if(s[i][i]=='T') t++;
		}
		if(x+t==4) px=1;
		if(o+t==4) po=1;
		
		x=0;o=0;t=0;
		for(int i=0;i<4;i++){
			if(s[i][4-i-1]=='X') x++;
			if(s[i][4-i-1]=='O') o++;
			if(s[i][4-i-1]=='T') t++;
		}
		if(x+t==4) px=1;
		if(o+t==4) po=1;

		if(px)
			printf("X won\n");
		else
			if(po)
				printf("O won\n");
			else
				if(emp==0)
					printf("Draw\n");
				else
					printf("Game has not completed\n");
	}



}