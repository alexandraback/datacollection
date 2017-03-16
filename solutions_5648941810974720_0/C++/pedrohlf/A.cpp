#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <stdlib.h>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stack>
#include <sstream>
#include <list>
#include <bitset>
#define ff first
#define ss second

using namespace std;

typedef long long ll;

char s[2005];
map<string,int> tab;
string tab2[10];
vector<int> ans;
int n, tot;

void remove(int a){
	string aux = tab2[a];
	int k = aux.size();
	for(int j = 0; j < k; j++){
		for(int i = 0; i < n; i++){
			if(s[i] == aux[j]){ s[i] = 'A'; break;}
		}
	}
	ans.push_back(a);
	tot += k;
}

int main() {
	int t,tc=1,x,i;

	tab["ZERO"] = 0;
	tab["ONE"] = 1;
	tab["TWO"] = 2;
	tab["THREE"] = 3;
	tab["FOUR"] = 4;
	tab["FIVE"] = 5;
	tab["SIX"] = 6;
	tab["SEVEN"] = 7;
	tab["EIGHT"] = 8;
	tab["NINE"] = 9;

	tab2[0] = "ZERO";
	tab2[1] = "ONE";
	tab2[2] = "TWO";
	tab2[3] = "THREE";
	tab2[4] = "FOUR";
	tab2[5] = "FIVE";
	tab2[6] = "SIX";
	tab2[7] = "SEVEN";
	tab2[8] = "EIGHT";
	tab2[9] = "NINE";
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		n = strlen(s);

		int cont = 0;
		tot = 0;
		ans.clear();
		for(i = 0; i < n; i++){
			if(s[i] == 'Z') remove(0),cont++;
			else if(s[i] == 'W') remove(2), cont++;
			else if(s[i] == 'X') remove(6), cont++;
			else if(s[i] == 'G') remove(8), cont++;
		}
		for(i = 0; i < n; i++){
			if(s[i] == 'H') remove(3),cont++;
		}
		for(i = 0; i < n; i++)
			if(s[i] == 'H') remove(3),cont++;
		for(i = 0; i < n; i++)
			if(s[i] == 'R') remove(4),cont++;
		for(i = 0; i < n; i++)
			if(s[i] == 'F') remove(5),cont++;
		for(i = 0; i < n; i++)
			if(s[i] == 'V') remove(7),cont++;
		for(i = 0; i < n; i++)
			if(s[i] == 'I') remove(9),cont++;
		while(tot < n) ans.push_back(1),tot+=3;
		sort(ans.begin(), ans.end());
		printf("Case #%d: ", tc++);
		for(int x : ans)
			printf("%d", x);
		printf("\n");
	}

	return 0;
}
