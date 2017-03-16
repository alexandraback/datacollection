#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

#define mp make_pair
#define nd second
#define st first
#define pb push_back

using namespace std;

typedef long long int LL;

int a,b,c, value[10], s, d[15];
bool exist[35], czy[75];

bool fun(int liczba, int mn){
	if(liczba==s){
		vector <int> v;
		for(int i=1;i<=b;++i)
			v.pb(value[i]);
		for(int i=0;i<s;++i)
			v.pb(d[i]);
		for(int i=1;i<=c;++i)
			czy[i]=false;
		czy[0]=true;
		int x=b+s;
		for(int i=0;i<x;++i){
			int ob=v[i];
			queue <int> q;
			for(int j=0;j<=c;++j)
				if(czy[j])
					q.push(j);
			while(!q.empty()){
				int k=q.front();
				q.pop();
				czy[k+ob]=true;
			}
		}
		for(int i=1;i<=c;++i)
			if(!czy[i])
				return false;
		return true;
	}
	if(mn>c)
		return false;
	for(int i=mn;i<=c;++i){
		if(!exist[i]){
			d[liczba]=i;
			if(fun(liczba+1,i+1))
				return true;
		}
	}
	return false;
}

int main(){
	int q;
	scanf("%d", &q);
	for(int kozdreczka=1;kozdreczka<=q;++kozdreczka){
		scanf("%d%d%d", &a, &b, &c);
		for(int i=1;i<=b;++i){
			scanf("%d", &value[i]);
			exist[value[i]]=true;
		}
		for(int i=0;i<=c-b;++i){
			s=i;
			if(fun(0,1)){
				printf("Case #%d: %d\n", kozdreczka, i);
				break;
			}
		}
		for(int i=1;i<=c;++i)
			exist[i]=false;
	}
	return 0;
}
