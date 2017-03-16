/* Problem	: Problem B. Lawnmower
** Time		: ???
** Algorithm: ???
**/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD 1000000007
#define MAXN 1000005
#define st first
#define nd second
#define read(x) scanf("%d",&x)
#define rep(i,a,b) for(int i = a ; i <= b ; ++i)
typedef long long int64;

int main (int argc, char const* argv[]){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int T; read(T);
	int n,m, a[111][111];
	int x,y; a[0][0] = 111;
	rep(t,1,T){
		read(m), read(n);
		rep(i,1,m){
			rep(j,1,n){
				read(a[i][j]);
			}
		}
		bool yes = true;
		while(yes){
			x = y = 0;
			rep(i,1,m){
				rep(j,1,n){
					if ( a[i][j] == 0 ) continue;
					if ( a[x][y] > a[i][j] ){
						x = i, y = j;
					}
				}
			}
			if ( x == 0 ) break;
			//horizotal
			bool pass = true;
			rep(k,1,n){
				if ( a[x][k] == 0 ) continue;
				if ( a[x][k] != a[x][y] ){
					pass = false;
					break;
				}
			}
			if ( pass ){
				rep(k,1,n){
					a[x][k] = 0;
				}
			}else{
				// vertical
				pass = true;
				rep(k,1,m){
					if ( a[k][y] == 0 ) continue;
					if ( a[k][y] != a[x][y] ){
						pass = false;
						break;
					}
				}
				if ( pass ){
					rep(k,1,m){
						a[k][y] = 0;
					}
				}else{
					yes = false;
				}
			}
		}
		if ( yes ){
			printf("Case #%d: YES\n",t);
		}else{
			printf("Case #%d: NO\n",t);
		}
	}
	return 0;
}

/* DOAN Minh Quy - mquy.doan@gmail.com */
