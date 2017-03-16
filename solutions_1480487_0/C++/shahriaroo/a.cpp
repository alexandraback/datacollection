									/*	In the name of God	*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <bitset>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define rep(i,n) for((i)=0;(i)<(n);(i)++)
typedef long long ll;

using namespace std;

int a[1001];
int main(){
	freopen("A-small-attempt2.in","r",stdin);
	freopen("A-small-attempt2.out","w",stdout);	
	int tc,ti,i,j,n,sum;
	scanf("%d",&tc);
	rep(ti,tc){
		scanf("%d",&n);
		int x=0;
		rep(i,n){
			scanf("%d",&a[i]);
			x+=a[i];
		}
		printf("Case #%d:",ti+1);
		double avg=2*x/(double)n;
		rep(i,n){
			double y=0;
			int cnt=0;
			rep(j,n)
				if (a[j]<=avg){
					cnt++;
				}
			y=x/(double)n+x/(double)cnt;
			printf(" %lf",max(0.,100*(y-a[i])/x));
		}
		printf("\n");
	}
	return 0;
}