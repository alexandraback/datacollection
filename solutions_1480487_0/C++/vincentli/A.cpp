#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
int n;
double total;
struct content{
	double score;
	int num;
}contents[210];

double ans[1000];

bool check(int num,double aim,double s){
	int i;
	double top;
	for (i = 0;i < n;i++){
		if (i == num)
			continue;
		if (contents[i].score > aim){
			continue;
		}
		if (contents[i].score + s*total < aim)
			return true;
		else{
			s = s-(aim-contents[i].score)/total;
		}
	}
	return false;
}
double calc(int num){
	int i;
	double low = 0.0;
	double high = 100.00;
	while (high-low > 0.000000005){
		double mid = (low+high)/2.0;
		if (check(num,contents[num].score+mid*total,100.0-mid)){
			high = mid;
		}
		else
			low = mid;
	}
	return low;
}
int main(){
	int t;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	int i,tmp,j;
	for (i = 1;i <= t;i++){
		scanf("%d",&n);
		total = 0.0;
		for (j = 0;j < n;j++){
			scanf("%d",&tmp);
			total += (double)tmp+0.000000001;
			contents[j].score = (double)tmp*100.0+0.000000001;
			contents[j].num = j;
		}
		tmp = 0;
		printf("Case #%d:",i);
		for (j = 0;j < n;j++){
			printf(" %lf",calc(j)+0.00000001);
		}
		printf("\n");
	}
}