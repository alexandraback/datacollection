#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int ml[][5]={
	{0,0,0,0,0},
	{0, 1, 2, 3, 4},
	{0, 2, -1, 4, -3},
	{0, 3, -4, -1, 2},
	{0, 4, 3, -2, -1}
};

char a[10010];
int d[10010];
int tt, l, r, final;
long long x;

int mul(int a, int b){
	int o1 =1, o2 = 1;
	if (a==0 || b==0)while (true);

	if (a<0){
		o1 = -1;
		a = -a;
	}
	if (b<0){
		o2 = -1;
		b = -b;
	}
	return ml[a][b]*o1*o2;
}

int calc(int* a, int s, int t){
	int ret = 1;
	for (int i=s; i<=t; i++){
		ret = mul(ret, d[i]);
	}

	return ret;
}

int exp(int a, long long x){
	if (a==1) return 1;
	int i = x%4;
	if (i==0) return 1;
	if (i==1) return a;
	if (i==2) return mul(a, a);
	if (i==3) return mul(mul(a, a), a);
}

void goo(long long& a, long long b){
	if (a == -1 || a > b) a = b;
}

bool doit(){
	long long bi = -1, bk = -1;

	if (r==2 && x>=2) bi = l;
	if (r==-2 && x>=4) bi = l*3;
	
	int current = 1;
	for (int i=0; i<l-1; i++){
		current = mul(current, d[i]);
		
		if (current == 2){
			goo(bi, i+1);
		}
		if (x>=2 && mul(r, current) == 2){
			goo(bi, i+1+l);
		}
		if (x>=3 && mul(-1, current) == 2){
			goo(bi, i+1+l*2);
		}
		if (x>=4 && mul(-r, current) == 2){
			goo(bi, i+1+l*3);
		}
	}

	if (r==4 && x>=2) bk = l;
	if (r==-4 && x>=4) bk = l*3;
	
	current = 1;
	for (int i=0; i<l-1; i++){
		current = mul(d[l-1-i], current);
		
		if (current == 4){
			goo(bk, i+1);
		}
		if (x>=2 && mul(current, r) == 4){
			goo(bk, i+1+l);
		}
		if (x>=3 && mul(current, -1) == 4){
			goo(bk, i+1+l*2);
		}
		if (x>=4 && mul(current, -r) == 4){
			goo(bk, i+1+l*3);
		}
	}
	
	return bi!=-1 && bk!=-1 && bi < x*l-bk;
}

bool doit2(){
	int current = 1, ret=0;
	for (int i=0; i<x; i++){
		for (int j=0; j<l; j++){
			current = mul(current, d[j]);
			
			if (current==2 && ret==0)
				ret++;
			else if (current==4 && ret==1)
				ret++;
			else if (ret==2)
				ret++;
		}
	}
	return ret==3;
}

int main(){
	freopen("C-small-attempt5.in", "r", stdin);
	freopen("aa.out", "w", stdout);

	scanf("%d", &tt);
	for (int task=1; task<=tt; task++){
		scanf("%d%lld", &l, &x);
		scanf("%s", a);
		for (int i=0; i<l; i++){
			if (a[i]=='i') d[i] = 2;
			if (a[i]=='j') d[i] = 3;
			if (a[i]=='k') d[i] = 4;
		}

		r = calc(d, 0, l-1);
		final = exp(r, x);

		if (final == -1 && doit2())
			printf("Case #%d: YES\n", task);
		else
			printf("Case #%d: NO\n", task);
	}

	return 0;
}
