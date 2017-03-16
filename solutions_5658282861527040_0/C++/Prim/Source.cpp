#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>

#define pb push_back
#define mp make_pair
#define vi vector <int>
#define vii vector <pair<int,int> >
#define ll long long
#define f first
#define s second

using namespace std;

int a,b,c,cnt, t1,t;

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("D.out", "w", stdout);

	scanf ("%d", &t);
	for(t1 = 1; t1 <= t; ++t1){
		scanf ("%d %d %d", &a, &b, &c);
		for(int i = 0; i < a; i++){
			for(int j = 0; j < b; j++){
				if( (i&j) < c) cnt++;
			}
		}
		printf("Case #%d: %d\n", t1,cnt);
		cnt = 0;
	}

	return 0;
}