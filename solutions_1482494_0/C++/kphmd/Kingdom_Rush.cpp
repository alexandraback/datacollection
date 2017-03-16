#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

void solve();
void runCase();

const int MN = 1000;
int a[MN],b[MN],c[MN];
int N;
int s;
int res;

bool run2() {
	int maxi = -1;
	for(int i = 0; i < N; i++) {
		if(c[i]==0) {
			if(s>=b[i]) {
				if(maxi==-1 || b[maxi]>b[i]) maxi = i;
			}
		}
	}
	if(maxi!=-1) {
		int i = maxi;
		s+=2;
		res++;
		c[i] = 2;
		return true;
	}
	return false;
}

bool run10() {
	for(int i = 0; i < N; i++) {
		if(c[i]==0) {
			if(s>=a[i]) {
				s+=1;
				res++;
				c[i] = 1;
				return true;
			}
		}
	}
	return false;
}

bool run11() {
	for(int i = 0; i < N; i++) {
		if(c[i]==1) {
			if(s>=b[i]) {
				s+=1;
				res++;
				c[i] = 2;
				return true;
			}
		}
	}
	return false;
}

bool check() {
	for(int i = 0; i < N; i++) {
		if(c[i]!=2) return false;
	}
	return true;
}

void runCase()
{
	scanf("%d",&N);
	for(int i = 0; i < N; i++) {
		scanf("%d %d",&a[i],&b[i]);
		c[i] = 0;
	}
	s = 0;
	res = 0;
	while(true) {
		bool f;
		f = run2();
		if(!f) f = run11();
		if(!f) f = run10();
		if(!f) {
			if(!check()) {
				res = -1;
			}
			break;
		}
	}

	if(res==-1) printf("Too Bad\n");
	else printf("%d\n",res);
}

void solve()
{
	int n;
	scanf("%d",&n);
	getchar();
	
	for(int i = 0; i < n; i++) {
		printf("Case #%d: ",i+1);
		runCase();
	}
}

int main()
{
	solve();
	return 0;
}
