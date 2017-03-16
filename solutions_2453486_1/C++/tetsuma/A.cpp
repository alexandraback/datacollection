#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;

typedef long long ll;
#define INF (1<<29)

int main(){
	int t;
	cin >> t;
	for(int tc=1;tc<=t;tc++){
		string s[4];
		int ret=0;
		bool ch=false;
		for(int i=0;i<4;i++)cin >> s[i];
		int x, o;
		for(int i=0;i<4;i++){
			x=0, o=0;
			for(int j=0;j<4;j++){
				if(s[i][j]=='O')o++;
				else if(s[i][j]=='X')x++;
				else if(s[i][j]=='T'){
					o++;
					x++;
				}
				else ch=true;
			}
			if(o==4)ret=1;
			else if(x==4)ret=2;
		}
		for(int j=0;j<4;j++){
			x=0, o=0;
			for(int i=0;i<4;i++){
				if(s[i][j]=='O')o++;
				else if(s[i][j]=='X')x++;
				else if(s[i][j]=='T'){
					o++;
					x++;
				}
				else ch=true;
			}
			if(o==4)ret=1;
			else if(x==4)ret=2;
		}
		x=0, o=0;
		for(int i=0;i<4;i++){
			if(s[i][i]=='O')o++;
			else if(s[i][i]=='X')x++;
			else if(s[i][i]=='T'){
				o++;
				x++;
			}
			if(o==4)ret=1;
			else if(x==4)ret=2;
		}
		x=0, o=0;
		for(int i=0;i<4;i++){
			if(s[i][3-i]=='O')o++;
			else if(s[i][3-i]=='X')x++;
			else if(s[i][3-i]=='T'){
				o++;
				x++;
			}
			if(o==4)ret=1;
			else if(x==4)ret=2;
		}
		printf("Case #%d: ",tc);
		if(ret==1)puts("O won");
		else if(ret==2)puts("X won");
		else if(ch)puts("Game has not completed");
		else puts("Draw");
	}
	return 0;
}

