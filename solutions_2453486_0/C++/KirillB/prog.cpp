#include <stdio.h>
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cassert>
#include <string.h>
#include <time.h>
#include <fstream>
using namespace std;
#pragma comment(linker, "/STACK:50000000")

typedef vector<int> vi; 
#define sz(a) int((a).size()) 
#define all(c) (c).begin(),(c).end() 

string problem_name = "A-small-attempt0";

void init(){
	freopen((problem_name+".in").c_str(),"rt",stdin);
	freopen((problem_name+".out").c_str(),"wt",stdout);
}


char mas[11][11];
int u[255];
string solve()
{
	int O=0,X=0;
	u['.']=0;
	for (int i=0;i<4;i++)
	{
		u['O']=0;
		u['T']=0;
		u['X']=0;
		for (int j=0;j<4;j++)
			u[mas[i][j]]++;
		if (u['O']+u['T']==4) O=1;
		if (u['X']+u['T']==4) X=1;

		u['O']=0;
		u['T']=0;
		u['X']=0;
		for (int j=0;j<4;j++)
			u[mas[j][i]]++;
		if (u['O']+u['T']==4) O=1;
		if (u['X']+u['T']==4) X=1;	
	}

	u['O']=0;
	u['T']=0;
	u['X']=0;
	for (int i=0;i<4;i++)
		u[mas[i][i]]++;
	if (u['O']+u['T']==4) O=1;
	if (u['X']+u['T']==4) X=1;

	u['O']=0;
	u['T']=0;
	u['X']=0;
	for (int i=0;i<4;i++)
		u[mas[i][3-i]]++;
	if (u['O']+u['T']==4) O=1;
	if (u['X']+u['T']==4) X=1;

	if (O) return "O won";
	if (X) return "X won";
	if (u['.']) return "Game has not completed";
	return "Draw";

}

int main() {

	init();

	int tst;

	scanf("%d\n",&tst);

	for (int cas=1;cas<=tst;cas++)
	{
		
		for (int i=0;i<5;i++)
			gets(mas[i]);
		
	
	
		printf("Case #%d: %s\n",cas,solve().c_str());
	}

	
	


	






	return 0;
}