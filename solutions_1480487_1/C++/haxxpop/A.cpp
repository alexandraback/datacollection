#include<stdio.h>
#include<algorithm>
using namespace std;
int ord[1000];
int a[1000];
int cmp(int x,int y){
	return a[x] < a[y];
}
int main(){
	int t;
	scanf("%d",&t);
	for(int g = 0 ; g < t; g++ ){
		int n;
		scanf("%d",&n);
		for(int i = 0 ; i < n ; i++ ) scanf("%d",&a[i]);
		int all = 0;
		for(int i = 0 ; i < n ; i++ ) all += a[i] ;
		printf("Case #%d:",g+1);
		for(int k = 0 ; k < n ; k++ ){
			int sum = a[k] ;
			int num = 1;
			int chk = 0;
			for(int i = 0 ; i < n ; i++ ){
				if( k != i ){
					ord[i-chk] = i;
				}else{
					chk = 1;
				}
			}
			sort(ord,ord+(n-1),cmp);
			for(int i = 0 ; i < n-1 ; i++ ){
				sum += a[ord[i]];
				num++;
				double val = ( (double)sum + all ) / num;
				if( num == n || val <= a[ord[i+1]] ){
					if( val-a[k] > 0) printf(" %lf",(val-a[k])/all*100);
					else printf(" %lf",0.0);
					break;
				}
			}
		}
		printf("\n");
	}
}
