#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

int main(){
	int t,r,c,w,ans;
	FILE *f = fopen("A-large.in", "r");
	FILE *fo = fopen("out.txt", "w+");
	fscanf(f, "%d", &t);
	for (int i = 1; i <= t; i++)
	{
		ans = 0;
		fscanf(f, "%d %d %d", &r, &c, &w);
		ans += c / w;
		if (c%w == 0)
		{
			ans += w - 1;
		}
		else{
			ans += w;
		}
		ans += (r - 1)*c / w;
		fprintf(fo, "Case #%d: %d\n", i, ans);
	}

}