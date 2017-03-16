#include <bits/stdc++.h>
using namespace std;

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

int main(){
	int T,X,L;
	char ex[10010];
	pair<int,char> A[10000];
	scanf("%d",&T);
	for(int t = 1;t <= T;t++){
		scanf("%d %d %s",&L,&X,ex);
		A[0].first = 1; A[0].second = ex[0];
		for(int i = 1;i < L*X;i++)
			A[i].first = A[i - 1].first * mul(A[i - 1].second,ex[i%L],A[i].second);
		int c = 0;
		if(A[L*X - 1].first == -1 && A[L*X - 1].second == '1')
		for(int i = 0;i < L*X - 2 && c == 0;i++)
			if(A[i].first == 1 && A[i].second == 'i')
				for(int j = i + 1;j < L*X - 1 && c == 0;j++)
					if(A[j].first == 1 && A[j].second == 'k')
						c = 1;
		printf("Case #%d: ",t);
		if(c) puts("YES");
		else puts("NO");
	}	
	return 0;
}