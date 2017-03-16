#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iterator>
#include <iostream>
#include <functional>
#include <sstream>
#include <numeric>

#define CLR( x , y ) ( memset( (x) , (y) , sizeof( (x) ) ) )
#define EPS 1e-9

using namespace std;

FILE *in=fopen("D.in","r");
FILE *out=fopen("D.out","w");

long double x[1001],y[1001];

int vis1[1001],vis2[1001];

int main()
{
	int i,j,k,test,tests;
	fscanf(in,"%d",&tests);
	int n;
	for(test=1;test<=tests;test++){
		fscanf(in,"%d", &n);
		for(i=0;i<n;i++)
			fscanf(in,"%llf", &x[i]);
		for(i=0;i<n;i++)
			fscanf(in,"%llf", &y[i]);
		sort(x,x+n);
		sort(y,y+n);
		int ret1=0,ret2=0;
		CLR(vis1,0);
		CLR(vis2,0);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(y[j] > x[i] && !vis2[j]){
					break;
				}
			}
			if(j==n) {
				ret2++;
				for(j=0;j<n;j++){
					if(!vis2[j]){
						vis2[j]=1;
						break;
					}
				}
			} else {
				vis2[j]=1;
			}

			for(j=0;j<n;j++) {
				if(y[j]<x[i] && !vis1[j]) {
					break;
				}
			}
			if(j==n) {
				for(j=n-1;j>=0;j--){
					if(!vis1[j]){
						vis1[j]=1;
						break;
					}
				}
			} else {
				vis1[j]=1;
				ret1++;
			}
		}
		fprintf(out,"Case #%d: %d %d\n", test, ret1, ret2);
	}
	return 0;
}
