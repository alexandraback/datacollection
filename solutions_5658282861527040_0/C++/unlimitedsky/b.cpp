//Template for Dev-C++ 5.5.3 by unlimitedsky
//2014 April 14 2135 hours (UTC +0800)
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define FOR(i,a,b,c) for (int i = a; i <= b; i+=c)
#define FORR(i,a,b,c) for (int i = a; i >= b; i-=c)
#define INCE(i,a,b) for (int i = a; i <= b; i++)
#define DECE(i,a,b) for (int i = a; i >= b; i--)
#define INC(i,a,b) for (int i = a; i < b; i++)
#define DEC(i,a,b) for (int i = a; i > b; i--)
#define MP make_pair
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a)
typedef long long LL;
typedef pair<int,int> pii;
typedef vector<pii> vii;

int a, b, c, ctr, tc;

int main(){
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++){
		scanf("%d %d %d", &a, &b, &c);
		ctr = 0;
		for (int j = 0; j < a; j++){
			for (int k = 0; k < b; k++){
				if ((j & k) < c){
					ctr++;
				}
			}
		}
		printf("Case #%d: %d\n", i, ctr);
	}
	return 0;
}
