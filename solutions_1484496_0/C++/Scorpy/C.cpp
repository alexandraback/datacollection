#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdio>
using namespace std;


int a [300];


bool finded = false;

int sum1 = 0;
int sum2 = 0;

int set1 [20];
int sz1 = 0;
int sz2 = 0;
int set2 [20];

void dfs( int i ){
	if( i==20 ){
		finded = sum1==sum2;
		return;
	}

	sum1+=a[i];
	dfs(i+1);
	if( finded ){
		set1[sz1++] = a[i];
		return;
	}
	sum1-=a[i];
	sum2+=a[i];
	dfs(i+1);
	if( finded ){
		set2[sz2++] = a[i];
		return;
	}
	sum2-=a[i];

	dfs(i+1);
}

void solve(){
	sz1 = 0;
	sz2 = 0;
	sum1 = 0;
	sum2 = 0;
	finded = false;
	int n;
	scanf("%d", &n);



	for( int i = 0; i < n; i++ )
		scanf("%d", &a[i]);
	
	dfs(0);
	if( finded ){
		printf("\n");
		for( int i = 0; i < sz1; i++ ){
			if(i)
				printf(" ");
			printf("%d", set1[i]);
		}
		printf("\n");
		for( int i = 0; i < sz2; i++ ){
			if(i)
				printf(" ");
			printf("%d", set2[i]);
		}
	}
	else{
		printf("Impossible");
	}
}



int main(){
	
	freopen("C.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	for( int i = 0; i < T; i++ ){
		printf("Case #%d:", i+1);
		solve();
		printf("\n");
	}
}