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
int T,x,n,m,k;    

int main () {
	freopen ("D-large.in","r",stdin);
	freopen ("output.txt","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d%d%d",&x,&n,&m);
		printf("Case #%d: ",t);
		if(n > m) swap(n,m);
		if(x > m){
			puts("RICHARD");
			continue;
		}
		if((n * m) % x != 0){
			puts("RICHARD");
			continue;
		}
		if(n < (x+1)/2){
			puts("RICHARD");              
			continue;
		}
		if(n > (x + 1) / 2){
			puts("GABRIEL");              
			continue;
		}
		k = (x + 2) / 2;
		bool ok = 1, flag = 0;
		for(int i=0;i<k;i++){
			ok = 1;
			for(int j=i+1;j+k-i-1<=m;j++){
				if(((j - 1)* n - i) % x == 0){
					ok = 0;	
					break;
				}
			}		
			if(ok){
				flag = 1;
				break;
			}
		}
		if(!flag) puts("GABRIEL");
		else puts("RICHARD");
	}                  
return 0;
}