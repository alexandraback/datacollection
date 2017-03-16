#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#define FOR(i,n) for(int i=0;i<n;++i)

using namespace std;

int ops[4][4] = {{0,1,2,3},{1,4,3,6},{2,7,4,1},{3,2,5,4}};
/*
 * 1-  0
 * i-  1
 * j-  2
 * k-  3
*/

int next(int x,int y) {
	int a = x&3;
	int b = y&3;
	int sa = x&4;
	int sb = y&4;
	return ops[a][b]^sa^sb;
}


int main(void) {
	int t;
	char in[12000];
	int prefix[12000];
	int suffix[12000];
	char s[150000];
	scanf("%d",&t);
	FOR(k,t) {
		int l;
		long long x;
		scanf("%d %lld\n",&l,&x);
		scanf("%s\n",in);
		FOR(i,12) {
			FOR(j,l) {
				s[i*l+j] = in[j];
			}
		}
		long long index_i = 0;
		int left = 0;
		//printf("%s\n",s);
		while(index_i<4*l && left!=1) left = next(left,s[index_i++]); // i is next char
		int index_k = 0;
		int right = 0;
		while(index_k<4*l && right!=3) {
			right = next(s[4*l-1-index_k],right);
			++index_k;
		}
		//printf("%d %d\n",index_i,index_k);
		//printf("%d %d\n",index_i,x*l-index_k);
		
		
		// i cant be done || k cant be done || ...
		if(index_i==4*l || index_k==4*l || index_i>=x*l-index_k || index_i>=x*l || x*l-index_k<0) {
			printf("Case #%d: %s\n",k+1,"NO");
			continue;
		}
		long long real_right = x*l-index_k; // exclusive
		int left_index = index_i / l;
		long long right_index = real_right / l;
		long long gap = right_index - left_index;
		int mid = 0;
		//printf("gap   %d\n");
		if(gap<2) {
			
			for(int i=index_i;i<real_right;++i) mid = next(mid,s[i]);
		}
		else {
			int a = 0;
			for(int i=index_i;i<(index_i/l)*l+l;++i) a = next(a,s[i]);
			int b = 0;
			for(int i=0;i<real_right%l;++i) b = next(b,s[i]);
			int c=0;
			for(int i=0;i<l;++i) c = next(c,s[i]);
			int d = 0;
			FOR(j,(gap-1)%4) d = next(d,c);
			// a b d
			a = next(a,d);
			a = next(a,b);
			mid = a;
		}
		printf("Case #%d: %s\n",k+1,mid==2?"YES":"NO");
		
	}

   
}