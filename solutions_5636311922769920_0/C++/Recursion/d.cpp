#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int task,s,c,k;
int main() {
	//freopen("D-small-attempt0.in","r",stdin);
	//freopen("D-small-attempt0.out","w",stdout);
	scanf("%d",&task);
	for (int id=1;id<=task;id++) {
		scanf("%d%d%d",&k,&c,&s);
		printf("Case #%d:",id);
		for (int i=1;i<=s;i++) printf(" %d",i);
		printf("\n");
	}
	return 0;
}
