//
//  main.cpp
//  intern
//
//  Created by AekdyCoin on 13-1-15.
//  Copyright (c) 2013年 AekdyCoin. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
using namespace std;
typedef long long LL ;
typedef double db;
#define rep(i,n) for(int i=0;i<n;++i)

int valid( char c, char d) {
	return c == d || d == 'T' ;
}

bool win( char a, char b, char c, char d, char t) {
	return valid(t,a) + valid(t,b) + valid(t,c)+ valid(t,d) == 4;
}

char mat[ 5 ][5 ];

int main(int argc, const char * argv[]){
	freopen("A-large.in","r", stdin);
	freopen("A-large.out","w" , stdout);
	int T; cin >> T;
	while(T --) {
		static int cas = 0; ++ cas;
		for(int i=0;i<4;++i)cin>>mat[i];
		printf("Case #%d: ", cas );
		bool full = true ;
		rep(i,4)rep(j,4) if(mat[i][j] == '.') full = false;
		bool w0, w1 ; w0 = w1 = false;
		int c0, c1;c0 = c1 = 0;
		rep(i,4)rep(j,4) if(mat[i][j] == 'X') ++ c0; else if(mat[i][j] == 'O') ++ c1;
		if(c0 == c1 || c0 == c1 + 1) {
			rep(i,4)w0 |= win(mat[i][0],mat[i][1],mat[i][2],mat[i][3],'X');
			rep(i,4)w1 |= win(mat[i][0],mat[i][1],mat[i][2],mat[i][3],'O');
			rep(i,4)w0 |= win(mat[0][i],mat[1][i],mat[2][i],mat[3][i],'X');
			rep(i,4)w1 |= win(mat[0][i],mat[1][i],mat[2][i],mat[3][i],'O');
			w0 |= win(mat[0][0],mat[1][1],mat[2][2], mat[3][3],'X');
			w0 |= win(mat[0][3],mat[1][2],mat[2][1], mat[3][0],'X');
			w1 |= win(mat[0][0],mat[1][1],mat[2][2], mat[3][3],'O');
			w1 |= win(mat[0][3],mat[1][2],mat[2][1], mat[3][0],'O');
			if(w0&&w1)puts("Game has not completed");
			else if(!w0&&!w1){
				if(full) puts("Draw");
				else puts("Game has not completed");
			}else printf("%s won\n", w0?"X":"O");
		}else {
			puts("Game has not completed");
		}
	}
	return 0;
}

