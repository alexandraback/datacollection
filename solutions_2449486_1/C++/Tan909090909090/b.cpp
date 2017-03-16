#include<stdio.h>
#include<string.h>
#include<array>
#include<limits.h>
#include<algorithm>
using namespace std;

int H,W;
int a[100][100];

bool Solve(){
	array<int,100> row, col;
	row.fill(0);
	col.fill(0);
	for(int x=0; x<W; ++x){
		for(int y=0; y<H; ++y){
			row[y] = max(row[y],a[y][x]);
			col[x] = max(col[x],a[y][x]);
		}
	}

	for(int x=0; x<W; ++x){
		for(int y=0; y<H; ++y){
			if(a[y][x]!=row[y] && a[y][x]!=col[x])
				return false;
		}

	}
	return true;
}


int main() {
	int T, caseNum;
	scanf("%d",&T);
	for(caseNum = 1; caseNum <= T; ++caseNum) {

		scanf("%d%d",&H,&W);
		for(int y=0; y<H; ++y)
			for(int x=0; x<W; ++x)
				scanf("%d",&a[y][x]);


		printf("Case #%d: ", caseNum);
		puts(Solve() ? "YES" : "NO");
	}
	return 0;
}
