#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>
#include <deque>
#include <set>
#include <queue>

using namespace std;


bool tab[5][5][5];

int main(){
	
	freopen("D-small-attempt6.in","r",stdin);
	freopen("D-small-attempt6.out","w",stdout);
	//1
	tab[1][1][1]=0;
	tab[1][2][1]=1;
	tab[1][2][2]=1;
	tab[1][3][1]=1;
	tab[1][3][2]=1;
	tab[1][3][3]=1;
	tab[1][4][1]=1;
	tab[1][4][2]=1;
	tab[1][4][3]=1;
	tab[1][4][4]=1;
	
	//2
	tab[2][1][1]=0;
	tab[2][2][1]=0;
	tab[2][2][2]=1;
	tab[2][3][1]=0;
	tab[2][3][2]=1;
	tab[2][3][3]=0;
	tab[2][4][1]=0;
	tab[2][4][2]=1;
	tab[2][4][3]=1;
	tab[2][4][4]=1;
	
	//
	tab[3][1][1]=0;
	tab[3][2][1]=0;
	tab[3][2][2]=0;
	tab[3][3][1]=0;
	tab[3][3][2]=0;
	tab[3][3][3]=1;
	tab[3][4][1]=0;
	tab[3][4][2]=0;
	tab[3][4][3]=1;
	tab[3][4][4]=0;	
	//
	tab[4][1][1]=0;
	tab[4][2][1]=0;
	tab[4][2][2]=0;
	tab[4][3][1]=0;
	tab[4][3][2]=0;
	tab[4][3][3]=0;
	tab[4][4][1]=0;
	tab[4][4][2]=0;
	tab[4][4][3]=0;
	tab[4][4][4]=1;
	
	int t;
	cin>>t;
	int cas=0;
	while(t--){
		cas++;
		int x,a,b;
		cin>>x>>a>>b;
		
		if(a<b)swap(a,b);
		
		if(tab[x][a][b]){
			printf("Case #%d: GABRIEL\n",cas);
		}else{
			printf("Case #%d: RICHARD\n",cas);
		}
	}
	
	return 0;
}

