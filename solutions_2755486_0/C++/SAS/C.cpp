#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
int N;
int d[1021],n[1021],w[1021],e[1021],s[1021],dd[1021],dp[1021],ds[1021];
int wall[3000];
int base = 1500;

class Attack{
	public:
		int d,w,e,s;
};
bool comp(pair<int, Attack> p1,pair<int, Attack> p2) {
	return (p1.first < p2.first);
}
vector<pair<int , Attack> >sequence;
int main(){
	int T;
	scanf("%d",&T);
	for(int ca = 0; ca < T; ca++){
		for(int i=0;i< 3000;i++)wall[i] = 0;
		scanf("%d", &N);
		sequence.clear();
		for(int i=0;i<N;i++){
			scanf("%d %d %d %d %d %d %d %d", &d[i], &n[i], &w[i], &e[i], &s[i], &dd[i], &dp[i], &ds[i]);
			for(int j=0;j<n[i];j++){
				Attack a;
				a.d = d[i] + dd[i] * j;
				a.w = w[i] + dp[i] * j;
				a.e = e[i] + dp[i] * j;
				a.s = s[i] + ds[i] * j;
				pair<int , Attack> p;
				p.first = a.d;
				p.second = a;
				sequence.push_back(p);
			}
		}
		int totalN = sequence.size();
		sort(sequence.begin(), sequence.end(), comp);
		int ans = 0;
		int i = 0;
		while(i < totalN){
			int begin = i;
			int d = sequence[i].first;
			int end = begin + 1;
			while(end < totalN){
				if(sequence[end].first != d)break;
				end++;
			}
			for(int j=begin;j<end;j++){
				Attack a = sequence[j].second;
				int d = a.d;
				int w = a.w;
				int e = a.e;
				int s = a.s;
				int mw = 2147483647;
				for(int k=base + w;k< base + e;k++){
					mw = min(wall[k], mw);
				}
				if(mw < s){
					ans += 1;
				}
			}
			for(int j=begin;j<end;j++){
				Attack a = sequence[j].second;
				int d = a.d;
				int w = a.w;
				int e = a.e;
				int s = a.s;
				for(int k=base + w;k< base + e;k++){
					wall[k] = max(wall[k] , a.s);
				}
			}
			i = end;
		}
		printf("Case #%d: %d\n", ca + 1,ans);
	}
	return 0;
}
