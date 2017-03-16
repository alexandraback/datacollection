#include <bits/stdc++.h>
using namespace std;

pair<int,char> A[500000];


pair<int,char> table[4][4] = {{{1,'1'},{1,'i'},{1,'j'},{1,'k'}},
						 {{1,'i'},{-1,'1'},{1,'k'},{-1,'j'}},
						 {{1,'j'},{-1,'k'},{-1,'1'},{1,'i'}},
						 {{1,'k'},{1,'j'},{-1,'i'},{-1,'1'}}
						};

int get_idx(char & c1){
	switch(c1){
		case '1':
			return 0;
		case 'i':
			return 1;
		case 'j':
			return 2;
		case 'k':
			return 3;
	}
}
int mul(char & c1,char & c2,char & c3){
	int k1 = get_idx(c1),k2 = get_idx(c2);
	c3 = table[k1][k2].second;
	return table[k1][k2].first;
}

bool solve(long long X,int L,char*ex){
	bool c = 0;
	int M = min(50LL,X)*L;
	for(int i = L;i < M;i++)
		A[i].first = A[i - 1].first * mul(A[i - 1].second,ex[i%L],A[i].second);
	for(int i = 0;i < M;i++)
		if(c == 0 && A[i].first == 1 && A[i].second == 'i') c = 1;
		else if(c && A[i].first == 1 && A[i].second == 'k') return 1;
	return 0;
}

pair<int,char> trans(pair<int,char> u,long long K){
	if(K == 1) return u;
	pair<int,char> v;
	v.first = mul(u.second,u.second,v.second);
	if(K%2 == 0) u = table[0][0];
	K /= 2;
	if((v.first == 1) || ((K%2 == 0) && K)) return u;
	u.first *= -1;
	return u;
}

int main(){
	int T,L; long long X;
	char ex[10010];
	scanf("%d",&T);
	for(int t = 1;t <= T;t++){
		scanf("%d %lld %s",&L,&X,ex);
		A[0].first = 1; A[0].second = ex[0];
		for(int i = 1;i < L;i++)
			A[i].first = A[i - 1].first * mul(A[i - 1].second,ex[i%L],A[i].second);
		pair<int,char> tmp = A[L - 1];
		int c = 0; 
		tmp = trans(tmp,X);
		if(tmp.first == -1 && tmp.second == '1') c = solve(X,L,ex);
		printf("Case #%d: ",t);
		if(c) puts("YES");
		else puts("NO");
	}	
	return 0;
}