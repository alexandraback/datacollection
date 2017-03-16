//BISMILLAHIRRAHMANIRRAHIM



#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cctype>
#include <climits>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <gmpxx.h>

using namespace std;


#define i64 long long
#define pii pair < int , int >
#define CLR(x) memset(x,0,sizeof x)
#define SET(x,y) memset(x,y,sizeof x)
#define PB(x) push_back(x)
#define mx 1000000

mpz_class rt[mx+10],sq[mx+10];

bool ispal(mpz_class a) {
	int d[160],l=0;
	mpz_class ten=10,t;
	while(cmp(a,0)) {
		t=a%ten;
		d[l++]=t.get_si();
		a/=ten;
	}
	int i=0,j=l-1;
	while(i<j) {
		if(d[i]!=d[j]) return false;
		i++;j--;
	}
	return true;
}

int main() {
	freopen("C-large-1.in","r",stdin);
	freopen("output_large1.out","w",stdout);
	int l=0,tl,ts,ml,j;
	int i;
	mpz_class t;
	for(i=1;i<10000;i++) if(ispal(t=mpz_class(i)) && ispal(t*t)) {
		rt[l]=i;
		sq[l]=i*i;
		//cout<<rt[l]<<' '<<sq[l]<<'\n';
		l++;
	}
	//cout<<l<<'\n';
	mpz_class bs(1000),ten(10),cr=bs,one(1);
	for(i=5;i<=51;i++) {
		tl=l;
		cr*=ten;
		bs=cr+one;
		rt[l]=bs;
		sq[l]=bs*bs;
		//cout<<rt[l]<<' '<<sq[l]<<'\n';
		l++;
		for(j=0;j<tl;j++) if((i&1) == ((ts=rt[j].get_str().size())&1)) {
			ml=(i-ts)>>1;
			t=rt[j];
			while(ml--) t*=ten;
			t+=bs;
			if(ispal(t) && ispal(t*t)) {
				rt[l]=t;
				sq[l]=t*t;
				//cout<<rt[l]<<' '<<sq[l]<<'\n';
				l++;
			}
		}
		bs+=bs;
		rt[l]=bs;
		sq[l]=bs*bs;
		//cout<<rt[l]<<' '<<sq[l]<<'\n';
		l++;
		for(j=0;j<tl;j++) if((i&1) == ((ts=rt[j].get_str().size())&1)) {
			ml=(i-ts)>>1;
			t=rt[j];
			while(ml--) t*=ten;
			t+=bs;
			if(ispal(t) && ispal(t*t)) {
				rt[l]=t;
				sq[l]=t*t;
				//cout<<rt[l]<<' '<<sq[l]<<'\n';
				l++;
			}
		}
	}
	cerr<<l<<'\n';
	int I,T;
	cin>>T;
	mpz_class a,b;
	for(I=1;I<=T;I++) {
		cin>>a>>b;
		i=int(lower_bound(sq,sq+l,a)-sq);
		j=int(upper_bound(sq,sq+l,b)-sq);
		printf("Case #%d: %d\n",I,j-i);
	}
	return 0;
}
