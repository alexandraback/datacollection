//============================================================================
// Name        : GCJ2012QC.cpp
// Author      : Takatomo Honda
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <queue>
using namespace std;

#define all(c) (c).begin(),(c).end()
#define FORE(i,d,e) for(int i=d;i<e;i++)
#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

int R,C,M;

void solve(){
	char p[R][C];
	int check[R][C];
	FORE(i,0,R)FORE(j,0,C)p[i][j]='.';
	memset(check,0,sizeof(check));

	int r=0,c=0;
	while(M>0&&r<R&&c<C){
		if( (R-r<=C-c && R-r-M!=1) || C-c-M==1){
			FORE(i,r,R){
				if(M==1&&R-i==2)break;
				if(M>0){
					p[i][c]='*';
					check[i][c]=1;
					M--;
				}
			}
			c++;
		}
		else{
			FORE(j,c,C){
				if(M==1&&C-j==2)break;
				if(M>0){
					p[r][j]='*';
					check[r][j]=1;
					M--;
				}
			}
			r++;
		}
	}

	queue<pair<int,int> > q;

	r=R-1,c=C-1;

	/*int ok=1;
	if(ok==0||M>0){
		printf("Impossible\n");
		return;
	}*/

	if(p[r][c]=='*'){
		printf("Impossible\n");
		return;
	}
	p[r][c]='c';
	check[r][c]=1;
	q.push(make_pair(r,c));

	while(!q.empty()){
		int curr=q.front().first;
		int curc=q.front().second;
		q.pop();
		int ok=1;
		for(int i=curr-1;i<=curr+1;i++){
			for(int j=curc-1;j<=curc+1;j++){
				if(0<=i&&i<R && 0<=j&&j<C &&p[i][j]=='*')ok=0;
			}
		}
		if(ok){
			for(int i=curr-1;i<=curr+1;i++){
				for(int j=curc-1;j<=curc+1;j++){
					if(0<=i&&i<R && 0<=j&&j<C && check[i][j]==0){
						check[i][j]=1;
						q.push(make_pair(i,j));
					}
				}
			}
		}
	}

	int invalid=0;
	FORE(i,0,R)FORE(j,0,C)if(check[i][j]==0)invalid=1;
	if(invalid||M>0){
		printf("Impossible\n");
		return;
	}

	FORE(i,0,R){
		FORE(j,0,C)printf("%c",p[i][j]);
		printf("\n");
	}

	return;
}

int main(int argc, char *args[]) {
	FILE *stream;

	if ( argc==2 && strcmp(args[1], "small")==0 ) {
		if( (stream=freopen("test.bsmall.txt","rt",stdin))==NULL){
			printf("file open error");
		}
        //freopen("small.out","wt",stdout);
    }
    else if (argc == 2 && strcmp(args[1], "large") == 0) {
        freopen("large.in","rt",stdin);
        freopen("large.out","wt",stdout);
    }
    else {
	    freopen("C-large.in", "rt", stdin);
        freopen("large.out","wt",stdout);
    }

	int N;
	cin>>N;

    vector<string> ans(N);
    ans.clear();


    FORE(i,0,N) {
    	printf("Case #%d:\n", i+1);
        cin>>R>>C>>M;
        solve();
    }

    return 0;
}



