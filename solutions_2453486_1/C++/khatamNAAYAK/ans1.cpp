# include <stdio.h>
# include <stdlib.h>
# include <cstdlib>
# include <iostream>
# include <cstdio>
# include <string>
# include <cstring>
# include <sstream>
# include <math.h>
# include <algorithm>
# include <map>
# include <vector>
# include <stack>
# include <queue>
# include <set>
#include <vector>

using namespace std;

int main ()
{
	int cnt,cases,i,j,k,l,m,n;
	cin >> cases;
	vector<string>bd;
	string str;
	for(cnt = 1 ; cnt <= cases ; cnt++){
		bd.clear();
		// str.clear();
		cin >> str;bd.push_back(str);
		cin >> str;bd.push_back(str);
		cin >> str;bd.push_back(str);
		cin >> str;bd.push_back(str);
		char winner='.',tnd=0;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				if(bd[i][j]=='.')tnd++;
		char ch[128];
		//Rows
		for(i = 0 ; i < 4 ; i++){
			memset(ch,0,128);
			for(j = 0 ; j < 4 ; j++){
				ch[bd[i][j]]++;
			}
			if(ch['X']==4)winner='X';
			if(ch['O']==4)winner='O';
			if((ch['X']==3)&&(ch['T']==1))winner='X';
			if((ch['O']==3)&&(ch['T']==1))winner='O';
		}
		//Columns
		for(i = 0 ; i < 4 ; i++){
			memset(ch,0,128);
			for(j = 0 ; j < 4 ; j++){
				ch[bd[j][i]]++;
			}
			if(ch['X']==4)winner='X';
			if(ch['O']==4)winner='O';
			if((ch['X']==3)&&(ch['T']==1))winner='X';
			if((ch['O']==3)&&(ch['T']==1))winner='O';
		}
		//+ve Diagonals
		memset(ch,0,128);
		for(i=0;i<4;i++){
			ch[bd[i][i]]++;
		}
		if(ch['X']==4)winner='X';
		if(ch['O']==4)winner='O';
		if((ch['X']==3)&&(ch['T']==1))winner='X';
		if((ch['O']==3)&&(ch['T']==1))winner='O';
		//-ve Diagonal
		memset(ch,0,128);
		for(i=0;i<4;i++){
			ch[bd[i][3-i]]++;
		}
		if(ch['X']==4)winner='X';
		if(ch['O']==4)winner='O';
		if((ch['X']==3)&&(ch['T']==1))winner='X';
		if((ch['O']==3)&&(ch['T']==1))winner='O';
		
		cout << "Case #" << cnt << ": ";

		if((winner=='.')&&(tnd==0))cout << "Draw\n";
		if((winner=='.')&&(tnd>0))cout << "Game has not completed\n";
		if(winner != '.')cout << winner << " won\n";
	}

	return 0;
}
