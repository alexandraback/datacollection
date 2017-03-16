#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

typedef pair<string,int> pr;

int main(){

	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int test,tc=1,n,m,i,j;
	int prev[10],now,next,mat[10][10];
	vector<pr> city;
	string in;
	
	for( scanf("%d",&test) ; test-- ;){
		scanf("%d%d",&n,&m);
		
		memset(mat,0,sizeof(mat));
		city.clear();
		
		for( i=1 ; i<=n ; i++ ){
			cin >> in;
			city.push_back(make_pair(in,i));
		}
		sort(city.begin(),city.end());
		
		for(; m-- ;){
			scanf("%d%d",&i,&j);
			mat[i][j]=mat[j][i]=1;
		}
		
		do{
			memset(prev,0,sizeof(prev));
			now = city[0].second;
			prev[now]=-1;
			
			for( i=1 ; i<n ; i++ ){
				next=city[i].second;
				lagi:
				if( mat[now][next] ){
					prev[next]=now;	
					now=next;
				}
				else{
					if( prev[now]==-1 ) goto next;	
					now=prev[now];
					goto lagi;
				}
			}
			break;
			next:;
		}
		while( next_permutation(city.begin(),city.end()) );
		
		printf("Case #%d: ",tc++);
		for( i=0 ; i<n ; i++ ) cout << city[i].first;
		putchar('\n');
		
	}
	
	return 0;
}

