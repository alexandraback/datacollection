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

char cod[20], jam[20], ans1[20], ans2[20];
int s1,s2;
ll dif, cod1, jam1;

void backtrack2(int a){
	if(a == s2){
		ll aux1 = stoi(cod);
		ll aux2 = stoi(jam);
		ll tmp = abs(aux1-aux2);
		if(tmp == dif && (aux1 < cod1 || (aux1 == cod1 && aux2 < jam1))){
			dif = tmp;
			cod1 = aux1;
			jam1 = aux2;
			strcpy(ans1, cod);
			strcpy(ans2, jam);
			return ;
		}
		if(tmp < dif){
			dif = tmp;
			cod1 = aux1;
			jam1 = aux2;
			strcpy(ans1, cod);
			strcpy(ans2, jam);
		}
		return ;
	}
	if(jam[a] != '?'){
		backtrack2(a+1);
		return;
	}
	for(int i = '0'; i <= '9'; i++){
		jam[a] = i;
		backtrack2(a+1);
	}
	jam[a] = '?';
}

void backtrack(int a){
	if(a == s1){
		backtrack2(0);
		return ;
	}
	if(cod[a] != '?'){
		backtrack(a+1);
		return;
	}
	for(int i = '0'; i <= '9'; i++){
		cod[a] = i;
		backtrack(a+1);
	}
	cod[a] = '?';
}

int main() {
	int t,n,tc=1,x,i;

	scanf("%d", &t);
	while(t--){
		scanf("%s %s", cod, jam);
		s1 = strlen(cod); s2 = strlen(jam);
		dif = cod1 = jam1 = 1e18;

		backtrack(0);
		printf("Case #%d: %s %s\n", tc++, ans1, ans2);
	}

	return 0;
}
