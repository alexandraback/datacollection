#include <algorithm>
#include <numeric>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <stack>
using namespace std;

char mas[4][4];

string check() {
	int emp=0;
	for (int i=0;i<4;i++) {
		int xx=0,oo=0;
		for (int j=0;j<4;j++) {
			if (mas[i][j]=='X')
				xx++;
			if (mas[i][j]=='O')
				oo++;
			if (mas[i][j]=='T') {
				xx++;
				oo++;
			}
			if (mas[i][j]=='.')
				emp++;
		}
		if (xx==4)
			return "X won";
		if (oo==4)
			return "O won";
	}
	for (int i=0;i<4;i++) {
		int xx=0,oo=0;
		for (int j=0;j<4;j++) {
			if (mas[j][i]=='X')
				xx++;
			if (mas[j][i]=='O')
				oo++;
			if (mas[j][i]=='T') {
				xx++;
				oo++;
			}
		}
		if (xx==4)
			return "X won";
		if (oo==4)
			return "O won";
	}
	int xx=0,oo=0;
	for (int i=0;i<4;i++) {
		if (mas[i][i]=='X')
			xx++;
		if (mas[i][i]=='O')
			oo++;
		if (mas[i][i]=='T') {
			xx++;
			oo++;
		}
	}
	if (xx==4)
		return "X won";
	if (oo==4)
		return "O won";
	xx=0,oo=0;
	for (int i=0;i<4;i++) {
		if (mas[i][3-i]=='X')
			xx++;
		if (mas[i][3-i]=='O')
			oo++;
		if (mas[i][3-i]=='T') {
			xx++;
			oo++;
		}
	}
	if (xx==4)
		return "X won";
	if (oo==4)
		return "O won";
	if (emp==0)
		return "Draw";
	return "Game has not completed";
}
void solveCase(int t) {
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++)
			cin>>mas[i][j];
	string res=check();
	printf("Case #%d: ",t+1);
	cout<<res<<endl;
}

int main()
{
   freopen("in.in", "rt", stdin);
   freopen("out.out", "wt", stdout);
   int T;
   cin>>T;
   for (int i=0;i<T;i++)
	   solveCase(i);
   return 0;
}