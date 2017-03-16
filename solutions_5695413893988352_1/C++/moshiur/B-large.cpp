#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int len;
char C[22], J[22];

LL dp[22];
pii ans[22];
LL pwr[22];

char ansC[22], ansJ[22];

LL G(int k, int x, int y, bool store) {
	if (k == len) return 0;

	LL a = 0, b = 0;
	for (int i=k;i<len;++i) {
		if (C[i]=='?') {
			a += x * pwr[i];
			if (store) ansC[i] = '0' + x;
		} else {
			a += (C[i]-'0') * pwr[i];
			if (store) ansC[i] = C[i];
		}

		if (J[i]=='?') {
			b += y * pwr[i];
			if (store) ansJ[i] = '0' + y;
		} else {
			b += (J[i]-'0') * pwr[i];
			if (store) ansJ[i] = J[i];
		}
	}

	//cout<<":::: " << a << ", " << b<<endl;
	return a - b;
}

void update(LL& ret, LL tmp, pii& best, int d1, int d2) {
	if (tmp < ret) {
		ret=tmp; best=pii(d1,d2);
	} else if(tmp == ret) {
		if (best.first==-1){
			best = pii(d1,d2);
		} else {
			if (best.first > d1) best = pii(d1,d2);
			else if (best.first == d1 && best.second > d2) best = pii(d1,d2);
		}
	}
}

LL ABS(LL x){
	if (x<0)x=-x;
	return x;
}

LL INF;

LL F(int k) {
	if (k == len) {
		return 0;
	}

	LL& ret = dp[k];
	if (ret>-1)return ret;

	ret = INF;
	pii best(-1,-1);

	for (int d1=0;d1<10;++d1) {
		if (C[k]!='?' && (C[k]-'0')!=d1) continue;
		for (int d2=0;d2<10;++d2) {
			if (J[k]!='?' && (J[k]-'0')!=d2) continue;
			LL tmp;
			if (d1 == d2) {
				tmp = F(k+1);
			} else if (d1 < d2) {
				tmp = (d1-d2) * pwr[k] + G(k+1, 9, 0, false);
			} else {
				tmp = (d1-d2) * pwr[k] + G(k+1, 0, 9, false);
			}
			tmp = ABS(tmp);
			update(ret, tmp, best, d1,d2);
		}
	}

	ans[k] = best;

	return ret;
}

void build(int k) {
	int d1 = ans[k].first;
	int d2 = ans[k].second;
	ansC[k]='0'+d1;
	ansJ[k]='0'+d2;
	if (d1==d2) {
		build(k+1);
	} else if (d1 < d2) {
		G(k+1, 9, 0, true);
	} else {
		G(k+1, 0, 9, true);
	}
}

int main() {
	INF = 0;
	for (int i=0;i<18;++i) INF = INF*10 + 9;
//cout<<INF<<endl;
	int T; scanf("%d",&T);
	for (int t=1;t<=T;++t) {
		scanf("%s%s",C,J);
		len = strlen(C);
		pwr[len-1] = 1;
		for (int i=len-2;i>=0;--i) pwr[i] = pwr[i+1] * 10LL;

		//for(int i=0;i<len;++i)cout<<pwr[i]<<endl;
		memset(dp, -1, sizeof(dp));
		//cout <<">> " << F(0) << endl;
		//cout << ">>> " << ans[0].first << " ... " << ans[0].second << endl;
		F(0);
		build(0);

		printf("Case #%d:", t);

		ansC[len] = ansJ[len] = '\0';

		printf(" %s %s\n", ansC, ansJ);
	}
	return 0;
}
