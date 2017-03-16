#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#define MAXN 102000
#define pb push_back
using namespace std;
typedef long long lint;
struct node
{
	int a,b,c;
};
int ar1[12][12];
int ar2[12][12];
int ar3[12][12];
node ar[111];
node res[111];
int ress;
int A,B,C,K;
void rec(int a,int b,int c,int k){
	if(ress == A*B*C) return;
	if(a == A && b == B && c == C+1){
		if(k > ress){
			ress = k;
			for(int i = 0; i < k ; i++)
				res[i] = ar[i];
		}
		return;
	}
	if(c == C+1){ b++; c = 1; }
	if(b == B+1){ a++; b = 1; }

	if(ar1[a][b]+1 <= K && ar2[a][c]+1 <= K && ar3[b][c]+1 <= K){
		ar1[a][b]++;
		ar2[a][c]++;
		ar3[b][c]++;
		ar[k] = (node){a,b,c};
		rec(a,b,c+1,k+1);
		ar1[a][b]--;
		ar2[a][c]--;
		ar3[b][c]--;
	}
	rec(a,b,c+1,k);
}
int main(){
	int Test,tt;
	scanf(" %d",&Test);
	for(tt=1;tt<=Test;tt++){
		scanf(" %d %d %d %d",&A,&B,&C,&K);
		printf("Case #%d: ", tt);
		ress = 0;
		for(int i = 0 ; i < 12 ; i++)
			for(int j = 0 ; j < 12 ; j++)
				 ar1[i][j] = ar2[i][j] = ar3[i][j] = 0;
		rec(1,1,1,0);
		printf("%d\n",ress);
		for(int i = 0 ; i < ress;i++){
			printf("%d %d %d\n", res[i].a,res[i].b,res[i].c);
		}	
	}
	return 0;
}