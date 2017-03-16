#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

#define mp make_pair
#define nd second
#define st first
#define pb push_back

using namespace std;

typedef long long int LL;

typedef long double LD;

LD w, mx;

int l,s,k;

char S[10], L[10], K[10];

void fun(int liczba){
	LD MX=0.0;
	if(liczba==s){
		for(int i=0;i<s-l+1;++i){
			bool kozdra=true;
			for(int j=0;j<l;++j)
				if(S[i+j]!=L[j]){
					kozdra=false;
					break;
				}
			if(kozdra){
				w+=1.0;
				MX+=1.0;
			}
		}
		mx=max(mx,MX);
		return;
	}
	for(int i=1;i<=k;++i){
		S[liczba]=K[i-1];
		fun(liczba+1);
	}
}

int main(){
	int q;
	scanf("%d", &q);
	for(int kozdreczka=1;kozdreczka<=q;++kozdreczka){
		scanf("%d %d %d", &k, &l, &s);
		scanf("%s %s", K, L);
		fun(0);
		LD inf=1.0;
		for(int i=1;i<=s;++i)
			inf*=(LD)k;
		printf("Case #%d: %.6Lf\n", kozdreczka, mx-w/inf);
		w=0.0;
		mx=0.0;
	}
	return 0;
}
