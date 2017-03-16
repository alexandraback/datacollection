#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>

#define SZ 100006
#define INF (1<<29)
using namespace std;

map<string,double>dp;

int S,K,L;

string tg,key;
double mx;


double back(string cur,int pos)
{
	if(dp.find(cur) != dp.end()) {
		return dp[cur];
	}
	if(pos==S) {
		double ret = 0;
		for(int i=0;i<cur.size() && i+L <= cur.size();i++) {
			bool pl = true;
			for(int j=0;j<L;j++) {
				if(tg[j] != cur[i+j]) {
					pl = false;
					break;
				}
			}
			if(pl) ret++;
		}
		dp[cur] = ret;
		mx = max(mx,ret);
		return ret;
	}
	double p = (1.0/K);
	double ret = 0;
	for(int i=0;i<K;i++) {
		string temp = cur;
		temp.push_back(key[i]);
		ret += p * back(temp,pos+1);
	}
	dp[cur] = ret;
	return ret;


}

int main()
{
	freopen("Bsm.txt","rt",stdin);
	freopen("Ban2.txt","wt",stdout);
	int tst,cas;
	scanf("%d",&tst);
	for(cas=1;cas<=tst;cas++) {
		mx = 0;
		scanf("%d%d%d",&K,&L,&S);
		cin>>key>>tg;
		dp.clear();
		string empty;
		double ans = back(empty,0);
		printf("Case #%d: %.8lf\n",cas,mx-ans);


	}
	return 0;
}