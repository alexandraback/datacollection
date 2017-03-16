#include <stdio.h>
const int table[][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 2, 3, 4},
	{0, 2, -1, 4, -3},
	{0, 3, -4, -1, 2},
	{0, 4, 3, -2, -1},
};
int get_one(int a, int b){
	int neg = ((a<0) ^ (b<0));
	int fac;
	if (neg)
		fac = -1;
	else
		fac = 1;
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;
	return fac*table[a][b];
}
int get_many(int *k, int n){
	int ans = k[0], i;
	for (i=1; i<n; i++)
		ans = get_one(ans, k[i]);
	return ans;
}
int postfix[10000], prefix[10000];
void calc_prepost(int *k, int n, int *postfix, int *prefix) {
	int i;
	prefix[0] = k[0];
	for (i=1;i<n;i++)
		prefix[i] = get_one(prefix[i-1], k[i]);
	postfix[n-1] = k[n-1];
	for (i=n-2; i>=0; i--)
		postfix[i] = get_one(k[i], postfix[i+1]);
}
char buf[10000];
int seq[10000];
int main(){
	int t, p;
	scanf("%d", &t);
	for (p=1;p<=t;p++) {
		int l, x;
		scanf("%d%d\n", &l, &x);
		scanf("%s", buf);
		int i;
		for(i=0;i<l;i++)
			seq[i] = buf[i]-'i'+2;
		calc_prepost(seq, l, postfix, prefix);
		int k;
		int pre=1;
		int cutpoint;
		int mx = x < 4 ? x : 4;
		for (k=0;k<mx;k++) {
			for (i=0;i<l;i++) {
				int tmp =get_one(pre, prefix[i]);
				if (tmp == 2) {
					cutpoint = i;
					break;
				}
			}
			if (i < l)
				break;
			pre = get_one(pre, prefix[l-1]);
		}
		if (k>=mx) {
			//no 'i' found
			printf("Case #%d: NO\n", p);
			continue;
		}
		x = x-k-1; //How many repeats have been consumed
		//Find 'j'
		pre = 1;
		int flags = 0;
		int cutpoint2;
		for (i=cutpoint+1; i < l; i++) {
			pre = get_one(pre, seq[i]);
			if (pre == 3) {
				cutpoint2 = i;
				break;
			}
		}
		if (i >= l) {
			int mx = x < 4 ? x : 4;
			pre = cutpoint+1 < l ? postfix[cutpoint+1] : 1;
			for (k=0;k<mx;k++) {
				for (i=0;i<l;i++) {
					int tmp =get_one(pre, prefix[i]);
					if (tmp == 3) {
						cutpoint2 = i;
						break;
					}
				}
				if (i < l)
					break;
				pre = get_one(pre, prefix[l-1]);
			}
			if (k >= mx) {
				//no 'j' found
				printf("Case #%d: NO\n", p);
				continue;
			}
			x -= k+1;
		}
		//Verify the last part is 'k'
		int last = 1;
		for (k=0;k<x%4;k++)
			last = get_one(last, prefix[l-1]);
		if (cutpoint2+1 < l)
			last = get_one(postfix[cutpoint2+1], last);
		if (last != 4)
			printf("Case #%d: NO\n", p);
		else
			printf("Case #%d: YES\n", p);
	}
}
