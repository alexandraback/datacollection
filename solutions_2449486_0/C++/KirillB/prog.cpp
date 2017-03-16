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

string problem_name = "B-small-attempt0";

void init(){
	freopen((problem_name+".in").c_str(),"rt",stdin);
	freopen((problem_name+".out").c_str(),"wt",stdout);
}

int arr[111][111];

int main() {

	init();

	int tst;

	scanf("%d\n",&tst);

	for (int cas=1;cas<=tst;cas++)
	{
		
		int n,m;
		scanf("%d %d",&n,&m);

		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				scanf("%d",&arr[i][j]);

		int res=1;
		for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			int ok=0;
			int mx=0;
			for (int k=0;k<m;k++)
				mx=max(mx,arr[i][k]);
			if (arr[i][j]>=mx) ok=1;
			mx=0;
			for (int k=0;k<n;k++)
				mx=max(mx,arr[k][j]);
			if (arr[i][j]>=mx) ok=1;
			if (!ok) res=0;		
		}
		
		string r;
		if (res) r="YES"; else
			r="NO";

		printf("Case #%d: %s\n",cas,r.c_str());
	}

	
	


	






	return 0;
}