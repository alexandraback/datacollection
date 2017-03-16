#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <list>
#include <set>
#include <string.h>
 
using namespace std;
 
typedef long long ll;
 
#define pii pair<int,int>
#define mp make_pair 
#define f first
#define s second
#define MAXN 1000009

int X,Y;

string a;

void Read() {
	scanf("%d %d",&X,&Y);
}

void Solve(int kase) {
	
	if (Y>0) {
		for (int i=1;i<=Y;i++) {
			a.push_back('S');
			a.push_back('N');
		}
	}
	else {
		for (int i=1;i<=-Y;i++) {
			a.push_back('N');
			a.push_back('S');
		}
	}
	
	if (X>0) {
		for (int i=1;i<=X;i++) {
			a.push_back('W');
			a.push_back('E');
		}
	}
	else {
		for (int i=1;i<=-X;i++) {
			a.push_back('E');
			a.push_back('W');
		}
	}
	
	printf("Case #%d: ",kase);
	cout<<a<<'\n';
}

void Init() {
	a.clear();
}

int main () {
	freopen("codejam.in","r",stdin);
	freopen("codejam.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	
	for (int i=1;i<=t;i++) {
		Read();
		Solve(i);
		Init();
	}
	
}
