#include <cstdio>
#include <iostream>
using namespace std;
int v[10010], e, r, n;
int m[10010], pos[10010];
int seg[40040];
void construct(int o, int l, int r){
	if(l<r){
		int mid = (l+r)>>1;
		construct(o*2, l, mid);
		construct(o*2+1, mid+1, r);
		seg[o] = max(seg[o*2], seg[o*2+1]);
	}
	else seg[o] = v[l];
}
int query(int o, int l, int r, int ql, int qr){
	int ans = 0, mid = (l+r)>>1;
	if(ql <= l && r <= qr) return seg[o];
	if(ql <= mid) ans = max(ans, query(o*2, l, mid, ql, qr));
	if(mid < qr) ans = max(ans, query(o*2+1, mid+1, r, ql, qr));
	return ans;
}
int main(){
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		scanf("%d%d%d", &e, &r, &n);
		for(int i = 1; i <= n; ++i) scanf("%d", &v[i]);
		m[n] = v[n]; pos[n] = n;
		for(int i = n-1; i>0; --i){
			if(v[i] >= m[i+1]){m[i] = v[i]; pos[i] = i;}
			else{m[i] = m[i+1]; pos[i] = pos[i+1];}
		}
		construct(1, 1, n);
		long long ans = 0, now = e;
		long long tmp;
		for(int i = 1; i <= n; ++i){
			if(v[i] == m[i]){ ans = ans + now*v[i]; now = r;}
			else if(v[i] == query(1,1,n,i,pos[i]-1)){
				tmp = (pos[i] - i)*r;
				tmp = (now+tmp) - e;
				if(tmp < 0) tmp = 0;
				if(tmp > now) tmp = now;
				ans = ans + tmp*v[i];
				now = now + r - tmp;
			}
			else{
				tmp = (now+r)-e;
				if(tmp < 0) tmp = 0;
				ans = ans + tmp*v[i];
				now = now+r-tmp;
			}
//			printf("At %d energy = %lld\n", i, now);
		}
		printf("Case #%d: %lld\n", kase, ans);
	}
}
