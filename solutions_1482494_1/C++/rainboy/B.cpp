#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MaxN=3000;
struct node{
	int x,y;
};
node a[MaxN];
int N,T;
void work(){
	int Ans=0,star=0;
	int now=N-1;
	while (N>0){
		for (int i=now;i>=0;i--)
		if (a[i].y<=star){
			swap(a[i],a[now]);
			now--;
		}
		if (now!=N-1){
			for (int i=now+1;i<N;i++){
				if (a[i].x<0) star+=1;else
				star+=2;
				Ans++;
			}
			N=now+1;
			continue;
		}
		int tmp=-1;
		int flag=0;
		for (int i=0;i<N;i++)
		if (a[i].x>=0 && a[i].x<=star){
			if (tmp==-1) tmp=i;else
			if (a[i].y>a[tmp].y) tmp=i;
		}
		if (tmp==-1){
			printf("Too Bad\n");
			return;
		}
		a[tmp].x=-1;
		star++;
		Ans++;
	}
	printf("%d\n", Ans);
}
int main(){
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	scanf("%d", &T);
	for (int t=1;t<=T;t++){
		scanf("%d", &N);
		for (int i=0;i<N;i++)
		scanf("%d %d", &a[i].x, &a[i].y);
		printf("Case #%d: ", t);
		work();
	}
	return 0;
}
