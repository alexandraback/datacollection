#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

char output[50];
long long int sum[50];

int main(void){
	freopen("B-large.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int c, cc=0, b;
	long long int m;
	
	sum[0] = 1;
	sum[1] = 1;
	for(int i=2; i<50; i++)	sum[i] = sum[i-1]*2;
	
	cin >> c;
	while( c-- ){
		cin >> b;	cin >> m;
		if( m>sum[b-1] ){
			printf("Case #%d: IMPOSSIBLE\n", ++cc);
			continue;
		}
		
		printf("Case #%d: POSSIBLE\n", ++cc);
		for(int i=b-2; i>=0; i--){
			if( m >= sum[i] ){
				m -= sum[i];
				output[i] = '1';
			}
			else output[i] = '0';
		}
		for(int i=0; i<b-1; i++){
			putchar('0');
			for(int j=0; j<i; j++)	putchar('0');
			for(int j=b-2; j>i; j--)	putchar('1');
			putchar(output[i]);
			putchar('\n');
		}
		for(int i=0; i<b; i++)	putchar('0');
		putchar('\n');
	}
	
	return 0;
}

