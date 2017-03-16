#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
typedef long long ll;
typedef unsigned long long hash;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define N 3000
#define oo 1000000000

int a[N], b[N];
int n;

int main(){
	int casos;
	scanf( "%d", &casos );
	
	for(int ca = 1; ca <= casos; ++ca){
		scanf( "%d", &n );
		for(int i = 0; i < n; ++i) scanf( "%d %d", a + i, b + i );
		int cmp = 0;
		int star = 0;
		
		while(1){
			bool parar = true;
			
			while(1){
				bool mudou = false;
				for(int i = 0; i < n; ++i){
					if(b[i] <= star){
						++cmp;
						if(a[i] < oo) star += 2;
						else ++star;
						
						a[i] = b[i] = oo;
						mudou = true;
					}
				}
				if(!mudou) break;
				parar = false;
			}
			int ind = -1, maior = -1;
			
			for(int i = 0; i < n; ++i){
				if(a[i] <= star && (ind == -1 || b[i] > maior)){
					maior = b[i];
					ind = i;
				}
			}
			
			if(~ind){
				++cmp;
				a[ind] = oo;
				++star;
				parar = false;
			}
			
			if(parar) break;
		}
		
		bool dm = false;
		for(int i = 0; i < n; ++i){
			if(b[i] < oo || a[i] < oo) dm = true;
		}
		
		if(!dm) printf( "Case #%d: %d\n", ca, cmp);
		else printf( "Case #%d: Too Bad\n", ca);
	}	
}


