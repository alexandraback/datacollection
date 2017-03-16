#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1010;

struct xs{
	double val;
	int play; 
	};

bool cmp(const xs & a, const xs & b){
	return a.val < b.val;
	}

vector<xs> stuff;
vector<int> player[2];

void solve(int test){
	int n;
	scanf("%d\n", &n);
	
	stuff.clear();
	player[0].clear();
	player[1].clear();
	
	double x;
	for(int i = 0; i < n; i++)
		scanf("%lf", &x),
		stuff.push_back( (xs){x, 0} );
	for(int i = 0; i < n; i++)
		scanf("%lf", &x),
		stuff.push_back( (xs){x, 1} );
	
	sort(stuff.begin(), stuff.end(), cmp);
	
	for(int i = 0; i < 2*n; i++)
		player[stuff[i].play].push_back(i);
	
	//~ cout << "Players:" << endl;
	//~ for(int i = 0; i < player[0].size(); i++)
		//~ printf("%d ", player[0][i]);
	//~ cout << "\nOther:" << endl;
	//~ for(int i = 0; i < player[1].size(); i++)
		//~ printf("%d ", player[1][i]);
	//~ cout << "" << endl;
	
	int won = 0;
	int start = 0;
	
	for(int i = 0; i < player[0].size(); i++)
		if(player[0][i] > player[1][start])
			won++, start++;
	
	int w = 0, pos = 0;
	for(int i = 0; i < n; i++){
		while(pos < n && player[1][pos] < player[0][i])
			pos++;
		if(pos >= n)
			w++;
		}
	
	printf("Case #%d: %d %d\n", test, won, w);
	}

int main(){	
	int testcases;
	scanf("%d", &testcases);
	
	for(int test = 0; test < testcases; test++)
		solve(test+1);
	
	return 0;
}
