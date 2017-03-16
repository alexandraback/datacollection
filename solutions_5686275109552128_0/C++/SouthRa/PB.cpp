#include<cstdio>

using namespace std;

int p[1005];
int t[1005];

int main()
{
	int test, maxx, minn, d, time, cake, i, j, k;
	bool valid;
	freopen("C:\\B-small-attempt0.in", "r", stdin);
	freopen("C:\\B-small-attempt0.txt", "w", stdout);
	scanf("%d",&test);
	for(i=1;i<=test;i++){
		maxx=0;
		minn=9999;
		scanf("%d",&d);
		for(j=1;j<=d;j++){
			scanf("%d",&p[j]);
			if(p[j]>maxx) maxx=p[j];
		}
		valid=0;
		for(cake=1;cake<=maxx;cake++){
			time=0;
			for(k=1;k<=d;k++){
				t[k]=(p[k]-1)/cake;
				time+=t[k];
			}
			if(cake+time<minn) minn=cake+time;
		}
		printf("Case #%d: %d\n",i,minn);
	}
	return 0;
}
