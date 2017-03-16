#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <iostream>

#define ln printf("\n")
typedef long long ll;

#define fr(a,b,c) for(int a = b; a < c; a++)
#define rep(a,b) fr(a,0,b)

#define dbg(x) cerr << #x << " = " << x << endl
#define db dbg
#define _  << " , " <<

#define sarr(r,n) rep(i,n) scanf("%d", &r[i])
#define parr(r,n) printf("%d", r[0]); fr(i,1,n) printf(" %d", r[i]);  ln; 
#define mem(r,v) memset(r, v, sizeof r)

using namespace std;

struct mote{
	int v;
	int mark;
	
	bool operator < (const mote & b) const{
		return v < b.v;
	}
};

const double eps = 1e-8;
int n,a;
mote r[11111];
int cn = 1;

bool read(){
	scanf("%d%d", &a,&n);	
	//db(n _ a);
	rep(i,n) scanf("%d", &r[i].v);
	
	return true;
}

int rem[11111];
int add[11111];

void print(){
	rep(i,n) printf("%d ", r[i].v);
	ln;
}

void process(){
	printf("Case #%d: ", cn++);
	
	int res = 1111111;
	
	if(a == 1){
		printf("%d\n", n);
		return;
	}	
	
	int added = 0;
	
	sort(r, r+n);	
	int cur = a;
	
	//print();
	
	rep(i,n){
		//printf("%d\n", i);
		//r[i].mark = 0;
		
		res = min(res, (n-i) + added);
		
		while(cur <= r[i].v){
			//r[n + added].v = (cur-1);
			//r[n + added].mark = 1;
			added++;
			cur += cur-1;						
		}
		
		cur += r[i].v;
	}
	
	res = min(res, added);
	/*
	n += added;
	
	sort(r, r+n);
	
	//print();
	
	rem[n-1] = 0;
	add[0] = 0;
	if(r[n-1].mark == 0) rem[n-1] = 1;
	if(r[0].mark == 1) add[0] = 1;
	
	for(int i = n-2; i >= 0; i--){
		rem[i] = rem[i+1];		
		if(r[i].mark == 0) rem[i]++;		
	}
	
	fr(i,1,n){
		add[i] = add[i-1];
		if(r[i].mark == 1) add[i]++;
	}
	
	
	
	rep(i,n+1){
		int addcur, remcur;
		if(i == n) addcur = add[n-1];
		else addcur = add[i];
		
		if(i == n) remcur = 0;
		else remcur = rem[i];
		
		res = min(res, addcur+remcur);
	}
		
	//parr(rem,n);
	//parr(add,n);
		*/
	printf("%d\n", res);
	
}

int main(){	
	int t = -1;
	scanf("%d", &t);
	
	while(t-- && read()){		
		process();
	}	
	
	return 0;
}
