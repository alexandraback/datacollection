#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int64;
const int maxn=11000;

// 1,i,j,k, -1,-i,-j,-k
int mult[8][8];
void print(int v, int s) {
	const char vtable[]="1ijk", stable[]="+-";
	printf("%c%c",stable[s],vtable[v]);
}
void preprocess() {
	for(int vA=0;vA<4;vA++)
	for(int sA=0;sA<2;sA++)
	for(int vB=0;vB<4;vB++)
	for(int sB=0;sB<2;sB++) {
		int s=sA+sB,v;
		if(vA==0)
			v=vB;
		else if(vB==0)
			v=vA;
		else if(vA==vB)
			v=0, s++;
		else {
			v=6-vA-vB;
			if((vB-vA+3)%3!=1)
				s++;
		}
		s%=2;
		mult[vA+sA*4][vB+sB*4]=v+s*4;
		//print(vA,sA),printf("*"),print(vB,sB),printf("="),print(v,s),printf("\n");
	}
}
char s[maxn];

void solve(int icase) {
	
	int n;
	int64 rep;
	scanf("%d%lld\n%s",&n,&rep,s);
	rep-=max((rep-24)/8*8,0LL);
	
	const int goal[3]={1,3,4};
	int len=n*rep, prod=0, step=0;
//	bool ans=false;
	for(int i=0,pos=0; i<len; i++,pos=(pos==n-1)?0:(pos+1)) {
		int val=s[pos]-'i'+1;
		prod = mult[prod][val];
		//print(prod%4,prod/4);printf(" ");
		if(prod == goal[step] && (step<2 || i==len-1)) {
			++step;
			//printf("HIT ");
		}
	}
	printf("Case #%d: %s\n",icase,(step==3)?"YES":"NO");
}
int main() {
	preprocess();
	
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
		solve(i);
	scanf("%*s");
	return 0;
}
