#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int Bitbit,J;

char ch[100005];

int pri[100005],Ths[100005],outpu[100005];

void another_check(int w){
	outpu[w]=0;
	fo(i,1,pri[0]){
		int now=0;
		fd(j,Bitbit,1)
			now=(now*w+Ths[j]) % pri[i];
		if (now==0) {
			outpu[w]=pri[i];
			return;
		}
	}
}

bool check(){
	fo(i,2,10) {
		another_check(i);
		if (outpu[i]==0) return 0;
	}
	fd(i,Bitbit,1) printf("%d",Ths[i]);
	fo(i,2,10) printf(" %d",outpu[i]);
	puts("");
	return 1;
}

void chazhao(int w){
	if (J==0) return;
	if (w==0) {
		if (check()) J--;
		return;
	}
	if (w==1||w==Bitbit) {
		Ths[w]=1;
		chazhao(w-1);
		if (J==0) return;
		return;
	}
	if (J==0) return;
	Ths[w]=0;
	chazhao(w-1);
	if (J==0) return;
	Ths[w]=1;
	chazhao(w-1);
	if (J==0) return;
}

int main(){
	freopen("3.out","w",stdout);
	Bitbit=32;
	J=500;
	fo(i,2,100) {
		bool ok=1;
		for(int j=2;j*j<=i;j++)
			if (i % j==0) {
				ok=0;
				break;
			}
		if (ok) pri[++pri[0]]=i;
	}
	puts("Case #1:");
	chazhao(Bitbit);
	return 0;
}
