#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <utility>

using namespace std;

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	string S[105][105];
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++){
		int x,y;
		scanf("%d %d",&x,&y);
		string ans;
		if(x < 0){
			//ans += 'W';
			for(int i=0;i<abs(x);i++)
				ans += "EW";
		}
		else if(x > 0){
			//ans += 'E';
			for(int i=0;i<x;i++)
				ans += "WE";
		}
		
		if(y > 0){
			//ans += 'N';
			for(int i=0;i<y;i++)
				ans += "SN";
		}
		else if(y < 0){
			//ans += 'S';
			for(int i=0;i<abs(y);i++)
				ans += "NS";
		}
		printf("Case #%d: ",tt);
		cout << ans << endl;
	}
	return 0;
}
