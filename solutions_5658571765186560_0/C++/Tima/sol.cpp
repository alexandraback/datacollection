#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define pii pair<int, int>
using namespace std;
int T,x,n,m;    

int main () {
	freopen ("D-small-attempt2.in","r",stdin);
	freopen ("output.txt","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d%d%d",&x,&n,&m);
		printf("Case #%d: ",t);
		if(x > max(n,m)){
			puts("RICHARD");
			continue;
		}
		if((n * m) % x != 0){
			puts("RICHARD");
			continue;
		}
		if(min(n,m) < (x+1)/2){
			puts("RICHARD");              
			continue;
		}
		if(n > m) swap(n,m);
		if(x == 4 && n == 2 && m == 4){
			puts("RICHARD");              
			continue;
		}
		puts("GABRIEL");
	}
return 0;
}