#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define N 1500

using namespace std;

struct level{
	int a,b,split;
} l[N];
int n,test,cas = 1,ans,cnt;

bool cmp(const level &q,const level &p){
	return q.b<=p.b;
}
int work(){
	scanf("%d",&n);
	for ( int i = 0 ; i < n ; i++ ){
		scanf("%d%d",&l[i].a,&l[i].b);
		l[i].split = 0;
	}
	sort(l,l+n,cmp);
	cnt = 0;
	ans = n;
	for ( int i = 0 ; i < n ; i++ ){
		while (l[i].b>cnt) {
			int best = -1;
			for ( int j = i ; j < n ; j++ )
				if (!l[j].split && l[j].a<=cnt) best = j;
			if (best==-1) return -1;
			cnt++;
			l[best].split = 1;
			ans++;
		}
		cnt += 2-l[i].split;
	}
	return ans;
}
int main(){
	freopen("B-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	for ( scanf("%d",&test) ; cas <= test ; cas++ ){
		printf("Case #%d: ",cas);
		int ans = work();
		if (ans==-1) printf("Too Bad\n");  else printf("%d\n",ans);
	}
}
